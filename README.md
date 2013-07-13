Cpp-Libraries
===================

C++ Libraries for Sorting, Searching, & Data Structures.

Why
-------

This is a set of C++ libraries used as a test bed to create new and interesting implementations for standard and non-standard data structures and sorting & searching algorithms. Many people have asked me why I created this since there is a wealth of highly tuned libraries already available in C++ through STL and Boost. My answer to that is simple: to learn. I feel it extremely neccessary for a Software Engineer to understand the underlying mechanics of the devices and constructs that he/she uses. Being able to 100% explain the space/time complexity trade-off of using a tail pointer for a linked list is important to me. And the best way to learn this in software is to implement it. So, that is what I am doing!

I am most interested in some of the more advanced tree structures and graph searching algorithms so those are probably going to get more attention than more basic DXs like lists.

Dependencies
------------

The commands to install these dependencies are for Debian-derived systems. However, you should be able to get them using any ol' package manager.

#### Boost:

Installs Boost headers in /usr/inlcude:

    $ sudo apt-get install libboost-dev

#### Google Test:

For GTest, you will need cmake to create the libs:

    $ sudo apt-get install cmake

Once that is complete, get the GTest src (puts in /usr/src):

    $ sudo apt-get install libgtest-dev

Now we need to go to the src directory, creates the libs, and move then to lib dir:

    $ cd /usr/src/gtest
    $ sudo cmake CMakeLists.txt
    $ sudo make
    $ sudo cp *.a /usr/lib

License
-----------
This project is released under the [MIT License](http://opensource.org/licenses/MIT). See the LICENSE file for more information.
