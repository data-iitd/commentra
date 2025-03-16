
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    return b? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
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
    int N;
    scanf("%d", &N);
    ll A[N];
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

    ll lcm_val = 1;
    for (int i = 0; i < N; i++) lcm_val = lcm(lcm_val, A[i]);

    ll ans = 0;
    ll mod = 1000000007;
    for (int i = 0; i < N; i++) ans = (ans + mod_div(lcm_val, A[i], mod)) % mod;

    printf("%lld\n", ans);

    return 0;
}
