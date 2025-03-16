#include <stdio.h>
#include <math.h>

#define MOD 1000000007

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // Calculate the coefficients for the number of multiples of each divisor up to n
    int coef[n];
    int coef_size = 0;
    for (int i = 1; i <= (int)sqrt(n); i++) {
        coef[coef_size++] = (n / i) - (n / (i + 1));
    }
    for (int i = 0; i < n - coef_size; i++) {
        coef[coef_size++] = 1;
    }
    for (int i = 0; i < coef_size / 2; i++) {
        int temp = coef[i];
        coef[i] = coef[coef_size - 1 - i];
        coef[coef_size - 1 - i] = temp;
    }

    // Initialize the dp table
    long long dp[k + 1][coef_size];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < coef_size; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
    for (int i = 1; i <= k; i++) {
        long long tmp = 0;
        for (int j = coef_size - 1; j >= 0; j--) {
            tmp += dp[i - 1][(coef_size - 1) - j];
            tmp %= MOD;
            dp[i][j] = (coef[j] * tmp) % MOD;
        }
    }

    // Calculate the result: the sum of the last row of dp modulo mod
    long long result = 0;
    for (int j = 0; j < coef_size; j++) {
        result += dp[k][j];
        result %= MOD;
    }
    printf("%lld\n", result);

    return 0;
}
