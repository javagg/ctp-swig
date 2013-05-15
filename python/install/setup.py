#!/usr/bin/env python

from distutils.core import setup
from distutils.extension import Extension

setup(name='ctp', 
      version='1.0',
      package_dir={'ctp': ''}, 
      packages=['ctp'],
      package_data={'ctp': ['_ctp.so', 'libthostmduserapi.so', 'libthosttraderapi.so']},
        )

