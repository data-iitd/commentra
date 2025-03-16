
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define MOD 998244353
#define MAX_N 8000

ll inv[MAX_N + 1];
ll fact[MAX_N + 1];
ll ifact[MAX_N + 1];

ll mod_pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    ifact[0] = 1;
    inv[1] = 1;
    for (int i = 1; i <= MAX_N; i++) {
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
    ll ans = 0;
    ll kumi = (n - 1) / 2;
    for (ll p = 0; p <= kumi; p++) {
        if (p > N) break;
        ans += mod_pow(2, p) * comb(kumi, p) % MOD * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0))) % MOD;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += mod_pow(2, p) * comb(kumi, p) % MOD * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0))) % MOD;
        }
    }
    return ans % MOD;
}

int main() {
    init();
    ll K, N;
    scanf("%lld %lld", &K, &N);
    ll ans[2 * K];
    for (ll i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            ans[i - 2] = solve(i);
            printf("%lld\n", ans[i - 2]);
        } else {
            printf("%lld\n", ans[2 * K - i]);
        }
    }
    return 0;
}

