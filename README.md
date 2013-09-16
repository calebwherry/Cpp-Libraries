# Cpp-Libraries

C++ Libraries for an assortment of different projects including but not limited to: Data Strauctures, Searching & Sorting Algorithms, and Math & String Utilities. 

## Why

This is a set of C++ libraries used as a test bed to create new and interesting implementations for standard and non-standard data structures, sorting & searching algorithms, and math utilties (among other things). Many people have asked me why I created this since there is a wealth of highly tuned libraries already available in C++ through STL, Boost, the GSL. My answer to that is simple: to learn. I feel it extremely neccessary for a Software Engineer to understand the underlying mechanics of the devices and constructs that he/she uses. Being able to 100% explain the space/time complexity trade-off of performing matrix multiplication on sparse and non-sparse data is important to me. And the best way to learn this in software is to implement it. So, that is what I am doing!

I am most interested in some of the more advanced tree structures, graph searching algorithms, and mathematical utilities for matrices so those are probably going to get more attention than more basic constructs like lists and sorting.

## Dependencies

__Important Note:__ We HAVE NOT included `sudo` on every command here since it sort of takes away from what we are going for. Most of these commands stand-alone will need `sudo` to run so we are just going to leave it off for brevity. Pleae add it in as needed.

### Debian-based Systems

Let us first get the system's package details up-to-date:

    $ apt-get update
    
#### Build Tools:

Installs all the goodies that are neccessary for development such as gcc and g++. You are more than welcome to install them individually but as a catch-all, we have included them all:

    $ apt-get install build-essentials

#### Boost:

Installs Boost headers in /usr/include:

    $ apt-get install libboost-dev

#### GNU Scientific Library

    $ apt-get install gsl-bin libgsl0-dev

#### Google Mock:

    $ apt-get install google-mock

#### Google Test:

For GTest, you will need cmake to create the libs:

    $ apt-get install cmake

Once that is complete, get the GTest src (puts in /usr/src):

    $ apt-get install libgtest-dev

Now we need to go to the src directory, create the libs, and move them to the lib directory:

    $ cd /usr/src/gtest
    $ cmake CMakeLists.txt
    $ make
    $ cp *.a /usr/lib

### RedHat-based Systems

This example was done on a box running Amazon EC2 Linux, so the package names may be *slightly* different on a different rpm-based distro.

#### G++:
    $ yum install gcc-c++

#### Boost:

Installs Boost headers in /usr/include:

    $ yum install boost boost-devel

#### GNU Scientific Library

    $ yum install gsl dsl-devel

#### Google Test:

    $ yum install gtest gtest-devel

### MAC OS X Systems

We first recommend using [Homebrew](http://brew.sh/) as your package manager, it simplifies many steps in getting at these libraries. Go to the link provided and follow the instructions for how to get it on our system.

#### Boost

Coming soon...

#### GNU Scientific Library

Coming soon...

#### Google Mock

Coming soon...

#### Google Test

Coming soon...

## Install

The easiest way to get the source is by cloning this git repo:

    $ git clone git@github.com:calebwherry/Cpp-Libraries.git
    
Or, if you do not have git installed, you can use curl and untar the tarball inline:

    $ curl -L http://github.com/calebwherry/Cpp-Libraries/tarball/HEAD | tar zx
    
You can also get a specific release with curl like so:

    $ curl -L http://github.com/calebwherry/Cpp-Libraries/tarball/v0.0.0-alpha | tar zx
    
And if you don't have either git _or_ curl, you can use wget:

    $ wget http://github.com/calebwherry/Cpp-Libraries/tarball/HEAD -O - | tar zx

After using one of the 3 above methods, CD into the new directory and run `make` and `make install`:

    $ make
    $ make install

## License
This project is released under the [MIT License](http://opensource.org/licenses/MIT). See the LICENSE file for more information.
