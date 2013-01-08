from swigmt import *;
import threading;

class DCallback(Callback):
    def __init__(self):
        Callback.__init__(self)

    def response(self):
        print("response from python in thread " + threading.current_thread().getName())

cb = DCallback()
caller = Caller(cb)
print("request from python in thread " + threading.current_thread().getName())
caller.request()
