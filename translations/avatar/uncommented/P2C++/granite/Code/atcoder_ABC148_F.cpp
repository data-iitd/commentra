
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 100000007
#define MOD2 998244353
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl;
#define int long long

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vpii> vvpii;
typedef vector<vvpii> vvvpii;
typedef vector<vvvpii> vvvvpii;

const int inf = 1e18;
const int N = 1e6 + 10;

int n, ta, ao;
vector<int> g[N];
int ta_dist[N], ao_dist[N];

void dfs1(int node, int par) {
    for (auto v : g[node]) {
        if (v == par) continue;
        ta_dist[v] = ta_dist[node] + 1;
        dfs1(v, node);
    }
}

void dfs2(int node, int par) {
    for (auto v : g[node]) {
        if (v == par) continue;
        ao_dist[v] = ao_dist[node] + 1;
        dfs2(v, node);
    }
}

void solve() {
    cin >> n >> ta >> ao;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(ta, 0);
    dfs2(ao, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ta_dist[i] < ao_dist[i]) ans = max(ans, ao_dist[i]);
    }
    cout << ans - 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

