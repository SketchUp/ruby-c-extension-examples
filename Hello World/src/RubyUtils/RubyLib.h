#ifndef SU_UTILS_RUBYLIB_H_
#define SU_UTILS_RUBYLIB_H_


///// Visual Studio CRT Config /////////////////////////////////////////////////

// Disable all warnings.
// http://stackoverflow.com/a/2541990/486990
#pragma warning(push, 0)

// Must disable the min/max macros defined by windows.h to avoid conflict with
// std::max and std:min. Ruby includes windows.h so it must be disabled here.
// http://stackoverflow.com/a/2789509/486990
#define NOMINMAX

// Ruby was configured for Visual Studio 2010. These macros are needed to
// prevent compiler errors with Visual Studio 2013. This relate to release
// builds which are compiled with MT.

#if _MT

// Visual Studio 2013
#if _MSC_VER >= 1800

// Ruby 2.0
#define HAVE_ACOSH 1
#define HAVE_CBRT 1
#define HAVE_ERF 1
#define HAVE_TGAMMA 1
#define HAVE_ROUND 1

// Ruby 2.2
#define HAVE_NEXTAFTER 1

#endif // VS 2013

// Visual Studio 2015
#if _MSC_VER >= 1900

#define HAVE_STRUCT_TIMESPEC 1

#endif // VS2015

#endif // _MT


///// Ruby Headers /////////////////////////////////////////////////////////////

// For some reason Xcode will flag warnings (which are treated as errors) in
// the Ruby headers. This works around that.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"

#include <ruby.h>
#ifdef HAVE_RUBY_ENCODING_H
#include <ruby/encoding.h>
#endif

#pragma clang diagnostic pop


///// Compatibility Macros /////////////////////////////////////////////////////

/* The structures changes between Ruby 1.8 and 2.0 so the access to the
 * properties are different. There are new macros in Ruby 2.0 that should be
 * used instead. In order to make the code compile for both we need to add
 * matching macros for 1.8.
 */

#ifndef RARRAY_LEN
#define RARRAY_LEN(x) (RARRAY(x)->len)
#endif

#ifndef DBL2NUM
#define DBL2NUM(dbl)  rb_float_new(dbl)
#endif

#ifndef NUM2SIZET
  #if defined(HAVE_LONG_LONG) && SIZEOF_SIZE_T > SIZEOF_LONG
  # define NUM2SIZET(x) ((size_t)NUM2ULL(x))
  #else
  # define NUM2SIZET(x) NUM2ULONG(x)
  #endif
#endif


// Ruby 2.0 renamed some functions. Need to add some compatibility macros for
// older Ruby.
#ifndef rb_ary_new2
#define rb_ary_new_capa rb_ary_new2
#define rb_ary_new_from_args rb_ary_new3
#define rb_ary_new_from_values rb_ary_new4
#endif


// Ruby 1.8 headers conflict with ostream because it defined a lot of macros
// that completely mess up the environment.

// win32.h
#ifdef getc
#undef getc
#endif

#ifdef putc
#undef putc
#endif

#ifdef fgetc
#undef fgetc
#endif

#ifdef fputc
#undef fputc
#endif

#ifdef getchar
#undef getchar
#endif

#ifdef putchar
#undef putchar
#endif

#ifdef fgetchar
#undef fgetchar
#endif

#ifdef fputchar
#undef fputchar
#endif

#ifdef utime
#undef utime
#endif


#ifdef close
#undef close
#endif

#ifdef fclose
#undef fclose
#endif

#ifdef read
#undef read
#endif

#ifdef write
#undef write
#endif

#ifdef getpid
#undef getpid
#endif

#ifdef sleep
#undef sleep
#endif


// config.h
#ifdef inline
#undef inline
#endif

#pragma warning (pop)


#endif // SU_UTILS_RUBYLIB_H_
