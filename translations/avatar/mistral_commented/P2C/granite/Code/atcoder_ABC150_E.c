
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the value of modulo for modular arithmetic calculations
    int mod = 100000007;

    // Read an integer n from the standard input
    int n;
    scanf("%d", &n);

    // Read n integers from the standard input and store them in an array c in descending order
    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Sort the array c in descending order
    qsort(c, n, sizeof(int), cmpfunc);

    // Calculate the value of b using the formula 2^(2*n-2) modulo mod
    int b = 1;
    for (int i = 0; i < 2 * n - 2; i++) {
        b = (b * 2) % mod;
    }

    // Calculate the value of a as 2*b modulo mod
    int a = (2 * b) % mod;

    // Initialize the variable ans to zero
    int ans = 0;

    // Iterate through each index i from 0 to n-1 in the array c
    for (int i = 0; i < n; i++) {
        // Add the product of the current element c[i] and the sum of a and i*b to the variable ans
        ans = (ans + (c[i] * ((a + i * b) % mod)) % mod) % mod;
    }

    // Print the value of ans as the output
    printf("%d\n", ans);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

