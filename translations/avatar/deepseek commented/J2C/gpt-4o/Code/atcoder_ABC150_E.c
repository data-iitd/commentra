#include <stdio.h>      // For input and output functions
#include <stdlib.h>     // For memory allocation and conversion functions
#include <string.h>     // For string manipulation functions

#define MOD 1000000007  // Defining the modulo value

// Function to calculate x^n % mod
long long power(long long x, long long n) {
    if (n == 0) {
        return 1; // Base case: x^0 is 1
    }
    long long val = power(x, n / 2); // Recursive call to calculate x^(n/2)
    val = (val * val) % MOD; // Squaring the result
    if (n % 2 == 1) {
        val = (val * x) % MOD; // Multiplying by x if n is odd
    }
    return val; // Returning the result
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); // Comparison function for qsort
}

int main() {
    int n;
    scanf("%d", &n); // Reading the first line for n
    int *c = (int *)malloc(n * sizeof(int)); // Dynamically allocating array of size n

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]); // Reading the integers into the array c
    }

    if (n == 1) {
        printf("%lld\n", (c[0] * 2LL) % MOD); // If n is 1, print the result directly
        free(c); // Freeing allocated memory
        return 0; // Exit the program
    }

    qsort(c, n, sizeof(int), compare); // Sorting the array c in ascending order

    long long b = power(2, n); // Calculating 2^n
    long long a = power(2, n - 2); // Calculating 2^(n-2)
    long long ans = 0; // Initializing the answer variable

    // Calculating the final answer
    for (int i = 2; i <= n + 1; i++) {
        long long val = (a * i) % MOD; // Intermediate calculation
        val = (val * c[n + 1 - i]) % MOD; // Intermediate calculation
        ans = (ans + val) % MOD; // Adding to the answer
    }
    ans = (ans * b) % MOD; // Multiplying the answer by b
    printf("%lld\n", ans); // Printing the final result

    free(c); // Freeing allocated memory
    return 0; // Exit the program
}

// <END-OF-CODE>
