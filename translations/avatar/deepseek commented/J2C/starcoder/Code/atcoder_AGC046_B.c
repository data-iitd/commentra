
#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    long dp[3001][3001];
    for (int i = 0; i <= 3000; i++) {
        for (int j = 0; j <= 3000; j++) {
            dp[i][j] = 0;
        }
    }

    dp[A][B] = 1;
    for (int c = A; c <= C; c++) {
        for (int d = B; d <= D; d++) {
            if (c == A && d == B) {
                continue;
            }

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

            dp[c][d] = ans;
        }
    }

    printf("%ld\n", dp[C][D]);

    return 0;
}

