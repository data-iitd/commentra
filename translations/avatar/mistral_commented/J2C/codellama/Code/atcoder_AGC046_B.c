
#include <stdio.h> // Importing header file for input and output
#include <stdlib.h> // Importing header file for dynamic memory allocation
#include <stdint.h> // Importing header file for integer types

#define MOD 998244353L // Defining a macro for the modulus value

long **dp; // Declaring a 2D dynamic programming table for storing intermediate results

void solve(int A, int B, int C, int D) { // Function to solve the problem

  dp = (long **)malloc(3001 * sizeof(long *)); // Allocating memory for the dynamic programming table

  for (int i = 0; i < 3001; i++) { // Iterating over all rows of the dynamic programming table
    dp[i] = (long *)malloc(3001 * sizeof(long)); // Allocating memory for each row of the dynamic programming table
  }

  for (int i = 0; i < 3001; i++) { // Iterating over all rows of the dynamic programming table
    for (int j = 0; j < 3001; j++) { // Iterating over all columns of the dynamic programming table
      dp[i][j] = 0; // Initializing all elements of the dynamic programming table as zero
    }
  }

  dp[A][B] = 1; // Setting the base case as dp[A][B] = 1

  for (int c = A; c <= C; c++) { // Iterating over all possible values of c from A to C
    for (int d = B; d <= D; d++) { // Iterating over all possible values of d from B to D
      if (c == A && d == B) { // Skipping the base case as it has already been calculated
        continue;
      }

      long ans = 0; // Initializing the answer as zero

      if (c > A) { // If c is greater than A
        long part = dp[c - 1][d]; // Calculating the sub-answer for the previous value of c and the same value of d
        ans = (part * d); // Multiplying the sub-answer with the current value of d
      }

      if (d > B) { // If d is greater than B
        long part = dp[c][d - 1]; // Calculating the sub-answer for the same value of c and the previous value of d
        ans = (ans + (part * c)); // Adding the sub-answer multiplied by the current value of c to the answer
      }

      if (c > A && d > B) { // If both c and d are greater than their respective initial values
        ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))); // Subtracting the answer for the previous values of c and d multiplied by their difference
      }

      dp[c][d] = (ans % MOD + MOD) % MOD; // Updating the answer for the current values of c and d
    }
  }

  printf("%ld\n", dp[C][D]); // Printing the final answer

  for (int i = 0; i < 3001; i++) { // Iterating over all rows of the dynamic programming table
    free(dp[i]); // Freeing memory for each row of the dynamic programming table
  }

  free(dp); // Freeing memory for the dynamic programming table
}

int main() { // Main function to run the program

  int A, B, C, D; // Declaring variables for the input numbers

  scanf("%d %d %d %d", &A, &B, &C, &D); // Reading the input numbers

  solve(A, B, C, D); // Calling the solve function to solve the problem

  return 0; // Returning 0 to indicate successful execution
}

