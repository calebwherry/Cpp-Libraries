////////////////////////////////////////
////////////////////////////////////////
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
////////////////////////////////////////
////////////////////////////////////////

// Include Guards:
#ifndef MATRIX_H
#define MATRIX_H

// Forward Declared Dependencies:
//

// Local Include Dependencies:
//

// Compiler Include Dependencies:
#include <iostream>
#include <string>
#include <vector>
#include <complex>

// Matrix Namespace:
namespace matrix
{

	// Empty string used for default pad in matrix printing:
	const std::string emptyStr = std::string();

	// Matrix Class:
	template <typename T>
	class Matrix
	{
		private:

			// Main matrix variable:
			std::vector<std::vector<T>> matrix;

			// Number of rows and cols:
			uint32_t numRows;
			uint32_t numCols;

		public:

			//
			// Constructors:
			//

			// Default Constructor:
      Matrix();

			// Copy constructor:
			Matrix(const Matrix<T>& rhs);

			// Custom constructors:
			Matrix(uint32_t _numRows, uint32_t _numCols, const T& initVals = 0);

      // Deconstructor:
      ~Matrix();


			//
			// Display:
			//

			// Print:
      void print(const std::string& pad = emptyStr);


			//
			// Accessors:
			//

			// Size Accessors:
			uint32_t getNumRows() const { return numRows; };
			uint32_t getNumCols() const { return numCols; };


			//
			// Operators:
			//

			// Assignment:
			Matrix<T>& operator=(const Matrix<T>& rhs);

			// Matrix/Matrix:
			//Matrix<T> operator*(const Matrix<T>& rhs);						// Matrix/Matrix Multiplication
			//Matrix<T> operator+(const Matrix<T>& rhs);						// Matrix/Matrix Addition
			//Matrix<T> operator-(const Matrix<T>& rhs);						// Matrix/Matrix Subtraction

			// Matrix/Vector:
			//std::vector<T> operator*(const std::vector<T>& rhs);	// Matrix/Vector Multiplication

			// Matrix/Scalar:
			Matrix<T> operator*(const T& rhs);										// Matrix/Scalar Multiplication
			Matrix<T> operator/(const T& rhs);										// Matrix/Scalar Division
			Matrix<T> operator+(const T& rhs);										// Matrix/Scalar Addition
			Matrix<T> operator-(const T& rhs);										// Matrix/Scalar Subtraction

			// Matrix (unitary):
			//Matrix<T> operator-();																// Unitary Matrix Negative
			//Matrix<T> operator^(const int32_t& power);										// Power function, not sure how to abstract to beyond integers at the moment...

			// Element Access:
			T& operator()(const uint32_t& row, const uint32_t& col);
			const T& operator()(const uint32_t& row, const uint32_t& col) const;

			// Comparison:
			bool operator==(const Matrix<T>& rhs);
			//bool operator~=(const Matrix<T>& rhs); // "Roughly equal to" (within a tolerance), MATLAB style.


			//
			// Operations:
			//

			Matrix<T> transpose();	// Not in-place
			//Matrix<T> conjugate();
			//Matrix<T> complexConjugate();


			//
			// Properties:
			//

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
			//bool isTriangular();
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
		//	Note: Probably not needed but... oh well.
		matrix.resize(0);
  }

	// Copy constructor:
	template <typename T>
	Matrix<T>::Matrix(const Matrix<T>& rhs)
	{
		// Copy everything:
		matrix = rhs.matrix;
		numRows = rhs.getNumRows();
		numCols = rhs.getNumCols();
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
	void Matrix<T>::print(const std::string& pad)
	{
		// Iterate through and print out each element:
		for (const auto& row : matrix)
		{
			// Output pad in front of each row:
			std::cout << pad;

			for (const auto& col : row)
			{
				// Output matrix element:
				const auto& a_ij = col;
				std::cout << a_ij << " ";
			}
			
			// Newline between rows:
			std::cout << std::endl;
		}
	}

	// Operator =
	template <typename T>
	Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
	{
		// If rhs is already this matrix, no reason to continue:
		if( this == &rhs )
		{
			return *this;
		}

		// Get rhs sizes and set them to class vars:
		numRows = rhs.getNumRows();
		numCols = rhs.getNumCols();

		// Resize matrix to new size:
		matrix.resize(numRows);
		for (auto& cols : matrix)
		{
			cols.resize(numCols);
		}

		// Copy data from rhs to this matrix:
		//	Note: As with '==', we can't use an iterator here because we are working on 2 objects, so we resort to normal looping.
		for (uint32_t i=0; i<numRows; ++i)
		{
			for (uint32_t j=0; j<numCols; ++j)
			{
				matrix[i][j] = rhs(i,j);
			}
		}

		// Return new, resized matrix:
		return *this;
	}

	// Operator * (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator*(const T& rhs)
	{
		Matrix result(this->numRows, this->numCols);

		// Iterate through matrix and multiply each element by scalar:
		for (auto& row : matrix)
		{
			for (auto& col : row)
			{
				auto& a_ij = col;
				a_ij = a_ij * rhs;
			}
		}

		return result;
	}

	// Operator / (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator/(const T& rhs)
	{
		Matrix result(this->numRows, this->numCols);

		// Iterate through matrix and divide each element by scalar:
		for (auto& row : matrix)
		{
			for (auto& col : row)
			{
				auto& a_ij = col;
				a_ij = a_ij / rhs;
			}
		}

		return result;
	}

	// Operator + (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator+(const T& rhs)
	{
		Matrix result(this->numRows, this->numCols);

		// Iterate through matrix and add each element by scalar:
		for (auto& row : matrix)
		{
			for (auto& col : row)
			{
				auto& a_ij = col;
				a_ij = a_ij + rhs;
			}
		}

		return result;
	}

	// Operator - (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator-(const T& rhs)
	{
		Matrix result(this->numRows, this->numCols);

		// Iterate through matrix and subtract each element by scalar:
		for (auto& row : matrix)
		{
			for (auto& col : row)
			{
				auto& a_ij = col;
				a_ij = a_ij - rhs;
			}
		}

		return result;
	}

	// Operator ()
	template <typename T>
	T& Matrix<T>::operator()(const uint32_t& row, const uint32_t& col)
	{
		return this->matrix[row][col];
	}

	// Operator () const
	template <typename T>
	const T& Matrix<T>::operator()(const uint32_t& row, const uint32_t& col) const
	{
		return this->matrix[row][col];
	}

	// Operator ==
	template <typename T>
	bool Matrix<T>::operator==(const Matrix<T>& rhs)
	{
		// If dimensions do not match, they are not equal:
		if ( (this->numRows != rhs.getNumRows()) || 
		     (this->numCols != rhs.getNumCols()) 
			 )
		{
			return false;
		}

		// Unfortunately, using iterators doesn't work here since we have to access
		//	both matrices at the same time. So we resort back to normal looping. Access
		//	should not be a problem because of the check at the beginning of this routine:
		for (uint32_t i=0; i < this->numRows; ++i)
		{
			for (uint32_t j=0; j < this->numCols; ++j)
			{
				if ( this->matrix[i][j] != rhs(i,j) )
					return false;
			}
		}

		// If all elements are equal, then the matrices are equal:
		return true;
	}

	// transpose
	template <typename T>
	Matrix<T> Matrix<T>::transpose()
	{
		Matrix matrixTranspose;

		// If matrix is square, create transpose of same size. Otherwise, swap
		//	number of rows and cols.
		if ( this->isSquare() )
		{
			matrixTranspose = Matrix(numRows, numCols);
		}
		else
		{
			matrixTranspose = Matrix(numCols, numRows);
		}

		// Loop through and swap elements:
		for (uint32_t i=0; i < numRows; ++i)
			for (uint32_t j=0; j < numCols; ++j)
				matrixTranspose(j,i) = this->matrix[i][j];

		// Return tranposed matrix:
		return matrixTranspose;
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
		// Iterate over all elements to see if they all have non-zero complex parts:
		for (const auto& row : matrix)
		{
			for (const auto& col : row)
			{
				// If a complex part if found, the matrix is not real:
				const auto& a_ij = col;
				if ( std::imag((std::complex<double>)a_ij) != 0 )
					return false;
			}
		}

		// If none of the elements have complex parts, its real:
		return true;
	}

	// isComplex
	template <typename T>
	bool Matrix<T>::isComplex()
	{
		// If the matrix is strictly real, then we say it is 'not complex'.
		//	To be complex, there has to be at least one element that has an imag part.
		return !( this->isReal() );
	}

	// isSymmetric
	template <typename T>
	bool Matrix<T>::isSymmetric()
	{
		// If the matrix is equal to its transpose, its symmetric:
		if ( *this == this->transpose() )
			return true;

		// If transpose doesn't match, not symmetric:
		return false;
	}

} // matrix namespace

#endif // MATRIX_H
