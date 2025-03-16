
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function with a main function as the entry point of the C program
int main ( int argc, char *argv [ ] ) {
  // Declare a variable buf to store the input from the standard input stream
  char buf [ 1000 ] ;

  // Read the first line of input and split it into an array of strings
  char *inp [ 1000 ] ;
  int n = 0 ;
  int m = 0 ;
  int i = 0 ;
  int j = 0 ;

  // Read the input from the standard input stream
  fgets ( buf, 1000, stdin ) ;

  // Split the input into an array of strings
  inp [ n ] = strtok ( buf, " " ) ;
  n ++ ;
  while ( inp [ n - 1 ] != NULL ) {
    inp [ n ] = strtok ( NULL, " " ) ;
    n ++ ;
  }

  // Parse the first two elements of the array into integers n and m
  n = atoi ( inp [ 0 ] ) ;
  m = atoi ( inp [ 1 ] ) ;

  // Create an array ans of size n to store the processed strings
  char ans [ n ] [ 1000 ] ;

  // Iterate through each string in the input
  for ( i = 0 ; i < n ; i ++ ) {
    // Read a string from the input
    fgets ( buf, 1000, stdin ) ;

    // Initialize an empty string temp
    char temp [ 1000 ] = "" ;

    // Iterate through each character in the string
    for ( j = 0 ; j < m ; j ++ ) {
      if ( buf [ j ] == '-' ) { // If the character is a '-'
        temp [ j ] = '-' ; // Append a '-' character to temp
      } else {
        if ( ( i + j ) % 2 == 1 ) { // If the index i + j is odd
          temp [ j ] = 'W' ; // Append 'W' character to temp
        } else {
          temp [ j ] = 'B' ; // Otherwise, append 'B' character to temp
        }
      }
    }

    // Store the final string in the ans array using the index i
    strcpy ( ans [ i ], temp ) ;
  }

  // Iterate through each string in the ans array and print it to the standard output stream
  for ( i = 0 ; i < n ; i ++ ) {
    printf ( "%s\n", ans [ i ] ) ;
  }

  return 0 ;
}

