#include <stdio.h>
#include <stdlib.h>

// Constants
const int mod = 1000000007;

// Function to calculate modular exponentiation
int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (1LL * res * a) % mod; // Use 1LL to prevent overflow
        }
        a = (1LL * a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    // Read an integer n from standard input
    scanf("%d", &n);

    // Allocate memory for the array of integers
    int *c = (int *)malloc(n * sizeof(int));

    // Read n integers c from standard input
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Initialize answer variable to 0
    long long ans = 0;

    // Sort the array c in ascending order
    qsort(c, n, sizeof(int), (int (*)(const void *, const void *))compare);

    // Iterate through array c and calculate answer
    for (int i = 0; i < n; i++) {
        // Calculate contribution of current integer to answer
        ans = (ans + (1LL * (n + 1 - i) * c[i]) % mod) % mod;
    }

    // Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
    printf("%lld\n", (ans * modpow(4, n - 1)) % mod);

    // Free allocated memory
    free(c);
    return 0;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
