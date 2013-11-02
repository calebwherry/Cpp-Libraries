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
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <initializer_list>

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

			// Pad for printing out matrix:
			std::string pad;

		public:

			//
			// Constructors:
			//

			// Default Constructor:
      Matrix();

			// Copy constructor:
			Matrix(const Matrix<T>& rhs);

			// Custom constructors:
			Matrix(uint32_t _numRows, 
			       uint32_t _numCols, 
						 const T& initVals = 0,
						 const std::string& _pad = emptyStr
						);

			// Initializer_list constructor:
			Matrix(std::initializer_list<std::initializer_list<T>> _matrix);

      // Deconstructor:
      ~Matrix();


			//
			// Accessors/Modifiers::
			//

			// Matrix accessor:
			std::vector<std::vector<T>> getMatrix() const { return matrix; };
	
			// Size Accessors:
			uint32_t getNumRows() const { return numRows; };
			uint32_t getNumCols() const { return numCols; };

			// Pad Accessor/Modifier:
			std::string getPad() const { return pad; };
			void setPad(const std::string& _pad) { pad = _pad; };


			//
			// Operators:
			//

			// Display:
			template <typename U>
			friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& rhs);

			// Assignment:
			Matrix<T>& operator=(const Matrix<T>& rhs);

			// Matrix/Matrix:
			Matrix<T> operator*(const Matrix<T>& rhs);						// Matrix/Matrix Multiplication
			Matrix<T> operator+(const Matrix<T>& rhs);						// Matrix/Matrix Addition
			Matrix<T> operator-(const Matrix<T>& rhs);						// Matrix/Matrix Subtraction

			// Matrix/Vector:
			//std::vector<T> operator*(const std::vector<T>& rhs);	// Matrix/Vector Multiplication

			// Matrix/Scalar:
			Matrix<T> operator*(const T& rhs);										// Matrix/Scalar Multiplication
			Matrix<T> operator/(const T& rhs);										// Matrix/Scalar Division
			Matrix<T> operator+(const T& rhs);										// Matrix/Scalar Addition
			Matrix<T> operator-(const T& rhs);										// Matrix/Scalar Subtraction

			// Matrix (unitary):
			Matrix<T> operator-();																// Matrix Negative
			Matrix<T> operator^(const uint32_t& power);						// Power function

			// Element Access:
			T& operator()(const uint32_t& row, const uint32_t& col);
			const T& operator()(const uint32_t& row, const uint32_t& col) const;

			// Comparison:
			bool operator==(const Matrix<T>& rhs);


			//
			// Operations:
			//

			Matrix<T> transpose();	// Not in-place
			//Matrix<T> conjugate();
			//Matrix<T> complexConjugate();


			//
			// Boolean Properties:
			//

			bool isSquare();
			bool isReal();
			bool isComplex();
			bool isSymmetric();					//  A = A^T
			bool isSkewSymmetric();			// -A = A^T
			//bool isHermition();					//  A = A^dagger (Complex extension of isSymmetric())
			//bool isSkewHermition();			// -A = A^dagger (Complex extension of isSkewSymmetric())
			//bool isSelfAdjoint();				// Same as isHermition()
			//bool isNormal();						// Real: A*A^T = A^T*A; Complex: A*A^dagger = A^dagger*A
			//bool isOrthogonal();				// A*A^T = A^T*A = I
			//bool isUnitary();						// A*A^dagger = A^dagger*A = I (Complex extension of isOrthogonal())
			//bool isInvertible();				// A*A^-1 = I
			//bool isSingular();					// A has no inverse (det A = 0)
			//bool isDegenerate();				// Same as isSingular()
			//bool isProjection();				// A = A^2
			//bool isInvolutory();				// A = A^-1 (A^2 = I)
			//bool isDiagonal();					// A*I = A
			//bool isTriDiagonal();
			//bool isIdentity();					// A = I
			//bool isTriangular();
			//bool isLowerTriangular();
			//bool isUpperTriangular();

			//
			// Numerical Properties:
			//

			T trace();
			//T sum();
			//T mean();
			//T determinant();

	}; // Matrix


	// Default constructor:
	template <typename T>
  Matrix<T>::Matrix()
        : numRows(0),
				  numCols(0),
					pad("")
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
		matrix = rhs.getMatrix();
		numRows = rhs.getNumRows();
		numCols = rhs.getNumCols();
		pad = rhs.getPad();
	}

	// Custom constructor:
	template <typename T>
	Matrix<T>::Matrix(uint32_t _numRows, uint32_t _numCols, const T& initVal, const std::string& _pad)
				: numRows(_numRows),
					numCols(_numCols),
					pad(_pad)
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

	// Initalizer_list constructor:
	template <typename T>
	Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> _matrix)
				: pad("")
	{
		// Set new row and col sizes:
		numRows = _matrix.size();
		numCols = _matrix.begin()->size();

		// Resize matrix rows:
		matrix.resize(numRows);

		// Resize all matrix columns:
		//	Note: The iterator takes care of the case when numRows is zero so we don't
		//				have to explicitly check for it.
		for (auto& row : matrix)
		{
			row.resize(numCols, 0);
		}

		// Copy values from initializer list to matrix:
		uint32_t i = 0, j = 0;
		for (const auto& rows : _matrix)
		{
			for (const auto& cols : rows)
			{
				auto a_ij = cols;
				matrix[i][j] = a_ij;
				j++;
			}
			i++;
			j = 0;
		}
	
	}

	// Destructor:
	template <typename T>
	Matrix<T>::~Matrix()
	{
		// No dynamic allocation so nothing to do. 
	}

	// Operator <<:
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<T>& rhs)
	{
		// Iterate through and print out each element:
		for (const auto& rows : rhs.getMatrix())
		{
			// Output pad in front of each row:
			os << rhs.getPad();

			for (const auto& cols : rows)
			{
				// Output matrix element:
				auto a_ij = cols;
				os << a_ij << " ";
			}
			
			// Newline between rows:
			os << std::endl;
		}

		return os;
	}

	// Operator = (Matrix)
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

		// Get pad and set to class var:
		pad = rhs.getPad();

		// Resize matrix to new size:
		matrix.resize(numRows);
		for (auto& cols : matrix)
		{
			cols.resize(numCols);
		}

		// Copy data from rhs to this matrix:
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

	// Operator * (Matrix/Matrix)
	template <typename T>
	Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
	{

		// If lhs col count doesn match rhs's row count, can't multiply:
		if ( this->numCols != rhs.getNumRows() )
		{
			throw std::logic_error("Matrices' inner dimensions do not match, can't multiply!");
		}

		// New dimensions and matrix:
		uint32_t rows = this->numRows,
						 cols = rhs.getNumCols();;
		Matrix result(rows, cols);

		// Multiply matrices together:
		for (uint32_t i=0; i<rows; ++i)
		{
			for (uint32_t j=0; j<cols; ++j)
			{
				for (uint32_t k=0; k<rows; ++k)
				{
					result(i,j) += this->matrix[i][j]*rhs(i,j);
				}
			}
		}

		// Return new matrix multiplied matrix:
		return result;
	}

	// Operator + (Matrix/Matrix)
	template <typename T>
	Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
	{

		// If matrices aren't same size, can't add them:
		if ( (this->numRows != rhs.getNumRows()) ||
				 (this->numCols != rhs.getNumCols())
			 )
		{
			throw std::logic_error("Matrices must be same size!");
		}

		Matrix result(this->numRows, this->numCols);

		// Loop through and add all elements:
		for (uint32_t i=0; i<this->numRows; ++i)
		{
			for (uint32_t j=0; j<this->numCols; ++j)
			{
				result(i,j) = matrix[i][j] + rhs(i,j);
			}
		}

		// Return 2 matrices added:
		return result;
	}

	// Operator - (Matrix/Matrix)
	template <typename T>
	Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs)
	{
		return (*this + rhs*(-1));
	}

	// Operator * (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator*(const T& rhs)
	{
		Matrix result(this->numRows, this->numCols);

		// Loop through matrix and multiply each element by scalar:
		for (uint32_t i=0; i<numRows; ++i)
		{
			for (uint32_t j=0; j<numCols; ++j)
			{
				result(i,j) = matrix[i][j] * rhs;
			}
		}

		return result;
	}

	// Operator / (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator/(const T& rhs)
	{
		Matrix result(this->numRows, this->numCols);

		// Loop through matrix and divide each element by scalar:
		for (uint32_t i=0; i<numRows; ++i)
		{
			for (uint32_t j=0; j<numCols; ++j)
			{
				result(i,j) = matrix[i][j] / rhs;
			}
		}

		return result;
	}

	// Operator + (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator+(const T& rhs)
	{
		Matrix result(this->numRows, this->numCols);

		// Loop through matrix and add each element by scalar:
		for (uint32_t i=0; i<numRows; ++i)
		{
			for (uint32_t j=0; j<numCols; ++j)
			{
				result(i,j) = matrix[i][j] + rhs;
			}
		}

		return result;
	}

	// Operator - (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator-(const T& rhs)
	{
		return ( (*this) + (-rhs) );
	}

	// Operator - (Matrix [unitary])
	template <typename T>
	Matrix<T> Matrix<T>::operator-()
	{
		return ( (*this)*(-1) );
	}

	// Operator ^ (Matrix [unitary])
	template <typename T>
	Matrix<T> Matrix<T>::operator^(const uint32_t& rhs)
	{
		// The power function can only be applied to square matrices:
		if ( !this->isSquare() )
		{
			throw std::logic_error("Matrix must be square!");
		}

		Matrix result(numRows, numCols, 0);
		result = *this;

		for (uint32_t i=0; i<rhs; ++i)
		{
			//result *= (*this); TODO: Implement *=
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

		// Loop through and if any elements don't match, the matrices are not equal:
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

	// isSkewSymmetric
	template <typename T>
	bool Matrix<T>::isSkewSymmetric()
	{
		// If the negative of the matrix equals its transpose, its skew-symmetric:
		if ( (*this)*(-1) == this->transpose() )
			return true;

		// If transpose doesn't match, not skew-symmetric:
		return false;
	}

	// Trace
	template <typename T>
	T Matrix<T>::trace()
	{
		// Sum of diagonal values:
		T sum;

		// Loop through the rows and sum the main diagonal
		for (uint32_t i=0; i<numRows; ++i)
			sum += matrix[i][i];
		
		return sum;
	}

} // matrix namespace

#endif // MATRIX_H
