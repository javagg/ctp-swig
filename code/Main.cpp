#include "ThreadedCallback.h"

int main(int argc, char *argv[]) {
    DCallback cb;
    Caller caller(&cb);
    caller.request();
}
