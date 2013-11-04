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

/// matrix Namespace
namespace matrix
{

	/// Empty string used for default pad in matrix printing
	const std::string emptyStr = std::string();

	/// Matrix Class
	template <typename T>
	class Matrix
	{
		private:

			// Matrix
			std::vector<std::vector<T>> matrix;		///< Matrix

			// Size
			uint32_t numRows;		///< Number of rows
			uint32_t numCols;		///< Number of columns

			// Printing Pad:
			std::string pad;		///< Pad used when printing matrix

		public:

			//
			// Constructors:
			//

			/// Default Constructor
      Matrix();

			/// Copy Constructor
			Matrix (
				const Matrix<T>& rhs		///< Matrix to copy from.
			);

			/// Custom Constructor
			Matrix (
				uint32_t _numRows,										///< Number of rows new matrix will have.
			  uint32_t _numCols,										///< Number of columns new matrix will have.
				const T& initVals = 0,								///< Initial value of all elements of new matrix.
				const std::string& _pad = emptyStr		///< Printing pad.
			);

			/// Initializer_list Constructor
			Matrix (
				std::initializer_list<std::initializer_list<T>> _matrix		///< Initial values list.
			);

      /// Deconstructor
      ~Matrix();


			//
			// Accessors/Modifiers:
			//

			/// Matrix Accessor
			std::vector<std::vector<T>> getMatrix() const { return matrix; };
	
			// Size Accessors
			uint32_t getNumRows() const { return numRows; };		///< Row accessor
			uint32_t getNumCols() const { return numCols; };		///< Columns accessor

			// Pad Accessor/Modifier
			std::string getPad() const { return pad; };							///< Pad accessor
			void setPad(const std::string& _pad) { pad = _pad; };		///< Pad modifier


			//
			// Operators:
			//

			/// Display
			template <typename U>
			friend std::ostream& operator<< (
				std::ostream& os,									///< Output stream
				const Matrix<T>& rhs							///< Matrix to output
			);

			/// Assignment
			Matrix<T>& operator= (
				const Matrix<T>& rhs		///< Matrix to assign
			);

			// Matrix/Matrix
			Matrix<T> operator*(const Matrix<T>& rhs) const;			///< Matrix/Matrix Multiplication
			Matrix<T> operator+(const Matrix<T>& rhs) const;			///< Matrix/Matrix Addition
			Matrix<T> operator-(const Matrix<T>& rhs) const;			///< Matrix/Matrix Subtraction

			// Matrix/Vector
			//std::vector<T> operator*(const std::vector<T>& rhs) const;	///< Matrix/Vector Multiplication

			// Matrix/Scalar
			Matrix<T> operator*(const T& rhs) const;							///< Matrix/Scalar Multiplication
			Matrix<T> operator/(const T& rhs) const;							///< Matrix/Scalar Division
			Matrix<T> operator+(const T& rhs) const;							///< Matrix/Scalar Addition
			Matrix<T> operator-(const T& rhs) const;							///< Matrix/Scalar Subtraction

			/// Matrix (unitary)
			Matrix<T> operator-() const;													///< Matrix Negative
			Matrix<T> operator^(const uint32_t& power) const;			///< Power function

			/// Element Access
			T& operator()(const uint32_t& row, const uint32_t& col);
			const T& operator()(const uint32_t& row, const uint32_t& col) const;

			/// Comparison
			bool operator==(const Matrix<T>& rhs) const;


			//
			// Operations:
			//

			Matrix<T> transpose() const;			// Not in-place
			Matrix<T> complexConjugate() const;
			Matrix<T> conjugateTranspose() const;
			//Matrix<T> inverse() const;


			//
			// Boolean Properties:
			//

			bool isSquare() const;						///< Is matrix square?
			bool isReal() const;							///< Are all elements real?
			bool isComplex() const;						///< Do any elements have imaginary parts?
			bool isSymmetric() const;					///<  A = A^T ?
			bool isSkewSymmetric() const;			///< -A = A^T ?
			bool isHermitian() const;					///<  A = A^dagger (Complex extension of isSymmetric()) ?
			bool isSelfAdjoint() const;       ///<  Same as isHermitian() 
			bool isSkewHermitian() const;			///< -A = A^dagger (Complex extension of isSkewSymmetric())
			bool isNormal() const;						///< Real: A*A^T = A^T*A; Complex: A*A^dagger = A^dagger*A
			bool isOrthogonal() const;				///< A*A^T = A^T*A = I
			//bool isUnitary() const;						///< A*A^dagger = A^dagger*A = I (Complex extension of isOrthogonal())
			//bool isInvertible() const;				///< A*A^-1 = I
			//bool isSingular() const;					///< A has no inverse (det A = 0)
			//bool isDegenerate() const;				///< Same as isSingular()
			bool isProjection() const;				///< A = A^2
			//bool isInvolutory() const;				///< A = A^-1 (A^2 = I)
			//bool isDiagonal() const;					///< Are all elemnets zero except those on diagonal?
			//bool isTriDiagonal() const;
			//bool isIdentity() const;					///< A = I
			//bool isTriangular() const;
			//bool isLowerTriangular() const;
			//bool isUpperTriangular() const;
			bool commutesWith(const Matrix<T>& rhs) const;

			//
			// Numerical Properties:
			//

			T trace() const;									///< Sum of diagonal elements
			T sum() const;										///< Sum of all elements
			//T mean() const;
			//T determinant() const;

	}; // Matrix


	/// Make indentity matrix with proper dimesion
	template <typename T>
	Matrix<T> makeIdentity(const uint32_t& dimension, const std::string& _pad = emptyStr)
	{
		Matrix<T> result(dimension, dimension, 0, _pad);

		for (uint32_t i=0; i<dimension; ++i)
		{
			result(i,i) = 1;
		}

		// Return identity matrix:
		return result;
	}


	//
	// Template Implementation
	//


	// Default constructor
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

	// Copy constructor
	template <typename T>
	Matrix<T>::Matrix(const Matrix<T>& rhs)
	{
		// Copy everything:
		matrix = rhs.getMatrix();
		numRows = rhs.getNumRows();
		numCols = rhs.getNumCols();
		pad = rhs.getPad();
	}

	// Custom constructor
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

	// Initalizer_list constructor
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

	// Destructor
	template <typename T>
	Matrix<T>::~Matrix()
	{
		// No dynamic allocation so nothing to do. 
	}

	// Operator <<
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
	Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) const
	{

		// If lhs col count doesn match rhs's row count, can't multiply:
		if ( this->numCols != rhs.getNumRows() )
		{
			throw std::logic_error("Matrix::operator* (Matrix/Matrix) - Matrices' inner dimensions do not match, can not multiply them!");
		}

		// New dimensions and matrix:
		uint32_t rows = this->numRows,
						 cols = rhs.getNumCols();
		Matrix result(rows, cols);

		// Multiply matrices together:
		for (uint32_t i=0; i<rows; ++i)
		{
			for (uint32_t j=0; j<cols; ++j)
			{
				for (uint32_t k=0; k<rows; ++k)
				{
					result(i,j) += this->matrix[i][k] * rhs(k,j);
				}
			}
		}

		// Return new matrix multiplied matrix:
		return result;
	}

	// Operator + (Matrix/Matrix)
	template <typename T>
	Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const
	{

		// If matrices aren't same size, can't add them:
		if ( (this->numRows != rhs.getNumRows()) ||
				 (this->numCols != rhs.getNumCols())
			 )
		{
			throw std::logic_error("Matrix::operator+ (Matrix/Matrix) - Matrices must be the same size!");
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
	Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) const
	{

		// If matrices aren't same size, can't subtract them:
		if ( (this->numRows != rhs.getNumRows()) ||
				 (this->numCols != rhs.getNumCols())
			 )
		{
			throw std::logic_error("Matrix::operator- (Matrix/Matrix) - Matrices must be the same size!");
		}

		return (*this + rhs*(-1));
	}

	// Operator * (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator*(const T& rhs) const
	{
		Matrix result(this->numRows, this->numCols);

		// Loop through matrix and multiply each element by scalar:
		for (uint32_t i=0; i< this->numRows; ++i)
		{
			for (uint32_t j=0; j< this->numCols; ++j)
			{
				result(i,j) = matrix[i][j] * rhs;
			}
		}

		return result;
	}

	// Operator / (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator/(const T& rhs) const
	{
		// Check for division by zero:
		if ( rhs == 0 )
		{
			throw std::logic_error("Matrix::operator/ (Matrix/Scalar) - Can't divide by zero!");
		}

		Matrix result(this->numRows, this->numCols);

		// Loop through matrix and divide each element by scalar:
		for (uint32_t i=0; i< this->numRows; ++i)
		{
			for (uint32_t j=0; j< this->numCols; ++j)
			{
				result(i,j) = matrix[i][j] / rhs;
			}
		}

		return result;
	}

	// Operator + (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator+(const T& rhs) const
	{
		Matrix result(this->numRows, this->numCols);

		// Loop through matrix and add each element by scalar:
		for (uint32_t i=0; i< this->numRows; ++i)
		{
			for (uint32_t j=0; j< this->numCols; ++j)
			{
				result(i,j) = matrix[i][j] + rhs;
			}
		}

		return result;
	}

	// Operator - (Matrix/Scalar)
	template <typename T>
	Matrix<T> Matrix<T>::operator-(const T& rhs) const
	{
		return ( (*this) + (-rhs) );
	}

	// Operator - (Matrix [unitary])
	template <typename T>
	Matrix<T> Matrix<T>::operator-() const
	{
		return ( (*this)*(-1) );
	}

	// Operator ^ (Matrix [unitary])
	template <typename T>
	Matrix<T> Matrix<T>::operator^(const uint32_t& rhs) const
	{
		// The power function can only be applied to square matrices:
		if ( !this->isSquare() )
		{
			throw std::logic_error("Matrix::operator^ - Matrix must be square!");
		}

		Matrix result(this->numRows, this->numCols, 0);
		result = *this;

		for (uint32_t i=0; i<rhs; ++i)
		{
			result = (*this) * (*this);
		}

		return result;
	}

	// Operator ()
	template <typename T>
	T& Matrix<T>::operator()(const uint32_t& row, const uint32_t& col)
	{
		// Check range:
		if ( (row >= this->numRows) ||
				 (col >= this->numCols)
			 )
		{
			throw std::out_of_range("Matrix::operator() - Indices out of bounds!");
		}

		return this->matrix[row][col];
	}

	// Operator () const
	template <typename T>
	const T& Matrix<T>::operator()(const uint32_t& row, const uint32_t& col) const
	{
		// Check range:
		if ( (row >= this->numRows) ||
				 (col >= this->numCols)
			 )
		{
			throw std::out_of_range("Matrix::operator() - Indices out of bounds!");
		}

		return this->matrix[row][col];
	}

	// Operator ==
	template <typename T>
	bool Matrix<T>::operator==(const Matrix<T>& rhs) const
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
	Matrix<T> Matrix<T>::transpose() const
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
		for (uint32_t i=0; i < this->numRows; ++i)
		{
			for (uint32_t j=0; j < this->numCols; ++j)
			{
				matrixTranspose(j,i) = this->matrix[i][j];
			}
		}

		// Return tranposed matrix:
		return matrixTranspose;
	}

	// complexConjugate
	template <typename T>
	Matrix<T> Matrix<T>::complexConjugate() const
	{

		// Check if real or not. If real, return it since complex conjugate leaves it unchanged::
		if ( this->isReal() )
		{
			return *this;
		}

		// New complex conjugate matrix:
		Matrix matrixCC = *this;

		// Iterate through and complex conjugate each element:
		for (uint32_t i=0; i < this->numRows; ++i)
		{
			for (uint32_t j=0; j < this->numCols; ++j)
			{
				matrixCC(i,j) = std::conj(this->matrix[i][j]);
			}
		}

		// Return the complex conjugate
		return matrixCC;
		
	}

	// conjugateTranspose
	template <typename T>
	Matrix<T> Matrix<T>::conjugateTranspose() const
	{
		Matrix matrixCT = *this;

		if ( matrixCT.isReal() )
		{
			return matrixCT.transpose();
		}

		return matrixCT.complexConjugate().transpose();
	}

	// isSquare
	template <typename T>
	bool Matrix<T>::isSquare() const
	{
		return (numRows == numCols) ? true : false;
	}

	// isReal
	template <typename T>
	bool Matrix<T>::isReal() const
	{
		// Iterate over all elements to see if they all have non-zero complex parts:
		for (const auto& row : this->matrix)
		{
			for (const auto& col : row)
			{
				// If a complex part if found, the matrix is not real:
				auto a_ij = col;
				if ( std::imag((std::complex<double>)a_ij) != 0 )
				{
					return false;
				}
			}
		}

		// If none of the elements have complex parts, its real:
		return true;
	}

	// isComplex
	template <typename T>
	bool Matrix<T>::isComplex() const
	{
		// If the matrix is strictly real, then we say it is 'not complex'.
		//	To be complex, there has to be at least one element that has an imag part.
		return !( this->isReal() );
	}

	// isSymmetric
	template <typename T>
	bool Matrix<T>::isSymmetric() const
	{
		// If the matrix is equal to its transpose, its symmetric:
		if ( *this == this->transpose() )
		{
			return true;
		}

		// If transpose doesn't match, not symmetric:
		return false;
	}

	// isSkewSymmetric
	template <typename T>
	bool Matrix<T>::isSkewSymmetric() const
	{
		// If the negative of the matrix equals its transpose, its skew-symmetric:
		if ( (*this)*(-1) == this->transpose() )
		{
			return true;
		}

		// If transpose doesn't match, not skew-symmetric:
		return false;
	}

	// isHermitian
	template <typename T>
	bool Matrix<T>::isHermitian() const
	{
		// If the matrix is equal to its conjugate transpose, its Hermitian:
		if ( *this == this->conjugateTranspose() )
		{
			return true;
		}

		// If the conjugate tranpose does not match, it is no Hermitian:
		return false;
	}

	// isSelfAdjoint
	template <typename T>
	bool Matrix<T>::isSelfAdjoint() const
	{
		return this->isHermitian();
	}

	// isSkewHermitian
	template <typename T>
	bool Matrix<T>::isSkewHermitian() const
	{

		// If the negative of the matrix equals its conjugate transpose, its skew-hermitian:
		if ( (*this)*(-1) == this->conjugateTranspose() )
		{
			return true;
		}

		// If conjugate transpose doesn't match, not skew-hermitian:
		return false;
	
	}

	// isNormal
	template <typename T>
	bool Matrix<T>::isNormal() const
	{

		// Can't be normal if not square:
		if ( !this->isSquare() )
		{
			return false;
		}

		// Seperate real from complex case:
		if (this->isReal())
		{
			return this->commutesWith(this->transpose());
		}
		else	// Complex case
		{
			return this->commutesWith(this->conjugateTranspose());
		}

	}

	// isOrthogonal
	template <typename T>
	bool Matrix<T>::isOrthogonal() const
	{

		// Can't be orthgonal is not square:
		if ( !this->isSquare() )
		{
			return false;
		}
		
		if ( (this->isNormal()) && 
		     (((*this)*this->transpose()) == makeIdentity(this->getNumRows()))
			 )
		{
			return true;
		}

		// Not orthogonal is none of the above are true:
		return false;
	}

	// isProjection
	template <typename T>
	bool Matrix<T>::isProjection() const
	{

		// Can't be a projection if not square:
		if ( !this->isSquare() )
		{
			return false;
		}

		// If the matrix equals its square, it is a projection:
		if ( (*this) == ((*this)^2) )
		{
			return true;
		}

		// If it doesn't equal its square, its not a projection:
		return false;
	}

	// commutesWith
	template <typename T>
	bool Matrix<T>::commutesWith(const Matrix<T>& rhs) const
	{
		// If inner dimensions don't match either way, can't multiply:
		if ( (this->getNumCols() != rhs.getNumRows()) ||
				 (this->getNumRows() != rhs.getNumCols())
			 )
		{
			return false;
		}

		// 2 matricies commute if AB = BA:
		if ( ((*this)*(rhs)) == ((rhs)*(*this)) )
		{
			return true;
		}

		// If they aren't equal, they don't commute:
		return false;
	}

	// Trace
	template <typename T>
	T Matrix<T>::trace() const
	{
		// Sum of diagonal values:
		T diagSum = 0;

		// Loop through the rows and sum the main diagonal
		for (uint32_t i=0; i<numRows; ++i)
		{
			diagSum += this->matrix[i][i];
		}
		
		return diagSum;
	}

	// Sum
	template <typename T>
	T Matrix<T>::sum() const
	{
		// Sum of all elements in matrix:
		T sum = 0;

		// Loop through and sum all ements:
		for (const auto& rows : this->matrix)
		{
			for (const auto& cols : rows)
			{
				auto a_ij = cols;
				sum += a_ij;
			}
		}

		return sum;
	}

} // matrix namespace

#endif // MATRIX_H
