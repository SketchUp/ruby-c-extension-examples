# SketchUp Ruby C/C++ Extension Examples

This project includes the Ruby lib and header files used by SketchUp.

## C++ Example - Hello World

### Visual Studio 2015

(For older Visual Studio versions, check out the commits prior to the VS2015 tag.)

Notes on how the solution is set up:

* The project name must match the name of the `Init_*()` function. Example: If the project name is HelloWorld the init function must be named `Init_HelloWorld`.
* The init function must be exported in the .def file - named the same as the project.

### Xcode 8

Xcode project is set up to build targets all the way back to Ruby 1.8.
