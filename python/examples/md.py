#!/usr/bin/env python
# -*- coding: utf-8 -*-

#from ctp import CThostFtdcMdSpi

import time, multiprocessing, signal, threading, thread
import weakref

# from ctp import *
# import threading
#
# class MdSpi(CThostFtdcMdSpi):
#     request_id = 0
#     def __init__(self, front, broker_id, user_id, password):
#         CThostFtdcMdSpi.__init__(self)
#
#         self.front = front
#         self.broker_id = broker_id
#         self.user_id = user_id
#         self.password = password
#
#         self.api = CThostFtdcMdApi_CreateFtdcMdApi("")
#         self.api.RegisterSpi(self)
#         self.api.RegisterFront(front)
#         self.api.Init()
#         print(threading.current_thread())
# #        self.api.RegisterFront("protocal=tcp;host=asp-sim2-front1.financial-trading-platform.com;port=26213;userid=352240;password=888888;brokerid=2030");
#         return
#     def join(self):
#         self.api.Join()
#
#
#     def OnFrontConnected(self):
#         print("FrontConnected")
#         print(threading.current_thread())
#
#         field = CThostFtdcReqUserLoginField();
#         field.BrokerID = "2030"
#         field.UserID = "352240"
#         field.Password = "888888"
#         request_id += 1
#         self.api.ReqUserLogin(field, request_id)
#         return
#
#     def OnRspUserLogin(self, *args):
#         print("OnRspUserLogin")
#         return
#
#     def OnRspError(self, *args):
#         return
#
#     def OnRspSubMarketData(self, *args):
#         return
#
#     def OnRtnDepthMarketData(self, *args):
#         return
#
#     def __del__(self):
#         self.api.RegisterSpi(None)
#         self.api.Release()
#         return
#
# front = "tcp://asp-sim2-front1.financial-trading-platform.com:26213"
# broker = "2030"
# user = "352240"
# password = "888888"
import sys
import signal

class Master:
    def __index__(self):
        signal.signal(signal.SIGINT, self.handle_signal);
        return

    def run(self):
        while True:
            time.sleep(1)

        return

    def handle_signal(self):
        print("exit")
        sys.exit(0);


def main():
    print(1)
    # master = Master();
    # master.run();

    # signal.signal(signal.SIGTSTP, lambda )
    signal.pause()
#    spi = MdSpi();
#    spi.Init()
#    spi.Join()

    # spi = MdSpi(front, broker, user, password)
    # spi.join()
    return


if __name__ == "__main__":
    main()
