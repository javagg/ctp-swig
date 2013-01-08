#ifndef _callback_h
#define _callback_h

#include <thread>
#include <iostream>
#include <chrono>

class Callback {
public:
    virtual ~Callback() {}
    virtual void response() = 0;
};

class Caller {
public:
    Caller(Callback *cb) : callback(cb) {}
    void request() {
        std::cout << "in c++ lib, request in thread " << std::this_thread::get_id() << std::endl;
        std::thread t(&Caller::response, this);
        if (t.joinable()) t.join();
    }

    void response() {
        std::cout << "in c++ lib, response in thread " << std::this_thread::get_id() << std::endl;
        callback->response();
    }

private:
    Callback *callback;
};

#endif
