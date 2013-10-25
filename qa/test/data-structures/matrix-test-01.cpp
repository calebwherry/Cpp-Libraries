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
class MatrixTest : public ::testing::Test
{
	protected:

		// Test Objects:
		M::Matrix<double> a, b, b_transpose;
		M::Matrix<complex<double>> c, d, e;

		virtual void SetUp() 
		{
			a = M::Matrix<double>(3, 3, 1.0);	// Square, Real
			b = M::Matrix<double>(3, 4, 0);	// Not square, Real
			c = M::Matrix<complex<double>>(3, 3, complex<double>(1,1));	// Square, Complex
			d = M::Matrix<complex<double>>(3, 4, complex<double>(3,3));	// Not square, Complex
			e = M::Matrix<complex<double>>(4, 4, complex<double>(1,0)); // Not square, Real (no imag part)
		}

		virtual void TearDown() {}
};

TEST_F(MatrixTest, Print)
{

	// A:
	cout << "A: " << endl;
	EXPECT_NO_THROW({
		a.print("\t");
	});

	// B:
	cout << "B: " << endl;
	EXPECT_NO_THROW({
		b.print("\t");
	});

	// C:
	cout << "C: " << endl;
	EXPECT_NO_THROW({
		c.print("\t");
	});

	// D:
	cout << "D: " << endl;
	EXPECT_NO_THROW({
		d.print("\t");
	});

	// E:
	cout << "E: " << endl;
	EXPECT_NO_THROW({
		e.print("\t");
	});
	
}

TEST_F(MatrixTest, Operators)
{

	//
	// =
	//

	// A-B:
	EXPECT_FALSE( a == b );
	EXPECT_EQ( a.getNumRows(), b.getNumRows() );
	EXPECT_NE( a.getNumCols(), b.getNumCols() );
	a = b;
	EXPECT_TRUE ( a == b );
	EXPECT_EQ( a.getNumRows(), b.getNumRows() );
	EXPECT_EQ( a.getNumCols(), b.getNumCols() );

	// B-C:
	// Can't do right now because C is complex and B real. Assignment only works for matrices of same type.
	/*
	EXPECT_FALSE( b == c );
	EXPECT_EQ( b.getNumRows(), c.getNumRows() );
	EXPECT_NE( b.getNumCols(), c.getNumCols() );
	b = c;
	EXPECT_TRUE ( b == c );
	EXPECT_EQ( b.getNumRows(), c.getNumRows() );
	EXPECT_EQ( b.getNumCols(), c.getNumCols() );
	*/

	// C-D:
	EXPECT_FALSE( c == d );
	EXPECT_EQ( c.getNumRows(), d.getNumRows() );
	EXPECT_NE( c.getNumCols(), d.getNumCols() );
	c = d;
	EXPECT_TRUE ( c == d );
	EXPECT_EQ( c.getNumRows(), d.getNumRows() );
	EXPECT_EQ( c.getNumCols(), d.getNumCols() );

	// D-E:
	EXPECT_FALSE( d == e );
	EXPECT_NE( d.getNumRows(), e.getNumRows() );
	EXPECT_EQ( d.getNumCols(), e.getNumCols() );
	d = e;
	EXPECT_TRUE ( d == e );
	EXPECT_EQ( d.getNumRows(), e.getNumRows() );
	EXPECT_EQ( d.getNumCols(), e.getNumCols() );

}

TEST_F(MatrixTest, Properties)
{

	// A:
	EXPECT_TRUE ( a.isSquare() );
	EXPECT_TRUE ( a.isReal() );
	EXPECT_FALSE( a.isComplex() );
	EXPECT_TRUE ( a.isSymmetric() );

	// B:
	EXPECT_FALSE( b.isSquare() );
	EXPECT_TRUE ( b.isReal() );
	EXPECT_FALSE( b.isComplex() );
	EXPECT_FALSE( b.isSymmetric() );

	// C:
	EXPECT_TRUE ( c.isSquare() );
	EXPECT_FALSE( c.isReal() );
	EXPECT_TRUE ( c.isComplex() );
	EXPECT_TRUE ( c.isSymmetric() );

	// D:
	EXPECT_FALSE( d.isSquare() );
	EXPECT_FALSE( d.isReal() );
	EXPECT_TRUE ( d.isComplex() );
	EXPECT_FALSE( d.isSymmetric() );

	// E:
	EXPECT_TRUE ( e.isSquare() );
	EXPECT_TRUE ( e.isReal() );
	EXPECT_FALSE( e.isComplex() );
	EXPECT_TRUE ( e.isSymmetric() );

}

} // anon namepace 
