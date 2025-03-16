
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

typedef long long ll;

ll mod = 1000000007;

ll modDiv(ll a, ll b) {
    a %= mod;
    b %= mod;
    for (ll m = mod; b; b >>= 1) {
        if (b & 1) a = a * b % mod;
        b = b * b % mod;
    }
    return a;
}

ll modInv(ll x) {
    return modDiv(1, x);
}

ll modPow(ll b, ll e) {
    ll ans = 1;
    ll x = b % mod;
    for (ll y = e; y!= 0; y >>= 1) {
        if (y & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
    }
    return ans;
}

int main() {
    int N;
    scanf("%d", &N);
    ll A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    ll lcm = 1;
    for (int i = 0; i < N; i++) {
        ll a = A[i];
        lcm = lcm / __gcd(lcm, a) * a;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + modDiv(lcm, A[i])) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}

