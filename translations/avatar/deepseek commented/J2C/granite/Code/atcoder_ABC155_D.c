
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100000;
const int MAXM = 100000;
const int MOD = 100000007;
const int MAMOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-6;

int n;
ll k;
ll a[MAXN + 5];

bool check(ll x) {
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll now = a[i];
        int l = 0, r = n;
        if (now >= 0) {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] < x) {
                    l = c + 1;
                } else {
                    r = c;
                }
            }
            tot += l;
        } else {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] >= x) {
                    l = c + 1;
                } else {
                    r = c;
                }
            }
            tot += (n - l);
        }
        if ((ll) a[i] * a[i] < x) {
            tot--;
        }
    }
    if (tot / 2 < k) {
        return true;
    } else {
        return false;
    }
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    ll l = -LLINF, r = LLINF;
    while (l + 1 < r) {
        ll c = (l + r) / 2;
        if (check(c)) {
            l = c;
        } else {
            r = c;
        }
    }
    printf("%lld\n", l);
    return 0;
}
