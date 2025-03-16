
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int id, to;
    Edge(int id, int to) : id(id), to(to) {}
};

int n;
vector<vector<Edge>> g;
vector<int> ans;

void dfs(int to, int color, int parents) {
    int k = 1;
    for (Edge e : g[to]) {
        if (e.to == parents) continue;
        if (k == color) k++;
        ans[e.id] = k;
        dfs(e.to, k, to);
        k++;
    }
}

int main() {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(Edge(i, b));
        g[b].push_back(Edge(i, a));
    }
    ans.resize(n - 1);
    dfs(0, -1, -1);
    int max = 0;
    for (int temp : ans) {
        max = max(max, temp);
    }
    cout << max << endl;
    for (int c : ans) {
        cout << c << endl;
    }
    return 0;
}
