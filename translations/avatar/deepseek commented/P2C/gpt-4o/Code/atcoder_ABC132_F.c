#include <stdio.h>

#define MOD 1000000007

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);  // Read the values of n and k from input

    // Calculate the coefficients for the number of multiples of each divisor up to n
    long long coef[1000000] = {0};  // Adjust size as needed
    int nn = 0;

    for (long long i = 1; i * i <= n; i++) {
        coef[nn++] = (n / i) - (n / (i + 1));  // Calculate the number of multiples of i
    }
    for (long long i = nn; i < n; i++) {
        coef[nn++] = 1;  // Adjust for remaining numbers
    }

    // Dynamic programming table
    long long dp[100][1000000] = {0};  // Adjust size as needed
    dp[0][0] = 1;  // Base case: one way to achieve sum 0 with 0 elements

    // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
    for (int i = 1; i <= k; i++) {
        long long tmp = 0;  // Temporary variable to accumulate the sum of previous row's values
        for (int j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][(nn - 1) - j];  // Update the temporary sum
            tmp %= MOD;
            dp[i][j] = coef[j] * tmp;  // Update the dp table
            dp[i][j] %= MOD;
        }
    }

    // Print the result: the sum of the last row of dp modulo MOD
    long long result = 0;
    for (int j = 0; j < nn; j++) {
        result += dp[k][j];
        result %= MOD;
    }
    printf("%lld\n", result);

    return 0;
}
