/* Here's some sample code to call C++ from Ruby and vice versa

class RubyClass < SUEX_UsingSWIG::INativeToRuby
  def CallFromNative(str)
    puts str
  end
end

a = SUEX_UsingSWIG::MyNativeClass.new(RubyClass.new)
a.CallBackToRuby("Hello from Ruby")
*/

#pragma once

#include <string>

class INativeToRuby
{
public:
  INativeToRuby();
  virtual ~INativeToRuby();

  virtual void CallFromNative(const std::string& message) = 0;
};
