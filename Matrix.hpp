
/*
 * File: Mtrix.hpp
 * ---------------
 * This interface exports a class representing matrix using valarray
 *
 */

#include <iostream>
#include <cassert>
#include <valarray>
using namespace std ;

#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

class matrix{
	valarray<int> data ;
	int row , col ;
public :
    
	matrix();
	matrix(int ROW , int COL , int array[]);
	// Destructor: ~matrix
	// Usage: Implicitly called when a point object ends
	~matrix();
	
	friend ostream& operator<< (ostream& out, matrix mat);
	friend istream& operator>> (istream& in, matrix& mat);
	friend matrix operator+  (matrix mat1, matrix mat2);
	friend matrix operator-  (matrix mat1, matrix mat2);
	friend matrix operator*  (matrix mat1, matrix mat2);
	friend matrix operator+  (matrix mat1, int scalar);
	friend matrix operator-  (matrix mat1, int scalar);
	friend matrix operator*  (matrix mat1, int scalar);
	friend matrix operator+= (matrix& mat1, matrix mat2);
	friend matrix operator-= (matrix& mat1, matrix mat2) ;
	friend matrix operator+= (matrix& mat, int scalar);
	friend matrix operator-= (matrix& mat, int scalar) ;
	friend void   operator++ (matrix& mat);
	friend void   operator-- (matrix& mat);
	friend bool operator== (matrix mat1, matrix mat2);
	friend bool operator!= (matrix mat1, matrix mat2);
	friend bool isSquare(matrix mat);
	friend bool   isSymetric (matrix mat);
	friend bool   isIdentity (matrix mat);
	friend matrix transpose(matrix mat1);
};
ostream& operator<< (ostream& out, matrix mat);
istream& operator>> (istream& in, matrix& mat);
matrix operator+  (matrix mat1, matrix mat2);
matrix operator-  (matrix mat1, matrix mat2);
matrix operator*  (matrix mat1, matrix mat2) ;
matrix operator+  (matrix mat1, int scalar);
matrix operator-  (matrix mat1, int scalar) ;
matrix operator*  (matrix mat1, int scalar) ;
matrix operator+= (matrix& mat1, matrix mat2);
matrix operator-= (matrix& mat1, matrix mat2) ;
matrix operator+= (matrix& mat, int scalar);
matrix operator-= (matrix& mat, int scalar) ;
void   operator++ (matrix& mat);
void   operator-- (matrix& mat);
bool operator== (matrix mat1, matrix mat2);
bool operator!= (matrix mat1, matrix mat2);
bool isSquare(matrix mat);
bool   isSymetric (matrix mat);
bool   isIdentity (matrix mat);
matrix transpose(matrix mat1) ;

#endif
