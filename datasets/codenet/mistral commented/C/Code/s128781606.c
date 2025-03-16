#include <stdio.h> // Include the standard input/output library

int main(void) { // The entry point of the program
  int A, B, C, D, E, max; // Declare variables A, B, C, D, E, and max

  scanf("%d %d",&A, &B); // Read two integers from the standard input and store them in variables A and B

  C = A + B; // Compute the sum of A and B and store the result in variable C

  D = A - B; // Compute the difference of A and B and store the result in variable D

  E = A * B; // Compute the product of A and B and store the result in variable E

  max = C; // Initialize max with the value of C

  if (max < D) { // Check if D is greater than max
    max = D; // If so, update max with the value of D
  }

  if (max < E) { // Check if E is greater than max
    max = E; // If so, update max with the value of E
  }

  printf("%d\n", max); // Print the maximum value to the standard output

  return 0; // Indicate successful termination of the program
}
