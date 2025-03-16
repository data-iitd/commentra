#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353L

long long dp[3001][3001];

void solve(void) {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    for (int c = A; c <= C; c++) {
        for (int d = B; d <= D; d++) {
            if (c == A && d == B) {
                dp[c][d] = 1;
                continue;
            }

            long long ans = 0;

            if (c > A) {
                ans = (dp[c - 1][d] * d) % MOD;
            }

            if (d > B) {
                ans = (ans + (dp[c][d - 1] * c) % MOD) % MOD;
            }

            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1) % MOD) + MOD) % MOD;
            }

            dp[c][d] = ans;
        }
    }

    printf("%lld\n", dp[C][D]);
}

int main(void) {
    solve();
    return 0;
}

