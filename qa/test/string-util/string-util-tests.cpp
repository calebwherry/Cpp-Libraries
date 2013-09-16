/////////////////////////////
//
//  File:
//      \file string-util-tests.cpp
//
//  Description:
//      \brief String Utility Tests
//
//  Author:
//      \author J. Caleb Wherry
//
/////////////////////////////

// Compiler Includes:
#include <iostream>
#include <string>

// Local Includes:
#include "StringUtil.h"

// Test include:
#include <gtest/gtest.h>

// Namespaces:
namespace SU = stringUtil;
using namespace std;

TEST(StringConversion, ConvertPrimitives)
{
    using namespace SU;

    int a = 10924;
    int b = -1;
    double c = 3.1415;
    char d = 'A';

    ASSERT_EQ(toString(a), "10924");

    ASSERT_EQ(toString(b), "-1");

    ASSERT_EQ(toString(c), "3.1415");

    ASSERT_EQ(toString(d), "A");
}
