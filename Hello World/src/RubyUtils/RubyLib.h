#ifndef SU_UTILS_RUBYLIB_H_
#define SU_UTILS_RUBYLIB_H_

// Needed for VS2015.
#if _MSC_VER >= 1900
#define HAVE_STRUCT_TIMESPEC 1
#endif

#include <ruby.h>
#ifdef HAVE_RUBY_ENCODING_H
#include <ruby/encoding.h>
#endif

#endif // SU_UTILS_RUBYLIB_H_
