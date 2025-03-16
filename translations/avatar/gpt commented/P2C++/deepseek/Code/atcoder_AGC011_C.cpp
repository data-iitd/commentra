#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> vis(n + 1, 0);
    int ci = 0, cb = 0, cc = 0;
    vector<vector<int>> g(n + 1);

    auto dfs = [&](int x) -> bool {
        queue<pair<int, int>> stk;
        stk.push({x, 1});
        while (!stk.empty()) {
            int u = stk.front().first;
            int col = stk.front().second;
            stk.pop();
            if (vis[u]) {
                if (vis[u] != col) {
                    return false;
                }
                continue;
            }
            vis[u] = col;
            for (int i : g[u]) {
                stk.push({i, 3 - col});
            }
        }
        return true;
    };

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            if (g[i].empty()) {
                ++ci;
            } else {
                if (dfs(i)) {
                    ++cb;
                } else {
                    ++cc;
                }
            }
        }
    }

    cout << ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb << endl;

    return 0;
}
