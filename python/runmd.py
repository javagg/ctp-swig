#!/usr/bin/env python

import ctp

class MdSpi(ctp.CThostFtdcMdSpi):
    def __init__(self):
        ctp.CThostFtdcMdSpi(self)
        api = CThostFtdcMdApi()
    def connect(self):
#        self.this = _example.new_Foo()
#        self.thisown = 1

