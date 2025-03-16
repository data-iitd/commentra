#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function prototypes
int64_t combi(int n, int k);
int64_t Pow64(int64_t base, uint exponent);

int main() {
    int n, k;
    int64_t total = 0;

    // Read input
    scanf("%d %d", &n, &k);

    // Calculate the sum of combinations from k to n+1
    for (int i = k; i <= n + 1; i++) {
        total += combi(n, i);
        total %= Pow64(10, 9) + 7;
    }

    // Print the final result
    printf("%lld\n", total);

    return 0;
}

// Combination function
int64_t combi(int n, int k) {
    int64_t min = (int64_t)(k - 1) * k / 2;
    int64_t max = (int64_t)(2 * n - k + 1) * k / 2;
    return max - min + 1;
}

// Power function for 64-bit integers
int64_t Pow64(int64_t base, uint exponent) {
    int64_t answer = 1;
    for (uint i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}
