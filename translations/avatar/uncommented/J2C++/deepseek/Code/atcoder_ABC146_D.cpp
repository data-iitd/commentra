#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Edge {
    int id;
    int to;
    Edge(int id, int to) : id(id), to(to) {}
};

vector<vector<Edge>> g;
vector<int> ans;
int n;

void dfs(int to, int color, int parent) {
    int k = 1;
    for (auto& e : g[to]) {
        if (e.to == parent) continue;
        if (k == color) k++;
        ans[e.id] = k;
        dfs(e.to, k, to);
        k++;
    }
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> n;
    g.resize(n);
    ans.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        getline(cin, line);
        stringstream ss2(line);
        ss2 >> a >> b;
        a--; b--;
        g[a].emplace_back(i, b);
        g[b].emplace_back(i, a);
    }
    dfs(0, -1, -1);
    int max_val = *max_element(ans.begin(), ans.end());
    cout << max_val << endl;
    for (int c : ans) {
        cout << c << endl;
    }
    return 0;
}

