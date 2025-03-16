#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()

int main()
{
    // Step 2: Read input values
    long long n, k; scanf("%lld %lld", &n, &k);
    long long MOD = 1e9 + 7;

    // Step 3: Calculate the maximum and minimum sums
    long long mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
    long long mn = k * (k - 1) / 2;

    // Step 4: Initialize variables
    long long res = 0;

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
    printf("%lld\n", res);
}

