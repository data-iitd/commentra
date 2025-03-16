

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll mod_div(ll a, ll b, ll mod) {
    return a * mod_pow(b, mod - 2, mod) % mod;
}

int main() {
    ll N;
    scanf("%lld", &N);
    ll A[N];
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

    ll l = 1;
    for (int i = 0; i < N; i++) l = lcm(l, A[i]);

    ll ans = 0;
    for (int i = 0; i < N; i++) ans = (ans + mod_div(l, A[i], 1000000007)) % 1000000007;

    printf("%lld\n", ans);

    return 0;
}

