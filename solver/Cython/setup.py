import sys,numpy as np
from setuptools import Extension, setup
from Cython.Build import cythonize

setup(
    ext_modules = cythonize([Extension( name='computeRates',
        sources=['computeRates.pyx', 'model.c'],
        include_dirs=[np.get_include()],
        extra_compile_args=['--std=c99'])]
        ),
    script_args = ['build_ext', '--inplace']
)

# For building in place python setup.py build_ext --inplace
# To call this from command line: https://stackoverflow.com/questions/2850971/directly-call-distutils-or-setuptools-setup-function-with-command-name-optio
# Based on https://github.com/yngtodd/cythe/blob/master/setup.py , probablbly using c99 is not needed.
# Warning: Many times it is needed to delete the conda environment and install it again if the compiler is broken after os update.