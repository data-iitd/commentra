#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define MAXN 8000

// Function to calculate factorial modulo mod
unsigned long long factorial(int n, unsigned long long *g1) {
    if (n >= MAXN) {
        printf("Factorial table size exceeded\n");
        exit(1);
    }
    return g1[n];
}

// Function to calculate binomial coefficient modulo mod
unsigned long long binomial_coefficient(int n, int r, unsigned long long *g1, unsigned long long *g2) {
    if (r < 0 || r > n) {
        return 0;
    }
    r = (r < n - r) ? r : n - r;
    return g1[n] * g2[r] % MOD * g2[n - r] % MOD;
}

// Function to calculate kumiawase (combination with repetition) modulo mod
unsigned long long kumiawase(int p, int q) {
    return binomial_coefficient(p + q - 1, q - 1, g1, g2);
}

// Function to solve the problem for a given n
unsigned long long solve(int n, int K, int N) {
    if (n > K + 1) {
        printf("Invalid n value\n");
        exit(1);
    }
    unsigned long long ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = 0; p <= kumi; ++p) {
        if (p > N) {
            break;
        }
        ans += (1ULL << p) * binomial_coefficient(kumi, p, g1, g2) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (1ULL << p) * binomial_coefficient(kumi, p, g1, g2) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
        }
    }
    return ans % MOD;
}

// Precompute factorials, inverses, and modular inverses up to MAXN
void precompute_factorials(unsigned long long *g1, unsigned long long *g2, unsigned long long *inverse) {
    g1[0] = 1;
    g1[1] = 1;
    g2[0] = 1;
    g2[1] = 1;
    inverse[0] = 0;
    inverse[1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        g1[i] = g1[i - 1] * i % MOD;
        inverse[i] = (-inverse[MOD % i] * (MOD / i)) % MOD;
        g2[i] = g2[i - 1] * inverse[i] % MOD;
    }
}

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    unsigned long long g1[MAXN + 1], g2[MAXN + 1], inverse[MAXN + 1];
    precompute_factorials(g1, g2, inverse);

    unsigned long long ans[2 * K + 1];
    for (int i = 2; i <= 2 * K; ++i) {
        if (i <= K + 1) {
            unsigned long long tmp = solve(i, K, N);
            ans[i] = tmp;
            printf("%llu\n", tmp);
        } else {
            printf("%llu\n", ans[2 * K + 1 - i]);
        }
    }

    return 0;
}
