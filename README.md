# SketchUp Ruby C/C++ Extension Examples

This project includes the Ruby lib and header files used by SketchUp.

## C++ Example - Hello World

### Visual Studio 2022

(For older Visual Studio versions, check out the various git tags.)

Notes on how the solution is set up:

* The project name must match the name of the `Init_*()` function. Example: If the project name is HelloWorld the init function must be named `Init_HelloWorld`.
* The init function must be exported in the .def file - named the same as the project.

#### Debugging

The Visual Studio project is set up to launch SketchUp and then load the built
Ruby C Extension so you can debug your code. The various build configuration
is set up to launch different SketchUp versions. Refer to the project
configuration and make your adjustments as needed:

`SUEX_HelloWorld > Right Click > Configuration Properties > Debugging`

### Xcode 14

Xcode project is set up to build targets all the way back to Ruby 2.0.

## Windows and Runtime DLLs

SketchUp itself builds Ruby with dynamic CRT - using the [`/MD` flag](https://msdn.microsoft.com/en-us/library/2kzt1wy3.aspx).

SU2014 - SU2016 used VS2010 runtime. The SketchUp installer will install the required runtime on the user machine if needed. This mean that if you build your extension with `/MD` with the same CRT you don't have to worry about this.

However, if you built with another CRT you have to ensure yourself that it's installed on the user's machine - which isn't trivial for a Ruby extension unless you bundle an installer with it.

This then poses a challenge when you want to support SU2017 which uses VS2015 runtime and also older versions that uses VS2010 runtimes. Either you need to build your C extensions with different VS compiler versions, or you need to ensure yourself the [runtimes are on the user machine](https://www.microsoft.com/en-us/download/details.aspx?id=48145).

The runtimes libraries will usually be on a user machine, but you might experience some users with brand new machines or when a runtime is brand new that some doesn't.

Incidentally we have upgraded the Ruby version at the same time as we upgraded the compiler version. But that's just by chance.

Because of this you might want to build your extensions with `/MT`. However, the Ruby config files are not set up for that by default. Hence the need to define from extra macros as seen the [TestUp project](https://github.com/SketchUp/testup-2/blob/main/ruby-c-extension/sketchup-taskbarlist/TaskbarProgress/src/RubyUtils/RubyLib.h). This is because there are some differences between `/MD` and `/MT` that would otherwise create compile errors.

Statically linking the CRT in my C extensions means they will be bigger, but you don't have to worry about the user not having the required DLLs.
