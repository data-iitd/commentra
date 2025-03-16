#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    // Initialize an array to store coefficients
    long long *coef = (long long *)malloc((n + 1) * sizeof(long long));
    long long total_coef = 0;

    // Calculate coefficients based on the divisors of n
    for (long long i = 1; i * i <= n; i++) {
        coef[i] = (n / i) - (n / (i + 1));
        total_coef += coef[i];
    }

    // Fill the remaining coefficients with 1s to ensure the length matches n
    for (long long i = total_coef + 1; i <= n; i++) {
        coef[i] = 1;
    }

    // Reverse the coefficients list for further processing
    long long nn = total_coef + (n - total_coef);
    long long *dp = (long long *)malloc((k + 1) * nn * sizeof(long long));

    // Initialize the dp array
    for (long long i = 0; i <= k; i++) {
        for (long long j = 0; j < nn; j++) {
            dp[i * nn + j] = 0;
        }
    }

    // Base case: there's one way to select 0 items (select nothing)
    dp[0] = 1;

    // Fill the dp table for k selections
    for (long long i = 1; i <= k; i++) {
        long long tmp = 0;  // Temporary variable to accumulate values
        // Iterate through the coefficients in reverse order
        for (long long j = nn - 1; j >= 0; j--) {
            // Accumulate the number of ways to select items
            tmp += dp[(i - 1) * nn + (nn - 1 - j)];
            tmp %= MOD;  // Ensure the value stays within modulus
            // Calculate the number of ways to select i items using the j-th coefficient
            dp[i * nn + j] = (coef[j] * tmp) % MOD;
        }
    }

    // Output the total number of ways to select k items, taking modulus
    long long result = 0;
    for (long long j = 0; j < nn; j++) {
        result = (result + dp[k * nn + j]) % MOD;
    }
    printf("%lld\n", result);

    // Free allocated memory
    free(coef);
    free(dp);

    return 0;
}

// <END-OF-CODE>
