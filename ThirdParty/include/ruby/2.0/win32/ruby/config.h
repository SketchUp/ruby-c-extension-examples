// Copyright 2014 Trimble Navigation Ltd.  All Rights Reserved
#ifndef INCLUDE_RUBY_CONFIG_WRAPPER_H
#define INCLUDE_RUBY_CONFIG_WRAPPER_H

// Ruby build places the actual config.h into a platform-specific directory but
// expects to find it under ruby. Apparently the assumption is that the
// platform-specific directory will be added to C++ include paths of every
// project that uses Ruby. This is inconvenient and I chose to create this
// wrapper that simply includes the platform-specific config header.

#if defined _WIN64
#pragma message("*** Include 64-bit ruby config.h here ***")
#else
#include "i386-mswin32_100/ruby/config.h"
#endif

#endif /* INCLUDE_RUBY_CONFIG_WRAPPER_H */
