#include <stdio.h>

#define MOD 998244353L
#define MAX 3001

long dp[MAX][MAX];

void solve() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    
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
            long ans = 0;

            // If moving down (increasing c)
            if (c > A) {
                long part = dp[c - 1][d];
                ans = (part * d) % MOD; // Calculate contribution from the previous row
            }

            // If moving right (increasing d)
            if (d > B) {
                long part = dp[c][d - 1];
                ans = (ans + (part * c) % MOD) % MOD; // Calculate contribution from the previous column
            }

            // If moving diagonally (increasing both c and d)
            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) % MOD * (d - 1) % MOD) + MOD) % MOD; // Adjust for double counting
            }

            // Store the result in the dp array with modulo adjustment
            dp[c][d] = (ans + MOD) % MOD;
        }
    }

    // Output the final result for dp[C][D]
    printf("%ld\n", dp[C][D]);
}

int main() {
    solve(); // Call the solve function
    return 0; // Return success
}

// <END-OF-CODE>
