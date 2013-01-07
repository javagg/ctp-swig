#include "Callback.h"

class DCallback : public Callback {
public:
    virtual void response() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "response from thread " << std::this_thread::get_id() << std::endl;
    }
};

int main(int argc, char *argv[]) {
    DCallback cb;
    Caller caller(&cb);
    caller.request();
}
