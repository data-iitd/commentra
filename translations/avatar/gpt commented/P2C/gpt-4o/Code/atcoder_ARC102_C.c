#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define MAX_N 8000

long long g1[MAX_N + 1]; // Factorials
long long g2[MAX_N + 1]; // Inverse factorials
long long inverse[MAX_N + 1]; // Modular inverses

// Function to compute modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to precompute factorials and inverse factorials
void precompute() {
    g1[0] = g1[1] = 1;
    inverse[0] = 0;
    inverse[1] = 1;
    g2[0] = g2[1] = 1;

    for (int i = 2; i <= MAX_N; i++) {
        g1[i] = (g1[i - 1] * i) % MOD;
        inverse[i] = (MOD - (MOD / i) * inverse[MOD % i] % MOD) % MOD; // Fermat's Little Theorem
        g2[i] = (g2[i - 1] * inverse[i]) % MOD;
    }
}

// Function to compute combinations modulo 'mod'
long long cmb(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    r = r < n - r ? r : n - r; // Use symmetry property
    return (g1[n] * g2[r] % MOD) * g2[n - r] % MOD;
}

// Function to compute kumiawase (combinations with repetition)
long long kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1);
}

// Function to solve the main problem for a given n
long long solve(int n, int K, int N) {
    if (n > K + 1) return 0; // Ensure n is within valid range
    long long ans = 0;
    int kumi = (n - 1) / 2;

    for (int p = 0; p <= kumi; p++) {
        if (p > N) break;
        ans = (ans + (mod_exp(2, p, MOD) * cmb(kumi, p) % MOD) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0))) % MOD) % MOD) % MOD;

        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans = (ans + (mod_exp(2, p, MOD) * cmb(kumi, p) % MOD) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0))) % MOD) % MOD) % MOD;
        }
    }

    return ans;
}

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    precompute(); // Precompute factorials and inverses

    long long ans[2 * K + 1]; // List to store answers for each i

    for (int i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            long long tmp = solve(i, K, N) % MOD;
            ans[i] = tmp; // Store result
            printf("%lld\n", tmp); // Print the result
        } else {
            printf("%lld\n", ans[2 * K - i]); // Print the corresponding result from the answers list
        }
    }

    return 0;
}

// <END-OF-CODE>
