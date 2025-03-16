
#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007

int main()
{
    int n, k, i, j, tmp, nn;
    int *coef, **dp;

    // Read input values for n and k
    scanf("%d %d", &n, &k);

    // Initialize a list 'coef' to store coefficients
    coef = (int *)malloc(sizeof(int) * n);

    // Calculate coefficients for n up to its square root
    for (i = 1; i <= n / 2; i++)
    {
        // Calculate the difference between the quotient and the next quotient
        coef[i] = n / i - n / (i + 1);
    }

    // Add remaining coefficients to the list
    for (i = n / 2 + 1; i < n; i++)
    {
        coef[i] = 1;
    }

    // Reverse the list 'coef'
    for (i = 0; i < n / 2; i++)
    {
        tmp = coef[i];
        coef[i] = coef[n - i - 1];
        coef[n - i - 1] = tmp;
    }

    // Initialize a 2D list 'dp' to store intermediate results
    nn = n;
    dp = (int **)malloc(sizeof(int *) * (k + 1));
    for (i = 0; i <= k; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * nn);
    }

    // Initialize the first row of dp with 1 at index 0
    for (i = 0; i < nn; i++)
    {
        dp[0][i] = 1;
    }

    // Calculate dp[i][j] for i from 1 to k and j from nn-1 to 0
    for (i = 1; i <= k; i++)
    {
        tmp = 0;
        // Iterate through the reverse list 'coef' from j = nn-1 to j = 0
        for (j = nn - 1; j >= 0; j--)
        {
            // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
            tmp += dp[i - 1][j];
            tmp = (tmp + coef[j]) % mod;
            // Update dp[i][j] with the product of coef[j] and tmp
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= mod;
        }
    }

    // Calculate the final answer by summing up dp[k]
    tmp = 0;
    for (i = 0; i < nn; i++)
    {
        tmp += dp[k][i];
        tmp %= mod;
    }
    printf("%d\n", tmp);

    // Free memory
    free(coef);
    for (i = 0; i <= k; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return 0;
}

