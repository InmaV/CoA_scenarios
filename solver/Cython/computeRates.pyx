"""See Cython docs at http://docs.cython.org/"""
import cython
import numpy as np
cimport numpy as np

cdef extern from "computeRates.h":
    void computeVariables(double VOI, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC)
    void computeRates(double VOI, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC)
    void initConsts(double* CONSTANTS, double* RATES, double *STATES)

def computeVariables_Cython(double VOI, 
                            np.ndarray[double, ndim=1, mode="c"] CONSTANTS,
                            np.ndarray[double, ndim=1, mode="c"] RATES,
                            np.ndarray[double, ndim=1, mode="c"] STATES, 
                            np.ndarray[double, ndim=1, mode="c"] ALGEBRAIC):
    # x.data is a pointer to the array data in memory
    cdef cython.double* CONSTANTS_ptr = <cython.double*> CONSTANTS.data
    cdef cython.double* RATES_ptr = <cython.double*> RATES.data
    cdef cython.double* STATES_ptr = <cython.double*> STATES.data
    cdef cython.double* ALGEBRAIC_ptr = <cython.double*> ALGEBRAIC.data

    computeVariables(VOI, CONSTANTS_ptr, RATES_ptr, STATES_ptr, ALGEBRAIC_ptr)
    return 1

def computeVariables_array_Cython(                            
                            np.ndarray[double, ndim=1, mode="c"] VOI,
                            np.ndarray[double, ndim=1, mode="c"] CONSTANTS,
                            np.ndarray[double, ndim=2, mode="c"] RATES,
                            np.ndarray[double, ndim=2, mode="c"] STATES, 
                            np.ndarray[double, ndim=2, mode="c"] ALGEBRAIC):
    # x.data is a pointer to the array data in memory
    cdef cython.double* CONSTANTS_ptr = <cython.double*> CONSTANTS.data
    cdef cython.double* RATES_ptr = <cython.double*> RATES.data
    cdef cython.double* STATES_ptr = <cython.double*> STATES.data
    cdef cython.double* ALGEBRAIC_ptr = <cython.double*> ALGEBRAIC.data

    cdef int i
    for i in range(VOI.shape[0]):
        computeVariables(VOI[i], CONSTANTS_ptr,
         RATES_ptr  + i * RATES.shape[1], 
         STATES_ptr  + i * STATES.shape[1], 
         ALGEBRAIC_ptr  + i * ALGEBRAIC.shape[1])
    return 1

def computeRates_Cython(double VOI, 
                            np.ndarray[double, ndim=1, mode="c"] CONSTANTS,
                            np.ndarray[double, ndim=1, mode="c"] RATES,
                            np.ndarray[double, ndim=1, mode="c"] STATES, 
                            np.ndarray[double, ndim=1, mode="c"] ALGEBRAIC):
    # x.data is a pointer to the array data in memory
    cdef cython.double* CONSTANTS_ptr = <cython.double*> CONSTANTS.data
    cdef cython.double* RATES_ptr = <cython.double*> RATES.data
    cdef cython.double* STATES_ptr = <cython.double*> STATES.data
    cdef cython.double* ALGEBRAIC_ptr = <cython.double*> ALGEBRAIC.data

    computeRates(VOI, CONSTANTS_ptr, RATES_ptr, STATES_ptr, ALGEBRAIC_ptr)
    return 1

def initConst_Cython(
                            np.ndarray[double, ndim=1, mode="c"] CONSTANTS,
                            np.ndarray[double, ndim=1, mode="c"] RATES,
                            np.ndarray[double, ndim=1, mode="c"] STATES, 
                            ):
    # x.data is a pointer to the array data in memory
    cdef cython.double* CONSTANTS_ptr = <cython.double*> CONSTANTS.data
    cdef cython.double* RATES_ptr = <cython.double*> RATES.data
    cdef cython.double* STATES_ptr = <cython.double*> STATES.data

    initConsts(CONSTANTS_ptr, RATES_ptr, STATES_ptr)
    return 1