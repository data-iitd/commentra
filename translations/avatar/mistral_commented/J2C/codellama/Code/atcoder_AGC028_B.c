
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int modinv(int a, int m) { // Function to calculate the modular inverse of 'a' with respect to 'm'
    int b = m;
    int u = 1;
    int v = 0;
    int tmp = 0;

    // Use extended Euclidean algorithm to find the modular inverse
    while (b > 0) {
        int t = a / b;
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
    int n; // Declare the number of elements in the array 'n'
    scanf("%d", &n); // Read the number of elements in the array
    int a[n]; // Declare an integer array 'a' of size 'n'

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int mod = 1000000007; // Set the modulus value
    long p = 1; // Initialize 'p' variable to calculate the factorial of all numbers from 2 to 'n'

    // Calculate the factorial of all numbers from 2 to 'n' and store it in 'p' variable
    for (int i = 2; i <= n; i++) {
        p = p * i % mod;
    }

    long q[n]; // Declare a long array 'q' of size 'n'
    q[0] = 1; // Initialize the first element of 'q' array with 1

    // Calculate the values of 'q' array using the formula (q[i] = q[i-1] + 1/i % mod)
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod;
    }

    long ans = 0; // Initialize the answer variable

    // Calculate the answer using the formula ans = sum of (q[i] * a[i] * p) for all i from 0 to n-1
    for (int i = 0; i < n; i++) {
        long val = q[i] + q[n - i - 1] - 1; // Calculate the value of 'val' using the formula
        val *= a[i]; // Multiply 'val' with 'a[i]'
        val %= mod; // Modulo the result with the modulus value
        val *= p; // Multiply 'val' with 'p'
        val %= mod; // Modulo the result with the modulus value
        ans += val; // Add the result to the answer
        ans %= mod; // Modulo the answer with the modulus value
    }

    printf("%ld\n", ans); // Print the answer

    return 0;
}

