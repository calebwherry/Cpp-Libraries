/////////////////////////////
//
//  File:
//      \file matrix-tests-01.cpp
//
//  Description:
//      \brief Matrix Tests
//
//  Author:
//      \author J. Caleb Wherry
//
/////////////////////////////

// Compiler Includes:
//

// Local Includes:
#include "Matrix.hpp"

// Test Includes:
#include <gtest/gtest.h>

// Namespaces:
namespace M = matrix;
//using namespace M;
using namespace std;

// Anonymous namespace:
namespace
{

class Matrix_Properties : public ::testing::Test
{
	protected:
		Matrix_Properties() {};
		virtual ~Matrix_Properties() {};

		virtual void SetUp()
		{
			// Real matrices:
			M::Matrix<double> a(3,3,1.0),
												b(3,4,0);

			// Complex matrices:
			M::Matrix<complex<double>> c(3,3,complex<double>(1,1));
		}

		virtual void TearDown() {};
};

TEST_F(Matrix_Properties, Properties)
{

	// Real matrices:
	M::Matrix<double> a(3,3,1.0),
										b(3,4,0);

	// Complex matrices:
	M::Matrix<complex<double>> c(3,3,complex<double>(1,1));

	cout << "A: " << endl;
	a.print();
	cout << "B: " << endl;
	b.print();
	cout << "C: " << endl;
	c.print();

	ASSERT_TRUE( a.isSquare() );
	ASSERT_TRUE( a.isReal() );
	ASSERT_FALSE( a.isComplex() );
	ASSERT_TRUE( a.isSymmetric() );
}

} // anon namepace 
