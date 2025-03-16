#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to compute combinations modulo'mod'
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

// Function to compute kumiawase (combinations with repetition)
int kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, mod);
}

// Function to solve the main problem for a given n
int solve(int n) {
    // Ensure n is within valid range
    assert(n <= K + 1);
    int ans = 0;  // Initialize answer
    int kumi = (n - 1) / 2;  // Calculate half of n-1

    // Iterate over possible values of p
    for (int p = 0; p <= kumi; p++) {
        if (p > N) {  // Break if p exceeds N
            break;
        }
        // Update answer with contributions from current p
        ans += 2 * pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));
        
        // If n is even, consider the case where p is used one less
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += 2 * pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
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
        ans[i] = solve(i) % 998244353;
    } else {
        // For i greater than K+1, use previously computed results
        printf("%d\n", ans[i - K]);
    }
}

