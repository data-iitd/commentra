

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define endl '\n'

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll n, m, k, t, a[N], b[N];
string s, s1, s2;

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0, cnt = 0, mx = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        ll profit = max(0ll, mx - a[i]);
        if (profit > ans) {
            ans = profit;
            cnt = 1;
        } else if (profit == ans) {
            cnt++;
        }
        mx = max(mx, a[i]);
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

