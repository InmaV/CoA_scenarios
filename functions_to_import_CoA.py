import matplotlib.pyplot as plt
import ctypes, numpy as np
from assimulo.problem import Explicit_Problem
from assimulo.solvers import CVode #Imports the solver CVode from Assimulo
import sys
import os
from scipy import interpolate
from scipy.ndimage import uniform_filter1d
from scipy.signal import argrelextrema

sizeAlgebraic = 181
sizeStates = 73
sizeConstants = 163

constants = np.empty(sizeConstants)
rates =  np.empty(sizeStates)
states =  np.empty(sizeStates)
algebraic =  np.empty(sizeAlgebraic)
myConstants = np.array(constants, dtype = float)

class HiddenPrints:
    def __enter__(self):
        self._original_stdout = sys.stdout
        sys.stdout = open(os.devnull, 'w')

    def __exit__(self, exc_type, exc_val, exc_tb):
        sys.stdout.close()
        sys.stdout = self._original_stdout

def initialize_data(sizeAlgebraic, sizeStates, sizeConstants, name_lib):

    constants = np.empty(sizeConstants)
    rates =  np.empty(sizeStates)
    states =  np.empty(sizeStates)
    algebraic =  np.empty(sizeAlgebraic)
    myConstants = np.array(constants, dtype = float)
    
    clib = ctypes.cdll.LoadLibrary(name_lib)
    c_double_p = ctypes.POINTER(ctypes.c_double)
    clib.initConsts(constants.ctypes.data_as(c_double_p), rates.ctypes.data_as(c_double_p), states.ctypes.data_as(c_double_p));
        
    (legend_states, legend_algebraic, legend_voi, legend_constants) = createLegends(sizeAlgebraic, sizeStates, sizeConstants)

    dictionary_legend_states = {v:k for k,v in enumerate(legend_states)}
    dictionary_legend_algebraic = {v:k for k,v in enumerate(legend_algebraic)}

    diam_ao = 0.77
    diam_mi = 0.9
    diam_tr = 0.93
    diam_pu = 0.87

    return constants, rates, states, algebraic, myConstants, legend_states, legend_algebraic, legend_voi, legend_constants, dictionary_legend_states, dictionary_legend_algebraic, diam_ao, diam_mi, diam_tr, diam_pu

def scaling_param_weight(weight, ref_param, b):
    parameter = ref_param*(weight/1897)**b #3025 for GA = 38 weeks
    return parameter

def scale_parameters_GA(m, weight, Tc):
    b_R = -1; b_L = -0.33; b_C = 1.33; b_K = -1.33; b_d = 0.33; b_A = 0.67; b_V = 1; b_s = 0; b_V0 = 1.33; # como escala el estrés?

    Lscini = 2.
    C0 = 0.0
    Crest = 0.02
    Lsref = 2.
    kS_v = 3.
    p_trise_v = 0.13
    p_td_v = 0.08
    vmax_v = 7.
    p_tact_v = 0.26
    kS_a = 2.25
    p_trise_a = 0.18
    p_td_a = 0.16
    vmax_a = 10.5        
    p_tact_a = 0.10
    B_param = 3.975e-4
    m.setConstantOrState0('Parameters', 'p_tact_v', 0.10*0.85 + 0.45*Tc)    
    m.setConstantOrState0('Parameters', 'delay_lv', 0.375*Tc/0.43) # no estoy segura del escalado de los delays, no estoy segura de que deba ser proporcional a Tc
    m.setConstantOrState0('Parameters', 'delay_rv', 0.375*Tc/0.43)
    m.setConstantOrState0('Parameters', 'p_tact_a', 0.1*Tc/0.43) 
    m.setConstantOrState0('Parameters', 'delay_la', 0.325*Tc/0.43)
    m.setConstantOrState0('Parameters', 'delay_ra', 0.325*Tc/0.43)
    m.setConstantOrState0('LV', 'Vcav', scaling_param_weight(weight, 17, b_V0))
    m.setConstantOrState0('RV', 'Vcav', scaling_param_weight(weight, 17, b_V0))
    m.setConstantOrState0('LA', 'Vcav', scaling_param_weight(weight, 17, b_V0))
    m.setConstantOrState0('RA', 'Vcav', scaling_param_weight(weight, 17, b_V0))
    m.setConstantOrState0('Parameters', 'Vwall_lv', scaling_param_weight(weight, 6.4, b_V))
    m.setConstantOrState0('Parameters', 'Amref_lv', scaling_param_weight(weight, 18.07, b_A))
    m.setConstantOrState0('Parameters', 'Amdead_lv', scaling_param_weight(weight, 3.66, b_A))
    m.setConstantOrState0('Parameters', 'Vwall_rv', scaling_param_weight(weight, 6.4, b_V))
    m.setConstantOrState0('Parameters', 'Amref_rv', scaling_param_weight(weight, 18.07, b_A))
    m.setConstantOrState0('Parameters', 'Amdead_rv', scaling_param_weight(weight, 3.66, b_A))
    m.setConstantOrState0('Parameters', 'Vwall_la', scaling_param_weight(weight, 1.25, b_V))
    m.setConstantOrState0('Parameters', 'Amref_la', scaling_param_weight(weight, 8.05, b_A))
    m.setConstantOrState0('Parameters', 'Amdead_la', scaling_param_weight(weight, 3.66, b_A))
    m.setConstantOrState0('Parameters', 'Vwall_ra', scaling_param_weight(weight, 1.25, b_V))
    m.setConstantOrState0('Parameters', 'Amref_ra', scaling_param_weight(weight, 8.05, b_A))
    m.setConstantOrState0('Parameters', 'Amdead_ra', scaling_param_weight(weight, 3.66, b_A))
    m.setConstantOrState0('Parameters', 'Kaovo', scaling_param_weight(weight, 186.05, b_K))
    m.setConstantOrState0('Parameters', 'Kaovc_p', scaling_param_weight(weight, 29.8, b_K))
    m.setConstantOrState0('Parameters', 'Kaovc_n', scaling_param_weight(weight, 186.05, b_K))
    m.setConstantOrState0('Parameters', 'Kmivo', scaling_param_weight(weight, 74.42, b_K))
    m.setConstantOrState0('Parameters', 'Kmivc_p', scaling_param_weight(weight, 99.2, b_K))
    m.setConstantOrState0('Parameters', 'Kmivc_n', scaling_param_weight(weight, 186.05, b_K))
    m.setConstantOrState0('Parameters', 'Kpvvo', scaling_param_weight(weight, 186.05, b_K))
    m.setConstantOrState0('Parameters', 'Kpvvc_p', scaling_param_weight(weight, 49.62, b_K))
    m.setConstantOrState0('Parameters', 'Kpvvc_n', scaling_param_weight(weight, 186.05, b_K))
    m.setConstantOrState0('Parameters', 'Ktrvo', scaling_param_weight(weight, 74.42, b_K))
    m.setConstantOrState0('Parameters', 'Ktrvc_p', scaling_param_weight(weight, 99.2, b_K))
    m.setConstantOrState0('Parameters', 'Ktrvc_n', scaling_param_weight(weight, 186.05, b_K))
    m.setConstantOrState0('Parameters', 'L_param', scaling_param_weight(weight, 0.00034289, 0.33))
    m.setConstantOrState0('Parameters', 'L_min_ao', scaling_param_weight(weight, 0.0011665, b_L))
    m.setConstantOrState0('Parameters', 'L_min_mi', scaling_param_weight(weight, 0.0011665, b_L))
    m.setConstantOrState0('Parameters', 'L_min_pv', scaling_param_weight(weight, 0.0011665, b_L))
    m.setConstantOrState0('Parameters', 'L_min_tr', scaling_param_weight(weight, 0.0011665, b_L))
    m.setConstantOrState0('Parameters', 'Aao', scaling_param_weight(weight, 0.302, 0.9))
    m.setConstantOrState0('Parameters', 'Ami', scaling_param_weight(weight, 0.407, 0.9))
    m.setConstantOrState0('Parameters', 'Apv', scaling_param_weight(weight, 0.363, 0.9))
    m.setConstantOrState0('Parameters', 'Atr', scaling_param_weight(weight, 0.439, 0.9))
    m.setConstantOrState0('Parameters', 'Rdtao', scaling_param_weight(weight, 0.0687, b_R))
    m.setConstantOrState0('Parameters', 'Rdaao', scaling_param_weight(weight, 0.0957, b_R))
    m.setConstantOrState0('Parameters', 'Rpa', scaling_param_weight(weight, 0.0063, b_R))
    m.setConstantOrState0('Parameters', 'Rlung', scaling_param_weight(weight, 21.531, b_R))
    m.setConstantOrState0('Parameters', 'Rda', scaling_param_weight(weight, 0.03888, b_R))
    m.setConstantOrState0('Parameters', 'Relg', scaling_param_weight(weight, 129.18, b_R))
    m.setConstantOrState0('Parameters', 'Rmea', scaling_param_weight(weight, 54.226, b_R))
    m.setConstantOrState0('Parameters', 'Rporv', scaling_param_weight(weight, 11.164, b_R))
    m.setConstantOrState0('Parameters', 'Rrea', scaling_param_weight(weight, 27.91, b_R))
    m.setConstantOrState0('Parameters', 'Rrev', scaling_param_weight(weight, 22.33, b_R))
    m.setConstantOrState0('Parameters', 'Rua', scaling_param_weight(weight, 6.22, b_R))
    m.setConstantOrState0('Parameters', 'Rplac', scaling_param_weight(weight, 5.423, b_R))
    m.setConstantOrState0('Parameters', 'Rfa', scaling_param_weight(weight, 5.582, b_R))
    m.setConstantOrState0('Parameters', 'Rfv', scaling_param_weight(weight, 0.957, b_R))
    m.setConstantOrState0('Parameters', 'Rha', scaling_param_weight(weight, 0.797, b_R))
    m.setConstantOrState0('Parameters', 'Rhv', scaling_param_weight(weight, 0.225, b_R))
    m.setConstantOrState0('Parameters', 'Rdv', scaling_param_weight(weight, 2.07, b_R))
    m.setConstantOrState0('Parameters', 'Rsvc', scaling_param_weight(weight, 0.32, b_R))
    m.setConstantOrState0('Parameters', 'Rivc', scaling_param_weight(weight, 0.19, b_R))
    m.setConstantOrState0('Parameters', 'Rla', scaling_param_weight(weight, 3.19, b_R))
    m.setConstantOrState0('Parameters', 'Kfo', scaling_param_weight(weight, 0.53, -0.6))
    m.setConstantOrState0('Parameters', 'Kdv', scaling_param_weight(weight, 0.26, -0.88))
    m.setConstantOrState0('Parameters', 'Lda', scaling_param_weight(weight, 0.0001, b_L))
    m.setConstantOrState0('Parameters', 'Lpa', scaling_param_weight(weight, 0.00272, b_L))
    m.setConstantOrState0('Parameters', 'Cao1', scaling_param_weight(weight, 0.08, b_C))
    m.setConstantOrState0('Parameters', 'Cao2', scaling_param_weight(weight, 0.026875, b_C))
    m.setConstantOrState0('Parameters', 'Cpa', scaling_param_weight(weight, 0.05375, b_C))
    m.setConstantOrState0('Parameters', 'Clung', scaling_param_weight(weight, 0.215, b_C))
    m.setConstantOrState0('Parameters', 'Cinte', scaling_param_weight(weight, 0.134374, b_C))
    m.setConstantOrState0('Parameters', 'Ckid', scaling_param_weight(weight, 0.01075, b_C))
    m.setConstantOrState0('Parameters', 'Che', scaling_param_weight(weight, 1.6125, b_C))
    m.setConstantOrState0('Parameters', 'Cplac', scaling_param_weight(weight, 0.806244, b_C))
    m.setConstantOrState0('Parameters', 'Cleg', scaling_param_weight(weight, 2.15, b_C))
    m.setConstantOrState0('Parameters', 'Cuv', scaling_param_weight(weight, 0.16125, b_C))
    m.setConstantOrState0('Parameters', 'Csvc', scaling_param_weight(weight, 0.5375, b_C))
    m.setConstantOrState0('Parameters', 'Civc', scaling_param_weight(weight, 0.3225, b_C))
    m.setConstantOrState0('Parameters', 'Risthm', scaling_param_weight(weight, 0.011, b_R))
    m.setConstantOrState0('Parameters', 'Raa', scaling_param_weight(weight, 0.0103, b_R))
    m.setConstantOrState0('Parameters', 'RaAoA', scaling_param_weight(weight, 0.0083, b_R))
    m.setConstantOrState0('Parameters', 'RdAoA', scaling_param_weight(weight, 0.0117, b_R))
    m.setConstantOrState0('Parameters', 'Rbct', scaling_param_weight(weight, 0.035555, b_R))
    m.setConstantOrState0('Parameters', 'R_L_CCA', scaling_param_weight(weight, 0.521, b_R))
    m.setConstantOrState0('Parameters', 'R_L_ICA', scaling_param_weight(weight, 0.889, b_R))
    m.setConstantOrState0('Parameters', 'R_L_SC', scaling_param_weight(weight, 0.227, b_R))
    m.setConstantOrState0('Parameters', 'R_L_ub', scaling_param_weight(weight, 35, b_R))
    m.setConstantOrState0('Parameters', 'R_L_br', scaling_param_weight(weight, 35, b_R))
    m.setConstantOrState0('Parameters', 'R_L_ub_p', scaling_param_weight(weight, 7.5, b_R))
    m.setConstantOrState0('Parameters', 'R_L_br_p', scaling_param_weight(weight, 7.5, b_R))
    m.setConstantOrState0('Parameters', 'R_R_CCA', scaling_param_weight(weight, 0.36411, b_R))
    m.setConstantOrState0('Parameters', 'R_R_ICA', scaling_param_weight(weight, 0.889, b_R))
    m.setConstantOrState0('Parameters', 'R_R_SC', scaling_param_weight(weight, 0.227, b_R))
    m.setConstantOrState0('Parameters', 'R_R_ub', scaling_param_weight(weight, 35, b_R))
    m.setConstantOrState0('Parameters', 'R_R_br', scaling_param_weight(weight, 35, b_R))
    m.setConstantOrState0('Parameters', 'R_R_ub_p', scaling_param_weight(weight, 7.5, b_R))
    m.setConstantOrState0('Parameters', 'R_R_br_p', scaling_param_weight(weight, 7.5, b_R))
    m.setConstantOrState0('Parameters', 'Listhm', scaling_param_weight(weight, 0.000011665, b_L))
    m.setConstantOrState0('Parameters', 'Laa', scaling_param_weight(weight, 5.83e-05, b_L))
    m.setConstantOrState0('Parameters', 'LaAoA', scaling_param_weight(weight, 0.0000234, b_L))
    m.setConstantOrState0('Parameters', 'LdAoA', scaling_param_weight(weight, 0.0000313554, b_L))
    m.setConstantOrState0('Parameters', 'Lbct', scaling_param_weight(weight, 0.00004595, b_L))
    m.setConstantOrState0('Parameters', 'L_L_CCA', scaling_param_weight(weight, 0.0004, b_L))
    m.setConstantOrState0('Parameters', 'L_L_ICA', scaling_param_weight(weight, 0.000525, b_L))
    m.setConstantOrState0('Parameters', 'L_L_SC', scaling_param_weight(weight, 0.00014, b_L))
    m.setConstantOrState0('Parameters', 'L_R_CCA', scaling_param_weight(weight, 0.000336, b_L))
    m.setConstantOrState0('Parameters', 'L_R_ICA', scaling_param_weight(weight, 0.000525, b_L))
    m.setConstantOrState0('Parameters', 'L_R_SC', scaling_param_weight(weight, 0.00014, b_L))
    m.setConstantOrState0('Parameters', 'Cisthm', scaling_param_weight(weight, 0.000956, b_C))
    m.setConstantOrState0('Parameters', 'Caa', scaling_param_weight(weight, 0.045, b_C))
    m.setConstantOrState0('Parameters', 'CaAoA', scaling_param_weight(weight, 0.00133, b_C))
    m.setConstantOrState0('Parameters', 'CdAoA', scaling_param_weight(weight, 0.00112, b_C))
    m.setConstantOrState0('Parameters', 'Cbct', scaling_param_weight(weight, 0.001212, b_C))
    m.setConstantOrState0('Parameters', 'C_L_CCA', scaling_param_weight(weight, 0.00238, b_C))
    m.setConstantOrState0('Parameters', 'C_L_ICA', scaling_param_weight(weight, 0.000645, b_C))
    m.setConstantOrState0('Parameters', 'C_L_SC', scaling_param_weight(weight, 0.0005366, b_C))
    m.setConstantOrState0('Parameters', 'C_L_ub', scaling_param_weight(weight, 0.045687, b_C))
    m.setConstantOrState0('Parameters', 'C_L_br', scaling_param_weight(weight, 0.01, b_C))
    m.setConstantOrState0('Parameters', 'C_R_CCA', scaling_param_weight(weight, 0.001666, b_C))
    m.setConstantOrState0('Parameters', 'C_R_ICA', scaling_param_weight(weight, 0.000645, b_C))
    m.setConstantOrState0('Parameters', 'C_R_SC', scaling_param_weight(weight, 0.0005366, b_C))
    m.setConstantOrState0('Parameters', 'C_R_ub', scaling_param_weight(weight, 0.1462, b_C))
    m.setConstantOrState0('Parameters', 'C_R_br', scaling_param_weight(weight, 0.01, b_C))

    GA = (0.1458 - np.sqrt(0.02286412 - 0.0064*np.log10(weight)))/0.0032
    risthm = 0.05*(-1.39 + 0.189*GA)
    rda = 0.05*(-0.1655 + 0.121125*GA)/(0.0028*GA + 0.798)
    rmpa = 0.05*(-2.77 + 0.3*GA)
    rlsca = 0.05*(-1.2169 + 0.1233*GA)
    rdaoa = np.cbrt(risthm**3 + rlsca**3)

    m.setConstantOrState0('Parameters', 'Bisthm', 1.05*1.706e-4/(2*0.2275*(np.pi*risthm**2)**2))
    m.setConstantOrState0('Parameters', 'Bda', 1.05*1.706e-4/(2*0.2275*(np.pi*rda**2)**2))
    m.setConstantOrState0('Parameters', 'Bmpa', 1.05*1.706e-4/(2*0.2275*(np.pi*rmpa**2)**2))
    m.setConstantOrState0('Parameters', 'BdAoA', 1.05*1.706e-4/(2*0.2275*(np.pi*rdaoa**2)**2))


def plot_model(legend_Q, legend_model, y, t, radius, color_plot, label_plot, typeline):
    #legend_states, legend_algebraic, legend_voi, legend_constants = modelCython.createLegends()
    dictionary_legend = {v:k for k,v in enumerate(legend_model)}
    extracted_y = [y[dictionary_legend[key],:] for key in dictionary_legend.keys() & legend_Q]
    if radius>0:
        extracted_y = np.array(extracted_y)/(np.pi*radius**2)   
    #print(legend_Q)
    #print('Mean = ' + str(round(np.mean(extracted_y),2)))
    #print(str(round(np.min(extracted_y),2)) + ' to ' + str(round(np.max(extracted_y),2)))
    plt.plot(t,np.array(extracted_y).flatten(),color=color_plot,label=label_plot,linestyle=typeline)

def plot_1(m, n_cycles, Tc, tFinal, color, xlabel, ylabel, component, name, linestyle):
    idx_t = m.t > tFinal - n_cycles*Tc
    t = m.t[idx_t]
    t = t - t[0]
    plt.plot(t, m.getVariable(component, name)[idx_t], linestyle=linestyle, color=color)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.grid(color = [0.7,0.7,0.7,1])
    plt.xlim([t[0],t[-1]])
    
def plot_2(m, fig, index, n_cycles, Tc, tFinal, color, xlabel, ylabel, component_1, name_1, label_1, linestyle_1, component_2, name_2, label_2, linestyle_2):
    idx_t = m.t > tFinal - n_cycles*Tc
    t = m.t[idx_t]
    t = t - t[0]
    plt.plot(t, m.getVariable(component_1, name_1)[idx_t], label=label_1, linestyle=linestyle_1, color=color)
    plt.plot(t, m.getVariable(component_2, name_2)[idx_t], label=label_2, linestyle=linestyle_2, color=color)    
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.xlim([t[0],t[-1]])
    if index == 0:
        legend = fig.legend(loc = 'upper right')
        fig.add_artist(legend)
    plt.grid(color = [0.7,0.7,0.7,1])

def plot_diff(m, n_cycles, Tc, tFinal, color, xlabel, ylabel, component_1, name_1, component_2, name_2, linestyle):
    idx_t = m.t > tFinal - n_cycles*Tc
    t = m.t[idx_t]
    t = t - t[0]
    plt.plot(t, m.getVariable(component_1, name_1)[idx_t] - m.getVariable(component_2, name_2)[idx_t], linestyle=linestyle, color=color)   
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.xlim([t[0],t[-1]])
    plt.grid(color = [0.7,0.7,0.7,1])

def compute_timings(Tc,tFinal,m):
    n_cycles = 1
    idx_t = m.t > tFinal - n_cycles*Tc
    t = m.t[idx_t]
    
    Q_ao_valve = m.getVariable('LV', 'Qo')[idx_t]
    Q_mi_valve = m.getVariable('LA', 'Qo')[idx_t]   

    Ao = np.where(Q_ao_valve>0)[0]
    Mi = np.where(Q_mi_valve>0)[0] 

    t_Ao = (t[Ao[-1]] - t[Ao[0]])/Tc*100
    t_Mi = (t[Mi[-1]] - t[Mi[0]])/Tc*100
    t_ir = (t[Mi[0]] - t[Ao[-1]])/Tc*100
    t_ic = 100-t_Ao-t_Mi-t_ir

    print('Aortic valve: ' + str(np.round(t_Ao,2)) + '% Tc')
    print('Mitral valve: ' + str(np.round(t_Mi,2)) + '% Tc') 
    print('Isovolumetric relaxation: ' + str(np.round(t_ir,2)) + '% Tc') 
    print('Isovolumetric contraction: ' + str(np.round(t_ic,2)) + '% Tc')  

def wrapper_algebraic(voi, states, clib, c_double_p, constants = constants, rates = rates):
    algebraic = np.zeros((sizeAlgebraic, len(voi)))
    for i,t in enumerate(voi):
        av = np.zeros((sizeAlgebraic))
        st = states[:,i]
        clib.computeVariables(ctypes.c_double(t), 
                              constants.ctypes.data_as(c_double_p), 
                              rates.ctypes.data_as(c_double_p),
                              st.ctypes.data_as(c_double_p), 
                              av.ctypes.data_as(c_double_p))
        algebraic[:,i] = av
    return algebraic

def rmse(predictions, targets):
    differences = (predictions - targets)/np.mean(targets)       
    differences_squared = differences ** 2   
    mean_of_differences_squared = differences_squared.mean() 
    rmse_val = np.sqrt(mean_of_differences_squared)
    return rmse_val 

def rmse2(predictions, targets, weights):    
    error_array = np.zeros(len(targets))    
    for index in range(len(targets)):
        error_array[index] = rmse(predictions[index], targets[index])    
    #print('minV_LV, maxV_LV, minP_LV, maxP_LV, maxv_LV, Ev_LA, Av_LA, tEA_LA, minP_LA, maxP_LA, Ev_RA, Av_RA: ')
    #print(str(np.round(error_array,2)))
    rmse_val = np.sum(error_array * weights)    
    return rmse_val 

def fun_dict_results(t,y,myConstants,clib,c_double_p,dictionary_legend_states,dictionary_legend_algebraic): 
    algebraic = wrapper_algebraic(voi = t, states = np.array(y), clib = clib, c_double_p = c_double_p, constants = myConstants)

    time = t
    Lsc_LV = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Lsc in component LV (Unitl)"]][0]
    C_LV = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["C in component LV (dimensionless)"]][0]
    V_LV = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Vcav in component LV (UnitV)"]][0]
    Pi_LV = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Pi in component LV (UnitP)"]][0]
    Qo_ao_valve = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component LV (UnitQ)"]][0]
    Pi_AA = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component AA_RCL (UnitP)"]][0]
    Qo_AA = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo in component AA_RCL (UnitQ)"]][0]
    V_LA = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["V in component LA (UnitV)"]][0]
    Pi_LA = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Pi in component LA (UnitP)"]][0]
    Qo_mi_valve = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo in component LA (UnitQ)"]][0]
    Pi_PA = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component PA_RCL (UnitP)"]][0]
    Qo_PA = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo in component PA_RCL (UnitQ)"]][0]
    Lsc_RV = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Lsc in component RV (Unitl)"]][0]
    C_RV = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["C in component RV (dimensionless)"]][0]
    V_RV = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Vcav in component RV (UnitV)"]][0]
    Pi_RV = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Pi in component RV (UnitP)"]][0]
    Qo_pu_valve = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component RV (UnitQ)"]][0]
    V_RA = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["V in component RA (UnitV)"]][0]
    Pi_RA = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Pi in component RA (UnitP)"]][0]
    Qo_tr_valve = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo in component RA (UnitQ)"]][0]
    Pi_CA = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component CA_RC (UnitP)"]][0]
    Qo_CA = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component CA_RC (UnitQ)"]][0]
    Pi_BR = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component BR_RC (UnitP)"]][0]
    Qo_BR = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component BR_RC (UnitQ)"]][0]
    Pi_UB = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component UB_RC (UnitP)"]][0]
    Qo_UB = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component UB_RC (UnitQ)"]][0]
    Pi_LUNG = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component LUNG_RCL (UnitP)"]][0]
    Qo_LUNG = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo in component LUNG_RCL (UnitQ)"]][0]
    Pi_AO1 = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component AO1_RC (UnitP)"]][0]
    Qo_AO1 = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component AO1_RC (UnitQ)"]][0]
    Pi_SVC = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component SVC_RCL (UnitP)"]][0]
    Qo_SVC = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo in component SVC_RCL (UnitQ)"]][0]
    Pi_AO2 = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component AO2_RCL (UnitP)"]][0]
    Qo_AO2 = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo in component AO2_RCL (UnitQ)"]][0]
    Pi_KID = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component KID_RC (UnitP)"]][0]
    Qo_KID = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component KID_RC (UnitQ)"]][0]
    Pi_INTE = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component INTE_RC (UnitP)"]][0]
    Qo_INTE = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component CA_RC (UnitQ)"]][0]
    Pi_LEG = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component INTE_RC (UnitP)"]][0]
    Qo_LEG = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component LEG_RC (UnitQ)"]][0]
    Pi_PLAC = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component PLAC_RC (UnitP)"]][0]
    Qo_PLAC = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component PLAC_RC (UnitQ)"]][0]
    Pi_UV = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component UV_RCL (UnitP)"]][0]
    Qo_UV = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo in component UV_RCL (UnitQ)"]][0]
    Pi_UA = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Pi in component Bif_AOin_LEG1out_UA2out (UnitP)"]][0]
    Qo_UA = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo2 in component Bif_AOin_LEG1out_UA2out (UnitQ)"]][0]
    Pi_HE = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component HE_RC (UnitP)"]][0]
    Qo_HE = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo in component HE_RC (UnitQ)"]][0]
    Pi_IVC = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Pi in component IVC_RCL (UnitP)"]][0]
    Qo_IVC = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo2 in component Bif_IVCin_FO1out_RA2out (UnitQ)"]][0]
    Pi_DA = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Pi in component Bif_PAin_LUNG1out_DA2out (UnitP)"]][0]
    Qo_DA = [y[dictionary_legend_states[key]] for key in dictionary_legend_states.keys() & ["Qo2 in component Bif_PAin_LUNG1out_DA2out (UnitQ)"]][0]
    Pi_AI = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Pi in component Bif_AOin_AO1out_CA2out_UB3out (UnitP)"]][0]
    Qo_AI = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo1 in component Bif_AOin_AO1out_CA2out_UB3out (UnitQ)"]][0]
    Pi_DV = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Pi in component Bif_UVin_DV1out_HE2out (UnitP)"]][0]
    Qo_DV = [algebraic[dictionary_legend_algebraic[key]] for key in dictionary_legend_algebraic.keys() & ["Qo1 in component Bif_UVin_DV1out_HE2out (UnitQ)"]][0]

    dict_results = dict(time=time,Lsc_LV=Lsc_LV,C_LV=C_LV,V_LV=V_LV,Pi_LV=Pi_LV,Qo_ao_valve=Qo_ao_valve,Pi_AA=Pi_AA,Qo_AA=Qo_AA,V_LA=V_LA,Pi_LA=Pi_LA,Qo_mi_valve=Qo_mi_valve,
                        Pi_PA=Pi_PA,Qo_PA=Qo_PA,Lsc_RV=Lsc_RV,C_RLV=C_RV,V_RV=V_RV,Pi_RV=Pi_RV,Qo_pu_valve=Qo_pu_valve,V_RA=V_RA,Pi_RA=Pi_RA,Qo_tr_valve=Qo_tr_valve,Pi_CA=Pi_CA,
                        Qo_CA=Qo_CA,Pi_BR=Pi_BR,Qo_BR=Qo_BR,Pi_UB=Pi_UB,Qo_UB=Qo_UB,Pi_LUNG=Pi_LUNG,Qo_LUNG=Qo_LUNG,Pi_AO1=Pi_AO1,Qo_AO1=Qo_AO1,Pi_SVC=Pi_SVC,Qo_SVC=Qo_SVC,
                        Pi_AO2=Pi_AO2,Qo_AO2=Qo_AO2,Pi_KID=Pi_KID,Qo_KID=Qo_KID,Pi_INTE=Pi_INTE,Qo_INTE=Qo_INTE,Pi_LEG=Pi_LEG,Qo_LEG=Qo_LEG,Pi_PLAC=Pi_PLAC,Qo_PLAC=Qo_PLAC,
                        Pi_UV=Pi_UV,Qo_UV=Qo_UV,Pi_UA=Pi_UA,Qo_UA=Qo_UA,Pi_HE=Pi_HE,Qo_HE=Qo_HE,Pi_IVC=Pi_IVC,Qo_IVC=Qo_IVC,Pi_DA=Pi_DA,Qo_DA=Qo_DA,Pi_AI=Pi_AI,Qo_AI=Qo_AI,
                        Pi_DV=Pi_DV,Qo_DV=Qo_DV)
    return dict_results


def createLegends(sizeAlgebraic, sizeStates, sizeConstants):
    legend_states = [""] * sizeStates
    legend_rates = [""] * sizeStates
    legend_algebraic = [""] * sizeAlgebraic
    legend_voi = ""
    legend_constants = [""] * sizeConstants
    legend_voi = "t in component environment (second)"
    legend_algebraic[27] = "L in component LV (dimensionless)"
    legend_algebraic[65] = "Ls in component LV (Unitl)"
    legend_constants[0] = "Lsref in component Parameters (Unitl)"
    legend_states[0] = "Lsc in component LV (Unitl)"
    legend_constants[1] = "Lscini in component Parameters (Unitl)"
    legend_algebraic[78] = "Lsnorm in component LV (dimensionless)"
    legend_algebraic[34] = "ta in component LV (second)"
    legend_constants[2] = "p_tact_v in component Parameters (second)"
    legend_constants[153] = "td in component LV (second)"
    legend_constants[152] = "trise in component LV (second)"
    legend_constants[151] = "p_tact in component LV (second)"
    legend_constants[3] = "p_trise_v in component Parameters (dimensionless)"
    legend_constants[4] = "p_td_v in component Parameters (dimensionless)"
    legend_states[1] = "C in component LV (dimensionless)"
    legend_constants[5] = "C0 in component Parameters (dimensionless)"
    legend_states[2] = "Vcav in component LV (UnitV)"
    legend_constants[6] = "Vlv0 in component Parameters (UnitV)"
    legend_constants[7] = "Vwall_lv in component Parameters (UnitV)"
    legend_algebraic[74] = "sfpas in component LV (UnitP)"
    legend_algebraic[35] = "sfact in component LV (UnitP)"
    legend_algebraic[41] = "sfrest in component LV (UnitP)"
    legend_algebraic[79] = "sf in component LV (UnitP)"
    legend_constants[8] = "spas_v in component Parameters (UnitP)"
    legend_constants[9] = "sact_v in component Parameters (UnitP)"
    legend_constants[10] = "vmax_v in component Parameters (Unitv)"
    legend_constants[11] = "delay_lv in component Parameters (second)"
    legend_algebraic[0] = "Time in component LV (second)"
    legend_algebraic[45] = "Time2 in component LV (second)"
    legend_algebraic[17] = "xrise in component LV (dimensionless)"
    legend_algebraic[40] = "fRise in component LV (dimensionless)"
    legend_algebraic[49] = "fDecay in component LV (dimensionless)"
    legend_constants[12] = "Crest in component Parameters (dimensionless)"
    legend_algebraic[68] = "xPos in component LV (dimensionless)"
    legend_algebraic[70] = "xSarc in component LV (dimensionless)"
    legend_algebraic[72] = "y in component LV (dimensionless)"
    legend_algebraic[76] = "NoBuckle in component LV (dimensionless)"
    legend_algebraic[46] = "Vm in component LV (UnitV)"
    legend_algebraic[50] = "Cm in component LV (Unitc)"
    legend_algebraic[56] = "Am in component LV (UnitA)"
    legend_algebraic[53] = "Amtotal in component LV (UnitA)"
    legend_constants[13] = "Amdead_lv in component Parameters (UnitA)"
    legend_constants[14] = "Amref_lv in component Parameters (UnitA)"
    legend_algebraic[59] = "z in component LV (dimensionless)"
    legend_algebraic[62] = "Ef in component LV (dimensionless)"
    legend_constants[15] = "kS_v in component Parameters (dimensionless)"
    legend_algebraic[80] = "Tension in component LV (UnitT)"
    legend_algebraic[81] = "Pi in component LV (UnitP)"
    legend_states[3] = "Pi in component AA_RCL (UnitP)"
    legend_states[4] = "Qo in component LA (UnitQ)"
    legend_states[5] = "Qo in component LV (UnitQ)"
    legend_constants[16] = "Q0foo in component Parameters (UnitQ)"
    legend_constants[17] = "T in component Parameters (second)"
    legend_constants[18] = "Kaovo in component Parameters (UnitKxi)"
    legend_constants[19] = "Kaovc_p in component Parameters (UnitKxi)"
    legend_constants[20] = "Kaovc_n in component Parameters (UnitKxi)"
    legend_algebraic[85] = "Linductance in component LV (UnitL)"
    legend_constants[21] = "L_min_ao in component Parameters (UnitL)"
    legend_constants[22] = "L_param in component Parameters (UnitLparam)"
    legend_states[6] = "xi in component LV (dimensionless)"
    legend_algebraic[82] = "Aeff in component LV (UnitA)"
    legend_constants[23] = "Aao in component Parameters (UnitA)"
    legend_algebraic[87] = "B in component LV (UnitB)"
    legend_algebraic[83] = "val_xi in component LV (ode_s)"
    legend_constants[24] = "B_param in component Parameters (UnitBparam)"
    legend_algebraic[88] = "L in component LA (dimensionless)"
    legend_algebraic[101] = "Ls in component LA (Unitl)"
    legend_states[7] = "Lsc in component LA (Unitl)"
    legend_algebraic[107] = "Lsnorm in component LA (dimensionless)"
    legend_algebraic[89] = "ta in component LA (second)"
    legend_constants[25] = "p_tact_a in component Parameters (second)"
    legend_constants[156] = "td in component LA (second)"
    legend_constants[155] = "trise in component LA (second)"
    legend_constants[154] = "p_tact in component LA (second)"
    legend_constants[26] = "p_trise_a in component Parameters (dimensionless)"
    legend_constants[27] = "p_td_a in component Parameters (dimensionless)"
    legend_states[8] = "C in component LA (dimensionless)"
    legend_states[9] = "Vcav in component LA (UnitV)"
    legend_constants[28] = "Vla0 in component Parameters (UnitV)"
    legend_constants[29] = "Vwall_la in component Parameters (UnitV)"
    legend_algebraic[105] = "sfpas in component LA (UnitP)"
    legend_algebraic[90] = "sfact in component LA (UnitP)"
    legend_algebraic[92] = "sfrest in component LA (UnitP)"
    legend_algebraic[108] = "sf in component LA (UnitP)"
    legend_constants[30] = "spas_a in component Parameters (UnitP)"
    legend_constants[31] = "sact_a in component Parameters (UnitP)"
    legend_constants[32] = "vmax_a in component Parameters (Unitv)"
    legend_constants[33] = "delay_la in component Parameters (second)"
    legend_algebraic[84] = "Time in component LA (second)"
    legend_algebraic[93] = "Time2 in component LA (second)"
    legend_algebraic[86] = "xrise in component LA (dimensionless)"
    legend_algebraic[91] = "fRise in component LA (dimensionless)"
    legend_algebraic[95] = "fDecay in component LA (dimensionless)"
    legend_algebraic[102] = "xPos in component LA (dimensionless)"
    legend_algebraic[103] = "xSarc in component LA (dimensionless)"
    legend_algebraic[104] = "y in component LA (dimensionless)"
    legend_algebraic[106] = "NoBuckle in component LA (dimensionless)"
    legend_algebraic[94] = "Vm in component LA (UnitV)"
    legend_algebraic[96] = "Cm in component LA (Unitc)"
    legend_algebraic[98] = "Am in component LA (UnitA)"
    legend_algebraic[97] = "Amtotal in component LA (UnitA)"
    legend_constants[34] = "Amdead_la in component Parameters (UnitA)"
    legend_constants[35] = "Amref_la in component Parameters (UnitA)"
    legend_algebraic[99] = "z in component LA (dimensionless)"
    legend_algebraic[100] = "Ef in component LA (dimensionless)"
    legend_constants[36] = "kS_a in component Parameters (dimensionless)"
    legend_algebraic[109] = "Tension in component LA (UnitT)"
    legend_algebraic[110] = "Pi in component LA (UnitP)"
    legend_algebraic[173] = "Qo in component Bif_LUNG1in_FO2in_LAout (UnitQ)"
    legend_constants[37] = "Kmivo in component Parameters (UnitKxi)"
    legend_constants[38] = "Kmivc_p in component Parameters (UnitKxi)"
    legend_constants[39] = "Kmivc_n in component Parameters (UnitKxi)"
    legend_algebraic[114] = "Linductance in component LA (UnitL)"
    legend_constants[40] = "L_min_mi in component Parameters (UnitL)"
    legend_states[10] = "xi in component LA (dimensionless)"
    legend_algebraic[111] = "Aeff in component LA (UnitA)"
    legend_constants[41] = "Ami in component Parameters (UnitA)"
    legend_algebraic[116] = "B in component LA (UnitB)"
    legend_algebraic[177] = "val_xi in component LA (ode_s)"
    legend_algebraic[117] = "L in component RV (dimensionless)"
    legend_algebraic[130] = "Ls in component RV (Unitl)"
    legend_states[11] = "Lsc in component RV (Unitl)"
    legend_algebraic[136] = "Lsnorm in component RV (dimensionless)"
    legend_algebraic[118] = "ta in component RV (second)"
    legend_constants[157] = "tact in component RV (second)"
    legend_constants[160] = "td in component RV (second)"
    legend_constants[159] = "trise in component RV (second)"
    legend_states[12] = "C in component RV (dimensionless)"
    legend_states[13] = "Vcav in component RV (UnitV)"
    legend_constants[42] = "Vrv0 in component Parameters (UnitV)"
    legend_constants[43] = "Vwall_rv in component Parameters (UnitV)"
    legend_algebraic[134] = "sfpas in component RV (UnitP)"
    legend_algebraic[119] = "sfact in component RV (UnitP)"
    legend_algebraic[121] = "sfrest in component RV (UnitP)"
    legend_algebraic[137] = "sf in component RV (UnitP)"
    legend_constants[44] = "delay_rv in component Parameters (second)"
    legend_algebraic[112] = "Time in component RV (second)"
    legend_algebraic[122] = "Time2 in component RV (second)"
    legend_algebraic[115] = "xrise in component RV (dimensionless)"
    legend_algebraic[120] = "fRise in component RV (dimensionless)"
    legend_algebraic[124] = "fDecay in component RV (dimensionless)"
    legend_algebraic[131] = "xPos in component RV (dimensionless)"
    legend_algebraic[132] = "xSarc in component RV (dimensionless)"
    legend_algebraic[133] = "y in component RV (dimensionless)"
    legend_algebraic[135] = "NoBuckle in component RV (dimensionless)"
    legend_algebraic[123] = "Vm in component RV (UnitV)"
    legend_algebraic[125] = "Cm in component RV (Unitc)"
    legend_algebraic[127] = "Am in component RV (UnitA)"
    legend_algebraic[126] = "Amtotal in component RV (UnitA)"
    legend_constants[45] = "Amdead_rv in component Parameters (UnitA)"
    legend_constants[46] = "Amref_rv in component Parameters (UnitA)"
    legend_algebraic[128] = "z in component RV (dimensionless)"
    legend_algebraic[129] = "Ef in component RV (dimensionless)"
    legend_algebraic[138] = "Tension in component RV (UnitT)"
    legend_algebraic[139] = "Pi in component RV (UnitP)"
    legend_states[14] = "Pi in component PA_RCL (UnitP)"
    legend_states[15] = "Qo in component RA (UnitQ)"
    legend_states[16] = "Qo in component RV (UnitQ)"
    legend_constants[47] = "Kpvvo in component Parameters (UnitKxi)"
    legend_constants[48] = "Kpvvc_p in component Parameters (UnitKxi)"
    legend_constants[49] = "Kpvvc_n in component Parameters (UnitKxi)"
    legend_algebraic[143] = "Linductance in component RV (UnitL)"
    legend_constants[50] = "L_min_pv in component Parameters (UnitL)"
    legend_states[17] = "xi in component RV (dimensionless)"
    legend_algebraic[140] = "Aeff in component RV (UnitA)"
    legend_constants[51] = "Apv in component Parameters (UnitA)"
    legend_algebraic[145] = "B in component RV (UnitB)"
    legend_algebraic[141] = "val_xi in component RV (ode_s)"
    legend_algebraic[146] = "L in component RA (dimensionless)"
    legend_algebraic[159] = "Ls in component RA (Unitl)"
    legend_states[18] = "Lsc in component RA (Unitl)"
    legend_algebraic[165] = "Lsnorm in component RA (dimensionless)"
    legend_algebraic[147] = "ta in component RA (second)"
    legend_constants[158] = "tact in component RA (second)"
    legend_constants[162] = "td in component RA (second)"
    legend_constants[161] = "trise in component RA (second)"
    legend_states[19] = "C in component RA (dimensionless)"
    legend_states[20] = "Vcav in component RA (UnitV)"
    legend_constants[52] = "Vra0 in component Parameters (UnitV)"
    legend_constants[53] = "Vwall_ra in component Parameters (UnitV)"
    legend_algebraic[163] = "sfpas in component RA (UnitP)"
    legend_algebraic[148] = "sfact in component RA (UnitP)"
    legend_algebraic[150] = "sfrest in component RA (UnitP)"
    legend_algebraic[166] = "sf in component RA (UnitP)"
    legend_constants[54] = "delay_ra in component Parameters (second)"
    legend_algebraic[142] = "Time in component RA (second)"
    legend_algebraic[151] = "Time2 in component RA (second)"
    legend_algebraic[144] = "xrise in component RA (dimensionless)"
    legend_algebraic[149] = "fRise in component RA (dimensionless)"
    legend_algebraic[153] = "fDecay in component RA (dimensionless)"
    legend_algebraic[160] = "xPos in component RA (dimensionless)"
    legend_algebraic[161] = "xSarc in component RA (dimensionless)"
    legend_algebraic[162] = "y in component RA (dimensionless)"
    legend_algebraic[164] = "NoBuckle in component RA (dimensionless)"
    legend_algebraic[152] = "Vm in component RA (UnitV)"
    legend_algebraic[154] = "Cm in component RA (Unitc)"
    legend_algebraic[156] = "Am in component RA (UnitA)"
    legend_algebraic[155] = "Amtotal in component RA (UnitA)"
    legend_constants[55] = "Amdead_ra in component Parameters (UnitA)"
    legend_constants[56] = "Amref_ra in component Parameters (UnitA)"
    legend_algebraic[157] = "z in component RA (dimensionless)"
    legend_algebraic[158] = "Ef in component RA (dimensionless)"
    legend_algebraic[167] = "Tension in component RA (UnitT)"
    legend_algebraic[168] = "Pi in component RA (UnitP)"
    legend_algebraic[170] = "Qo in component Bif_SVC1in_IVC2in_RAout (UnitQ)"
    legend_constants[57] = "Ktrvo in component Parameters (UnitKxi)"
    legend_constants[58] = "Ktrvc_p in component Parameters (UnitKxi)"
    legend_constants[59] = "Ktrvc_n in component Parameters (UnitKxi)"
    legend_algebraic[174] = "Linductance in component RA (UnitL)"
    legend_constants[60] = "L_min_tr in component Parameters (UnitL)"
    legend_states[21] = "xi in component RA (dimensionless)"
    legend_algebraic[171] = "Aeff in component RA (UnitA)"
    legend_constants[61] = "Atr in component Parameters (UnitA)"
    legend_algebraic[178] = "B in component RA (UnitB)"
    legend_algebraic[175] = "val_xi in component RA (ode_s)"
    legend_algebraic[18] = "Pi in component Bif_AAin_AAA1out_BrachT2out (UnitP)"
    legend_states[22] = "Qo in component AA_RCL (UnitQ)"
    legend_constants[62] = "Raa in component Parameters (UnitR)"
    legend_constants[63] = "Caa in component Parameters (UnitC)"
    legend_constants[64] = "Laa in component Parameters (UnitL)"
    legend_constants[65] = "P0foo in component Parameters (UnitP)"
    legend_states[23] = "Pi in component AAA_RCL (UnitP)"
    legend_algebraic[19] = "Pi in component Bif_AAAin_DAA1out_CCaroAL2out (UnitP)"
    legend_states[24] = "Qo in component AAA_RCL (UnitQ)"
    legend_algebraic[1] = "Qo1 in component Bif_AAin_AAA1out_BrachT2out (UnitQ)"
    legend_constants[66] = "RaAoA in component Parameters (UnitR)"
    legend_constants[67] = "CaAoA in component Parameters (UnitC)"
    legend_constants[68] = "LaAoA in component Parameters (UnitL)"
    legend_states[25] = "Pi in component DAA_RCL (UnitP)"
    legend_algebraic[20] = "Pi in component Bif_DAAin_AI1out_SubAL2out (UnitP)"
    legend_states[26] = "Qo in component DAA_RCL (UnitQ)"
    legend_algebraic[2] = "Qo1 in component Bif_AAAin_DAA1out_CCaroAL2out (UnitQ)"
    legend_constants[69] = "RdAoA in component Parameters (UnitR)"
    legend_constants[70] = "CdAoA in component Parameters (UnitC)"
    legend_constants[71] = "LdAoA in component Parameters (UnitL)"
    legend_states[27] = "Pi in component AI_RCL (UnitP)"
    legend_algebraic[3] = "Pi2 in component Bif_DA1in_AI2in_AOout (UnitP)"
    legend_states[28] = "Qo in component AI_RCL (UnitQ)"
    legend_algebraic[4] = "Qo1 in component Bif_DAAin_AI1out_SubAL2out (UnitQ)"
    legend_constants[72] = "Risthm in component Parameters (UnitR)"
    legend_constants[73] = "Cisthm in component Parameters (UnitC)"
    legend_constants[74] = "Listhm in component Parameters (UnitL)"
    legend_constants[75] = "Bisthm in component Parameters (UnitK)"
    legend_constants[76] = "BdAoA in component Parameters (UnitK)"
    legend_algebraic[21] = "Pi in component Bif_PAin_LUNG1out_DA2out (UnitP)"
    legend_states[29] = "Qo in component PA_RCL (UnitQ)"
    legend_constants[77] = "Rpa in component Parameters (UnitR)"
    legend_constants[78] = "Cpa in component Parameters (UnitC)"
    legend_constants[79] = "Lpa in component Parameters (UnitL)"
    legend_states[30] = "Pi in component LUNG_RCL (UnitP)"
    legend_algebraic[113] = "Pi1 in component Bif_LUNG1in_FO2in_LAout (UnitP)"
    legend_states[31] = "Qo in component LUNG_RCL (UnitQ)"
    legend_algebraic[5] = "Qo1 in component Bif_PAin_LUNG1out_DA2out (UnitQ)"
    legend_constants[80] = "Rla in component Parameters (UnitR)"
    legend_constants[81] = "Clung in component Parameters (UnitC)"
    legend_constants[82] = "Lfoo in component Parameters (UnitL)"
    legend_states[32] = "Pi in component AO1_RC (UnitP)"
    legend_algebraic[22] = "Pi in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitP)"
    legend_algebraic[6] = "Qo in component Bif_DA1in_AI2in_AOout (UnitQ)"
    legend_algebraic[28] = "Qo in component AO1_RC (UnitQ)"
    legend_constants[83] = "Rdtao in component Parameters (UnitR)"
    legend_constants[84] = "Cao1 in component Parameters (UnitC)"
    legend_states[33] = "Pi in component SVC_RCL (UnitP)"
    legend_algebraic[172] = "Pi1 in component Bif_SVC1in_IVC2in_RAout (UnitP)"
    legend_states[34] = "Qo in component SVC_RCL (UnitQ)"
    legend_algebraic[77] = "Qo in component Bif_BR1in_UB2in_SVCout (UnitQ)"
    legend_constants[85] = "Rsvc in component Parameters (UnitR)"
    legend_constants[86] = "Csvc in component Parameters (UnitC)"
    legend_states[35] = "Pi in component AO2_RCL (UnitP)"
    legend_algebraic[23] = "Pi in component Bif_AOin_LEG1out_UA2out (UnitP)"
    legend_states[36] = "Qo in component AO2_RCL (UnitQ)"
    legend_algebraic[36] = "Qo1 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ)"
    legend_constants[87] = "Rdaao in component Parameters (UnitR)"
    legend_constants[88] = "Cao2 in component Parameters (UnitC)"
    legend_states[37] = "Pi in component KID_RC (UnitP)"
    legend_algebraic[47] = "Pi1 in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitP)"
    legend_states[38] = "Qo4 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ)"
    legend_algebraic[51] = "Qo in component KID_RC (UnitQ)"
    legend_constants[89] = "Rrev in component Parameters (UnitR)"
    legend_constants[90] = "Ckid in component Parameters (UnitC)"
    legend_states[39] = "Pi in component INTE_RC (UnitP)"
    legend_algebraic[29] = "Pi2 in component Bif_UV1in_INTE2in_AO3in_HEout (UnitP)"
    legend_states[40] = "Qo2 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ)"
    legend_algebraic[37] = "Qo in component INTE_RC (UnitQ)"
    legend_constants[91] = "Rporv in component Parameters (UnitR)"
    legend_constants[92] = "Cinte in component Parameters (UnitC)"
    legend_states[41] = "Pi in component LEG_RC (UnitP)"
    legend_algebraic[60] = "Pi4 in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitP)"
    legend_algebraic[7] = "Qo1 in component Bif_AOin_LEG1out_UA2out (UnitQ)"
    legend_algebraic[63] = "Qo in component LEG_RC (UnitQ)"
    legend_constants[93] = "Rfv in component Parameters (UnitR)"
    legend_constants[94] = "Cleg in component Parameters (UnitC)"
    legend_states[42] = "Pi in component PLAC_RC (UnitP)"
    legend_states[43] = "Pi in component UV_RCL (UnitP)"
    legend_states[44] = "Qo2 in component Bif_AOin_LEG1out_UA2out (UnitQ)"
    legend_algebraic[8] = "Qo in component PLAC_RC (UnitQ)"
    legend_constants[95] = "Rplac in component Parameters (UnitR)"
    legend_constants[96] = "Cplac in component Parameters (UnitC)"
    legend_algebraic[43] = "Pi in component Bif_UVin_DV1out_HE2out (UnitP)"
    legend_states[45] = "Qo in component UV_RCL (UnitQ)"
    legend_constants[97] = "Rfoo in component Parameters (UnitR)"
    legend_constants[98] = "Cuv in component Parameters (UnitC)"
    legend_states[46] = "Pi in component HE_RC (UnitP)"
    legend_algebraic[54] = "Pi3 in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitP)"
    legend_algebraic[42] = "Qo in component Bif_UV1in_INTE2in_AO3in_HEout (UnitQ)"
    legend_algebraic[57] = "Qo in component HE_RC (UnitQ)"
    legend_constants[99] = "Rhv in component Parameters (UnitR)"
    legend_constants[100] = "Che in component Parameters (UnitC)"
    legend_states[47] = "Pi in component IVC_RCL (UnitP)"
    legend_algebraic[179] = "Pi in component Bif_IVCin_FO1out_RA2out (UnitP)"
    legend_states[48] = "Qo in component IVC_RCL (UnitQ)"
    legend_algebraic[66] = "Qo in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitQ)"
    legend_constants[101] = "Civc in component Parameters (UnitC)"
    legend_states[49] = "Pi in component BrachT_RCL (UnitP)"
    legend_algebraic[25] = "Pi in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitP)"
    legend_states[50] = "Qo in component BrachT_RCL (UnitQ)"
    legend_states[51] = "Qo2 in component Bif_AAin_AAA1out_BrachT2out (UnitQ)"
    legend_constants[102] = "Rbct in component Parameters (UnitR)"
    legend_constants[103] = "Cbct in component Parameters (UnitC)"
    legend_constants[104] = "Lbct in component Parameters (UnitL)"
    legend_states[52] = "Pi in component SubAR_RCL (UnitP)"
    legend_algebraic[9] = "Pi in component UBR_R (UnitP)"
    legend_states[53] = "Qo in component SubAR_RCL (UnitQ)"
    legend_algebraic[10] = "Qo1 in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitQ)"
    legend_constants[105] = "R_R_SC in component Parameters (UnitR)"
    legend_constants[106] = "C_R_SC in component Parameters (UnitC)"
    legend_constants[107] = "L_R_SC in component Parameters (UnitL)"
    legend_states[54] = "Pi in component UBR_RC (UnitP)"
    legend_algebraic[11] = "Qo in component UBR_R (UnitQ)"
    legend_constants[108] = "R_R_ub_p in component Parameters (UnitR)"
    legend_algebraic[67] = "Pi1 in component Bif_UBR1in_UBL2in_UBout (UnitP)"
    legend_algebraic[69] = "Qo in component UBR_RC (UnitQ)"
    legend_constants[109] = "R_R_ub in component Parameters (UnitR)"
    legend_constants[110] = "C_R_ub in component Parameters (UnitC)"
    legend_states[55] = "Pi in component CCaroAR_RC (UnitP)"
    legend_states[56] = "Pi in component ICaroAR_RCL (UnitP)"
    legend_states[57] = "Qo2 in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitQ)"
    legend_algebraic[12] = "Qo in component CCaroAR_RC (UnitQ)"
    legend_constants[111] = "R_R_CCA in component Parameters (UnitR)"
    legend_constants[112] = "C_R_CCA in component Parameters (UnitC)"
    legend_algebraic[13] = "Pi in component BRR_R (UnitP)"
    legend_states[58] = "Qo in component ICaroAR_RCL (UnitQ)"
    legend_constants[113] = "R_R_ICA in component Parameters (UnitR)"
    legend_constants[114] = "C_R_ICA in component Parameters (UnitC)"
    legend_constants[115] = "L_R_ICA in component Parameters (UnitL)"
    legend_states[59] = "Pi in component BRR_RC (UnitP)"
    legend_algebraic[48] = "Pi1 in component Bif_BRR1in_BRL2in_BRout (UnitP)"
    legend_algebraic[26] = "Qo in component BRR_R (UnitQ)"
    legend_algebraic[52] = "Qo in component BRR_RC (UnitQ)"
    legend_constants[116] = "R_R_br in component Parameters (UnitR)"
    legend_constants[117] = "C_R_br in component Parameters (UnitC)"
    legend_constants[118] = "R_R_br_p in component Parameters (UnitR)"
    legend_states[60] = "Pi in component CCaroAL_RC (UnitP)"
    legend_states[61] = "Pi in component ICaroAL_RCL (UnitP)"
    legend_states[62] = "Qo2 in component Bif_AAAin_DAA1out_CCaroAL2out (UnitQ)"
    legend_algebraic[14] = "Qo in component CCaroAL_RC (UnitQ)"
    legend_constants[119] = "R_L_CCA in component Parameters (UnitR)"
    legend_constants[120] = "C_L_CCA in component Parameters (UnitC)"
    legend_algebraic[15] = "Pi in component BRL_R (UnitP)"
    legend_states[63] = "Qo in component ICaroAL_RCL (UnitQ)"
    legend_constants[121] = "R_L_ICA in component Parameters (UnitR)"
    legend_constants[122] = "C_L_ICA in component Parameters (UnitC)"
    legend_constants[123] = "L_L_ICA in component Parameters (UnitL)"
    legend_states[64] = "Pi in component BRL_RC (UnitP)"
    legend_algebraic[31] = "Qo in component BRL_R (UnitQ)"
    legend_constants[124] = "R_L_br_p in component Parameters (UnitR)"
    legend_algebraic[55] = "Pi2 in component Bif_BRR1in_BRL2in_BRout (UnitP)"
    legend_algebraic[58] = "Qo in component BRL_RC (UnitQ)"
    legend_constants[125] = "R_L_br in component Parameters (UnitR)"
    legend_constants[126] = "C_L_br in component Parameters (UnitC)"
    legend_states[65] = "Pi in component SubAL_RCL (UnitP)"
    legend_algebraic[16] = "Pi in component UBL_R (UnitP)"
    legend_states[66] = "Qo in component SubAL_RCL (UnitQ)"
    legend_states[67] = "Qo2 in component Bif_DAAin_AI1out_SubAL2out (UnitQ)"
    legend_constants[127] = "R_L_SC in component Parameters (UnitR)"
    legend_constants[128] = "C_L_SC in component Parameters (UnitC)"
    legend_constants[129] = "L_L_SC in component Parameters (UnitL)"
    legend_states[68] = "Pi in component UBL_RC (UnitP)"
    legend_algebraic[39] = "Qo in component UBL_R (UnitQ)"
    legend_constants[130] = "R_L_ub_p in component Parameters (UnitR)"
    legend_algebraic[71] = "Pi2 in component Bif_UBR1in_UBL2in_UBout (UnitP)"
    legend_algebraic[73] = "Qo in component UBL_RC (UnitQ)"
    legend_constants[131] = "R_L_ub in component Parameters (UnitR)"
    legend_constants[132] = "C_L_ub in component Parameters (UnitC)"
    legend_constants[133] = "L_R_CCA in component Parameters (UnitL)"
    legend_constants[134] = "L_L_CCA in component Parameters (UnitL)"
    legend_algebraic[44] = "Pi1 in component Bif_BR1in_UB2in_SVCout (UnitP)"
    legend_algebraic[61] = "Qo in component Bif_BRR1in_BRL2in_BRout (UnitQ)"
    legend_algebraic[64] = "Pi2 in component Bif_BR1in_UB2in_SVCout (UnitP)"
    legend_algebraic[75] = "Qo in component Bif_UBR1in_UBL2in_UBout (UnitQ)"
    legend_algebraic[32] = "Pi1 in component Bif_DA1in_AI2in_AOout (UnitP)"
    legend_states[69] = "Qo2 in component Bif_PAin_LUNG1out_DA2out (UnitQ)"
    legend_constants[135] = "Rda in component Parameters (UnitR)"
    legend_constants[136] = "Bda in component Parameters (UnitK)"
    legend_constants[137] = "Bmpa in component Parameters (UnitK)"
    legend_constants[138] = "Rlung in component Parameters (UnitR)"
    legend_constants[139] = "Lda in component Parameters (UnitL)"
    legend_algebraic[33] = "Pi3 in component Bif_UV1in_INTE2in_AO3in_HEout (UnitP)"
    legend_states[70] = "Qo3 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ)"
    legend_constants[140] = "Rmea in component Parameters (UnitR)"
    legend_constants[141] = "Relg in component Parameters (UnitR)"
    legend_constants[142] = "Rrea in component Parameters (UnitR)"
    legend_constants[143] = "Rfa in component Parameters (UnitR)"
    legend_constants[144] = "Rua in component Parameters (UnitR)"
    legend_algebraic[38] = "Pi2 in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitP)"
    legend_algebraic[30] = "Pi1 in component Bif_UV1in_INTE2in_AO3in_HEout (UnitP)"
    legend_algebraic[24] = "Qo1 in component Bif_UVin_DV1out_HE2out (UnitQ)"
    legend_states[71] = "Qo2 in component Bif_UVin_DV1out_HE2out (UnitQ)"
    legend_constants[145] = "Rha in component Parameters (UnitR)"
    legend_constants[146] = "Rdv in component Parameters (UnitR)"
    legend_constants[147] = "Kdv in component Parameters (UnitK)"
    legend_algebraic[176] = "Pi2 in component Bif_LUNG1in_FO2in_LAout (UnitP)"
    legend_algebraic[180] = "Pi2 in component Bif_SVC1in_IVC2in_RAout (UnitP)"
    legend_algebraic[169] = "Qo1 in component Bif_IVCin_FO1out_RA2out (UnitQ)"
    legend_states[72] = "Qo2 in component Bif_IVCin_FO1out_RA2out (UnitQ)"
    legend_constants[148] = "Rivc in component Parameters (UnitR)"
    legend_constants[149] = "Kfo in component Parameters (UnitKfo)"
    legend_constants[150] = "Cfoo in component Parameters (UnitC)"
    legend_rates[1] = "d/dt C in component LV (dimensionless)"
    legend_rates[0] = "d/dt Lsc in component LV (Unitl)"
    legend_rates[2] = "d/dt Vcav in component LV (UnitV)"
    legend_rates[5] = "d/dt Qo in component LV (UnitQ)"
    legend_rates[6] = "d/dt xi in component LV (dimensionless)"
    legend_rates[8] = "d/dt C in component LA (dimensionless)"
    legend_rates[7] = "d/dt Lsc in component LA (Unitl)"
    legend_rates[9] = "d/dt Vcav in component LA (UnitV)"
    legend_rates[4] = "d/dt Qo in component LA (UnitQ)"
    legend_rates[10] = "d/dt xi in component LA (dimensionless)"
    legend_rates[12] = "d/dt C in component RV (dimensionless)"
    legend_rates[11] = "d/dt Lsc in component RV (Unitl)"
    legend_rates[13] = "d/dt Vcav in component RV (UnitV)"
    legend_rates[16] = "d/dt Qo in component RV (UnitQ)"
    legend_rates[17] = "d/dt xi in component RV (dimensionless)"
    legend_rates[19] = "d/dt C in component RA (dimensionless)"
    legend_rates[18] = "d/dt Lsc in component RA (Unitl)"
    legend_rates[20] = "d/dt Vcav in component RA (UnitV)"
    legend_rates[15] = "d/dt Qo in component RA (UnitQ)"
    legend_rates[21] = "d/dt xi in component RA (dimensionless)"
    legend_rates[3] = "d/dt Pi in component AA_RCL (UnitP)"
    legend_rates[22] = "d/dt Qo in component AA_RCL (UnitQ)"
    legend_rates[23] = "d/dt Pi in component AAA_RCL (UnitP)"
    legend_rates[24] = "d/dt Qo in component AAA_RCL (UnitQ)"
    legend_rates[25] = "d/dt Pi in component DAA_RCL (UnitP)"
    legend_rates[26] = "d/dt Qo in component DAA_RCL (UnitQ)"
    legend_rates[27] = "d/dt Pi in component AI_RCL (UnitP)"
    legend_rates[28] = "d/dt Qo in component AI_RCL (UnitQ)"
    legend_rates[14] = "d/dt Pi in component PA_RCL (UnitP)"
    legend_rates[29] = "d/dt Qo in component PA_RCL (UnitQ)"
    legend_rates[30] = "d/dt Pi in component LUNG_RCL (UnitP)"
    legend_rates[31] = "d/dt Qo in component LUNG_RCL (UnitQ)"
    legend_rates[32] = "d/dt Pi in component AO1_RC (UnitP)"
    legend_rates[33] = "d/dt Pi in component SVC_RCL (UnitP)"
    legend_rates[34] = "d/dt Qo in component SVC_RCL (UnitQ)"
    legend_rates[35] = "d/dt Pi in component AO2_RCL (UnitP)"
    legend_rates[36] = "d/dt Qo in component AO2_RCL (UnitQ)"
    legend_rates[37] = "d/dt Pi in component KID_RC (UnitP)"
    legend_rates[39] = "d/dt Pi in component INTE_RC (UnitP)"
    legend_rates[41] = "d/dt Pi in component LEG_RC (UnitP)"
    legend_rates[42] = "d/dt Pi in component PLAC_RC (UnitP)"
    legend_rates[43] = "d/dt Pi in component UV_RCL (UnitP)"
    legend_rates[45] = "d/dt Qo in component UV_RCL (UnitQ)"
    legend_rates[46] = "d/dt Pi in component HE_RC (UnitP)"
    legend_rates[47] = "d/dt Pi in component IVC_RCL (UnitP)"
    legend_rates[48] = "d/dt Qo in component IVC_RCL (UnitQ)"
    legend_rates[49] = "d/dt Pi in component BrachT_RCL (UnitP)"
    legend_rates[50] = "d/dt Qo in component BrachT_RCL (UnitQ)"
    legend_rates[52] = "d/dt Pi in component SubAR_RCL (UnitP)"
    legend_rates[53] = "d/dt Qo in component SubAR_RCL (UnitQ)"
    legend_rates[54] = "d/dt Pi in component UBR_RC (UnitP)"
    legend_rates[55] = "d/dt Pi in component CCaroAR_RC (UnitP)"
    legend_rates[56] = "d/dt Pi in component ICaroAR_RCL (UnitP)"
    legend_rates[58] = "d/dt Qo in component ICaroAR_RCL (UnitQ)"
    legend_rates[59] = "d/dt Pi in component BRR_RC (UnitP)"
    legend_rates[60] = "d/dt Pi in component CCaroAL_RC (UnitP)"
    legend_rates[61] = "d/dt Pi in component ICaroAL_RCL (UnitP)"
    legend_rates[63] = "d/dt Qo in component ICaroAL_RCL (UnitQ)"
    legend_rates[64] = "d/dt Pi in component BRL_RC (UnitP)"
    legend_rates[65] = "d/dt Pi in component SubAL_RCL (UnitP)"
    legend_rates[66] = "d/dt Qo in component SubAL_RCL (UnitQ)"
    legend_rates[68] = "d/dt Pi in component UBL_RC (UnitP)"
    legend_rates[57] = "d/dt Qo2 in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitQ)"
    legend_rates[51] = "d/dt Qo2 in component Bif_AAin_AAA1out_BrachT2out (UnitQ)"
    legend_rates[62] = "d/dt Qo2 in component Bif_AAAin_DAA1out_CCaroAL2out (UnitQ)"
    legend_rates[67] = "d/dt Qo2 in component Bif_DAAin_AI1out_SubAL2out (UnitQ)"
    legend_rates[69] = "d/dt Qo2 in component Bif_PAin_LUNG1out_DA2out (UnitQ)"
    legend_rates[40] = "d/dt Qo2 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ)"
    legend_rates[70] = "d/dt Qo3 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ)"
    legend_rates[38] = "d/dt Qo4 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ)"
    legend_rates[44] = "d/dt Qo2 in component Bif_AOin_LEG1out_UA2out (UnitQ)"
    legend_rates[71] = "d/dt Qo2 in component Bif_UVin_DV1out_HE2out (UnitQ)"
    legend_rates[72] = "d/dt Qo2 in component Bif_IVCin_FO1out_RA2out (UnitQ)"
    return (legend_states, legend_algebraic, legend_voi, legend_constants)