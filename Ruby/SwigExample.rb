# Load the C extension
ruby_path = File.dirname(__FILE__)
project_path = File.expand_path( File.join(ruby_path, '..') )
binary_path = File.join(project_path, 'Debug (2.0)', 'SUEX_UsingSWIG.so')
require binary_path

# Derive a class from the interface defined in C++
class FromNative < SUEX_UsingSWIG::INativeToRuby
  def initialize
       # http://stackoverflow.com/questions/549249/polymorphism-across-c-and-ruby-using-swig
      super()
  end

  def CallFromNative(message)
    UI.messagebox(message)
  end
end

fn = FromNative.new
native_obj = SUEX_UsingSWIG::MyNativeClass.new(fn)
native_obj.CallBackToRuby('This came from Ruby')
