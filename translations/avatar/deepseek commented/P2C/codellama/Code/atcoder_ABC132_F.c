#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int coef[n];
    for (int i = 1; i <= n; i++) {
        coef[i] = (n / i) - (n / (i + 1));
    }

    int nn = n;
    int dp[k + 1][nn];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        int tmp = 0;
        for (int j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][j];
            tmp %= mod;
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= mod;
        }
    }

    int sum = 0;
    for (int i = 0; i < nn; i++) {
        sum += dp[k][i];
        sum %= mod;
    }

    printf("%d\n", sum);

    return 0;
}

