# ZBiasEFT

Installation
---------------------

This software is dependent only on one library:
https://github.com/jwgcarlson/Copter

Install that library wherever is convenient, 
and point your linker to that directory.
If you install it in a default library location
(e.g. found in `LD_LIBRARY_PATH`), you need only
the `-lcopter` flag.

Configure Makefile to use a C++ compiler that 
implements the C++11 standard (g++ 4.8.1 and later)

Then compile using `make`.

Usage
---------------------

After compilation, calling `/.ZBiasEFT` will begin 
the computation, and continuously store the results 
in a file called `integrals_noresum.txt`

### TODO: 
add options

