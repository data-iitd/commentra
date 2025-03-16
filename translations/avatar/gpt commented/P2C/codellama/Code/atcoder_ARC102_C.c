#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Read input values K and N from user
int K, N;
scanf("%d %d", &K, &N);

// Define a debug print function (currently does nothing)
void dprint(int *x, int n) {
    return;
}

// Function to compute combinations modulo 'mod'
int cmb(int n, int r, int mod) {
    // Return 0 if r is out of bounds
    if (r < 0 || r > n) {
        return 0;
    }
    // Use symmetry property of combinations
    r = min(r, n - r);
    // Calculate combination using precomputed factorials and inverses
    return g1[n] * g2[r] * g2[n - r] % mod;
}

// Set modulo value and maximum value for precomputation
int mod = 998244353;
int __N = 8000;

// Precompute factorials and inverse factorials
int g1[__N + 1];  // g1 will hold factorials
int g2[__N + 1];  // g2 will hold inverse factorials
int inverse[__N + 1];  // inverse will hold modular inverses

// Fill g1, g2, and inverse arrays
for (int i = 2; i <= __N; i++) {
    g1[i] = (g1[i - 1] * i) % mod;  // Compute factorial
    inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;  // Compute modular inverse using Fermat's Little Theorem
    g2[i] = (g2[i - 1] * inverse[i]) % mod;  // Compute inverse factorial
}

// Function to compute kumiawase (combinations with repetition)
int kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, mod);
}

// Function to solve the main problem for a given n
int solve(int n) {
    assert(n <= K + 1);  // Ensure n is within valid range
    int ans = 0;  // Initialize answer
    int kumi = (n - 1) / 2;  // Calculate half of n-1

    // Iterate over possible values of p
    for (int p = kumi + 1; p >= 0; p--) {
        if (p > N) {  // Break if p exceeds N
            break;
        }
        // Update answer with contributions from current p
        ans += 2 ** p * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));

        // If n is even, consider the case where p is used one less
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += 2 ** p * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
        }
    }
    return ans;  // Return the computed answer
}

// List to store answers for each i
int ans[2 * K + 1];

// Iterate over the range to compute results for each i
for (int i = 2; i <= 2 * K + 1; i++) {
    if (i <= K + 1) {
        // Solve for i and store the result
        ans[i - 2] = solve(i) % 998244353;
        printf("%d\n", ans[i - 2]);  // Print the result
    } else {
        // For i greater than K+1, use previously computed results
        printf("%d\n", ans[2 * K + 1 - i]);  // Print the corresponding result from the answers list
    }
}

