#include <stdio.h>

#define MOD 998244353L
#define MAX 3001

long dp[MAX][MAX];

void solve() {
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

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
