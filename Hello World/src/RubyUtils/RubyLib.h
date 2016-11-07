#ifndef SU_UTILS_RUBYLIB_H_
#define SU_UTILS_RUBYLIB_H_

// Needed for VS2015.
// TODO(thomthom): Not sure if this apply for Ruby 2.0 build.
#if _MSC_VER >= 1900

// Ruby was configured for Visual Studio 2010. These macros are needed to
// prevent compiler errors with Visual Studio 2013. This relate to release
// builds which are compiled with MT.

// Ruby 2.0
#define HAVE_ACOSH 1
#define HAVE_CBRT 1
#define HAVE_ERF 1
#define HAVE_TGAMMA 1
#define HAVE_ROUND 1
#define HAVE_STRUCT_TIMESPEC 1

// Ruby 2.2
// TODO(thomthom): #ifdef this out to only apply when building Ruby 2.2?
#define HAVE_NEXTAFTER 1

#endif

#include <ruby.h>
#ifdef HAVE_RUBY_ENCODING_H
#include <ruby/encoding.h>
#endif

#endif // SU_UTILS_RUBYLIB_H_
