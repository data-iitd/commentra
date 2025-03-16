#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    int n;
    scanf("%d", &n); // Read the integer input `n`

    int *c = (int *)malloc(n * sizeof(int)); // Allocate memory for the array `c`
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]); // Read the list of integers `c`
    }

    qsort(c, n, sizeof(int), compare); // Sort the array `c` in descending order

    long long b = 1; // Use long long to prevent overflow
    for (int i = 0; i < 2 * n - 2; i++) {
        b = (b * 2) % MOD; // Calculate `b` as 2^(2*n - 2) % MOD
    }

    long long a = (2 * b) % MOD; // Calculate `a` as twice `b` modulo `MOD`

    long long ans = 0; // Initialize `ans` to 0

    for (int i = 0; i < n; i++) {
        ans = (ans + c[i] * (a + i * b)) % MOD; // Update `ans`
    }

    printf("%lld\n", ans); // Print the final result `ans`

    free(c); // Free the allocated memory
    return 0;
}
// <END-OF-CODE>
