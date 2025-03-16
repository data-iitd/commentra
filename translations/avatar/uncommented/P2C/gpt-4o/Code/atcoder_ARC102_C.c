#include <stdio.h>

#define MOD 998244353
#define N 8000

long long g1[N + 1], g2[N + 1], inverse[N + 1];

void precompute() {
    g1[0] = g1[1] = 1;
    inverse[0] = 0;
    inverse[1] = 1;
    g2[0] = g2[1] = 1;

    for (int i = 2; i <= N; i++) {
        g1[i] = (g1[i - 1] * i) % MOD;
        inverse[i] = (-(inverse[MOD % i] * (MOD / i)) % MOD + MOD) % MOD;
        g2[i] = (g2[i - 1] * inverse[i]) % MOD;
    }
}

long long cmb(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    r = r < n - r ? r : n - r;
    return (g1[n] * g2[r] % MOD) * g2[n - r] % MOD;
}

long long kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1);
}

long long solve(int n, int K) {
    if (n > K + 1) {
        return 0;
    }
    long long ans = 0;
    int kumi = (n - 1) / 2;

    for (int p = 0; p <= kumi; p++) {
        if (p > N) {
            break;
        }
        ans = (ans + (1LL << p) * cmb(kumi, p) % MOD * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0))) % MOD) % MOD) % MOD;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans = (ans + (1LL << p) * cmb(kumi, p) % MOD * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0))) % MOD) % MOD) % MOD;
        }
    }
    return ans;
}

int main() {
    int K, N;
    scanf("%d %d", &K, &N);
    precompute();

    long long ans[2 * K + 1];
    for (int i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            long long tmp = solve(i, K) % MOD;
            ans[i] = tmp;
            printf("%lld\n", tmp);
        } else {
            printf("%lld\n", ans[-i + K]);
        }
    }

    return 0;
}

// <END-OF-CODE>
