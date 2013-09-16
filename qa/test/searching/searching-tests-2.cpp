/////////////////////////////
//
//  File:
//      \file searching_tests.cpp
//
//  Description:
//      \brief Searching Tests
//
//  Author:
//      \author J. Caleb Wherry
//
/////////////////////////////

// Compiler Includes:
//

// Local Includes:
#include "SearchUtil.h"

// Test Includes:
#include <gtest/gtest.h>

// Namespaces:
namespace SU = searchUtil;
using namespace SU;

TEST(SimpleTest, Exists)
{
    ASSERT_TRUE(exists());
}
