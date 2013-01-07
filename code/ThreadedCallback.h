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
        std::cout << "request from thread " << std::this_thread::get_id() << std::endl;
        std::thread t(&Caller::response, this);
        if (t.joinable()) t.join();
    }

    void response() {
        callback->response();
    }

private:
    Callback *callback;
};

class DCallback : public Callback {
public:
    virtual void response() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "response from thread " << std::this_thread::get_id() << std::endl;
    }
};
