import numpy as np
from scipy import optimize
import importlib
import functions_to_import_CoA as f_CoA
import solver.model
#import solver.cwrapping 
importlib.reload(solver.model)
importlib.reload(solver.model.cwrapping)

def ventricular_disproportion_vasculature(m,degree_aovalve,degree_pvvalve,default_values):
    # Pulmonary artery
    degree_pa = np.sqrt(degree_pvvalve)
    m.setConstantOrState0('Parameters', 'Rpa', default_values['Rpa']/(degree_pa**4)) 
    m.setConstantOrState0('Parameters', 'Bmpa', default_values['Bmpa']/(degree_pa**4)) 
    m.setConstantOrState0('Parameters', 'Cpa', default_values['Cpa']*(degree_pa**2))
    m.setConstantOrState0('Parameters', 'Lpa', default_values['Lpa']/(degree_pa**2)) 
    
    # Ascending aorta
    degree_aAo = np.sqrt(degree_aovalve)
    m.setConstantOrState0('Parameters', 'Raa', default_values['Raa']/(degree_aAo**4)) 
    m.setConstantOrState0('Parameters', 'Caa', default_values['Caa']*(degree_aAo**2))
    m.setConstantOrState0('Parameters', 'Laa', default_values['Laa']/(degree_aAo**2)) 

def ductus_increase(m,degree_da,default_values):
    m.setConstantOrState0('Parameters', 'Rda', default_values['Rda']/(degree_da**4)) 
    m.setConstantOrState0('Parameters', 'Bda', default_values['Bda']/(degree_da**4))
    
def aortic_narrowing(m,degree_ist,default_values):
    # Radius arch
    radius_bct = 0.19899999999999998
    radius_lsca = 0.136435
    radius_rsca = 0.136435
    radius_lcca = 0.15234000000000003
    radius_ist = 0.2329
    radius_dAoA = 0.24756422700788266
    radius_aAoA = 0.26546686273838843
    radius_aAo = 0.2984690662736599
    radius_tAo = 0.25955
    radius_duct = 0.2090187021180712
    radius_pA = 0.3415
        
    # Aortic isthmus
    m.setConstantOrState0('Parameters', 'Risthm', default_values['Risthm']/(degree_ist**4))
    m.setConstantOrState0('Parameters', 'Bisthm', default_values['Bisthm']/(degree_ist**4))
    m.setConstantOrState0('Parameters', 'Cisthm', default_values['Cisthm']*(degree_ist**2))
    m.setConstantOrState0('Parameters', 'Listhm', default_values['Listhm']/(degree_ist**2))
    
    # Desdending aortic arch
    degree_dAoA = np.cbrt(((degree_ist*radius_ist)**3 + radius_lsca**3)/radius_dAoA**3)
    m.setConstantOrState0('Parameters', 'RdAoA', default_values['RdAoA']/(degree_dAoA**4))
    m.setConstantOrState0('Parameters', 'BdAoA', default_values['BdAoA']/(degree_dAoA**4))
    m.setConstantOrState0('Parameters', 'CdAoA', default_values['CdAoA']*(degree_dAoA**2))
    m.setConstantOrState0('Parameters', 'LdAoA', default_values['LdAoA']/(degree_dAoA**2)) 
    
    # Ascending aortic arch
    degree_aAoA = np.cbrt(((degree_dAoA*radius_dAoA)**3 + radius_lcca**3)/radius_aAoA**3)
    m.setConstantOrState0('Parameters', 'RaAoA', default_values['RaAoA']/(degree_aAoA**4))     
    m.setConstantOrState0('Parameters', 'CaAoA', default_values['CaAoA']*(degree_aAoA**2))
    m.setConstantOrState0('Parameters', 'LaAoA', default_values['LaAoA']/(degree_aAoA**2))   
    
    # Ascending aorta
    degree_aAo = np.cbrt(((degree_aAoA*radius_aAoA)**3 + radius_bct**3)/radius_aAo**3)
    m.setConstantOrState0('Parameters', 'Raa', default_values['Raa']/(degree_aAo**4)) 
    m.setConstantOrState0('Parameters', 'Caa', default_values['Caa']*(degree_aAo**2))
    m.setConstantOrState0('Parameters', 'Laa', default_values['Laa']/(degree_aAo**2)) 
    
    # Aortic valve
    m.setConstantOrState0('Parameters', 'Aao', default_values['Aao']*(degree_aAo**2))

def function_to_optimise_CSV(variable, index_da, degree_ist, targets, Ls_lv_healthy, Ls_rv_healthy, weight, default_constants, Tc, Amref_lv, Vwall_lv, Amref_rv):
    with f_CoA.HiddenPrints():
        Vwall_rv = default_constants['Vwall_rv']*variable
        #Amref_rv = default_constants['Amref_rv']*variable**(2/3)
        tFinal = 25*Tc
        m = solver.model.ModelSolver('FETAL_MODEL_CoA_random7.c')
        ductus_increase(m,index_da,default_constants)
        aortic_narrowing(m,degree_ist,default_constants)
        m.setConstantOrState0('Parameters', 'Vwall_lv', Vwall_lv)
        m.setConstantOrState0('Parameters', 'Vwall_rv', Vwall_rv)
        m.setConstantOrState0('Parameters', 'Amref_lv', Amref_lv)
        m.setConstantOrState0('Parameters', 'Amref_rv', Amref_rv)   
        m.setConstantOrState0('Parameters', 'Vwall_la', default_constants['Vwall_la']*Vwall_lv/default_constants['Vwall_lv'])
        m.setConstantOrState0('Parameters', 'Vwall_ra', default_constants['Vwall_ra']*Vwall_rv/default_constants['Vwall_rv'])
        m.setConstantOrState0('Parameters', 'Amref_la', default_constants['Amref_la']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Amref_ra', default_constants['Amref_ra']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))   
        m.setConstantOrState0('Parameters', 'Amdead_lv', default_constants['Amdead_lv']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Amdead_rv', default_constants['Amdead_rv']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3)) 
        m.setConstantOrState0('Parameters', 'Amdead_la', default_constants['Amdead_la']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Amdead_ra', default_constants['Amdead_ra']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3)) 
        m.setConstantOrState0('Parameters', 'Aao', default_constants['Aao']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Ami', default_constants['Ami']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Apv', default_constants['Apv']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))
        m.setConstantOrState0('Parameters', 'Atr', default_constants['Atr']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))        
        ventricular_disproportion_vasculature(m,Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3),Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3),default_constants)
        m.solve(tFinal = tFinal)

    idx = m.t > tFinal - Tc
    CSV = np.trapz(m.getVariable('LV', 'Qo')[idx], m.t[idx]) + np.trapz(m.getVariable('RV', 'Qo')[idx], m.t[idx])

    Ls_lv_min = np.min(m.getVariable('LV', 'Ls')[idx])
    Ls_lv_max = np.max(m.getVariable('LV', 'Ls')[idx])
    Ls_rv_min = np.min(m.getVariable('RV', 'Ls')[idx])
    Ls_rv_max = np.max(m.getVariable('RV', 'Ls')[idx])  
        
    predictions = [CSV,Ls_lv_min,Ls_lv_max,Ls_rv_min,Ls_rv_max]
    targets_2 = [targets,np.min(Ls_lv_healthy),np.max(Ls_lv_healthy),np.min(Ls_rv_healthy),np.max(Ls_rv_healthy)]

    rmse_val = f_CoA.rmse2(predictions, targets_2, [1,0.5,0.5,0.5,0.5])
    return rmse_val

def function_to_optimise_thicknessLV(variable, index_da, degree_ist, targets, Ls_lv_healthy, Ls_rv_healthy, weight, default_constants, Tc, Vwall_lv, Amref_rv, Vwall_rv):
    with f_CoA.HiddenPrints():
        Amref_lv = variable
        tFinal = 25*Tc
        m = solver.model.ModelSolver('FETAL_MODEL_CoA_random7.c')
        ductus_increase(m,index_da,default_constants)
        aortic_narrowing(m,degree_ist,default_constants)
        m.setConstantOrState0('Parameters', 'Vwall_lv', Vwall_lv)
        m.setConstantOrState0('Parameters', 'Vwall_rv', Vwall_rv)
        m.setConstantOrState0('Parameters', 'Amref_lv', Amref_lv)
        m.setConstantOrState0('Parameters', 'Amref_rv', Amref_rv)   
        m.setConstantOrState0('Parameters', 'Vwall_la', default_constants['Vwall_la']*Vwall_lv/default_constants['Vwall_lv'])
        m.setConstantOrState0('Parameters', 'Vwall_ra', default_constants['Vwall_ra']*Vwall_rv/default_constants['Vwall_rv'])
        m.setConstantOrState0('Parameters', 'Amref_la', default_constants['Amref_la']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Amref_ra', default_constants['Amref_ra']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))   
        m.setConstantOrState0('Parameters', 'Amdead_lv', default_constants['Amdead_lv']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Amdead_rv', default_constants['Amdead_rv']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3)) 
        m.setConstantOrState0('Parameters', 'Amdead_la', default_constants['Amdead_la']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Amdead_ra', default_constants['Amdead_ra']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3)) 
        m.setConstantOrState0('Parameters', 'Aao', default_constants['Aao']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Ami', default_constants['Ami']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Apv', default_constants['Apv']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))
        m.setConstantOrState0('Parameters', 'Atr', default_constants['Atr']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))        
        ventricular_disproportion_vasculature(m,Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3),Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3),default_constants)
        m.solve(tFinal = tFinal)

    idx = m.t > tFinal - Tc
    Vcav_lv = np.max(m.getVariable('LV', 'Vcav')[idx])
    Vcav_Vwall_lv = Vcav_lv/Vwall_lv

    Ls_lv_min = np.min(m.getVariable('LV', 'Ls')[idx])
    Ls_lv_max = np.max(m.getVariable('LV', 'Ls')[idx])
    Ls_rv_min = np.min(m.getVariable('RV', 'Ls')[idx])
    Ls_rv_max = np.max(m.getVariable('RV', 'Ls')[idx])  
        
    predictions = [Vcav_Vwall_lv,Ls_lv_min,Ls_lv_max,Ls_rv_min,Ls_rv_max]
    targets_2 = [targets,np.min(Ls_lv_healthy),np.max(Ls_lv_healthy),np.min(Ls_rv_healthy),np.max(Ls_rv_healthy)]

    rmse_val = f_CoA.rmse2(predictions, targets_2, [1,0.5,0.5,0.5,0.5])
    return rmse_val

def function_to_optimise_thicknessRV(variable, index_da, degree_ist, targets, Ls_lv_healthy, Ls_rv_healthy, weight, default_constants, Tc, Amref_lv, Vwall_lv, Vwall_rv):
    with f_CoA.HiddenPrints():
        Amref_rv = variable
        tFinal = 25*Tc
        m = solver.model.ModelSolver('FETAL_MODEL_CoA_random7.c')
        ductus_increase(m,index_da,default_constants)
        aortic_narrowing(m,degree_ist,default_constants)
        m.setConstantOrState0('Parameters', 'Vwall_lv', Vwall_lv)
        m.setConstantOrState0('Parameters', 'Vwall_rv', Vwall_rv)
        m.setConstantOrState0('Parameters', 'Amref_lv', Amref_lv)
        m.setConstantOrState0('Parameters', 'Amref_rv', Amref_rv)   
        m.setConstantOrState0('Parameters', 'Vwall_la', default_constants['Vwall_la']*Vwall_lv/default_constants['Vwall_lv'])
        m.setConstantOrState0('Parameters', 'Vwall_ra', default_constants['Vwall_ra']*Vwall_rv/default_constants['Vwall_rv'])
        m.setConstantOrState0('Parameters', 'Amref_la', default_constants['Amref_la']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Amref_ra', default_constants['Amref_ra']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))   
        m.setConstantOrState0('Parameters', 'Amdead_lv', default_constants['Amdead_lv']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Amdead_rv', default_constants['Amdead_rv']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3)) 
        m.setConstantOrState0('Parameters', 'Amdead_la', default_constants['Amdead_la']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Amdead_ra', default_constants['Amdead_ra']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3)) 
        m.setConstantOrState0('Parameters', 'Aao', default_constants['Aao']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Ami', default_constants['Ami']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
        m.setConstantOrState0('Parameters', 'Apv', default_constants['Apv']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))
        m.setConstantOrState0('Parameters', 'Atr', default_constants['Atr']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))        
        ventricular_disproportion_vasculature(m,Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3),Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3),default_constants)
        m.solve(tFinal = tFinal)

    idx = m.t > tFinal - Tc
    Vcav_rv = np.max(m.getVariable('RV', 'Vcav')[idx])
    Vcav_Vwall_rv = Vcav_rv/Vwall_rv

    Ls_lv_min = np.min(m.getVariable('LV', 'Ls')[idx])
    Ls_lv_max = np.max(m.getVariable('LV', 'Ls')[idx])
    Ls_rv_min = np.min(m.getVariable('RV', 'Ls')[idx])
    Ls_rv_max = np.max(m.getVariable('RV', 'Ls')[idx])  
        
    predictions = [Vcav_Vwall_rv,Ls_lv_min,Ls_lv_max,Ls_rv_min,Ls_rv_max]
    targets_2 = [targets,np.min(Ls_lv_healthy),np.max(Ls_lv_healthy),np.min(Ls_rv_healthy),np.max(Ls_rv_healthy)]

    rmse_val = f_CoA.rmse2(predictions, targets_2, [1,0.5,0.5,0.5,0.5])
    return rmse_val

def fetal_aortic_coarctation(degree_ist):
    Tc = 0.43
    GA = 32 
    weight = 10**(0.2508+0.1458*GA-0.0016*GA**2) 
    #mywrapper = solver.cwrapping.ClibWrapper(cPath = '/home/ivillanueva/CoA/FETAL_MODEL_CoA_random7.c', cLibPath = '/home/ivillanueva/CoA/solver/Cython/libcomputeRates.cpython-39-x86_64-linux-gnu.so') 
    
    with f_CoA.HiddenPrints():
        tFinal = 25*Tc
        m = solver.model.ModelSolver('FETAL_MODEL_CoA_random7.c') #, wrapper = mywrapper
        m.solve(tFinal = tFinal)
    
    constants_names = ['Aao','Apv','Ami','Atr','Vwall_lv','Vwall_rv','Amref_lv','Amref_rv','Vwall_la','Vwall_ra','Amref_la','Amref_ra','Amdead_lv','Amdead_rv','Amdead_la','Amdead_ra','Risthm','Bisthm','Cisthm','Listhm','RdAoA','BdAoA','CdAoA','LdAoA','RaAoA','CaAoA','LaAoA','Raa','Caa','Laa','Rpa','Bmpa','Lpa','Cpa','Rda','Bda','Kda','Lda']
    default_constants = {element: m.getConstant('Parameters', element) for element in constants_names}

    idx = m.t > tFinal - Tc
    Ls_lv_healthy = m.getVariable('LV', 'Ls')[idx]
    Ls_rv_healthy = m.getVariable('RV', 'Ls')[idx]
    CSV = np.trapz(m.getVariable('LV', 'Qo')[idx], m.t[idx]) + np.trapz(m.getVariable('RV', 'Qo')[idx], m.t[idx])
    Vcav_rv = np.max(m.getVariable('RV', 'Vcav')[idx])
    healthy_Vcav_Vwall_rv = Vcav_rv/default_constants['Vwall_rv']    
    Vcav_lv = np.max(m.getVariable('LV', 'Vcav')[idx])
    healthy_Vcav_Vwall_lv = Vcav_lv/default_constants['Vwall_lv']  
    
    v_degree_LV = [0.9,0.7,0.5,0.35] #[0.9,0.8,0.7,0.6,0.5,0.4]
    v_degree_da = [1,1.2,1.4,1.6] #[1,1.1,1.2,1.3,1.4,1.5,1.6,1.7]
     
    for index_LV in v_degree_LV:
        for index_da in v_degree_da:
            Vwall_lv = default_constants['Vwall_lv']*index_LV
            Vwall_rv = default_constants['Vwall_rv']*(2-index_LV)
            Amref_lv = default_constants['Amref_lv']*index_LV**(2/3)
            Amref_rv = default_constants['Amref_rv']*(2-index_LV)**(2/3)

            print('1')
            res = optimize.minimize_scalar(function_to_optimise_thicknessLV,args=(index_da, degree_ist, healthy_Vcav_Vwall_lv, Ls_lv_healthy, Ls_rv_healthy, weight, default_constants, Tc, Vwall_lv, Amref_rv, Vwall_rv),bounds=(6, 18), method='bounded') #(6, 18)
            Amref_lv = res.x

            res = optimize.minimize_scalar(function_to_optimise_CSV,args=(index_da, degree_ist, CSV, Ls_lv_healthy, Ls_rv_healthy, weight, default_constants, Tc, Amref_lv, Vwall_lv, Amref_rv),bounds=(1, 3), method='bounded') # (1, 3)
            variation = res.x
            Vwall_rv = default_constants['Vwall_rv']*variation

            res = optimize.minimize_scalar(function_to_optimise_thicknessRV,args=(index_da, degree_ist, healthy_Vcav_Vwall_rv, Ls_lv_healthy, Ls_rv_healthy, weight, default_constants, Tc, Amref_lv, Vwall_lv, Vwall_rv),bounds=(18, 40), method='bounded')#(18, 40)
            Amref_rv = res.x
    
            m = solver.model.ModelSolver('FETAL_MODEL_CoA_random7.c') #, wrapper = mywrapper
            ductus_increase(m,index_da,default_constants)
            aortic_narrowing(m,degree_ist,default_constants)
            m.setConstantOrState0('Parameters', 'Vwall_lv', Vwall_lv)
            m.setConstantOrState0('Parameters', 'Vwall_rv', Vwall_rv)
            m.setConstantOrState0('Parameters', 'Amref_lv', Amref_lv)
            m.setConstantOrState0('Parameters', 'Amref_rv', Amref_rv)   
            m.setConstantOrState0('Parameters', 'Vwall_la', default_constants['Vwall_la']*Vwall_lv/default_constants['Vwall_lv'])
            m.setConstantOrState0('Parameters', 'Vwall_ra', default_constants['Vwall_ra']*Vwall_rv/default_constants['Vwall_rv'])
            m.setConstantOrState0('Parameters', 'Amref_la', default_constants['Amref_la']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
            m.setConstantOrState0('Parameters', 'Amref_ra', default_constants['Amref_ra']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))   
            m.setConstantOrState0('Parameters', 'Amdead_lv', default_constants['Amdead_lv']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
            m.setConstantOrState0('Parameters', 'Amdead_rv', default_constants['Amdead_rv']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3)) 
            m.setConstantOrState0('Parameters', 'Amdead_la', default_constants['Amdead_la']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
            m.setConstantOrState0('Parameters', 'Amdead_ra', default_constants['Amdead_ra']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3)) 
            m.setConstantOrState0('Parameters', 'Aao', default_constants['Aao']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
            m.setConstantOrState0('Parameters', 'Ami', default_constants['Ami']*Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3))
            m.setConstantOrState0('Parameters', 'Apv', default_constants['Apv']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))
            m.setConstantOrState0('Parameters', 'Atr', default_constants['Atr']*Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3))        
            ventricular_disproportion_vasculature(m,Vwall_lv**(2/3)/default_constants['Vwall_lv']**(2/3),Vwall_rv**(2/3)/default_constants['Vwall_rv']**(2/3),default_constants)
            
            with f_CoA.HiddenPrints():
                m.solve(tFinal = tFinal)
                
            m.saveResults('/gpfs/home/ivillanueva/CoA/Results_random7/IST' + str(round(degree_ist*100)) + '_LV' + str(round(index_LV*100)) + '_DA' + str(round(index_da*100)) + '.npz', degree_ist = degree_ist, degree_da = index_da, degree_LV = index_LV)
    return m       

# RUN SIMULATIONS
degree_ist = 1 # [1,0.9,0.8,0.7,0.6,0.5,0.4,0.3,0.2,0.1]
m = fetal_aortic_coarctation(degree_ist)