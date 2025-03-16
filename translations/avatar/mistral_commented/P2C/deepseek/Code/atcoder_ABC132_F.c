#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int coef[n];
    int coef_size = 0;

    // Calculate coefficients for n up to its square root
    for (int i = 1; i * i <= n; i++) {
        coef[coef_size++] = n / i - n / (i + 1);
    }

    // Add remaining coefficients to the list
    for (int i = 1; i * i <= n; i++) {
        coef[coef_size++] = n / i - n / (i + 1);
    }

    // Reverse the list 'coef'
    for (int i = 0; i < coef_size / 2; i++) {
        int temp = coef[i];
        coef[i] = coef[coef_size - i - 1];
        coef[coef_size - i - 1] = temp;
    }

    // Initialize a 2D array 'dp' to store intermediate results
    int dp[k + 1][coef_size];

    // Initialize the first row of dp with 1 at index 0
    for (int i = 0; i < coef_size; i++) {
        dp[0][i] = 0;
    }
    dp[0][0] = 1;

    // Calculate dp[i][j] for i from 1 to k and j from coef_size-1 to 0
    for (int i = 1; i <= k; i++) {
        int tmp = 0;
        // Iterate through the reverse list 'coef' from j = coef_size-1 to j = 0
        for (int j = coef_size - 1; j >= 0; j--) {
            // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
            tmp = (tmp + dp[i - 1][j]) % MOD;
            tmp = (tmp + coef[j]) % MOD;
            // Update dp[i][j] with the product of coef[j] and tmp
            dp[i][j] = (coef[j] * tmp) % MOD;
        }
    }

    // Calculate the final answer by summing up dp[k]
    int result = 0;
    for (int i = 0; i < coef_size; i++) {
        result = (result + dp[k][i]) % MOD;
    }
    printf("%d\n", result);

    return 0;
}
