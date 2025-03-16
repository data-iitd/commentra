#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define MAX_N 8000

// Function to compute combinations modulo 'mod'
long long cmb(long long n, long long r, long long mod, long long *g1, long long *g2) {
    // Return 0 if r is out of bounds
    if (r < 0 || r > n) {
        return 0;
    }
    // Use symmetry property of combinations
    r = r < n - r ? r : n - r;
    // Calculate combination using precomputed factorials and inverses
    return g1[n] * g2[r] % mod * g2[n - r] % mod;
}

// Function to compute kumiawase (combinations with repetition)
long long kumiawase(long long p, long long q) {
    return cmb(p + q - 1, q - 1, MOD, g1, g2);
}

// Function to solve the main problem for a given n
long long solve(long long n, long long K, long long *g1, long long *g2) {
    long long ans = 0;
    long long kumi = (n - 1) / 2;

    // Iterate over possible values of p
    for (long long p = 0; p <= kumi; ++p) {
        if (p > K) {
            break;
        }
        // Update answer with contributions from current p
        ans += (1LL << p) * cmb(kumi, p, MOD, g1, g2) % MOD * kumiawase(K - p, p + (n - kumi * 2 - (n % 2 == 0))) % MOD;
        ans %= MOD;
        
        // If n is even, consider the case where p is used one less
        if (n % 2 == 0 && K - p - 1 >= 0) {
            ans += (1LL << p) * cmb(kumi, p, MOD, g1, g2) % MOD * kumiawase(K - p - 1, p + (n - kumi * 2 - (n % 2 == 0))) % MOD;
            ans %= MOD;
        }
    }
    return ans;
}

int main() {
    long long K, N;
    scanf("%lld %lld", &K, &N);

    // Precompute factorials and inverse factorials
    long long g1[MAX_N + 1], g2[MAX_N + 1], inverse[MAX_N + 1];
    g1[0] = g1[1] = 1;
    g2[0] = g2[1] = 1;
    inverse[0] = 0;
    inverse[1] = 1;

    for (long long i = 2; i <= MAX_N; ++i) {
        g1[i] = g1[i - 1] * i % MOD;
        inverse[i] = (-inverse[MOD % i] * (MOD / i)) % MOD;
        g2[i] = g2[i - 1] * inverse[i] % MOD;
    }

    // List to store answers for each i
    long long ans[2 * K + 1];

    // Iterate over the range to compute results for each i
    for (long long i = 2; i <= 2 * K; ++i) {
        if (i <= K + 1) {
            // Solve for i and store the result
            long long tmp = solve(i, K, g1, g2) % MOD;
            ans[i] = tmp;
            printf("%lld\n", tmp);
        } else {
            // For i greater than K+1, use previously computed results
            printf("%lld\n", ans[K + 1 - (i - K)]);
        }
    }

    return 0;
}
