#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define MAXN 8000

typedef long long ll;

ll g1[MAXN + 1], g2[MAXN + 1], inverse[MAXN + 1];

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll cmb(int n, int r, ll mod) {
    if (r < 0 || r > n) return 0;
    r = r < n - r ? r : n - r;
    return g1[n] * g2[r] % mod * g2[n - r] % mod;
}

ll kumiawase(int p, int q, ll mod) {
    return cmb(p + q - 1, q - 1, mod);
}

ll solve(int n, int K, int N, ll mod) {
    if (n > K + 1) return 0;
    ll ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = 0; p <= kumi; p++) {
        if (p > N) break;
        ans += (ll)mod_pow(2, p, mod) * cmb(kumi, p, mod) % mod * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)), mod) % mod;
        ans %= mod;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (ll)mod_pow(2, p, mod) * cmb(kumi, p, mod) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)), mod) % mod;
            ans %= mod;
        }
    }
    return ans;
}

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    g1[0] = g1[1] = 1;
    g2[0] = g2[1] = 1;
    inverse[0] = 0;
    inverse[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        g1[i] = g1[i - 1] * i % MOD;
        inverse[i] = (MOD - inverse[MOD % i] * (MOD / i) % MOD) % MOD;
        g2[i] = g2[i - 1] * inverse[i] % MOD;
    }

    for (int i = 2; i <= 2 * K + 1; i++) {
        if (i <= K + 1) {
            ll tmp = solve(i, K, N, MOD);
            printf("%lld\n", tmp);
        } else {
            printf("%lld\n", solve(i, K, N, MOD));
        }
    }

    return 0;
}
