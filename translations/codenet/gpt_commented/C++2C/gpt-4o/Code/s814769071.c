#include <stdio.h>

#define MOD 1000000007

int main()
{
    // Read input values for n and k
    long long n, k; 
    scanf("%lld %lld", &n, &k);

    // Calculate the maximum possible value based on n and k
    long long mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

    // Calculate the minimum possible value based on k
    long long mn = k * (k - 1) / 2;

    // Initialize result variable
    long long res = 0;

    // Loop through values from k to n+1 to compute the result
    for (int i = k; i <= n + 1; ++i)
    {
        // Update result based on current mx and mn values
        res += mx - mn + 1;

        // Update mx and mn for the next iteration
        mx += n - i;
        mn += i;

        // Ensure result stays within the bounds of MOD
        res %= MOD;
    }

    // Output the final result
    printf("%lld\n", res);

    return 0;
}

// <END-OF-CODE>
