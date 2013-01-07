#!/usr/bin/env python

#from ctp import CThostFtdcMdSpi

from ctp import *
import threading

def runme():
#    spi = MdSpi();
#    spi.Init()
#    spi.Join()
    return

class MdSpi(CThostFtdcMdSpi):
    request_id = 0
    def __init__(self, front, broker_id, user_id, password):
        CThostFtdcMdSpi.__init__(self)

        self.front = front
        self.broker_id = broker_id
        self.user_id = user_id
        self.password = password

        self.api = CThostFtdcMdApi_CreateFtdcMdApi("")
        self.api.RegisterSpi(self)
        self.api.RegisterFront(front)
        self.api.Init()
        print(threading.current_thread())
#        self.api.RegisterFront("protocal=tcp;host=asp-sim2-front1.financial-trading-platform.com;port=26213;userid=352240;password=888888;brokerid=2030");
        return
    def join(self):
        self.api.Join()


    def OnFrontConnected(self):
        print("FrontConnected")
        print(threading.current_thread())

        field = CThostFtdcReqUserLoginField();
        field.BrokerID = "2030"
        field.UserID = "352240"
        field.Password = "888888"
        request_id += 1
        self.api.ReqUserLogin(field, request_id)
        return

    def OnRspUserLogin(self, *args):
        print("OnRspUserLogin")
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

front = "tcp://asp-sim2-front1.financial-trading-platform.com:26213"
broker = "2030"
user = "352240"
password = "888888"

spi = MdSpi(front, broker, user, password)
spi.join()