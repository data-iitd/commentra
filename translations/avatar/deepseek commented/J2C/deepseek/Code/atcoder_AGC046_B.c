#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353L

long long dp[3001][3001];

// This function solves the problem using dynamic programming
void solve(void) {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // Initialize the dp array for the starting point (A, B)
    dp[A][B] = 1;

    // Iterate over the range from A to C and from B to D
    for (int c = A; c <= C; c++) {
        for (int d = B; d <= D; d++) {
            // Skip the starting point (A, B)
            if (c == A && d == B) {
                continue;
            }

            // Calculate the answer based on previous states
            long long ans = 0;
            if (c > A) {
                long long part = dp[c - 1][d];
                ans = (part * d) % MOD;
            }
            if (d > B) {
                long long part = dp[c][d - 1];
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
    printf("%lld\n", dp[C][D]);
}

// Main method to set up input/output and call the solve method
int main(void) {
    solve();
    return 0;
}
