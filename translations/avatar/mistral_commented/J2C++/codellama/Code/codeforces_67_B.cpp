
#include <iostream>
#include <cstdlib>

using namespace std ;

int main ( ) {
  int n , k ;  // Declaring and initializing two integer variables 'n' and 'k'
  cin >> n >> k ;  // Reading the values of 'n' and 'k' from the standard input

  int bb [ n ] ;  // Declaring an integer array 'bb' of size 'n'

  for ( int i = 0 ; i < n ; i ++ ) {
    cin >> bb [ i ] ;  // Reading each element of the array 'bb' from the standard input
  }

  int aa [ n ] ;  // Declaring an integer array 'aa' of size 'n'
  int m = 0 ;  // Initializing an integer variable 'm' to keep track of the index of the last element added to 'aa'

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
    cout << aa [ i ] + 1 << " " ;
  }

  cout << endl ;  // Printing a newline character to the console

  return 0 ;
}

