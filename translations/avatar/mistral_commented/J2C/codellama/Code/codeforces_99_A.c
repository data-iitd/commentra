
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ( ) {
  char str [ 100 ] ; // Creating a character array of size 100 to read the entire line from the console
  int dotIndex = 0 ; // Initializing dotIndex variable to 0
  int i = 0 ; // Initializing i variable to 0

  // Reading a line of input from the console and storing it in the character array str
  fgets ( str, 100, stdin ) ;

  // Finding the index of the last occurrence of '.' character in the string
  for ( i = 0 ; i < strlen ( str ) ; i ++ )
    if ( str [ i ] == '.' ) {
      dotIndex = i ;
      break ;
    }

  // Checking if the character before the '.' character is '9'
  if ( str [ dotIndex - 1 ] == '9' ) {
    printf ( "GOTO Vasilisa.\n" ) ; // Printing the message if the condition is true
  }

  // Checking if the character after the '.' character is a digit greater than 4
  else if ( str [ dotIndex + 1 ] - '0' > 4 ) {
    char _str [ 100 ] ; // Initializing an empty character array _str
    int j = 0 ; // Initializing j variable to 0

    // Creating a substring of the character array str from the beginning to the index of '.' character
    for ( j = 0 ; j < dotIndex ; j ++ )
      _str [ j ] = str [ j ] ;

    // Performing big integer addition and printing the result
    printf ( "%s\n", _str ) ;
  }

  // Printing the substring of the character array str from the beginning to the index of '.' character
  else {
    for ( i = 0 ; i < dotIndex ; i ++ )
      printf ( "%c", str [ i ] ) ;

    // Printing a newline character at the end of the substring
    printf ( "\n" ) ;
  }

  return 0 ;
}

