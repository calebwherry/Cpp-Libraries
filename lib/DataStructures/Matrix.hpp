/////////////////////////////
//
//  File:
//      \file Matrix.hpp
//
//  Description:
//      \brief Matrix: Header & Impl
//
//  Author:
//      \author J. Caleb Wherry
//
/////////////////////////////

// Include Guards:
#ifndef MATRIX_H
#define MATRIX_H

// Forward Declared Dependencies:
//

// Local Include Dependencies:
//

// Compiler Include Dependencies:
#include <iostream>
#include <vector>
#include <complex>

// Matrix Namespace:
namespace matrix
{

	// Matrix Class:
	template <class T>
	class Matrix
	{
		private:

			// Main matrix variable:
			std::vector<std::vector<T>> matrix;

			// Number of rows and cols:
			uint32_t numRows;
			uint32_t numCols;

		public:

			// Default Constructor:
      Matrix();

			// Custom constructors:
			Matrix(uint32_t _numRows, uint32_t _numCols, const T& initVals = 0);

      // Deconstructor:
      ~Matrix();
    
			// Print:
      void print();

			// Operations:
			//

			// Properties:
			bool isSquare();
			bool isReal();
			bool isComplex();
			bool isSymmetric();
			//bool isSkewSymmetrix();
			//bool isHermition();
			//bool isUnitary();					// Complex Case nomenclature
			//bool isNormal();
			//bool isInvertible();
			//bool isSingular();
			//bool isOrthogonal();			// Real Case nomenclature
			//bool isProjection();
			//bool isDiagonal();
			//bool isTriDiagonal();
			//bool isIdentity();
			//bool isLowerTriangular();
			//bool isUpperTriangular();

	}; // Matrix


	// Default constructor:
	template <typename T>
  Matrix<T>::Matrix()
        : numRows(0),
				  numCols(0)
  {
		// Resize matrix to 0:
		matrix.resize(0);
  }

	// Custom constructor:
	template <typename T>
	Matrix<T>::Matrix(uint32_t _numRows, uint32_t _numCols, const T& initVal)
				: numRows(_numRows),
					numCols(_numCols)
	{

		// Resize matrix rows:
		matrix.resize(numRows);

		// Resize all matrix columns:
		//	Note: The iterator takes care of the case when numRows is zero so we don't
		//				have to explicitly check for it.
		for (auto& row : matrix)
		{
			row.resize(numCols, initVal);
		}

	}
	
	// Destructor:
	template <typename T>
	Matrix<T>::~Matrix()
	{
		// No dynamic allocation so nothing to do. 
	}

	// Print matrix:
	template <typename T>
	void Matrix<T>::print()
	{
		// Newline at beginning to get matrix on its own line:
		std::cout << std::endl;

		// Iterate through and print out each element:
		for (const auto& row : matrix)
		{
			for (const auto& col : row)
			{
				const auto& a_ij = col;
				std::cout << a_ij << " ";
			}
			
			// Newline between rows:
			std::cout << std::endl;
		}
	}

	// isSquare
	template <typename T>
	bool Matrix<T>::isSquare()
	{
		return (numRows == numCols) ? true : false;
	}

	// isReal
	template <typename T>
	bool Matrix<T>::isReal()
	{
		return true;
	}

	// isComplex
	template <typename T>
	bool Matrix<T>::isComplex()
	{
		// Iterate over all elements to see if any have non-zero complex parts:
		for (const auto& row : matrix)
		{
			for (const auto& col : row)
			{
				const auto& a_ij = col;
				if ( std::imag((std::complex<double>)a_ij) != 0 )
					return true;
			}
		}

		// If no non-zero complex parts were found, return false:
		return false;
	}

	// isSymmetric
	template <typename T>
	bool Matrix<T>::isSymmetric()
	{
		return true;
	}

} // matrix namespace

#endif // MATRIX_H
