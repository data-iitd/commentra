
#include <stdio.h> // Include the standard input/output library for input/output operations

int main()  { // Start of the main function
  int A, B, C, X; // Declare variables A, B, C, and X to store user input
  scanf("%d %d %d %d", &A, &B, &C, &X); // Read user input for variables A, B, C, and X using scanf

  int cnt = 0; // Initialize counter variable cnt to 0
  for (int a = 0; a <= A; a++) { // Start of the outermost for loop, iterating from 0 to A
    for (int b = 0; b <= B; b++) { // Start of the inner for loop, iterating from 0 to B
      for (int c = 0; c <= C; c++) { // Start of the innermost for loop, iterating from 0 to C
        int total = 500*a + 100*b + 50*c; // Calculate the total value based on the current values of a, b, and c
        if (total == X) cnt++; // If the total value equals X, increment the counter variable cnt
      }
    }
  }
  printf("%d\n", cnt); // Output the final value of the counter variable cnt to the console
}


