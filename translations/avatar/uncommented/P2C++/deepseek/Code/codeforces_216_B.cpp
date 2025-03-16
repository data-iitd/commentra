#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <cstdlib>

using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> ints;
    int num;
    while (ss >> num) {
        ints.push_back(num);
    }
    return ints;
}

pair<int, int> dfs(const vector<set<int>>& g, vector<bool>& seen, int i) {
    if (seen[i]) {
        return make_pair(0, 0);
    }
    seen[i] = true;
    int nodes = 1;
    int edges = g[i].size();
    for (int j : g[i]) {
        auto [x, y] = dfs(g, seen, j);
        nodes += x;
        edges += y;
    }
    return make_pair(nodes, edges);
}

bool solve() {
    vector<int> line0 = readInts();
    if (line0.empty()) {
        return false;
    }
    int n = line0[0];
    int m = line0[1];
    vector<set<int>> g(n + 1);
    vector<bool> seen(n + 1, false);
    for (int i = 0; i < m; ++i) {
        vector<int> ab = readInts();
        int a = ab[0];
        int b = ab[1];
        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            auto [nodes, edges] = dfs(g, seen, i);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ++ans;
            }
        }
    }
    if ((n - ans) % 2 == 1) {
        ++ans;
    }
    cout << ans << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
