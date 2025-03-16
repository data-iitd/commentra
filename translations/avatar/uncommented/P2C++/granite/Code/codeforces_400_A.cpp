
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define clr(x) memset(x,0,sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it = a.begin(); it!= a.end(); it++)
#define PI 3.1415926535897932384626433832795
const int MOD = 1000000007;
const int N = 2e5 + 10;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<pii> ans;
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            bool ok = true;
            for (int j = 0; j < i; j++) {
                int cnt = 0;
                for (int k = j; k < n; k += i) {
                    if (s[k] == 'O') cnt++;
                }
                if (cnt!= 12 / i) ok = false;
            }
            if (ok) ans.pb({12 / i, i});
        }
    }
    sort(all(ans));
    cout << ans.size() << " ";
    for (auto x : ans) cout << x.fi << "x" << x.se << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

