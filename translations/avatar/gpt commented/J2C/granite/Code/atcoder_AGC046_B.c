
#include <stdio.h>
#include <stdlib.h>

// Define a constant for the modulo operation
#define MOD 998244353L

// Create a 2D array for dynamic programming
long long dp[3001][3001];

// Method to solve the problem
void solve(int A, int B, int C, int D) {
    // Initialize the starting point in the dp array
    dp[A][B] = 1;

    // Iterate over the range from A to C and B to D
    for (int c = A; c <= C; c++) {
        for (int d = B; d <= D; d++) {
            // Skip the initial point
            if (c == A && d == B) {
                continue;
            }

            // Variable to store the current answer
            long long ans = 0;

            // If moving down (increasing c)
            if (c > A) {
                long long part = dp[c - 1][d];
                ans = (part * d); // Calculate contribution from the previous row
            }

            // If moving right (increasing d)
            if (d > B) {
                long long part = dp[c][d - 1];
                ans = (ans + (part * c)); // Calculate contribution from the previous column
            }

            // If moving diagonally (increasing both c and d)
            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))); // Adjust for double counting
            }

            // Store the result in the dp array with modulo adjustment
            dp[c][d] = ((ans % MOD) + MOD) % MOD;
        }
    }

    // Output the final result for dp[C][D]
    printf("%lld\n", dp[C][D]);
}

int main() {
    // Read input values A, B, C, D from the user
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // Call the solve method with the input values
    solve(A, B, C, D);

    return 0;
}
