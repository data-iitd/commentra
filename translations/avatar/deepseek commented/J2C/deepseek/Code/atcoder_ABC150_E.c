#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate x^n % mod
long long power(long long x, long long n, int mod) {
    if (n == 0) {
        return 1; // Base case: x^0 is 1
    }
    long long val = power(x, n / 2, mod); // Recursive call to calculate x^(n/2)
    val = val * val % mod; // Squaring the result
    if (n % 2 == 1) {
        val = val * x % mod; // Multiplying by x if n is odd
    }
    return val; // Returning the result
}

int main() {
    int n;
    scanf("%d", &n); // Reading the first line and splitting it by spaces
    int c[n]; // Initializing an array of size n to store the integers
    char buffer[1000];
    fgets(buffer, 1000, stdin); // Read the newline character
    fgets(buffer, 1000, stdin); // Reading the second line and splitting it by spaces
    char *token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL) {
        c[i++] = atoi(token); // Parsing each element and storing it in the array c
        token = strtok(NULL, " ");
    }

    int mod = 1000000007; // Defining the modulo value
    if (n == 1) {
        printf("%d\n", c[0] * 2 % mod); // If n is 1, print the result directly
        return 0; // Exit the program as no further computation is needed
    }

    // Sorting the array c in ascending order
    qsort(c, n, sizeof(int), (int (*)(const void *, const void *))compare);

    long long b = power(2, n, mod); // Calculating 2^n
    long long a = power(2, n - 2, mod); // Calculating 2^(n-2)
    long long ans = 0; // Initializing the answer variable

    // Calculating the final answer
    for (int i = 2; i <= n + 1; i++) {
        long long val = a * i % mod; // Intermediate calculation
        val *= c[n + 1 - i]; // Intermediate calculation
        val %= mod; // Modulo operation
        ans += val; // Adding to the answer
        ans %= mod; // Modulo operation
    }
    ans *= b; // Multiplying the answer by b
    ans %= mod; // Modulo operation
    printf("%lld\n", ans); // Printing the final result

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
