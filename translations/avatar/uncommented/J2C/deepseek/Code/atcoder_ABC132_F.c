#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    long long mod = 1e9 + 7;
    int n, k;
    scanf("%d %d", &n, &k);

    int l = 1;
    int len[100000];
    int q = 0;

    while (l <= n) {
        int r = n / (n / l);
        len[q++] = r - l + 1;
        l = r + 1;
    }

    long long dp[k+1][q+1];
    for (int j = 1; j <= q; j++) {
        dp[0][j] = dp[0][j-1] + len[j-1];
    }

    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][q-j+1] * len[j-1]) % MOD;
        }
    }

    printf("%lld\n", dp[k-1][q]);
    return 0;
}
