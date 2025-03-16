
#include <stdio.h>
#define mod 100000007

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int coef[n];
    for (int i = 1; i < n; i++) {
        coef[i] = (n / i) - (n / (i + 1));
    }
    coef[0] = 1;

    int dp[k + 1][n];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        int tmp = 0;
        for (int j = n - 1; j >= 0; j--) {
            tmp = (tmp + dp[i - 1][(n - 1) - j]) % mod;
            dp[i][j] = coef[j] * tmp % mod;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp[k][i]) % mod;
    }
    printf("%d\n", ans);

    return 0;
}
