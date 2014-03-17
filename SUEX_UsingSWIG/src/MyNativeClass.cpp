#include "MyNativeClass.h"
#include "INativeToRuby.h"
#include <iostream>

MyNativeClass::MyNativeClass(INativeToRuby& ri)
    : ruby_interface_(ri)
{}

MyNativeClass::~MyNativeClass() {
}

void MyNativeClass::CallBackToRuby(const std::string& message) {
  std::cout << message << std::endl;
  ruby_interface_.CallFromNative("This came from C++");
}
