#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to perform modular exponentiation
long long pow_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Read the list of integers
    int *c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Sort the list in descending order
    qsort(c, n, sizeof(int), compare);

    // Calculate the value of b as 2^(2*n - 2) modulo MOD
    long long b = pow_mod(2, 2 * n - 2, MOD);

    // Calculate the value of a as 2 * b modulo MOD
    long long a = (2 * b) % MOD;

    // Initialize the answer variable
    long long ans = 0;

    // Iterate through the sorted list and calculate the answer
    for (int i = 0; i < n; i++) {
        // Update the answer by adding the product of the current element and (a + i * b)
        ans = (ans + c[i] * (a + i * b)) % MOD;
    }

    // Print the final result
    printf("%lld\n", ans);

    // Free allocated memory
    free(c);

    return 0;
}

// <END-OF-CODE>
