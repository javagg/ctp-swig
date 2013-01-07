#include "ThreadedCallback.h"

int main(int argc, char *argv[]) {
    DCallback cb;
    Caller caller(&cb);
    std::thread t([]() {
        for(int i = 0; i < 10000; ++i) {}
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    });
    t.join();
//    if (t.joinable()) t.join();
//    caller.request();
}
