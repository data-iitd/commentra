
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
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
    ll N;
    scanf("%lld", &N);
    ll A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    ll lcm_val = 1;
    for (int i = 0; i < N; i++) {
        lcm_val = lcm(lcm_val, A[i]);
    }
    ll ans = 0;
    ll mod = 10000000007;
    for (int i = 0; i < N; i++) {
        ans = (ans + mod_div(lcm_val, A[i], mod)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
// END-OF-CODE