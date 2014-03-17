%module(directors=1) SUEX_UsingSWIG

%{
#include "MyNativeClass.h"
#include "INativeToRuby.h"
%}

%include std_string.i

%include "MyNativeClass.h"

%feature("director") INativeToRuby;
%include "INativeToRuby.h"
