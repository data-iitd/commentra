

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MOD 1000000007

typedef long long ll;

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    ll c[n];
    for (int i = 0; i < n; i++) scanf("%lld", &c[i]);
    ll ans = 0;
    sort(c, c + n);
    for (int i = 0; i < n; i++) {
        ans = (ans + (n + 1 - i) * c[i] % MOD) % MOD;
    }
    ans = ans * modpow(4, n - 1) % MOD;
    printf("%lld\n", ans);
    return 0;
}

