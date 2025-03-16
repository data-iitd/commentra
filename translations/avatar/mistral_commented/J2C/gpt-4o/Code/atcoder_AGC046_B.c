#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

#define MOD 998244353L // Modulus value for modular arithmetic

long dp[3001][3001]; // 2D dynamic programming table for storing intermediate results

void solve() { // Function to solve the problem
    int A, B, C, D; // Declare variables for input
    scanf("%d %d %d %d", &A, &B, &C, &D); // Reading the four numbers A, B, C, D from input

    dp[A][B] = 1; // Setting the base case as dp[A][B] = 1

    for (int c = A; c <= C; c++) { // Iterating over all possible values of c from A to C
        for (int d = B; d <= D; d++) { // Iterating over all possible values of d from B to D
            if (c == A && d == B) { // Skipping the base case as it has already been calculated
                continue;
            }

            long ans = 0; // Initializing the answer as zero

            if (c > A) { // If c is greater than A
                long part = dp[c - 1][d]; // Calculating the sub-answer for the previous value of c and the same value of d
                ans = (part * d) % MOD; // Multiplying the sub-answer with the current value of d and taking modulo
            }

            if (d > B) { // If d is greater than B
                long part = dp[c][d - 1]; // Calculating the sub-answer for the same value of c and the previous value of d
                ans = (ans + (part * c) % MOD) % MOD; // Adding the sub-answer multiplied by the current value of c to the answer
            }

            if (c > A && d > B) { // If both c and d are greater than their respective initial values
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) % MOD * (d - 1) % MOD) + MOD) % MOD; // Subtracting the answer for the previous values of c and d multiplied by their difference
            }

            dp[c][d] = (ans + MOD) % MOD; // Updating the answer for the current values of c and d
        }
    }

    printf("%ld\n", dp[C][D]); // Printing the final answer
}

int main() { // Main function to run the program
    solve(); // Calling the solve function to solve the problem
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
