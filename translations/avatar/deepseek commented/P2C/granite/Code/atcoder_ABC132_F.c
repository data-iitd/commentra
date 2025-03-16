
#include <stdio.h>
#define MOD 100000007  // Set the modulus to 10^9 + 7

int main() {
    int n, k;
    scanf("%d %d", &n, &k);  // Read the values of n and k from input

    int coef[n + 1];  // Initialize the coefficients for the number of multiples of each divisor up to n
    for (int i = 1; i <= n; i++) {
        coef[i] = (n / i) - (n / (i + 1));  // Calculate the number of multiples of i
    }

    int nn = n + 1;  // Get the length of the coefficient list
    int dp[k + 1][nn];  // Initialize the dp table
    dp[0][0] = 1;  // Base case: one way to achieve sum 0 with 0 elements

    // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
    for (int i = 1; i <= k; i++) {
        int tmp = 0;  // Temporary variable to accumulate the sum of previous row's values
        for (int j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][(nn - 1) - j];  // Update the temporary sum
            tmp %= MOD;
            dp[i][j] = coef[j] * tmp % MOD;  // Update the dp table
        }
    }

    // Print the result: the sum of the last row of dp modulo MOD
    int ans = 0;
    for (int i = 0; i < nn; i++) {
        ans += dp[k][i];
        ans %= MOD;
    }
    printf("%d\n", ans);

    return 0;
}
