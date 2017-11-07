#ifndef SU_UTILS_RUBYLIB_H_
#define SU_UTILS_RUBYLIB_H_


// Disable all warnings.
// http://stackoverflow.com/a/2541990/486990
#pragma warning(push, 0)

// Must disable the min/max macros defined by windows.h to avoid conflict with
// std::max and std:min. Ruby includes windows.h so it must be disabled here.
// http://stackoverflow.com/a/2789509/486990
#define NOMINMAX

// Ruby in SketchUp was configured with /MD and the headers reflect that.
// And from Ruby version to Ruby version the configuration needs to be slightly
// different. These macros smooth over this and should allow the project
// to be built with newer Visual Studio runtimes as well as /MT.

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

// For some reason Xcode will flag warnings (which are treated as errors) in
// the Ruby headers. This works around that.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"

#include <ruby.h>
// ruby/encoding.h only existed from Ruby 2.0.
#ifdef HAVE_RUBY_ENCODING_H
#include <ruby/encoding.h>
#endif

#pragma clang diagnostic pop

#pragma warning (pop)

#endif // SU_UTILS_RUBYLIB_H_
