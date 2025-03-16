#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a; // Sort in descending order
}

int main() {
    // Read an integer n from the standard input
    int n;
    scanf("%d", &n);

    // Read n integers from the standard input and store them in an array c
    int *c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Sort the array c in descending order
    qsort(c, n, sizeof(int), compare);

    // Calculate the value of b using the formula 2^(2*n-2) modulo MOD
    long long b = 1;
    for (int i = 0; i < 2 * n - 2; i++) {
        b = (b * 2) % MOD;
    }

    // Calculate the value of a as 2*b modulo MOD
    long long a = (2 * b) % MOD;

    // Initialize the variable ans to zero
    long long ans = 0;

    // Iterate through each index i from 0 to n-1 in the array c
    for (int i = 0; i < n; i++) {
        // Add the product of the current element c[i] and the sum of a and i*b to the variable ans
        ans = (ans + c[i] * (a + i * b)) % MOD;
    }

    // Print the value of ans as the output
    printf("%lld\n", ans);

    // Free the allocated memory
    free(c);

    return 0;
}

// <END-OF-CODE>
