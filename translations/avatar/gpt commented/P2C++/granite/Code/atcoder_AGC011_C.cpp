
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> vis(n + 1, 0);
    int ci = 0, cb = 0, cc = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<bool(int)> dfs = [&](int x) {
        queue<pair<int, int>> stk;
        stk.push({x, 1});
        bool flag = true;
        while (!stk.empty()) {
            int u = stk.top().first, col = stk.top().second;
            stk.pop();
            if (vis[u]) {
                flag &= (vis[u] == col);
                continue;
            }
            vis[u] = col;
            for (int i : g[u]) {
                stk.push({i, 3 - col});
            }
        }
        return flag;
    };

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (g[i].empty()) {
                ci++;
            } else {
                if (dfs(i)) {
                    cb++;
                } else {
                    cc++;
                }
            }
        }
    }

    cout << ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb << endl;

    return 0;
}

