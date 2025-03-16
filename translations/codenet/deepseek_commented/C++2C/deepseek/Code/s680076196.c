#include <stdio.h>  // Step 1: Include necessary headers for input/output operations
#include <stdlib.h> // Include headers for general utilities

typedef long long ll; // Step 2: Define a type for long long integers to handle large numbers

int main(){ // Step 3: Read input values
  int a, b, c, d; // Declare variables to store the input values
  scanf("%d %d %d %d", &a, &b, &c, &d); // Read the four integer values from the user

  // Step 4: Perform calculations
  int area = (a - c) * (b - d); // Calculate the area of the rectangle using the given coordinates

  // Step 5: Output the result
  printf("%d\n", area); // Print the calculated area to the console
}
