#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MOD 1000000007

// Function prototypes
int64_t combi(int n, int k);
int pow64(int64_t base, unsigned int exponent);
int min(int a, int b);
int max(int a, int b);

int main() {
    // Read two integers n and k from input
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize a variable to hold the total count
    int64_t total = 0;

    // Calculate the total combinations from k to n+1
    for (int i = k; i <= n + 1; i++) {
        total += combi(n, i); // Add combinations for the current i
        total = total % MOD; // Apply modulo to prevent overflow
    }

    // Print the final total
    printf("%lld\n", total);
    return 0;
}

// combi calculates the number of combinations based on the given n and k
int64_t combi(int n, int k) {
    // Calculate the minimum and maximum possible values for combinations
    int64_t min = (int64_t)(k - 1) * (int64_t)k / 2;
    int64_t max = (int64_t)(2 * n - k + 1) * (int64_t)k / 2;
    // Return the count of combinations
    return max - min + 1;
}

// pow64 calculates the power of a base (int64_t) raised to an exponent
int64_t pow64(int64_t base, unsigned int exponent) {
    int64_t answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

// min returns the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// max returns the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

