

#include <stdio.h> // Include the standard input/output library for input/output operations
#include <stdlib.h> // Include the standard library library for various functions and data types
#include <limits.h> // Include the limits library for constant definitions related to data types
#include <math.h> // Include the math library for mathematical functions

int main() { // The main function is the entry point of the program
  int r; // Declare an integer variable named "r"

  // Read the value of "r" from the standard input using scanf
  scanf("%d", &r);

  // Output the square of "r" to the standard output using printf and the %d format specifier
  printf("%d\n", r * r);

  // The program ends with a return statement, which is not strictly necessary since main returns 0 by default if no return statement is present
  return 0;
}

Translate the above C code to Rust and end with comment "