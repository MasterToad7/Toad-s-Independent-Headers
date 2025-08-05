# Toads-Independent-Headers
A collection of libraries contained within a single header, heavily inspired by [nothings/stb](https://github.com/nothings/stb).

# Usage
To use these "independent headers" start by defining the function definitions, the syntax is typically TIH_HEADERNAME_DEFINITIONS.
For instance, needle would be:
``` #define TIH_NEEDLE_DEFINITIONS ```
Then just simply include the header file in your project.
``` #include <needle.h> ```
> **NOTE**
> Make sure to only define the functions once in your project.

# Header file descriptions
### needle.h
This is a single header version of needle, a universal threading library, the original needle project can be found here: [MasterToad7/Needle](https://github.com/MasterToad7/Needle).

### smpld.h
SMPLDR is a shortened name for simple loader which is a independent header file designed to make loading fies in a project a little less repetitive.

# How to compile examples
Run the following commands
```
mkdir build
cd build
cmake ../
cmake --build .
```
