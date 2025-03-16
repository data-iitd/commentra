#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Function to calculate x^n % mod
long power(long x, long n) {
    if (n == 0) {
        return 1; // Base case: x^0 is 1
    }
    long val = power(x, n / 2); // Recursive call to calculate x^(n/2)
    val = val * val % 1000000007; // Squaring the result
    if (n % 2 == 1) {
        val = val * x % 1000000007; // Multiplying by x if n is odd
    }
    return val; // Returning the result
}

int main() {
    int n;
    scanf("%d", &n);
    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    int mod = 1000000007;
    if (n == 1) {
        printf("%d\n", c[0] * 2 % mod);
        return 0;
    }
    qsort(c, n, sizeof(int), (int (*)(const void *, const void *))__cmpint);
    long b = power(2, n);
    long a = power(2, n - 2);
    long ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        long val = a * i % mod;
        val *= c[n + 1 - i];
        val %= mod;
        ans += val;
        ans %= mod;
    }
    ans *= b;
    ans %= mod;
    printf("%ld\n", ans);
    return 0;
}

