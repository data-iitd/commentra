
#include <stdio.h>      // Include the input-output stream library for console I/O
#include <stdlib.h>     // Include the standard library for various functions (not used in this code)
#include <math.h>       // Include the mathematical library for mathematical functions (not used in this code)
#include <string.h>     // Include the string library for string manipulation functions (not used in this code)
#include <stdbool.h>    // Include the boolean library for boolean data type (not used in this code)
#include <assert.h>     // Include the assert library for error checking and debugging (not used in this code)
#include <time.h>       // Include the time library for time-related functions (not used in this code)
#include <float.h>      // Include the floating-point library for floating-point constants and functions (not used in this code)
#include <limits.h>     // Include the limits library for numeric limits (not used in this code)
#include <errno.h>      // Include the error library for error handling functions (not used in this code)
#include <setjmp.h>     // Include the setjmp library for non-local jumps (not used in this code)
#include <signal.h>     // Include the signal library for signal handling functions (not used in this code)
#include <ctype.h>      // Include the character type library for character classification functions (not used in this code)

int main() {
  int r; // Declare an integer variable 'r' to store the radius

  // Read the radius value from user input
  scanf("%d", &r);

  // Calculate the area of the circle using the formula πr²
  // Here, we are using the simplified version by omitting π for demonstration
  printf("%d\n", r * r); // Output the calculated area (r squared)

  return 0; // Return 0 to indicate successful completion of the program
}

