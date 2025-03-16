
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9;

int n, k, a[N];
vector<int> g[N];

int dfs(int u, int p, int h) {
    int cnt = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        int hh = dfs(v, u, h + 1);
        cnt += hh;
    }
    if (p != 0 && h == k) {
        h = 0;
        cnt++;
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[a[i]].push_back(i);
    }
    int ans = dfs(0, 0, 0);
    if (a[1] != 1) ans++;
    cout << ans << endl;
    return 0;
}

