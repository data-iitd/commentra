
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 
#include <stdint.h> 

#define MOD 998244353L 
#define MAX_SIZE 3001 

// This method solves the problem using dynamic programming
void solve(int A, int B, int C, int D) { 
    // Initialize the dp array for the starting point (A, B)
    long dp[MAX_SIZE][MAX_SIZE] = {0}; 
    dp[A][B] = 1; 

    // Iterate over the range from A to C and from B to D
    for (int c = A; c <= C; c++) { 
        for (int d = B; d <= D; d++) { 
            // Skip the starting point (A, B)
            if (c == A && d == B) { 
                continue; 
            } 

            // Calculate the answer based on previous states
            long ans = 0; 
            if (c > A) { 
                long part = dp[c - 1][d]; 
                ans = (part * d) % MOD; 
            } 
            if (d > B) { 
                long part = dp[c][d - 1]; 
                ans = (ans + (part * c) % MOD) % MOD; 
            } 
            if (c > A && d > B) { 
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1) % MOD) + MOD) % MOD; 
            } 

            // Store the result in dp array
            dp[c][d] = ans; 
        } 
    } 

    // Output the result for the final state (C, D)
    printf("%ld\n", dp[C][D]); 
} 

// Main method to set up input/output and call the solve method
int main() { 
    int A, B, C, D; 
    scanf("%d %d %d %d", &A, &B, &C, &D); 
    solve(A, B, C, D); 
    return 0; 
} 

