

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b > 0) {
        ll t = a / b;
        a -= t * b;
        ll tmp = a;
        a = b;
        b = tmp;
        u -= t * v;
        tmp = u;
        u = v;
        v = tmp;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    ll mod = 1000000007;
    ll n, p = 1, ans = 0;
    scanf("%lld", &n);
    ll a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        p = p * (i + 1) % mod;
    }
    ll q[n];
    q[0] = 1;
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod;
    }
    for (int i = 0; i < n; i++) {
        ll val = q[i] + q[n - i - 1] - 1;
        val = val * a[i] % mod;
        val = val * p % mod;
        ans = (ans + val) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
