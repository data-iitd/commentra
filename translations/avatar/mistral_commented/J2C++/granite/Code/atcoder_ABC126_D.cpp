

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({a - 1, c});
    }
    vector<int> colors(n, -1);
    function<void(int, int)> dfs = [&](int v, int c) {
        if (colors[v]!= -1) return;
        colors[v] = c;
        for (auto e : graph[v]) {
            dfs(e.first, c ^ e.second);
        }
    };
    dfs(0, 0);
    for (int c : colors) {
        cout << c << endl;
    }
    return 0;
}

