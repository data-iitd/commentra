#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define MAX_N 8000

typedef long long ll;

// Function prototypes
void dprint(int num, ...);
ll cmb(int n, int r, ll mod);
void compute_combinations(ll g1[], ll g2[], ll inverse[], int size, ll mod);
ll kumiawase(int p, int q);
ll solve(int n, int N, int K);

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    // Compute g1, g2, and inverse arrays
    ll g1[MAX_N + 1], g2[MAX_N + 1], inverse[MAX_N + 1];
    compute_combinations(g1, g2, inverse, MAX_N, MOD);

    // Compute and print answers
    for (int i = 2; i <= 2 * K; i++) {
        ll tmp = solve(i, N, K) % MOD;
        printf("%lld\n", tmp);
    }

    // Print answers for negative integers
    for (int i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            printf("%lld\n", ans[i - K]);
        } else {
            printf("%lld\n", ans[-i + K]);
        }
    }

    return 0;
}

void dprint(int num, ...) {
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; i++) {
        printf("%lld ", va_arg(args, ll));
    }
    printf("\n");
    va_end(args);
}

ll cmb(int n, int r, ll mod) {
    if (r < 0 || r > n) return 0;
    r = (r < n - r) ? r : n - r;
    return g1[n] * g2[r] % mod * g2[n - r] % mod;
}

void compute_combinations(ll g1[], ll g2[], ll inverse[], int size, ll mod) {
    g1[0] = g1[1] = 1;
    g2[0] = g2[1] = 1;
    inverse[0] = 0;
    inverse[1] = 1;
    for (int i = 2; i <= size; i++) {
        g1[i] = g1[i - 1] * i % mod;
        inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
        g2[i] = g2[i - 1] * inverse[i] % mod;
    }
}

ll kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, MOD);
}

ll solve(int n, int N, int K) {
    if (n > K + 1) return 0;
    ll ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = 0; p <= kumi; p++) {
        if (p > N) break;
        ans += (1LL << p) * cmb(kumi, p, MOD) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0))) % MOD;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (1LL << p) * cmb(kumi, p, MOD) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0))) % MOD;
        }
    }
    return ans % MOD;
}
