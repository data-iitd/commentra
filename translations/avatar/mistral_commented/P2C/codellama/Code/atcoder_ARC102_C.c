#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define K and N as integers read from the standard input
int K, N;

// Define a helper function to print arguments with a space between them
void dprint(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

// Define a function to compute the number of combinations of r items chosen from a set of n items, modulo a given modulus
int cmb(int n, int r, int mod) {
    // Check if r is out of range
    if (r < 0 || r > n) {
        return 0;
    }
    // Adjust r to be between 0 and n
    r = min(r, n - r);
    // Compute the combination using the formula
    return g1[n] * g2[r] * g2[n - r] % mod;
}

// Set the modulus to 998244353
int mod = 998244353;

// Define a constant N for the size of the arrays
int __N = 8000;

// Initialize g1 and g2 with the first two elements
int g1[2] = {1, 1};
int g2[2] = {1, 1};

// Initialize inverse with the first two elements and the identity list
int inverse[__N + 1] = {0, 1};
for (int i = 2; i <= __N; i++) {
    // Compute g1[i] using the previous value and the current i
    g1[i] = (g1[i - 1] * i) % mod;
    // Compute inverse[i] using the formula
    inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
    // Compute g2[i] using the previous values of g1 and inverse
    g2[i] = (g2[i - 1] * inverse[i]) % mod;
}

// Define a function to compute the value of a combinatorial sum
int kumiawase(int p, int q) {
    // Compute the combination using the cmb function
    return cmb(p + q - 1, q - 1, mod);
}

// Define a function to compute the answer for a given value of n
int solve(int n) {
    // Check if n is out of range
    assert(n <= K + 1);
    // Initialize the answer as 0
    int ans = 0;
    // Compute the number of pairs (p, q) such that p <= N and q <= K - p
    int kumi = (n - 1) / 2;
    // Compute the answer using the kumiawase function and the precomputed values
    for (int p = 0; p <= kumi; p++) {
        if (p > N) {
            break;
        }
        ans += 2**p * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += 2**p * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
        }
    }
    // Return the answer
    return ans;
}

// Initialize an empty list to store the answers
int ans[2 * K + 1];

// Compute the answers for all integers from 2 to 2K+1
for (int i = 2; i <= 2 * K + 1; i++) {
    // Compute the answer for the current integer using the solve function
    ans[i - 2] = solve(i) % mod;
    // Print the answer
    printf("%d\n", ans[i - 2]);
}

// Print the answers for the negative integers by reprinting the results from the ans list
for (int i = 2; i <= 2 * K + 1; i++) {
    if (i <= K + 1) {
        printf("%d\n", ans[i - 2]);
    } else {
        printf("%d\n", ans[2 * K + 1 - i]);
    }
}

