
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define gcd __gcd
#define debug(x) cout << #x << " : " << x << endl;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int inf = 1e18;
const double eps = 1e-9;
const double PI = acos(-1);

void solve() {
    int k;
    cin >> k;
    int t = 0;
    for (int i = 1; i <= k; i++) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main() {
    faster
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

