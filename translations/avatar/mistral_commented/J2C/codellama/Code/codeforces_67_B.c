
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
  int n ;  // Declaring an integer variable 'n' to store the number of elements in the array 'bb'
  int k ;  // Declaring an integer variable 'k' to store the value of 'k'
  int * bb ;  // Declaring a pointer to an integer array 'bb'
  int * aa ;  // Declaring a pointer to an integer array 'aa'
  int m ;  // Declaring an integer variable 'm' to keep track of the index of the last element added to 'aa'

  scanf ( "%d %d" , & n , & k ) ;  // Reading the number of elements in the array 'bb' and the value of 'k' from the standard input

  bb = ( int * ) malloc ( n * sizeof ( int ) ) ;  // Allocating memory for the integer array 'bb'
  aa = ( int * ) malloc ( n * sizeof ( int ) ) ;  // Allocating memory for the integer array 'aa'

  for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through the array 'bb' and reading each element from the standard input
    scanf ( "%d" , & bb [ i ] ) ;
  }

  for ( int a = n - 1 ; a >= 0 ; a -- ) {  // Iterating through the array 'bb' from the last index to the first index
    int j = 0 ;
    while ( bb [ a ] > 0 ) {  // While there are still elements in 'bb' at index 'a' to be processed
      if ( aa [ j ] >= a + k ) {  // Checking if the current element in 'aa' is greater than or equal to the index 'a' plus 'k'
        bb [ a ] -- ;  // If true, decrement the number of elements in 'bb' at index 'a'
      }
      j ++ ;
    }

    for ( int j_ = m ++ ; j_ > j ; j_ -- ) {  // Iterating through the array 'aa' from the last index added to the current index 'j'
      aa [ j_ ] = aa [ j_ - 1 ] ;  // Swapping the elements at indices 'j_' and 'j_ - 1'
    }

    aa [ j ] = a ;  // Adding the current index 'a' to the array 'aa' at index 'j'
  }

  for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through the array 'aa' and printing each element to the console
    printf ( "%d " , aa [ i ] + 1 ) ;
  }

  printf ( "\n" ) ;  // Printing a newline character to the console

  free ( bb ) ;  // Freeing the memory allocated for the integer array 'bb'
  free ( aa ) ;  // Freeing the memory allocated for the integer array 'aa'

  return 0 ;
}

