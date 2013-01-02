#!/usr/bin/env python

from distutils.core import setup, Extension

ctp_module = Extension('_ctp', sources=['ctpPYTHON_wrap.cxx'],
   
setup(name='ctp', version='1.0', author='Alex Lee', url='http://www.freequant.org', packages=['ctp'])
