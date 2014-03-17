#ifndef SU_UTILS_RUBYUTILS_H_
#define SU_UTILS_RUBYUTILS_H_

#include "RubyLib.h"


/*
 * Need to be very careful about how these macros are defined, especially
 * when compiling C++ code or C code with an ANSI C compiler.
 *
 * VALUEFUNC(f) is a macro used to typecast a C function that implements
 * a Ruby method so that it can be passed as an argument to API functions
 * like rb_define_method() and rb_define_singleton_method().
 *
 * VOIDFUNC(f) is a macro used to typecast a C function that implements
 * either the "mark" or "free" stuff for a Ruby Data object, so that it
 * can be passed as an argument to API functions like Data_Wrap_Struct()
 * and Data_Make_Struct().
 */

#define VALUEFUNC(f) ((VALUE (*)(ANYARGS)) f)
#define VOIDFUNC(f)  ((RUBY_DATA_FUNC) f)

// Ruby interfaces for strings.

VALUE GetRubyInterface(const char *s);


// Ruby interfaces for booleans.

inline VALUE GetRubyInterface(bool bValue) {
  return bValue ? Qtrue : Qfalse;
}


// Ruby interfaces for numbers.

inline VALUE GetRubyInterface(double value) {
  return rb_float_new(value);
}

inline VALUE GetRubyInterface(float value) {
  return rb_float_new((double) value);
}

inline VALUE GetRubyInterface(long value) {
  return rb_int2inum(value);
}

inline VALUE GetRubyInterface(int value) {
  return rb_int2inum((long) value);
}

inline VALUE GetRubyInterface(short value) {
  return rb_int2inum((long) value);
}

inline VALUE GetRubyInterface(unsigned char value) {
  return rb_int2inum((long) value);
}

inline VALUE GetRubyInterface(unsigned long value) {
  return rb_uint2inum(value);
}

inline VALUE GetRubyInterface(unsigned int value) {
  return rb_uint2inum(value);
}


#endif // SU_UTILS_RUBYUTILS_H_
