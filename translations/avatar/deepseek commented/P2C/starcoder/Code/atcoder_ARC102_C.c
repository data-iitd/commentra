#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define MOD 998244353
#define MAXN 8000

int g1[MAXN + 1];
int g2[MAXN + 1];
int inverse[MOD + 1];

int cmb(int n, int r, int mod) {
    if (r < 0 || r > n) {
        return 0;
    }
    r = min(r, n - r);
    return g1[n] * g2[r] * g2[n - r] % mod;
}

int kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, MOD);
}

int main() {
    int K, N;
    scanf("%d%d", &K, &N);
    assert(N <= K + 1);
    int ans = 0;
    int kumi = (N - 1) / 2;
    for (int p = 0; p <= kumi; p++) {
        if (p > N) {
            break;
        }
        ans += 1LL * pow(2, p) * cmb(kumi, p, MOD) * kumiawase(N - p, p + (K - kumi * 2 - (N & 1))) % MOD;
        if (N & 1 && N - p - 1 >= 0) {
            ans += 1LL * pow(2, p) * cmb(kumi, p, MOD) * kumiawase(N - p - 1, p + (K - kumi * 2 - (N & 1))) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}

