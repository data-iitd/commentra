
#include <stdio.h>

int main()
{
    // Step 2: Read input values
    int n, k; scanf("%d %d", &n, &k);
    int MOD = 1e9 + 7;

    // Step 3: Calculate the maximum and minimum sums
    int mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
    int mn = k * (k - 1) / 2;

    // Step 4: Initialize variables
    int res = 0;

    // Step 5: Loop through possible lengths
    for (int i = k; i <= n + 1; ++i)
    {
        // Update res, mx, and mn in each iteration
        res += mx - mn + 1;
        mx += n - i;
        mn += i;
        res %= MOD;
    }

    // Step 6: Output the result
    printf("%d\n", res);
}
