
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a BufferedReader to read input from the console
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the integer n, which represents the number of elements
    int n;
    fscanf(fp, "%d", &n);

    // Read the next line of input and split it into an array of strings
    char line[1000];
    fgets(line, sizeof(line), fp);
    char *token = strtok(line, " ");
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Close the BufferedReader as we no longer need it
    fclose(fp);

    // Define a modulus value for calculations to prevent overflow
    int mod = 1000000007;

    // Initialize a variable to hold the factorial product
    long long p = 1;

    // Calculate the factorial of n modulo mod
    for (int i = 2; i <= n; i++) {
        p = (p * i) % mod;
    }

    // Initialize an array to hold cumulative sums of modular inverses
    long long *q = (long long *)malloc(n * sizeof(long long));
    q[0] = 1; // Base case for the first element

    // Calculate the cumulative sum of modular inverses
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod;
    }

    // Initialize a variable to hold the final answer
    long long ans = 0;

    // Calculate the final answer using the cumulative sums and input array
    for (int i = 0; i < n; i++) {
        long long val = q[i] + q[n - i - 1] - 1; // Combine values from the q array
        val = (val * a[i]) % mod; // Multiply by the corresponding element in a
        val = (val * p) % mod; // Multiply by the factorial product
        ans = (ans + val) % mod; // Add to the final answer
    }

    // Print the final result
    printf("%lld\n", ans);

    // Free memory
    free(a);
    free(q);

    return 0;
}

// Function to compute the modular inverse using the Extended Euclidean Algorithm
long long modinv(long long a, int m) {
    long long b = m;
    long long u = 1;
    long long v = 0;
    long long tmp = 0;

    // Apply the Extended Euclidean Algorithm
    while (b > 0) {
        long long t = a / b;
        a -= t * b;
        tmp = a;
        a = b;
        b = tmp;
        u -= t * v;
        tmp = u;
        u = v;
        v = tmp;
    }

    // Ensure u is positive and within the modulus
    u %= m;
    if (u < 0) u += m;

    // Return the modular inverse
    return u;
}

