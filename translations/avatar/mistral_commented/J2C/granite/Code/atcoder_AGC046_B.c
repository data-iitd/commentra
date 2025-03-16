

#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353L

long long dp[3001][3001];

void solve(int A, int B, int C, int D) {
    int c, d;
    dp[A][B] = 1;
    for (c = A; c <= C; c++) {
        for (d = B; d <= D; d++) {
            if (c == A && d == B) {
                continue;
            }
            long long ans = 0;
            if (c > A) {
                long long part = dp[c - 1][d];
                ans = (part * d) % MOD;
            }
            if (d > B) {
                long long part = dp[c][d - 1];
                ans = (ans + (part * c)) % MOD;
            }
            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1)) % MOD + MOD) % MOD;
            }
            dp[c][d] = ans;
        }
    }
    printf("%lld\n", dp[C][D]);
}

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    solve(A, B, C, D);
    return 0;
}

These comments should provide a clear understanding of the code for anyone who reads it.

Translate the above C code to Python and end with comment "