#pragma once

#include <string>

class INativeToRuby
{
public:
  INativeToRuby();
  virtual ~INativeToRuby();

  virtual void CallFromNative(const std::string& message) = 0;
};
