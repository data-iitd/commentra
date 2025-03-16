
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// Define a debug print function (currently does nothing)
#define dprint(...)

// Function to compute combinations modulo'mod'
ll cmb(ll n, ll r, ll mod) {
    // Return 0 if r is out of bounds
    if (r < 0 || r > n) {
        return 0;
    }
    // Use symmetry property of combinations
    r = (r < n - r)? r : n - r;
    // Calculate combination using precomputed factorials and inverses
    ll ans = 1;
    while (r) {
        ans = ans * n / r;
        n--;
        r--;
    }
    return ans % mod;
}

// Set modulo value and maximum value for precomputation
const ll mod = 998244353;
const int __N = 8000;

// Precompute factorials and inverse factorials
ll g1[__N + 1], g2[__N + 1], inverse[__N + 1];

int main() {
    // Read input values K and N from user
    int K, N;
    scanf("%d%d", &K, &N);

    // Precompute factorials and inverse factorials
    g1[0] = g1[1] = g2[0] = g2[1] = inverse[1] = 1;
    for (int i = 2; i <= __N; i++) {
        g1[i] = g1[i - 1] * i % mod;
        inverse[i] = (mod - mod / i) * inverse[mod % i] % mod;
        g2[i] = g2[i - 1] * inverse[i] % mod;
    }

    // Function to compute kumiawase (combinations with repetition)
    ll kumiawase(int p, int q) {
        return cmb(p + q - 1, q - 1, mod);
    }

    // Function to solve the main problem for a given n
    ll solve(int n) {
        ll ans = 0;
        int kumi = (n - 1) / 2;
        for (int p = 0; p <= kumi; p++) {
            if (p > N) {
                break;
            }
            ans += (1ll << p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));
            if (n % 2 == 0 && N - p - 1 >= 0) {
                ans += (1ll << p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
            }
        }
        return ans % mod;
    }

    // List to store answers for each i
    ll ans[2 * K];

    // Iterate over the range to compute results for each i
    for (int i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            // Solve for i and store the result
            ans[i - 2] = solve(i);
            printf("%lld\n", ans[i - 2]);
        } else {
            // For i greater than K+1, use previously computed results
            printf("%lld\n", ans[i - 2 - K]);
        }
    }

    return 0;
}

Translate the above C code to Rust and end with comment "