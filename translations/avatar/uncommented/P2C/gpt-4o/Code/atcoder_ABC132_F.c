#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    
    long long *coef = (long long *)malloc((n + 1) * sizeof(long long));
    long long nn = 0;

    for (long long i = 1; i * i <= n; i++) {
        coef[nn++] = (n / i) - (n / (i + 1));
    }
    
    for (long long i = 0; i < n - (nn > 0 ? coef[0] : 0); i++) {
        coef[nn++] = 1;
    }

    // Reverse the coef array
    for (long long i = 0; i < nn / 2; i++) {
        long long temp = coef[i];
        coef[i] = coef[nn - 1 - i];
        coef[nn - 1 - i] = temp;
    }

    long long **dp = (long long **)malloc((k + 1) * sizeof(long long *));
    for (long long i = 0; i <= k; i++) {
        dp[i] = (long long *)malloc(nn * sizeof(long long));
        for (long long j = 0; j < nn; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (long long i = 1; i <= k; i++) {
        long long tmp = 0;
        for (long long j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][nn - 1 - j];
            tmp %= MOD;
            dp[i][j] = coef[j] * tmp % MOD;
        }
    }

    long long result = 0;
    for (long long j = 0; j < nn; j++) {
        result += dp[k][j];
        result %= MOD;
    }

    printf("%lld\n", result);

    // Free allocated memory
    free(coef);
    for (long long i = 0; i <= k; i++) {
        free(dp[i]);
    }
    free(dp);

    return 0;
}

// <END-OF-CODE>
