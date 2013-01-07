set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(_c_headers Callback.h Caller.h)

set(_sources ThreadedCallback.cpp Main.cpp)

add_executable(tCallback ${_sources})
