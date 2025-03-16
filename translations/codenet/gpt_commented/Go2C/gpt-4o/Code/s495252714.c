#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to perform modular exponentiation
int modpow(int a, int n) {
    int res = 1; // Initialize result
    while (n > 0) {
        if (n & 1) { // If n is odd
            res = (res * a) % MOD; // Update result
        }
        a = (a * a) % MOD; // Square the base
        n >>= 1; // Divide n by 2
    }
    return res; // Return the final result
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of integers

    int *c = (int *)malloc(n * sizeof(int)); // Allocate memory for n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]); // Read n integers into array c
    }

    long long ans = 0; // Initialize answer variable
    qsort(c, n, sizeof(int), compare); // Sort the array of integers

    // Calculate the answer based on the sorted integers
    for (int i = 0; i < n; i++) {
        ans = (ans + (long long)(n + 1 - i) * c[i] % MOD) % MOD; // Update the answer using the formula
    }

    // Print the final result after applying modular exponentiation
    printf("%lld\n", (ans * modpow(4, n - 1)) % MOD);

    free(c); // Free allocated memory
    return 0; // Return success
}

// <END-OF-CODE>
