#include <stdio.h> // Include the standard input/output library

int main(void){ // Define the main function with no arguments
  int A, B; // Declare two integer variables A and B
  scanf("%d %d", &A, &B); // Read two integers from the standard input and store them in variables A and B
  if(A < 10 && B < 10) { // Check if both A and B are less than 10
    printf("%d\n", A * B); // If true, print the product of A and B to the standard output
  }
  else { // If the condition is false
    printf("-1\n"); // Print -1 to the standard output as an error message
  }
  return 0; // Indicate that the program has run successfully
}
