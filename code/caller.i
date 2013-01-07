%module(directors="1") caller

%{
#include "ThreadedCallback.h"
}

%feature("director") Callback;

%include "ThreadedCallback.h"