

#include <stdio.h>
#include <stdlib.h>

#define MOD 100000007

int main() {
    // Read input values for n and k
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize a list 'coef' to store coefficients
    int coef[n];
    for (int i = 0; i < n; i++) {
        coef[i] = n / (i + 1) - n / (i + 2);
    }

    // Reverse the list 'coef'
    for (int i = 0; i < n / 2; i++) {
        int tmp = coef[i];
        coef[i] = coef[n - i - 1];
        coef[n - i - 1] = tmp;
    }

    // Initialize a 2D array 'dp' to store intermediate results
    int dp[k + 1][n];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // Initialize the first row of dp with 1 at index 0
    dp[0][0] = 1;

    // Calculate dp[i][j] for i from 1 to k and j from n-1 to 0
    for (int i = 1; i <= k; i++) {
        int tmp = 0;
        for (int j = n - 1; j >= 0; j--) {
            // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
            tmp = (tmp + dp[i - 1][j]) % MOD;
            // Update dp[i][j] with the product of coef[j] and tmp
            dp[i][j] = (coef[j] * tmp) % MOD;
        }
    }

    // Calculate the final answer by summing up dp[k]
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp[k][i]) % MOD;
    }
    printf("%d\n", ans);

    return 0;
}

