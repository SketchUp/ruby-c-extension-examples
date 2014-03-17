#include "RubyUtils.h"


// Ruby interfaces for strings.

VALUE GetRubyInterface(const char* s) {
  VALUE str_val = rb_str_new2(s);
#ifdef HAVE_RUBY_ENCODING_H
  // Mark all strings as UTF-8 encoded Ruby 2.0 generally expects strings to be
  // Encoded UTF-8.
  static int enc_index = rb_enc_find_index("UTF-8");
  rb_enc_associate_index(str_val, enc_index);
#endif
  return str_val;
}
