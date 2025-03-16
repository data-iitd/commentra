#include <stdio.h> // Include the stdio.h library for input/output operations
#include <stdlib.h> // Include the stdlib.h library for dynamic memory allocation and other utility functions
#include <vector> // Include the vector container template for dynamic arrays (Note: This is not standard C, so it will be ignored)
#include <unordered_map> // Include the unordered_map container template for hash-based associative arrays (Note: This is not standard C, so it will be ignored)
#include <unordered_set> // Include the unordered_set container template for hash-based sets (Note: This is not standard C, so it will be ignored)
#include <algorithm> // Include the algorithm library for various algorithms on sequences (Note: This is not standard C, so it will be ignored)
#include <limits.h> // Include the limits.h library for constant definitions related to data types
#include <math.h> // Include the math.h library for mathematical functions
#include <map> // Include the map container template for associative arrays (Note: This is not standard C, so it will be ignored)

int main() { // The main function is the entry point of the program
  int r; // Declare an integer variable named "r"

  // Read the value of "r" from the standard input using scanf
  scanf("%d", &r);

  // Output the square of "r" to the standard output using printf and the %d format specifier
  printf("%d\n", r * r);

  // Use the \n character to insert a newline character after the output

  // The program ends with a return statement, which is not strictly necessary since main returns 0 by default if no return statement is present
  return 0;
}
