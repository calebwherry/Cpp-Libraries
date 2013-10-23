////////////////////////////////////////
////////////////////////////////////////
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
////////////////////////////////////////
////////////////////////////////////////

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

// This doesn't currently work for some reason?
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

	// Matrices redefined here since fixture is not currently working...

	// Real matrices:
	M::Matrix<double> a(3,3,1.0),
										b(3,4,0);

	// Complex matrices:
	M::Matrix<complex<double>> c(3,3,complex<double>(1,1)),
														 d(3,4,complex<double>(3,3)),
														 e(4,4,complex<double>(1,0)); // No imaginary component

	cout << "A: " << endl;
	a.print("\t");
	cout << "B: " << endl;
	b.print("\t");
	cout << "B transpose: " <<endl;
	M::Matrix<double> temp = b.transpose();
	temp.print();
	cout << "C: " << endl;
	c.print("\t");
	cout << "D: " << endl;
	d.print("\t");
	cout << "E: " << endl;
	e.print("\t");

	// A:
	ASSERT_TRUE ( a.isSquare() );
	ASSERT_TRUE ( a.isReal() );
	ASSERT_FALSE( a.isComplex() );
	ASSERT_TRUE ( a.isSymmetric() );

	// B:
	ASSERT_FALSE( b.isSquare() );
	ASSERT_TRUE ( b.isReal() );
	ASSERT_FALSE( b.isComplex() );
	ASSERT_FALSE( b.isSymmetric() );

	// C:
	ASSERT_TRUE ( c.isSquare() );
	ASSERT_FALSE( c.isReal() );
	ASSERT_TRUE ( c.isComplex() );
	ASSERT_TRUE ( c.isSymmetric() );

	// D:
	ASSERT_FALSE( d.isSquare() );
	ASSERT_FALSE( d.isReal() );
	ASSERT_TRUE ( d.isComplex() );
	ASSERT_TRUE ( d.isSymmetric() );

	// E:
	ASSERT_TRUE ( e.isSquare() );
	ASSERT_FALSE( e.isReal() );
	ASSERT_TRUE ( e.isComplex() );
	ASSERT_TRUE ( e.isSymmetric() );

}

} // anon namepace 
