#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> readInts() {
    vector<int> res;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        int x = 0;
        while (s[i] != ' ') {
            x = x * 10 + s[i] - '0';
            i++;
        }
        res.push_back(x);
    }
    return res;
}

int dfs(vector<vector<int>> &g, set<int> &seen, int i) {
    if (seen.find(i) != seen.end()) return 0;
    seen.insert(i);
    int nodes = 1, edges = g[i].size();
    for (int j : g[i]) {
        int x = dfs(g, seen, j);
        nodes += x;
        edges += x;
    }
    return nodes;
}

int main() {
    vector<int> line0 = readInts();
    int n = line0[0], m = line0[1];
    vector<vector<int>> g(n + 1);
    set<int> seen;
    for (int i = 1; i <= n; i++) {
        g[i] = vector<int>();
    }
    for (int i = 0; i < m; i++) {
        vector<int> line = readInts();
        int a = line[0], b = line[1];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (seen.find(i) == seen.end()) {
            int nodes = dfs(g, seen, i);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == g[i].size()) {
                ans++;
            }
        }
    }
    if ((n - ans) % 2 == 1) ans++;
    cout << ans << endl;
    return 0;
}

