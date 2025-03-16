
#include <stdio.h>
#define MOD 998244353L

long long dp[3001][3001];

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    dp[A][B] = 1;
    for (int c = A; c <= C; c++) {
        for (int d = B; d <= D; d++) {
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
                ans = (ans + (part * c) % MOD) % MOD;
            }
            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1)) % MOD + MOD) % MOD;
            }
            dp[c][d] = ans;
        }
    }
    printf("%lld\n", dp[C][D]);
    return 0;
}
