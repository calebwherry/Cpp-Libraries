Cpp-Libraries
===================

C++ Libraries for an assortment of different projects including but not limited to: Data Strauctures, Searching & Sorting Algorithms, and Math & String Utilities. 

Why
-------

This is a set of C++ libraries used as a test bed to create new and interesting implementations for standard and non-standard data structures, sorting & searching algorithms, and math utilties (among other things). Many people have asked me why I created this since there is a wealth of highly tuned libraries already available in C++ through STL, Boost, the GSL. My answer to that is simple: to learn. I feel it extremely neccessary for a Software Engineer to understand the underlying mechanics of the devices and constructs that he/she uses. Being able to 100% explain the space/time complexity trade-off of performing matrix multiplication on sparse and non-sparse data is important to me. And the best way to learn this in software is to implement it. So, that is what I am doing!

I am most interested in some of the more advanced tree structures, graph searching algorithms, and mathematical utilities for matrices so those are probably going to get more attention than more basic constructs like lists and sorting.

Dependencies
------------

## Debian-based systems
The commands to install these dependencies are for Debian-based systems. However, you should be able to get them using any ol' package manager.

#### Boost:

Installs Boost headers in /usr/include:

    $ sudo apt-get install libboost-dev

#### GNU Scientific Library

    $ sudo apt-get install gsl-bin libgsl0-dev

#### Google Mock:

    $ sudo apt-get install google-mock

#### Google Test:

For GTest, you will need cmake to create the libs:

    $ sudo apt-get install cmake

Once that is complete, get the GTest src (puts in /usr/src):

    $ sudo apt-get install libgtest-dev

Now we need to go to the src directory, create the libs, and move them to the lib directory:

    $ cd /usr/src/gtest
    $ sudo cmake CMakeLists.txt
    $ sudo make
    $ sudo cp *.a /usr/lib

## RedHat-based systems
This example was done on a box running Amazon EC2 Linux, so the package names may be *slightly* different on a different rpm-based distro.

#### G++:
    $ sudo yum install gcc-c++

#### Boost:
Installs Boost headers in /usr/include:

    $ sudo yum install boost boost-devel

#### GNU Scientific Library

    $ sudo yum install gsl dsl-devel

#### Google Test:

    $ sudo yum install gtest gtest-devel

Install
-----------
The easiest way to get the source is by cloning this git repo:

    $ git clone git@github.com:calebwherry/Cpp-Libraries.git

CD into the new directory and run make:

    $ cd Cpp-Libraries
    $ make

License
-----------
This project is released under the [MIT License](http://opensource.org/licenses/MIT). See the LICENSE file for more information.
