#include <stdio.h>      // Include the input-output stream library for console I/O
#include <stdlib.h>     // Include the standard library for various functions (not used in this code)
#include <math.h>       // Include the math library for mathematical functions (not used in this code)

int main() {
  int r; // Declare an integer variable 'r' to store the radius

  // Read the radius value from user input
  scanf("%d", &r);

  // Calculate the area of the circle using the formula πr²
  // Here, we are using the simplified version by omitting π for demonstration
  printf("%d\n", (r * r)); // Output the calculated area (r squared)

  return 0; // Return 0 to indicate successful completion of the program
}

