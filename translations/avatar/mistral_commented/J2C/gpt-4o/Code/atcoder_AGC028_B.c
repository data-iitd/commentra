#include <stdio.h>  // Include standard input/output library
#include <stdlib.h> // Include standard library for memory allocation and conversions

#define MOD 1000000007 // Define the modulus value

// Function to calculate the modular inverse of 'a' with respect to 'm'
long modinv(long a, int m) {
    long b = m;
    long u = 1;
    long v = 0;
    long tmp = 0;

    // Use extended Euclidean algorithm to find the modular inverse
    while (b > 0) {
        long t = a / b;
        a -= t * b;
        tmp = a;
        a = b;
        b = tmp;
        u -= t * v;
        tmp = u;
        u = v;
        v = tmp;
    }

    u %= m; // If the result is negative, add 'm' to make it positive
    if (u < 0) {
        u += m;
    }

    return u; // Return the modular inverse
}

int main() {
    int n; // Variable to store the number of elements in the array
    scanf("%d", &n); // Read the number of elements

    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the array 'a'
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read each element into the array 'a'
    }

    long p = 1; // Initialize 'p' variable to calculate the factorial of all numbers from 2 to 'n'

    // Calculate the factorial of all numbers from 2 to 'n' and store it in 'p' variable
    for (int i = 2; i <= n; i++) {
        p = p * i % MOD;
    }

    long *q = (long *)malloc(n * sizeof(long)); // Dynamically allocate memory for the array 'q'
    q[0] = 1; // Initialize the first element of 'q' array with 1

    // Calculate the values of 'q' array using the formula (q[i] = q[i-1] + 1/(i+1) % mod)
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + modinv(i + 1, MOD)) % MOD;
    }

    long ans = 0; // Initialize the answer variable

    // Calculate the answer using the formula ans = sum of (q[i] * a[i] * p) for all i from 0 to n-1
    for (int i = 0; i < n; i++) {
        long val = q[i] + q[n - i - 1] - 1; // Calculate the value of 'val' using the formula
        val *= a[i]; // Multiply 'val' with 'a[i]'
        val %= MOD; // Modulo the result with the modulus value
        val *= p; // Multiply 'val' with 'p'
        val %= MOD; // Modulo the result with the modulus value
        ans += val; // Add the result to the answer
        ans %= MOD; // Modulo the answer with the modulus value
    }

    printf("%ld\n", ans); // Print the answer

    free(a); // Free the allocated memory for array 'a'
    free(q); // Free the allocated memory for array 'q'

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
