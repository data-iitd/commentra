#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> vis(n + 1, 0);
    int ci = 0, cb = 0, cc = 0;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (g[i].size() == 0) {
                ci++;
            } else {
                bool flag = true;
                queue<pair<int, int>> stk;
                stk.push({i, 1});
                while (!stk.empty()) {
                    int u = stk.front().first;
                    int col = stk.front().second;
                    stk.pop();
                    if (vis[u]) {
                        flag &= (vis[u] == col);
                        continue;
                    }
                    vis[u] = col;
                    for (int j = 0; j < g[u].size(); j++) {
                        stk.push({g[u][j], 3 - col});
                    }
                }
                if (flag) {
                    cb++;
                } else {
                    cc++;
                }
            }
        }
    }

    cout << ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb << "\n";

    return 0;
}

