
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int colors[100000];

void dfs(int v, int length) {
    if (colors[v]!= -1) return;
    if (length % 2 == 0) {
        colors[v] = 0;
    } else {
        colors[v] = 1;
    }
    for (auto &p : friends[v]) {
        dfs(p.first, length + p.second);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> friends(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        friends[x].push_back({y, z});
        friends[y].push_back({x, z});
    }
    fill(colors, colors + n, -1);
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        cout << colors[i] << endl;
    }
    return 0;
}

