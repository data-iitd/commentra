
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
  int n ; // Declaring a variable to store the number of elements in the array
  printf ( "Enter the number of elements in the array: " ) ; // Prompting the user to enter the number of elements in the array
  scanf ( "%d", &n ) ; // Reading the number of elements in the array from the user

  int a [ n ] ; // Declaring an integer array of size n

  // Initializing the array with user input
  for ( int i = 0 ; i < n ; i ++ ) {
    printf ( "Enter element %d: ", i + 1 ) ; // Prompting the user to enter the next element
    scanf ( "%d", &a [ i ] ) ; // Reading the next element from the user
  }

  // Sorting the array in ascending order
  for ( int i = 0 ; i < n - 1 ; i ++ ) {
    for ( int j = i + 1 ; j < n ; j ++ ) {
      if ( a [ i ] > a [ j ] ) {
        int temp = a [ i ] ;
        a [ i ] = a [ j ] ;
        a [ j ] = temp ;
      }
    }
  }

  // Checking if there is any pair of adjacent elements that satisfy the condition
  for ( int i = 0 ; i < n - 1 ; i ++ ) {
    // Checking if the next element is less than twice the current element and they are not the same
    if ( a [ i + 1 ] < a [ i ] * 2 && a [ i ] != a [ i + 1 ] ) {
      printf ( "YES\n" ) ; // Printing "YES" if a pair is found
      return 0 ; // Exiting the method if a pair is found
    }
  }

  // If no pair is found, printing "NO"
  printf ( "NO\n" ) ;

  return 0 ;
}

