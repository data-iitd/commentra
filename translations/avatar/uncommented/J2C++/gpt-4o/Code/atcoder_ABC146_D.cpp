#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int id;
    int to;
    Edge(int id, int to) : id(id), to(to) {}
};

vector<vector<Edge>> g;
vector<int> ans;

void dfs(int to, int color, int parents) {
    int k = 1;
    for (const Edge& e : g[to]) {
        if (e.to == parents) continue;
        if (k == color) k++;
        ans[e.id] = k;
        dfs(e.to, k, to);
        k++;
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        g[a].emplace_back(i, b);
        g[b].emplace_back(i, a);
    }
    ans.resize(n - 1);
    dfs(0, -1, -1);
    int max_val = *max_element(ans.begin(), ans.end());
    cout << max_val << endl;
    for (int c : ans) {
        cout << c << endl;
    }
    return 0;
}

// <END-OF-CODE>
