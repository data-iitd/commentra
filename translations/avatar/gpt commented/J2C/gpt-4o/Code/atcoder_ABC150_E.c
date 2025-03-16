#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate (x^n) % mod using recursion
long long power(long long x, long long n) {
    // Base case: x^0 = 1
    if (n == 0) {
        return 1;
    }

    // Recursively calculate power
    long long val = power(x, n / 2);

    // Square the result and take modulus
    val = (val * val) % MOD;

    // If n is odd, multiply by x and take modulus
    if (n % 2 == 1) {
        val = (val * x) % MOD;
    }

    // Return the final result
    return val;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read the first line of input
    int n;
    scanf("%d", &n);

    // Initialize an integer array 'c' of size 'n'
    int *c = (int *)malloc(n * sizeof(int));

    // Read the second line of input and populate the array 'c'
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // If there is only one element, calculate and print the result directly
    if (n == 1) {
        printf("%lld\n", (c[0] * 2LL) % MOD);
        free(c);
        return 0;
    }

    // Sort the array 'c'
    qsort(c, n, sizeof(int), compare);

    // Calculate powers of 2 for later use
    long long b = power(2, n);
    long long a = power(2, n - 2);

    // Initialize the answer variable
    long long ans = 0;

    // Calculate the final answer using a loop
    for (int i = 2; i <= n + 1; i++) {
        // Calculate the value for the current iteration
        long long val = (a * i) % MOD;
        val = (val * c[n + 1 - i]) % MOD;

        // Accumulate the result
        ans = (ans + val) % MOD;
    }

    // Multiply the accumulated answer by 'b' and take modulus
    ans = (ans * b) % MOD;

    // Print the final result
    printf("%lld\n", ans);

    // Free allocated memory
    free(c);

    return 0;
}

// <END-OF-CODE>
