
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n;
ll k;
ll a[100005];

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
    }
    if (tot / 2 < k) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll l = -1e18, r = 1e18;
    while (l + 1 < r) {
        ll c = (l + r) / 2;
        if (check(c)) l = c;
        else r = c;
    }
    cout << l << endl;
    return 0;
}

