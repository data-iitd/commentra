

#include <stdio.h> // Include the standard input/output library for C

int main ( void ) {
  int n ; // Declare an integer variable `n` to store the size of the character array
  int i, j ; // Declare two integer variables `i` and `j` to use as loop counters
  char c [ ] ; // Declare a character array `c` of size `n`
  char p = 'a' ; // Declare a character variable `p` to store the current character to be added to the array

  scanf ( "%d", & n ) ; // Read an integer `n` from the standard input using the scanf function
  c = ( char * ) malloc ( n * sizeof ( char ) ) ; // Allocate memory for the character array `c` of size `n`

  for ( i = 0 ; i < 4 ; i ++ ) { // Use a for loop to iterate through the first four elements of the array
    for ( j = i ; j < n ; j += 4 ) { // Use a nested for loop to populate every fourth element of the array with the next character
      c [ j ] = p ; // Set the current element of the array to the current character
      p ++ ; // Increment the character to be added to the next element
    }
  }

  for ( i = 0 ; i < n ; i ++ ) { // Use a for loop to print each character in the array to the standard output
    printf ( "%c", c [ i ] ) ;
  }

  free ( c ) ; // Free the memory allocated for the character array `c` to release system resources
  return 0 ; // Return 0 to indicate successful execution of the program
}

