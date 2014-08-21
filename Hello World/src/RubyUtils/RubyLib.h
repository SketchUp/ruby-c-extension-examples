#ifndef SU_UTILS_RUBYLIB_H_
#define SU_UTILS_RUBYLIB_H_

///// Visual Studio CRT Config /////////////////////////////////////////////////

// Must define these macros for VS2013 runtime.
#define HAVE_ACOSH 1
#define HAVE_CBRT 1
#define HAVE_ERF 1
#define HAVE_ROUND 1
#define HAVE_TGAMMA 1


///// Ruby Headers /////////////////////////////////////////////////////////////

#include <ruby.h>
#ifdef HAVE_RUBY_ENCODING_H
#include <ruby/encoding.h>
#endif


#endif // SU_UTILS_RUBYLIB_H_
