import numpy as np
import re, itertools

from . import cwrapping

from assimulo.problem import Explicit_Problem
from assimulo.solvers import CVode #Imports the solver CVode from Assimulo


class ModelSolver:
    def __init__(self, c_code_path, wrapper = None):
        if wrapper is None:
            self.wrapper = cwrapping.CythonWrapper(c_code_path)
        else:
            self.wrapper = wrapper 

        #Parse from the C file
        with open(c_code_path) as f:
            self.algebraicNames = {}
            self.statesNames = {}
            self.constantsNames = {}
            for l in f.readlines():
                parsedVar = re.search('(ALGEBRAIC|STATES|CONSTANTS)\[([0-9]+)\] is (.*) in component (.*) \(.*\)',l)
                if parsedVar:
                    if parsedVar.group(1) == 'ALGEBRAIC':
                        d = self.algebraicNames
                    elif parsedVar.group(1) == 'STATES':
                        d = self.statesNames
                    elif parsedVar.group(1) == 'CONSTANTS':
                        d = self.constantsNames
                    else:
                        raise ValueError('Unknown var type')
                    
                    d[(parsedVar.group(4), parsedVar.group(3))] = int(parsedVar.group(2))
                    continue

                numConstants = re.search('There are a total of ([0-9]+) entries in the constant variable array.', l)
                if numConstants:
                    self.nConstants = int(numConstants.group(1))
                    continue

                numAlgebraic = re.search('There are a total of ([0-9]+) entries in the algebraic variable array.', l)
                if numAlgebraic:
                    self.nAlgebraic = int(numAlgebraic.group(1))
                    continue

                numStates = re.search('There are a total of ([0-9]+) entries in each of the rate and state variable arrays.', l)
                if numStates:
                    self.nStates = int(numStates.group(1))
                    continue
        # Check everything was OK
        assert(self.nAlgebraic == len(self.algebraicNames))
        assert(self.nStates == len(self.statesNames))
        assert(self.nConstants == len(self.constantsNames))

        self.resetStatesAndConstants()

    def resetStatesAndConstants(self):
        #Initialise Values
        self.constants = np.empty(self.nConstants)
        self.states0 =  np.empty(self.nStates)
        self.wrapper.initConsts(self.constants, self.states0)


    def solve(self, tFinal = 1, t0 = 0):
        rates =  np.empty(self.nStates)
        algebraic =  np.empty(self.nAlgebraic)

        def wrapper_f(voi, states, constants = self.constants, rates = rates, algebraic = algebraic):
            self.wrapper.computeRates(voi,
                                    constants, 
                                    rates,
                                    states,
                                    algebraic)
            return rates

        model = Explicit_Problem(wrapper_f, self.states0, t0) #Create an Assimulo problem
        model.name = 'Model'        #Specifies the name of problem (optional)


        sim = CVode(model)
        sim.discr='BDF'
        sim.iter='Newton'
        sim.atol = 1e-7
        sim.rtol = 1e-7

        self.t, self.states = sim.simulate(tFinal) #Use the .simulate method to simulate and provide the final time
        self.algebraic = np.zeros((len(self.t), self.nAlgebraic))
        self.t = np.array(self.t)

        #TODO: this is quite slow, use the loop in C instead for much faster acceleration
        rates = np.empty(self.states.shape)
        self.wrapper.computeAlgebraicVector(self.t, self.constants, rates, self.states, self.algebraic)

    def setConstantOrState0(self, component, name, value):
        if (component, name) in self.statesNames:
            self.states0[self.statesNames[(component, name)]] = value
        elif (component, name) in self.constantsNames:
            self.constants[self.constantsNames[(component, name)]] = value
        else:
            raise ValueError('Name not found')
    
    def getVariable(self, component, name):
        if (component, name) in self.statesNames:
            i = self.statesNames[(component, name)]
            return self.states[:, i]
        if (component, name) in self.algebraicNames:
            i = self.algebraicNames[(component, name)]
            return self.algebraic[:, i]
        else:
            raise ValueError('Name not found')
        
    def getConstant(self, component, name):
        if (component, name) in self.constantsNames.keys():
            i = self.constantsNames[(component, name)]
            return self.constants[i]

    #Getters
    def getAllNames(self):
        return [v for v in itertools.chain(self.statesNames.keys(), self.constantsNames.keys(), self.algebraicNames.keys())]
    
    def getAllComponents(self):
        s = {}
        for c, _ in itertools.chain(self.statesNames.keys(), self.constantsNames.keys(), self.algebraicNames.keys()):
            s.add(c)
        return s
    
    def saveResults(self, path, n_cycles = 2, **kwargs):
        names = [0] * (len(self.statesNames) + len(self.algebraicNames))
        names_constants = [0] * len(self.constantsNames)
        for k, v in self.statesNames.items():
            names[v] = k
        for k, v in self.algebraicNames.items():
            names[v + len(self.statesNames) ] = k
        for k, v in self.constantsNames.items():
            names_constants[v] = k

        idx = self.t > self.t[-1] - self.getConstant('Parameters','T')*n_cycles        # save only last 2 cycles

        np.savez(path, voi = self.t[idx],  data = np.concatenate([self.states[idx], self.algebraic[idx]], axis = 1), names = names, constants = self.constants, names_constants = names_constants, **kwargs)

    def saveResults2(self, path, n_cycles = 2, **kwargs):
        names = [0] * (len(self.statesNames) + len(self.algebraicNames))
        names_constants = [0] * len(self.constantsNames)
        for k, v in self.statesNames.items():
            names[v] = k
        for k, v in self.algebraicNames.items():
            names[v + len(self.statesNames) ] = k
        for k, v in self.constantsNames.items():
            names_constants[v] = k

        idx = self.t > self.t[-1] - self.getConstant('Parameters','T')*n_cycles        # save only last 2 cycles

        np.savez(path, voi = self.t[idx].astype(np.float16),  data = np.concatenate([self.states[idx].astype(np.float16), self.algebraic[idx].astype(np.float16)], axis = 1), names = names, constants = self.constants, names_constants = names_constants, **kwargs)

    def saveResults3(self, path, n_cycles = 2, **kwargs):
        names = [0] * (len(self.statesNames) + len(self.algebraicNames))
        names_constants = [0] * len(self.constantsNames)
        for k, v in self.statesNames.items():
            names[v] = k
        for k, v in self.algebraicNames.items():
            names[v + len(self.statesNames) ] = k
        for k, v in self.constantsNames.items():
            names_constants[v] = k

        idx = self.t > self.t[-1] - self.getConstant('Parameters','T')*n_cycles        # save only last 2 cycles

        np.savez(path, voi = self.t[idx].astype(np.float32),  data = np.concatenate([self.states[idx].astype(np.float32), self.algebraic[idx].astype(np.float32)], axis = 1), names = names, constants = self.constants, names_constants = names_constants, **kwargs)