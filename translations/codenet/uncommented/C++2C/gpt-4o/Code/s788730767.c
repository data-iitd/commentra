#include <stdio.h>
#include <math.h>

typedef long long ll;

int n, a[50], p, b = 0, c = 0;

ll nPr(ll n, ll r) {
    ll res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
    }
    return res;
}

ll nCr(ll n, ll r) {
    double res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return (ll)res;
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) {
            b++;
        } else {
            c++;
        }
    }

    ll bsum = 0, csum = 0;
    bsum = (ll)pow(2, b);

    if (p == 0) {
        for (int i = 0; i <= c; i++) {
            if (i % 2 == 0) {
                csum += nCr(c, i);
            }
        }
    } else {
        for (int i = 0; i <= c; i++) {
            if (i % 2 == 1) {
                csum += nCr(c, i);
            }
        }
    }

    ll ans = bsum * csum;
    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
