
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long ll;

const int mod = 998244353;
const int N = 8000;

int g1[N + 1], g2[N + 1], inverse[N + 1];

int cmb(int n, int r, int mod) {
    if (r < 0 || r > n) {
        return 0;
    }
    r = std::min(r, n - r);
    return (ll)g1[n] * g2[r] % mod * g2[n - r] % mod;
}

int kumiawase(int p, int q) {
    return cmb(p + q - 1, q - 1, mod);
}

int solve(int n) {
    assert(n <= K + 1);
    int ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = 0; p <= kumi; p++) {
        if (p > N) {
            break;
        }
        ans = (ans + (ll)pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)))) % mod;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans = (ans + (ll)pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)))) % mod;
        }
    }
    return ans;
}

int main() {
    int K, N;
    scanf("%d%d", &K, &N);
    g1[0] = g2[0] = 1;
    inverse[1] = 1;
    for (int i = 2; i <= N; i++) {
        inverse[i] = (ll)(mod - mod / i) * inverse[mod % i] % mod;
    }
    for (int i = 1; i <= N; i++) {
        g1[i] = (ll)g1[i - 1] * i % mod;
        g2[i] = (ll)g2[i - 1] * inverse[i] % mod;
    }
    for (int i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            printf("%d\n", solve(i));
        } else {
            printf("%d\n", solve(i) - solve(i - K));
        }
    }
    return 0;
}
