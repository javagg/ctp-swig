%module(directors="1") swigmt

%{
#include "Callback.h"
%}

%feature("director") Callback;

%include "Callback.h"
