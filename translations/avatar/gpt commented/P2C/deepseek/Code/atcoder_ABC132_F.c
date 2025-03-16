#include <stdio.h>
#include <math.h>

#define MOD 1000000007

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int coef[n];
    int nn = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        coef[nn++] = (n / i) - (n / (i + 1));
    }

    for (int i = 0; i < n - nn; i++) {
        coef[nn + i] = 1;
    }

    long long dp[k + 1][n];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        long long tmp = 0;
        for (int j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][(nn - 1) - j];
            tmp %= MOD;
            dp[i][j] = (coef[j] * tmp) % MOD;
        }
    }

    long long result = 0;
    for (int j = 0; j < n; j++) {
        result += dp[k][j];
        result %= MOD;
    }

    printf("%lld\n", result);

    return 0;
}
