#include <bits/stdc++.h>
using namespace std;

// Function to compute combinations modulo'mod'
long long cmb(long long n, long long r, long long mod) {
    // Return 0 if r is out of bounds
    if (r < 0 || r > n) return 0;
    // Use symmetry property of combinations
    r = min(r, n - r);
    // Calculate combination using precomputed factorials and inverses
    return g1[n] * g2[r] * g2[n - r] % mod;
}

// Set modulo value and maximum value for precomputation
long long mod = 998244353;
long long __N = 8000;

// Precompute factorials and inverse factorials
long long g1[__N + 1], g2[__N + 1], inverse[__N + 1];

// Fill g1, g2, and inverse arrays
void precompute() {
    g1[0] = g2[0] = inverse[0] = 1;
    for (long long i = 1; i <= __N; i++) {
        g1[i] = (g1[i - 1] * i) % mod;
        inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
        g2[i] = (g2[i - 1] * inverse[i]) % mod;
    }
}

// Function to compute kumiawase (combinations with repetition)
long long kumiawase(long long p, long long q) {
    return cmb(p + q - 1, q - 1, mod);
}

// Function to solve the main problem for a given n
long long solve(long long n) {
    // Ensure n is within valid range
    assert(n <= K + 1);
    long long ans = 0;  // Initialize answer
    long long kumi = (n - 1) / 2;  // Calculate half of n-1

    // Iterate over possible values of p
    for (long long p = 0; p <= kumi; p++) {
        if (p > N) break;  // Break if p exceeds N
        // Update answer with contributions from current p
        ans += 1LL << p * 2 * kumi * 2 * (K - kumi * 2 - (n & 1)) % mod * cmb(kumi, p, mod) % mod * kumiawase(N - p, p + (K - kumi * 2 - (n & 1))) % mod;
        // If n is even, consider the case where p is used one less
        if (n & 1) ans += 1LL << p * 2 * kumi * 2 * (K - kumi * 2 - (n & 1)) % mod * cmb(kumi, p, mod) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - (n & 1))) % mod;
    }

    return ans;  // Return the computed answer
}

// List to store answers for each i
vector<long long> ans;

// Iterate over the range to compute results for each i
int main() {
    precompute();
    for (long long i = 2; i <= 2 * K + 1; i++) {
        if (i <= K + 1) {
            // Solve for i and store the result
            long long tmp = solve(i) % mod;
            ans.push_back(tmp);  // Append result to answers list
            cout << tmp << endl;  // Print the result
        } else {
            // For i greater than K+1, use previously computed results
            cout << ans[i - K - 1] << endl;  // Print the corresponding result from the answers list
    }
}

