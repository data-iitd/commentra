#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 0) {
            continue;
        }
        set<int> seen;
        int nodes = 0, edges = 0;
        queue<int> q;
        q.push(i);
        seen.insert(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            nodes++;
            for (int j : g[x]) {
                if (j not in seen) {
                    q.push(j);
                    seen.insert(j);
                }
            }
        }
        edges = seen.size();
        if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
            ans++;
        }
    }
    if ((n - ans) % 2 == 1) {
        ans++;
    }
    cout << ans << "\n";
    return 0;
}

