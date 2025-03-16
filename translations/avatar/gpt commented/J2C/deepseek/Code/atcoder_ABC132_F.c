#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    long mod = 1000000007;
    int n, k;
    scanf("%d %d", &n, &k);

    int len[n + 1];
    int q = 0;
    int l = 1;

    while (l <= n) {
        int r = n / (n / l);
        len[q++] = r - l + 1;
        l = r + 1;
    }

    long dp[k + 1][q + 1];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= q; j++) {
            dp[i][j] = 0;
        }
    }

    for (int j = 1; j <= q; j++) {
        dp[0][j] = dp[0][j - 1] + len[j - 1];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][q - j + 1] * len[j - 1]) % MOD;
        }
    }

    printf("%ld\n", dp[k][q]);
    return 0;
}
