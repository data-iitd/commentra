#include <stdio.h>

#define MOD 998244353L
#define MAX 3001

long dp[MAX][MAX];

void solve() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    
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
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) % MOD * (d - 1) % MOD) + MOD) % MOD;
            }
            dp[c][d] = (ans + MOD) % MOD;
        }
    }
    
    printf("%ld\n", dp[C][D]);
}

int main() {
    solve();
    return 0;
}
