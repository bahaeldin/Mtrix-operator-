// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1 - Problem 2
// Program: CS213-2018-A2-T1-P2
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0


/**************** main function ************************/
/*
 * File: main.cpp
 * ---------------
 * This is a demo of using class matrix
 *
 * Authors:  Bahaeldin Bahar
             Thon Tor Chol
             Adel Azhary
 * Version: 1.0
 */
/*******************************************************/

#include <iostream>
#include <cassert>
#include <valarray>
#include "matrix.cpp"

using namespace std ;

int main(){
// Matrix is a clss
// mat is an object from the class matrix
// The object mat call defailt constructor
   /* Identitiy Matrix example
           *****
           1 0 0
           0 1 0
           0 0 1
           *****
   
   */
   /* Symetric matrix example
      Normal Natrix
          *****
          1 2 3
          2 4 5
          3 5 8
          *****
      Symetric Matrix
      of the Normal Matrix
          *****
          1 2 3
          2 4 5
          3 5 8
          *****
      */
   int data[9] = {1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1} ;
   int data1[9] = {1 , 2 , 3 , 2 , 4 , 5 , 3 , 5 , 8} ;
	
	matrix mat , identitiyMatrix(3 , 3 , data ) , Symetricmatrix(3,3, data1), mat1 ;
	cout <<(identitiyMatrix+identitiyMatrix);
//	cin >> mat1 ;


	return 0 ;
}
