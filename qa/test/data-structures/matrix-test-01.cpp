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

// Matrix class test fixture:
class MatrixTest : public ::testing::Test
{
	protected:

		// Test Objects:
		M::Matrix<double> I, a, a2, a3, b;
		M::Matrix<complex<double>> c, d, e;
		string pad;

		// Called before every test group:
		virtual void SetUp() 
		{
			// Pad:
			pad = "\t";

			// Matrices
			I = { {1, 0, 0},
						{0, 1, 0},
						{0, 0, 1}
					};
			I.setPad(pad);

			a  = M::Matrix<double>(3, 3, 1.0, pad);	// Square, Real
			a2 = M::Matrix<double>(3, 3, 2.0, pad);  // Square, Real
			a3 = M::Matrix<double>(3, 3, 3.0, pad);  // Square, Real
			b  = M::Matrix<double>(3, 4, 0, pad);	// Not square, Real
			c  = M::Matrix<complex<double>>(3, 3, complex<double>(1,1), pad);	// Square, Complex
			d  = M::Matrix<complex<double>>(3, 4, complex<double>(3,3), pad);	// Not square, Complex
			e  = M::Matrix<complex<double>>(4, 4, complex<double>(1,0), pad); // Not square, Real (no imag part)
		}

		// Called after every test group:
		virtual void TearDown() {}
};

TEST_F(MatrixTest, PrintOperator)
{

	// Identity 3x3:
	EXPECT_NO_THROW({
		cout << "Identity: " << endl << I << endl;
	});

	// A:
	EXPECT_NO_THROW({
		cout << "A: " << endl << a << endl;
	});

	// B:
	EXPECT_NO_THROW({
		cout << "B: " << endl << b << endl;;
	});

	// C:
	EXPECT_NO_THROW({
		cout << "C: " << endl << c << endl;
	});

	// D:
	EXPECT_NO_THROW({
		cout << "D: " << endl << d << endl;
	});

	// E:
	EXPECT_NO_THROW({
		cout << "E: " << endl << e << endl;;
	});
	
}

TEST_F(MatrixTest, OperatorElementAccess)
{

	EXPECT_NO_THROW({
		auto temp  = I(0,0);
	});

	EXPECT_NO_THROW({
		auto temp = a(0,0);
	});

	EXPECT_THROW({
		auto temp = I(3,0);
	}, out_of_range);

	EXPECT_THROW({
		auto temp  = I(0,10);
	}, out_of_range);

	EXPECT_THROW({
		auto temp = I(10,0);
	}, out_of_range);

}

TEST_F(MatrixTest, OperatorEqual)
{

	//
	// = and ==
	//

	// I-A:
	EXPECT_FALSE( I == a );
	EXPECT_EQ( I.getNumRows(), a.getNumRows() );
	EXPECT_EQ( I.getNumCols(), a.getNumCols() );

	// A-B:
	EXPECT_FALSE( a == b );
	EXPECT_EQ( a.getNumRows(), b.getNumRows() );
	EXPECT_NE( a.getNumCols(), b.getNumCols() );
	a = b;
	EXPECT_TRUE ( a == b );
	EXPECT_EQ( a.getNumRows(), b.getNumRows() );
	EXPECT_EQ( a.getNumCols(), b.getNumCols() );

	// B-C:
	// Can't do because C is complex and B real. Assignment only works for matrices of same type.
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

TEST_F(MatrixTest, OperatorMultiply)
{

	//
	// *
	//

	EXPECT_TRUE( a == (a*I) );

	// B & I's inner dimensions don't match::
	EXPECT_THROW({
		b = b*I;
	}, logic_error);
}

TEST_F(MatrixTest, OperatorPlus)
{

	//
	// +
	//

	EXPECT_NO_THROW({
		a = a + a2;
	});
	EXPECT_TRUE( a == a3 );

	EXPECT_THROW({
		a = a + b;
	}, logic_error);

}

TEST_F(MatrixTest, Properties)
{

	// Identity:
	EXPECT_TRUE ( I.isSquare() );
	EXPECT_TRUE ( I.isReal() );
	EXPECT_FALSE( I.isComplex() );
	EXPECT_TRUE ( I.isSymmetric() );
	EXPECT_FALSE( I.isSkewSymmetric() );
	EXPECT_TRUE ( I.isHermitian() );
	EXPECT_FALSE( I.isSkewHermitian() );
	EXPECT_TRUE ( I.isProjection() );

	// A:
	EXPECT_TRUE ( a.isSquare() );
	EXPECT_TRUE ( a.isReal() );
	EXPECT_FALSE( a.isComplex() );
	EXPECT_TRUE ( a.isSymmetric() );
	EXPECT_FALSE( a.isSkewSymmetric() );
	EXPECT_TRUE ( a.isHermitian() );
	EXPECT_FALSE( a.isSkewHermitian() );
	EXPECT_FALSE( a.isProjection() );

	// B:
	EXPECT_FALSE( b.isSquare() );
	EXPECT_TRUE ( b.isReal() );
	EXPECT_FALSE( b.isComplex() );
	EXPECT_FALSE( b.isSymmetric() );
	EXPECT_FALSE( b.isSkewSymmetric() );
	EXPECT_FALSE( b.isHermitian() );
	EXPECT_FALSE( b.isSkewHermitian() );
	EXPECT_FALSE( b.isProjection() );

	// C:
	EXPECT_TRUE ( c.isSquare() );
	EXPECT_FALSE( c.isReal() );
	EXPECT_TRUE ( c.isComplex() );
	EXPECT_TRUE ( c.isSymmetric() );
	EXPECT_FALSE( c.isSkewSymmetric() );
	EXPECT_FALSE( c.isHermitian() );
	EXPECT_FALSE( c.isSkewHermitian() );
	EXPECT_FALSE( c.isProjection() );

	// D:
	EXPECT_FALSE( d.isSquare() );
	EXPECT_FALSE( d.isReal() );
	EXPECT_TRUE ( d.isComplex() );
	EXPECT_FALSE( d.isSymmetric() );
	EXPECT_FALSE( d.isSkewSymmetric() );
	EXPECT_FALSE( d.isHermitian() );
	EXPECT_FALSE( d.isSkewHermitian() );
	EXPECT_FALSE( d.isProjection() );

	// E:
	EXPECT_TRUE ( e.isSquare() );
	EXPECT_TRUE ( e.isReal() );
	EXPECT_FALSE( e.isComplex() );
	EXPECT_TRUE ( e.isSymmetric() );
	EXPECT_FALSE( e.isSkewSymmetric() );
	EXPECT_TRUE ( e.isHermitian() );
	EXPECT_FALSE( e.isSkewHermitian() );
	EXPECT_FALSE( e.isProjection() );

}

} // anon namepace 
