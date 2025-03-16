

#include <stdio.h> // Including the required C header files for input/output and standard I/O
#include <stdlib.h> // Including the required C header file for dynamic memory allocation

int main ( void ) {
  int n ; // Declaring an integer variable 'n' to store the number of test cases

  // Reading the first line of input which contains the number of test cases
  scanf ( "%d", &n ) ;

  // Checking if the number of test cases is equal to 1
  if ( n == 1 ) {
    // If yes, printing "Hello World" as output
    printf ( "Hello World\n" ) ;
  } else {
    // If not, reading the next two lines of input which contain two integers
    int num1, num2 ; // Declaring two integer variables 'num1' and 'num2' to store the input integers
    scanf ( "%d %d", &num1, &num2 ) ;

    // Printing the sum of the two integers as output
    printf ( "%d\n", num1 + num2 ) ;
  }

  return 0 ; // Returning 0 to indicate successful program execution
}

Translate the above C code to Python and end with comment "