#pragma once

#include <string>

class INativeToRuby;

class MyNativeClass
{
public:
  MyNativeClass(INativeToRuby& ri);
  ~MyNativeClass();

  void CallBackToRuby(const std::string& message);

private:
  INativeToRuby& ruby_interface_;
};
