
/*
 * File: Matrix.cpp
 * ---------------
 * This file has the implementation of class Matrix
 * defined in point.hpp
 *
 * Allso contains the fuctions defintions
 * 
 */

#include <iostream>
#include <valarray>
#include <iomanip>
#include <cassert>
#include "matrix.hpp"


// An empty <-> default constructor give a default values
// integer row and column assigned with the value 3
// integer valarray data assigned the matrix dat
// .rsize is function that
matrix::matrix(){
   row = col = 3 ;
   data.resize(row*col);
   for(int i = 0 ; i < (col * row) ; i++){
	   data[i] = 1 ;
   }
}
//____________________________________________________________
// A pramateraise constructor give the values to variables
// integer row and column assigned with the value of the object
// integer valarray data assigned the matrix dat
// .rsize is function that
/******************************************************/
matrix::matrix(int ROW , int COL , int array[]){
    row = ROW , col = COL ;
    data.resize(row*col);
    for(int i = 0 ; i < (col * row) ; i++){
	   data[i] = array[i] ;
    }
    
    
}
//____________________________________________________________
//Destructor delete the object
/*************************************************************/
matrix::~matrix(){
	
}
//____________________________________________________________
//This a function print the matrix
//Takes two prameters an object from the class & ostream library
//return the matrix to the main
//It's a friend function to the class matrix
/*************************************************************/
ostream& operator<< (ostream& out, matrix mat){
	for(int i = 0 ; i < mat.row ; i++){
		cout << endl ;
		for(int j = 0 ; j < mat.col ; j++){
			out << setw(5) << mat.data[i * mat.col + j] << " " ;
		}
		cout << endl ;
	}
	return out ;
}
//____________________________________________________________
/* This function get the matrix elements
 * take two pametrs
 * istream
 * struct matrix
 * return the matrix to the screen
 */
 /*************************************************************/
istream& operator>> (istream& in, matrix& mat){
	cout << "Enter the number of rows : " ;
	cin >> mat.row ;
	cout << "Enter the number of columns : " ;
	cin >> mat.col ;
	mat.data.resize(mat.col * mat.row) ;
	cout << "Enter the data : " ;
    for(int i=0 ; i < mat.row * mat.col ; i++){
        in >> mat.data[i] ;
  }
}
//___________________________________________________ done
/* This function add two matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * class matrix one
 * class matrix two
 * return a new matrix with the sum
 */
matrix operator+  (matrix mat1, matrix mat2){
   matrix mat ;
  assert((mat1.row == mat2.row)&&(mat1.col == mat2.col));
  mat.row = mat1.row ;
  mat.col = mat1.col ;
  mat.data.resize(mat.col * mat.row) ;
  mat.data = mat1.data + mat2.data ;
  return mat ;
}
//___________________________________________________ done
/* This function subtract two matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * struct matrix one
 * struct matrix two
 * return a new matrix with the result
 */
matrix operator-  (matrix mat1, matrix mat2){
  matrix mat ;
  assert((mat1.row == mat2.row)&&(mat1.col == mat2.col));
  mat.row = mat1.row ;
  mat.col = mat1.col ;
  mat.data.resize(mat.col*mat.row);
  mat.data =  mat1.data - mat2.data ;

  return mat;
}
//___________________________________________________ done
/* This function multiply two matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * struct matrix one
 * struct matrix two
 * return a new matrix with the result
 */
matrix operator*  (matrix mat1, matrix mat2){
   matrix mat ;
   assert(mat1.col == mat2.row);
   mat.row = mat1.row ;
   mat.col = mat1.col ;
   mat.data.resize(mat.col*mat.row);
   mat.data = mat1.data * mat2.data ;
  return mat ;

}
//___________________________________________________
/* This function add scalar to matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * struct matrix
 * integer scalar
 * return a new matrix with the sum
 */
matrix operator+  (matrix mat1, int scalar){

   matrix mat ;
   mat.row = mat1.row ;
   mat.col = mat1.col ;
   mat.data.resize(mat.col*mat.row);
   mat.data = mat1.data + scalar ;
  return mat ;
}
//___________________________________________________
/* This function subtract  scalar from matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * struct matrix
 * integer scalar
 * return a new matrix with the result
 */
matrix operator-  (matrix mat1, int scalar){
   matrix mat ;
   mat.row = mat1.row ;
   mat.col = mat1.col ;
   mat.data.resize(mat.col*mat.row);
   mat.data = mat1.data - scalar ;
  return mat ;
}
//____________________________________________________
/* This function multiply scalar with matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * struct matrix
 * integer scalar
 * return a new matrix with the result
 */
matrix operator*  (matrix mat1, int scalar){
  matrix mat ;
  mat.row = mat1.row ;
  mat.col = mat1.col ;
  mat.data.resize(mat.row*mat.col);
  mat.data = mat1.data * scalar ;
 return mat;
}
//______________________________________________________  done
/* This function add two matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * struct matrix one
 * struct matrix two
 * return a new matrix with the result
 * matrix one changes and return
 */
matrix operator+= (matrix& mat1, matrix mat2){
   assert((mat1.row == mat2.row)&&(mat1.col == mat2.col));
   matrix mat ;
   mat.row = mat1.row ;
   mat.col = mat1.col ;
   mat.data.resize(mat.col*mat.row);
   mat.data = mat1.data += mat2.data ;
  return mat ;
}
//______________________________________________________  done
/* This function subtract two matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * struct matrix one
 * struct matrix two
 * return a new matrix with the result
 * matrix one changes and return
 */
matrix operator-= (matrix& mat1, matrix mat2){
   assert((mat1.row == mat2.row)&&(mat1.col == mat2.col));
   matrix mat ;
   mat.row = mat1.row ;
   mat.col = mat1.col ;
   mat.data.resize(mat.col*mat.row);
   mat.data = mat1.data -= mat2.data ;
  return mat ;
}
//______________________________________________________  done
/* This function add scalar to matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * struct matrix
 * integer scalar
 * return a new matrix with the sum
 * matrix one  changes and return
 */
matrix operator+= (matrix& mat, int scalar){
   matrix mat1 ;
   mat1.row = mat.row ;
   mat1.col = mat.col ;
   mat1.data.resize(mat.col*mat.row);
   mat1.data = mat.data += scalar ;
  return mat1 ;
}
//______________________________________________________  done
/* This function subtract scalar to matrix
 * the liberary asseert check if the condition true or false
   if true the statments will be excute
   else go out and skip the function
 * take two pametrs
 * struct matrix
 * integer scalar
 * return a new matrix with the sum
 * matrix one  changes and return
 */
matrix operator-= (matrix& mat, int scalar){
   matrix mat1 ;
   mat1.row = mat.row ;
   mat1.col = mat.col ;
   mat1.data.resize(mat.col*mat.row);
   mat1.data = mat.data -= scalar ;
  return mat1 ;
}
//______________________________________________________  done
/* This function is increase the matrix by 1
 * The function takes one prameter
 * class matrix
 * return a new matrix with the sum
 * The matrix changes and return
 */
void   operator++ (matrix& mat){
	mat.data += 1 ;
}
//_____________________________________________________  done
/* This function is decrease the matrix by 1
 * The function takes one prameter
 * class matrix
 * return a new matrix with the sum
 * The matrix changes and return
 */
void   operator-- (matrix& mat){
   mat.data -= 1 ;
}
//____________________________________________________
// This function compare two matrices
// Takes two matrices
// Assert function is check if the rows and columns are equal to each other
// check if the matrices are equal returns 1 & 0 other wise
/* The count is increasing by 1 if the elements are equals
   and skip the rest of the code
   if they are not the loop stop and return false
   by the end of the two nested loop
   we check the count if it's equal to size of the matrix
   that means all the elements are equal & return true
   and return false other wise
   */
// The integre count if defined to check if

/**********************************************************/
bool operator== (matrix mat1, matrix mat2){
  int k=0 ;
  assert((mat1.row == mat2.row)&&(mat1.col == mat2.col));
    for( int i=0 ; i < (mat2.row * mat1.col) ; i++ ){
      if(mat1.data[i]==mat2.data[i]){
        k++ ;
        continue ;
      }
      else{
        break ;
      }
    }
    if (k == (mat2.row * mat1.col) ){
      return true ;
    }
    else{
      return false ;
    }
}
//_________________________________________________  done
// This function compare two matrices
// Takes two matrices
// Assert function is check if the rows and columns are equal to each other
// check if the matrices are equal returns 1 & 0 other wise
/* The count is increasing by 1 if the elements are equals
   and skip the rest of the code
   if they are not the loop stop and return false
   by the end of the two nested loop
   we check the count if it's equal to size of the matrix
   that means all the elements are equal & return true
   and return false other wise
   */
// The integre count if defined to check if

/**********************************************************/
bool   operator!= (matrix mat1, matrix mat2){
   int count = 0 ;
  assert((mat1.row == mat2.row)&&(mat1.col == mat2.col));
    for( int i=0 ; i < (mat2.row * mat1.col) ; i++ ){
      if(mat1.data[i]!=mat2.data[i]){
        count++ ;
        continue ;
      }
      else{
        break ;
      }
    }
    if (count == (mat2.row * mat1.col) ){
      return true ;
    }
    else{
      return false ;
    }
}
//_________________________________________________  
// This function compare two matrices
// Takes two matrices
// check if the matrices are equal returns 1 & 0 other wise
/**********************************************************/
bool isSquare(matrix mat){
  if(mat.row == mat.col){
    return true ;
  }
  else{
    return false ;
  }
}
//_________________________________________________  
// This function chck whether if the matrix is Symetric or not
// Takes one prameter matrix
   /*First if it's square matrix or not
   if yes go to the next
   else return false
   */
   /*Second after checked is square the next step
   transpos the matrix
   and check if the orignal matrix equal to the
   transposed matrix
   if yes return true & false other wise
   */
/****************************************************/
bool   isSymetric (matrix mat){
	matrix mat1 ;
   if(isSquare(mat)){
		mat1 = transpose(mat) ;
		if(mat1 ==  mat){
			return true ;
		}
		else{
			return false ;
		}
   }
   else{
   	return false ;
   }
}
//________________________________________________  
// This function chck whether if the matrix is Identity or not
// Takes one prameter matrix
   /*First if it's square matrix or not
   if yes go to the next
   else return false
   */
   /*Second after checked is square the next step
   check if the daidonal of the matrix element's are equal to 1's
   if not return false
   if yes
   we check the other element's of the matrix
   if all the elements are equal to 0's
   return true & false other wise
   */
/*****************************************************************/
bool   isIdentity (matrix mat){
  if(isSymetric(mat)){
   for(int i = 0 ; i < mat.row ; i++){
  		for(int j = 0 ; j < mat.row ; j++){
  			if( i != j)
  			{
                if(mat.data[i * mat.col + j] == 0 ){
                    return true ;
                }
                else{
                    return false ;
                }
  			}
  			else{
  				 if( mat.data[i * mat.col + j] == 1 ){
  				 	return true ;
  				 }
  				 else{
  				 	return false ;
  				 }
  			}
  		}
  	}
  }
  else {
  	return false ;
  }
}
//________________________________________________
//This function transpose matrix
// Takes one prameter
// To transpose two nested loop used
// Create a new object matrix
// Assigne the colum of the matrix to the row of the new  matrix
// Assigne the row of the matrix to the column the new matrix
/***************************************************************/
matrix transpose(matrix mat1){
  matrix mat ;
  mat.row = mat1.col ;
  mat.col = mat1.row ;
  mat.data.resize(mat.row*mat.col);
  for(int i=0 ; i < mat.row ; i++){
    for(int j=0 ; j < mat.col ; j++){
      mat.data[i * mat.col + j] = mat1.data[j * mat1.col  + i] ;
    }
  }
  return mat ;
}

/*********************************   End ***************************************/
