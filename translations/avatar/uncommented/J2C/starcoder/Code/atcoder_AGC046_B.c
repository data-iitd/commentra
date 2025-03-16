#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353

long dp[3001][3001];

void solve(int A, int B, int C, int D) {
    dp[A][B] = 1;
    for (int c = A; c <= C; c++) {
        for (int d = B; d <= D; d++) {
            if (c == A && d == B) continue;
            long ans = 0;
            if (c > A) {
                long part = dp[c - 1][d];
                ans = (part * d);
            }
            if (d > B) {
                long part = dp[c][d - 1];
                ans = (ans + (part * c));
            }
            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1)));
            }
            dp[c][d] = ((ans % MOD) + MOD) % MOD;
        }
    }
}

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    solve(A, B, C, D);
    printf("%ld\n", dp[C][D]);
    return 0;
}

