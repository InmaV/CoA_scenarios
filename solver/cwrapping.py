import abc,ctypes
import numpy as np
import shutil, pathlib, os, importlib


class CWrapper(metaclass=abc.ABCMeta):
    pass

c_double_p = ctypes.POINTER(ctypes.c_double)
class ClibWrapper(CWrapper):
    # To generate the library
    #gcc -shared -o libModel.so -fPIC FULL_MODEL_Audebert.c (-arch x86_64 -> if osx new)

    def __init__(self, cPath = None, cLibPath = None):
        if cPath is None and cLibPath is None:
            raise ValueError('Either a clib or a must be provided')
        elif cLibPath:
            self.clib = ctypes.cdll.LoadLibrary(cLibPath)
        else:
            raise NotImplemented('TODO: compile the C code and get a')
    
    def initConsts(self, constants, states0):
        rates_dummy =  np.empty(len(states0))
        return self.clib.initConsts(constants.ctypes.data_as(c_double_p), rates_dummy.ctypes.data_as(c_double_p), states0.ctypes.data_as(c_double_p))
    
    def computeRates(self, voi, constants, rates, states, algebraic):
        self.clib.computeRates(ctypes.c_double(voi),
                        constants.ctypes.data_as(c_double_p), 
                        rates.ctypes.data_as(c_double_p), 
                        states.ctypes.data_as(c_double_p), 
                        algebraic.ctypes.data_as(c_double_p))
        
    def computeAlgebraic(self, voi, constants, rates, states, algebraic):
        self.clib.computeVariables(ctypes.c_double(voi), 
                                  constants.ctypes.data_as(c_double_p), 
                                  rates.ctypes.data_as(c_double_p), 
                                  states.ctypes.data_as(c_double_p), 
                                  algebraic.ctypes.data_as(c_double_p))
        
    def computeAlgebraicVector(self, voi, constants, rates, states, algebraic):
        for i,tt in enumerate(voi):
            self.clib.computeVariables(ctypes.c_double(tt), 
                                    constants.ctypes.data_as(c_double_p), 
                                    rates[i].ctypes.data_as(c_double_p), 
                                    states[i].ctypes.data_as(c_double_p), 
                                    algebraic[i].ctypes.data_as(c_double_p))
            

class CythonWrapper(CWrapper):
    def __init__(self, cPath, needBuild = True):
        pathFile = pathlib.Path(__file__).parent.resolve()
        # Compile and generate the module
        shutil.copyfile(cPath, pathFile / 'Cython' / 'model.C')
        currentCwd = os.getcwd()
        os.chdir(pathFile / 'Cython')
        if not needBuild:
            try:
                self.module = importlib.import_module('computeRates', 'Cython')
                needBuild = False

            except:
                needBuild = True

        if needBuild:
            os.system('python setup.py  build_ext --inplace') #TODO: Superugly, think of something better!
            self.module = importlib.import_module('computeRates', 'Cython')
        os.chdir(currentCwd)


    def initConsts(self, constants, states0):
        rates_dummy =  np.empty(len(states0))
        self.module.initConst_Cython(constants, rates_dummy, states0)
        return constants, states0
    
    def computeRates(self, voi, constants, rates, states, algebraic):
        self.module.computeRates_Cython(voi,
                        constants, 
                        rates, 
                        states, 
                        algebraic)
        
    def computeAlgebraic(self, voi, constants, states, rates, algebraic):
        self.module.computeVariables_Cython(voi, 
                                  constants, 
                                  rates, 
                                  states, 
                                  algebraic)
        return algebraic
        
    def computeAlgebraicVector(self, voi, constants, states, rates, algebraic ):
        self.module.computeVariables_array_Cython(voi, constants, states, rates, algebraic)
        return algebraic
