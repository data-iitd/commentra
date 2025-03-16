#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= a; --i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int main ( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int max_val = 0, max_sign = 0, max_index = -1;
    rep(i, 0, n) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = (a[i] > 0) - (a[i] < 0);
            max_index = i;
        }
    }
    if (max_sign == 0) {
        cout << 0 << endl;
    } else if (max_sign == 1) {
        cout << 2 * n - 1 << endl;
        rep(i, 0, n) cout << max_index + 1 << " " << i + 1 << endl;
        rep(i, 0, n - 1) cout << i + 1 << " " << i + 2 << endl;
    } else {
        cout << 2 * n - 1 << endl;
        rep(i, 0, n) cout << max_index + 1 << " " << i + 1 << endl;
        rep(i, 1, n) cout << i + 1 << " " << i << endl;
    }
    return 0;
}
