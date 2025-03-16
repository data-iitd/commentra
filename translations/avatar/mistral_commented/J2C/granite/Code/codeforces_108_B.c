

#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for dynamic memory allocation
#include <string.h> // Include the string library for string manipulation

int main ( void ) {
  int n ; // Declare an integer variable n to store the number of elements in the array
  scanf ( "%d", & n ) ; // Read the number of elements in the array from user input using scanf

  int * a = ( int * ) malloc ( n * sizeof ( int ) ) ; // Dynamically allocate memory for an integer array of size n

  // Read the elements of the array from user input using a loop
  for ( int i = 0 ; i < n ; i ++ ) {
    scanf ( "%d", & a [ i ] ) ;
  }

  // Sort the array in ascending order using the qsort function from the standard library
  qsort ( a, n, sizeof ( int ), cmpfunc ) ;

  // Check if there is any pair of adjacent elements that satisfy the condition using a loop
  for ( int i = 0 ; i < n - 1 ; i ++ ) {
    // Check if the next element is less than twice the current element and they are not the same
    if ( a [ i + 1 ] < a [ i ] * 2 && a [ i ]!= a [ i + 1 ] ) {
      printf ( "YES\n" ) ; // Print "YES" if a pair is found
      return 0 ; // Exit the program if a pair is found
    }
  }

  // If no pair is found, print "NO"
  printf ( "NO\n" ) ;

  // Free the dynamically allocated memory for the array
  free ( a ) ;

  return 0 ; // Return 0 to indicate successful execution of the program
}

int cmpfunc ( const void * a, const void * b ) {
  // Compare two elements of the array and return a negative value if the first element is less than the second element, a positive value if the first element is greater than the second element, or zero if the elements are equal
  if ( *( int * ) a < *( int * ) b ) {
    return -1 ;
  } else if ( *( int * ) a > *( int * ) b ) {
    return 1 ;
  } else {
    return 0 ;
  }
}

