

#include <stdio.h>

typedef long long ll;

#define MOD 1000000007

ll max(ll a, ll b) {
    return a > b? a : b;
}

void primeFactorize(int n, int *p, int *e) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            (*e)++;
        }
    }
    if (n!= 1) {
        (*e)++;
    }
    *p = n;
}

ll pow(ll n, ll k) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 1) {
        return pow(n, k - 1) * n % MOD;
    } else {
        ll t = pow(n, k / 2);
        return t * t % MOD;
    }
}

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll sub(ll a, ll b) {
    return (a + MOD - b) % MOD;
}

ll mul(ll a, ll b) {
    return a % MOD * b % MOD % MOD;
}

ll div(ll a, ll b) {
    return mul(a, pow(b, MOD - 2));
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int p[n], e[n];
    for (int i = 0; i < n; i++) {
        primeFactorize(a[i], &p[i], &e[i]);
    }
    ll x = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= e[i]; j++) {
            x = mul(x, p[i]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div(x, a[i]));
    }
    printf("%lld\n", ans);
    return 0;
}

