#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MOD 1000000007

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    // Calculate the maximum and minimum sums
    long long mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
    long long mn = k * (k - 1) / 2;

    // Initialize variables
    long long res = 0;

    // Loop through possible lengths
    for (int i = k; i <= n + 1; ++i) {
        // Update res, mx, and mn in each iteration
        res += mx - mn + 1;
        mx += n - i;
        mn += i;
        res %= MOD;
    }

    // Output the result
    printf("%lld\n", res);

    return 0;
}
