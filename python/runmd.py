#!/usr/bin/env python

#from ctp import *

import ctp

def runme():
    spi = MdSpi();
    spi.Init()
    spi.Join()
    return

class MdSpi(ctp.CThostFtdcMdSpi):
    def __init__(self):
        ctp.CThostFtdcMdSpi(self)
        self.api = ctp.CThostFtdcTraderApi_CreateFtdcTraderApi("")
        self.api.RegisterFront()
        self.api.RegisterSpi(self)
        self.api.RegisterFront("protocal=tcp;host=asp-sim2-front1.financial-trading-platform.com;port=26213;userid=352240;password=888888;brokerid=2030");
        return

    def OnFrontConnected(self):
        print("FrontConnected")

        field = ctp.CThostFtdcReqUserLoginField();
        field.BrokerID = "2030"
        field.UserID = "352240"
        field.Password = "888888"
        self.api.ReqUserLogin(field, 2)
        return

    def OnRspUserLogin(self, *args):
        return

    def OnRspError(self, *args):
        return

    def OnRspSubMarketData(self, *args):
        return

    def OnRtnDepthMarketData(self, *args):
        return

    def __del__(self):
        self.api.RegisterSpi(None)
        self.api.Release()
        return

if __name__ == "__main__":
    runme()
