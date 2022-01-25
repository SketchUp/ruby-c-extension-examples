# macOS Notes

## Useful commands

### Check the architecture of a binary

```
$ file SUEX_HelloWorld.bundle 
SUEX_HelloWorld.bundle: Mach-O universal binary with 2 architectures: [x86_64:Mach-O 64-bit bundle x86_64] [arm64:Mach-O 64-bit bundle arm64]
SUEX_HelloWorld.bundle (for architecture x86_64):	Mach-O 64-bit bundle x86_64
SUEX_HelloWorld.bundle (for architecture arm64):	Mach-O 64-bit bundle arm64
```

### Check the deployment target

It appear that x86_64 and arm64 binaries doesn't report the same way.

```
$ otool -arch x86_64 -l SUEX_HelloWorld.bundle | grep -A 5 LC_VERSION_MIN_MACOSX
      cmd LC_VERSION_MIN_MACOSX
  cmdsize 16
  version 10.13
      sdk 11.3
Load command 8
      cmd LC_SOURCE_VERSION
```

```
$ otool -arch arm64 -l SUEX_HelloWorld.bundle | grep -A 5 LC_BUILD_VERSION
      cmd LC_BUILD_VERSION
  cmdsize 32
 platform 1
    minos 11.0
      sdk 11.3
   ntools 1
```
