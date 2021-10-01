
#include "RubyUtils/RubyUtils.h"


VALUE hello_world() {
  return GetRubyInterface("Hello World!");
}

VALUE ruby_platform() {
  return GetRubyInterface(RUBY_PLATFORM);
}

// Load this module from Ruby using:
//   require 'SUEX_HelloWorld'
extern "C"
void Init_SUEX_HelloWorld()
{
  VALUE mSUEX_HelloWorld = rb_define_module("SUEX_HelloWorld");
  rb_define_const(mSUEX_HelloWorld, "CEXT_VERSION", GetRubyInterface("1.0.0"));
  rb_define_module_function(mSUEX_HelloWorld, "hello_world", VALUEFUNC(hello_world), 0);
  rb_define_module_function(mSUEX_HelloWorld, "ruby_platform", VALUEFUNC(ruby_platform), 0);
}
