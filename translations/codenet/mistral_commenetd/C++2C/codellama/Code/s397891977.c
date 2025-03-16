
#include <stdio.h> // Include the standard input/output library for input/output operations
#include <stdlib.h> // Include the standard library for various functions

int main() { // The main function is the entry point of the program
  int r; // Declare an integer variable named "r"

  // Read the value of "r" from the standard input using scanf
  scanf("%d", &r);

  // Output the square of "r" to the standard output using printf and the %d format specifier
  printf("%d\n", r * r);

  // Use the \n newline character to insert a newline character after the output

  // The program ends with a return statement, which is not strictly necessary since main returns 0 by default if no return statement is present
  return 0;
}

