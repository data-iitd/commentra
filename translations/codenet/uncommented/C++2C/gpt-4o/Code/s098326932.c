#include <stdio.h>
#include <math.h>

typedef long long ll;

ll f(ll N) {
    ll a[20] = {0};
    ll d = 0;
    while (N > 0) {
        a[d] = N % 10;
        N /= 10;
        d++;
    }
    double m = 1e18;
    ll res = N;
    for (int i = 0; i <= d; i++) {
        ll bunsi = 0;
        ll bunbo = 9 * i;
        for (int j = d - 1; j >= 0; j--) {
            bunsi *= 10;
            if (j < i) bunsi += 9;
            else bunsi += a[j];

            if (j >= i) bunbo += a[j];
        }
        double frac = (double)bunsi / (double)bunbo;
        if (frac < m) {
            m = frac;
            res = bunsi;
        }
    }
    return res;
}

int main() {
    ll K;
    scanf("%lld", &K);
    ll N = f(1);
    for (ll i = 0; i < K; i++) {
        printf("%lld\n", N);
        N = f(N + 1);
    }
    
    return 0;
}

// <END-OF-CODE>
