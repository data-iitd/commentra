
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 2e9;
const long long LNF = 2e18;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    int left = INF, right = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        left = min(left, a[i]);
        right = max(right, b[i]);
    }
    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

// END-OF-CODE