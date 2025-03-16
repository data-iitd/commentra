

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define MOD 100000007
#define N 100000
#define K 100000000000000000

typedef long long ll;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n;
ll k;
ll a[N];

bool check(ll x) {
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll now = a[i];
        int l = 0, r = n;
        if (now >= 0) {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] < x) l = c + 1;
                else r = c;
            }
            tot += l;
        } else {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] >= x) l = c + 1;
                else r = c;
            }
            tot += (n - l);
        }
        if ((ll)a[i] * a[i] < x) tot--;
        if (tot / 2 < k) return true;
    }
    return false;
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    ll l = -K, r = K;
    while (l + 1 < r) {
        ll c = (l + r) / 2;
        if (check(c)) l = c;
        else r = c;
    }
    printf("%lld\n", l);
    return 0;
}

Translate the above C code to Python and end with comment "