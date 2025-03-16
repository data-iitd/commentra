#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define __N 8000

long long g1[__N + 1], g2[__N + 1], inverse[__N + 1];

void precompute() {
    g1[0] = g1[1] = 1;
    inverse[0] = 0;
    inverse[1] = 1;
    g2[0] = g2[1] = 1;

    for (int i = 2; i <= __N; i++) {
        g1[i] = (g1[i - 1] * i) % MOD;
        inverse[i] = (-inverse[MOD % i] * (MOD / i)) % MOD;
        if (inverse[i] < 0) inverse[i] += MOD; // Ensure positive
        g2[i] = (g2[i - 1] * inverse[i]) % MOD;
    }
}

long long cmb(int n, int r) {
    if (r < 0 || r > n) return 0;
    r = r < n - r ? r : n - r; // Take the smaller of r and n - r
    return (g1[n] * g2[r] % MOD) * g2[n - r] % MOD;
}

long long kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1);
}

long long solve(int n, int K, int N) {
    if (n > K + 1) return 0; // Assert n <= K + 1
    long long ans = 0;
    int kumi = (n - 1) / 2;

    for (int p = 0; p <= kumi; p++) {
        if (p > N) break;
        ans = (ans + (2LL * p * cmb(kumi, p) % MOD) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0))) % MOD) % MOD) % MOD;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans = (ans + (2LL * p * cmb(kumi, p) % MOD) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0))) % MOD) % MOD) % MOD;
        }
    }
    return ans;
}

int main() {
    int K, N;
    scanf("%d %d", &K, &N); // Reading K and N from input

    precompute(); // Precompute factorials and inverses

    long long ans[2 * K + 1]; // Array to store results
    for (int i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            ans[i] = solve(i, K, N) % MOD;
            printf("%lld\n", ans[i]);
        } else {
            printf("%lld\n", ans[2 * K - i + K]);
        }
    }

    return 0;
}

// <END-OF-CODE>
