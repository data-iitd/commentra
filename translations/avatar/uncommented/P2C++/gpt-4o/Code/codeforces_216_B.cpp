#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

vector<int> readInts() {
    int n;
    vector<int> result;
    while (cin >> n) {
        result.push_back(n);
    }
    return result;
}

pair<int, int> dfs(const vector<set<int>>& g, set<int>& seen, int i) {
    if (seen.count(i)) {
        return {0, 0};
    }
    seen.insert(i);
    int nodes = 1;
    int edges = g[i].size();
    for (int j : g[i]) {
        auto [x, y] = dfs(g, seen, j);
        nodes += x;
        edges += y;
    }
    return {nodes, edges};
}

bool solve() {
    vector<int> line0 = readInts();
    if (line0.empty()) return false;
    int n = line0[0], m = line0[1];
    
    vector<set<int>> g(n + 1);
    set<int> seen;

    for (int i = 0; i < m; ++i) {
        vector<int> edge = readInts();
        g[edge[0]].insert(edge[1]);
        g[edge[1]].insert(edge[0]);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (seen.count(i) == 0) {
            auto [nodes, edges] = dfs(g, seen, i);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans += 1;
            }
        }
    }

    if ((n - ans) % 2 == 1) {
        ans += 1;
    }
    cout << ans << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}

// <END-OF-CODE>
