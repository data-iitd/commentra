
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pipii;
typedef pair<pll, pll> ppll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

ll readLong() {
    ll x;
    scanf("%lld", &x);
    return x;
}

void solve() {
    int n = readInt(), m = readInt();
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a = readInt() - 1, b = readInt() - 1;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<bool> used(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            queue<int> q;
            q.push(i);
            used[i] = true;
            int nodes = 0, edges = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                ++nodes;
                edges += g[v].size();
                for (int u : g[v]) {
                    if (!used[u]) {
                        q.push(u);
                        used[u] = true;
                    }
                }
            }
            if (nodes % 2 == 1 && edges == 2 * nodes) {
                ++ans;
            }
        }
    }
    if ((n - ans) % 2 == 1) {
        ++ans;
    }
    cout << ans << endl;
}

int main() {
    while (solve()) {}
    return 0;
}

END-OF-CODE