# SketchUp Ruby C/C++ Extension Examples

This project includes the Ruby lib and header files used by SketchUp.

## C++ Example - Hello World

### Visual Studio 2010

Notes on how the solution is set up:

* The project name must match the name of the `Init_*()` function. Example: If the project name is HelloWorld the init function must be named `Init_HelloWorld`.
* The init function must be exported in the .def file - named the same as the project.

### Xcode 4.5

Tested to also work on Xcode 4.6 and Xcode 5.

### Ruby

Notes on how to call the Hello World Example from Ruby :

* first copy the file SUEX_HelloWorld.so to the Plugins folder

* call the extension using the following lines 

require 'SUEX_HelloWorld'

puts SUEX_HelloWorld::CEXT_VERSION

puts SUEX_HelloWorld::hello_world
