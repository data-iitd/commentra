
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define FOR(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define MOD 100000007
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define rrep(i, m, n) for (ll i = m; i >= n; i--)
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    ll rep = n / (a + b);
    ans += rep * a;
    ll res = n - rep * (a + b);
    ans += min(res, a);
    cout << ans << endl;
    return 0;
}

