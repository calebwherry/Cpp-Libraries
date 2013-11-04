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

// Local Includes:
#include "Matrix.hpp"

// Compiler includes:
//#include <vector>

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
		M::Matrix<double> I3, real_1, real_1b, real_1c, real_2, real_3;
		M::Matrix<complex<double>> complex_1, complex_2, complex_3;

		// Print pad
		string pad;

		// Called before every test group:
		virtual void SetUp() 
		{

			// Pad:
			pad = "\t";

			// Matrices
			I3 = { {1, 0, 0},
						 {0, 1, 0},
						 {0, 0, 1}
					  };
			I3.setPad(pad);

			real_1  = M::Matrix<double>(3, 3, 1.0, pad);
			real_1b = M::Matrix<double>(3, 3, 2.0, pad);
			real_1c = M::Matrix<double>(3, 3, 3.0, pad);
			real_2  = M::Matrix<double>(3, 4, 0, pad);
			complex_1  = M::Matrix<complex<double>>(3, 3, complex<double>(1,1), pad);
			complex_2  = M::Matrix<complex<double>>(3, 4, complex<double>(3,3), pad);
			complex_3  = M::Matrix<complex<double>>(4, 4, complex<double>(1,0), pad);

		}

		// Called after every test group:
		virtual void TearDown() {}
};


TEST_F(MatrixTest, OperatorDisplay)
{

	EXPECT_NO_THROW({
		cout << "Identity 3x3: " << endl << I3 << endl;
	});

	EXPECT_NO_THROW({
		cout << "Identity 4x4: " << endl << M::makeIdentity<uint32_t>(4, "\t") << endl;
	});

	EXPECT_NO_THROW({
		cout << "Real 3x3 - Ones: " << endl << real_1 << endl;
	});

	EXPECT_NO_THROW({
		cout << "Real 3x4 - Zeroes: " << endl << real_2 << endl;
	});

	EXPECT_NO_THROW({
		cout << "Complex 3x3 - (1,1): " << endl << complex_1 << endl;
	});

	EXPECT_NO_THROW({
		cout << "Complex 3x4 - (3,3): " << endl << complex_2 << endl;
	});

	EXPECT_NO_THROW({
		cout << "Complex 4x4 - (1,0): " << endl << complex_3 << endl;
	});
	
}


TEST_F(MatrixTest, OperatorElementAccess)
{

	EXPECT_NO_THROW({
		auto temp  = I3(0,0);
	});

	EXPECT_NO_THROW({
		auto temp = real_1(0,0);
	});

	EXPECT_THROW({
		auto temp = I3(3,0);
	}, out_of_range);

	EXPECT_THROW({
		auto temp  = I3(0,10);
	}, out_of_range);

	EXPECT_THROW({
		auto temp = I3(10,0);
	}, out_of_range);

}


TEST_F(MatrixTest, OperatorEqual)
{

	EXPECT_FALSE( I3 == real_1 );
	EXPECT_TRUE (real_1 == real_1 );

	EXPECT_FALSE( real_1 == real_2 );
	real_1 = real_2;
	EXPECT_TRUE ( real_1 == real_2 );

	EXPECT_FALSE( complex_1 == complex_2 );
	complex_1 = complex_2;
	EXPECT_TRUE ( complex_1 == complex_2 );

	EXPECT_FALSE( complex_2 == complex_3 );
	complex_2 = complex_3;
	EXPECT_TRUE ( complex_2 == complex_3 );

}


TEST_F(MatrixTest, OperatorDivide_Scalar)
{
	// TODO
}


TEST_F(MatrixTest, OperatorMultiply_Matrix)
{

	EXPECT_TRUE( real_1 == (real_1*I3) );

	// B & I's inner dimensions don't match::
	EXPECT_THROW({
		real_2 = real_2*I3;
	}, logic_error);
}


TEST_F(MatrixTest, OperatorMultiply_Vector)
{
	// TODO
}


TEST_F(MatrixTest, OperatorMultiply_Scalar)
{
	// TODO
}


TEST_F(MatrixTest, OperatorPlus_Matrix)
{

	// Same size:
	EXPECT_NO_THROW({
		real_1 = real_1 + real_1b;
	});
	EXPECT_TRUE( real_1 == real_1c );

	// Not same size:
	EXPECT_THROW({
		real_1 = real_1 + real_2;
	}, logic_error);

}


TEST_F(MatrixTest, OperatorPlus_Scalar)
{
	// TODO
}


TEST_F(MatrixTest, OperatorMinus_Matrix)
{
	// TODO
}


TEST_F(MatrixTest, OperatorMinux_Scalar)
{
	// TODO
}


TEST_F(MatrixTest, Accessors_Size)
{

	EXPECT_EQ( real_1.getNumRows(), 3);
	EXPECT_NE( real_1.getNumRows(), 4);
	EXPECT_EQ( real_1.getNumRows(), I3.getNumRows() );
	EXPECT_EQ( real_2.getNumCols(), 4);
	EXPECT_NE( real_2.getNumCols(), I3.getNumCols() );

}


TEST_F(MatrixTest, Modifiers_Size)
{
	// TODO
}
 

TEST_F(MatrixTest, Properties_Numerical)
{
	// TODO
}


TEST_F(MatrixTest, Properties_Boolean)
{

	EXPECT_TRUE ( I3.isSquare() );
	EXPECT_TRUE ( I3.isReal() );
	EXPECT_FALSE( I3.isComplex() );
	EXPECT_TRUE ( I3.isSymmetric() );
	EXPECT_FALSE( I3.isSkewSymmetric() );
	EXPECT_TRUE ( I3.isHermitian() );
	EXPECT_FALSE( I3.isSkewHermitian() );
	EXPECT_TRUE ( I3.isProjection() );
	EXPECT_TRUE ( I3.commutesWith(I3) );

	EXPECT_TRUE ( real_1.isSquare() );
	EXPECT_TRUE ( real_1.isReal() );
	EXPECT_FALSE( real_1.isComplex() );
	EXPECT_TRUE ( real_1.isSymmetric() );
	EXPECT_FALSE( real_1.isSkewSymmetric() );
	EXPECT_TRUE ( real_1.isHermitian() );
	EXPECT_FALSE( real_1.isSkewHermitian() );
	EXPECT_FALSE( real_1.isProjection() );
	EXPECT_TRUE ( real_1.commutesWith(real_1) );

	EXPECT_FALSE( real_2.isSquare() );
	EXPECT_TRUE ( real_2.isReal() );
	EXPECT_FALSE( real_2.isComplex() );
	EXPECT_FALSE( real_2.isSymmetric() );
	EXPECT_FALSE( real_2.isSkewSymmetric() );
	EXPECT_FALSE( real_2.isHermitian() );
	EXPECT_FALSE( real_2.isSkewHermitian() );
	EXPECT_FALSE( real_2.isProjection() );
	EXPECT_FALSE( real_2.commutesWith(real_2) );

	EXPECT_TRUE ( complex_1.isSquare() );
	EXPECT_FALSE( complex_1.isReal() );
	EXPECT_TRUE ( complex_1.isComplex() );
	EXPECT_TRUE ( complex_1.isSymmetric() );
	EXPECT_FALSE( complex_1.isSkewSymmetric() );
	EXPECT_FALSE( complex_1.isHermitian() );
	EXPECT_FALSE( complex_1.isSkewHermitian() );
	EXPECT_FALSE( complex_1.isProjection() );
	EXPECT_TRUE ( complex_1.commutesWith(complex_1) );

	EXPECT_FALSE( complex_2.isSquare() );
	EXPECT_FALSE( complex_2.isReal() );
	EXPECT_TRUE ( complex_2.isComplex() );
	EXPECT_FALSE( complex_2.isSymmetric() );
	EXPECT_FALSE( complex_2.isSkewSymmetric() );
	EXPECT_FALSE( complex_2.isHermitian() );
	EXPECT_FALSE( complex_2.isSkewHermitian() );
	EXPECT_FALSE( complex_2.isProjection() );
	EXPECT_FALSE( complex_2.commutesWith(complex_2) );

	EXPECT_TRUE ( complex_3.isSquare() );
	EXPECT_TRUE ( complex_3.isReal() );
	EXPECT_FALSE( complex_3.isComplex() );
	EXPECT_TRUE ( complex_3.isSymmetric() );
	EXPECT_FALSE( complex_3.isSkewSymmetric() );
	EXPECT_TRUE ( complex_3.isHermitian() );
	EXPECT_FALSE( complex_3.isSkewHermitian() );
	EXPECT_FALSE( complex_3.isProjection() );
	EXPECT_TRUE ( complex_3.commutesWith(complex_3) );

}

} // anon namepace 
