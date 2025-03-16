#include <stdio.h>      // For standard input and output
#include <stdlib.h>     // For memory allocation and conversion functions
#include <string.h>     // For string manipulation functions

#define MOD 1000000007  // Defining a constant value for modulus

// Function to calculate the power of a number x raised to the power n
long long power(long long x, long long n) {
    if (n == 0) { // Base case when n is 0
        return 1;
    }

    long long val = power(x, n / 2); // Recursively calculating the square of x raised to the power n/2

    // If n is odd, multiplying the result with x
    if (n % 2 == 1) {
        val = (val * x) % MOD;
    }

    // Returning the final result
    return val;
}

int main() {
    char buffer[100000]; // Buffer for reading input
    fgets(buffer, sizeof(buffer), stdin); // Reading the first line of input
    int n = atoi(buffer); // Parsing the first element of the array as an integer representing the size of the array

    fgets(buffer, sizeof(buffer), stdin); // Reading the second line of input
    int *c = (int *)malloc(n * sizeof(int)); // Creating an integer array of size n

    // Initializing the array c with the input values
    char *token = strtok(buffer, " ");
    for (int i = 0; i < n; i++) {
        c[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Checking if the size of the array is 1
    if (n == 1) {
        // Printing the result for the case when the size of the array is 1
        printf("%lld\n", (c[0] * 2LL) % MOD);
        free(c); // Freeing allocated memory
        return 0; // Exiting the method after printing the result
    }

    // Sorting the array c
    qsort(c, n, sizeof(int), (int (*)(const void *, const void *))compare);

    // Calculating the values of b and a
    long long b = power(2, n);
    long long a = power(2, n - 2);

    // Initializing the variable ans to 0
    long long ans = 0;

    // Iterating through the array from index 2 to n+1
    for (int i = 2; i <= n + 1; i++) {
        // Calculating the value of val using the current index i and the previously calculated value a
        long long val = (a * i) % MOD;

        // Multiplying the value of val with the current element of the array c[n+1-i]
        val = (val * c[n + 1 - i]) % MOD;

        // Adding the value of val to the variable ans
        ans = (ans + val) % MOD;
    }

    // Multiplying the value of ans with the value of b
    ans = (ans * b) % MOD;

    // Printing the final result
    printf("%lld\n", ans);

    // Freeing allocated memory
    free(c);
    return 0;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

