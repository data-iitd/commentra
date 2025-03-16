
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define MOD 998244353

ll inv[8001];
ll fact[8001];
ll ifact[8001];

ll mod_pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void init_comb() {
    fact[0] = 1;
    ifact[0] = 1;
    inv[1] = 1;
    for (int i = 1; i <= 8000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        if (i > 1) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        ifact[i] = ifact[i - 1] * inv[i] % MOD;
    }
}

ll comb(ll n, ll r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

ll kumiawase(ll p, ll q) {
    return comb(p + q - 1, q - 1);
}

ll solve(ll n) {
    ll res = 0;
    ll k = (n - 1) / 2;
    for (ll p = 0; p <= k; p++) {
        if (p > 8000) break;
        res += mod_pow(2, p) * comb(k, p) % MOD * kumiawase(8000 - p, p + (n - k * 2 - (n % 2 == 0))) % MOD;
        if (n % 2 == 0 && 8000 - p - 1 >= 0) {
            res += mod_pow(2, p) * comb(k, p) % MOD * kumiawase(8000 - p - 1, p + (n - k * 2 - (n % 2 == 0))) % MOD;
        }
    }
    return res % MOD;
}

int main() {
    init_comb();
    ll K, N;
    scanf("%lld%lld", &K, &N);
    for (ll i = 2; i <= 2 * K; i++) {
        ll ans = solve(i);
        printf("%lld\n", ans);
    }
    for (ll i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            printf("%lld\n", ans[i - K]);
        } else {
            printf("%lld\n", ans[-i + K]);
        }
    }
    return 0;
}

Translate the above C code to Rust and end with comment "