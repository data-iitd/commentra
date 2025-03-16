#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MOD = 1e9 + 7;

void dfs(int node, vector<int>& dist, const vector<vector<int>>& g) {
    for (int v : g[node]) {
        if (dist[v] != -1) continue;
        dist[v] = dist[node] + 1;
        dfs(v, dist, g);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ta, ao;
    cin >> n >> ta >> ao;
    ta--; ao--; // Convert to 0-based indexing

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based indexing
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> ta_dist(n, -1);
    vector<int> ao_dist(n, -1);

    ta_dist[ta] = 0;
    ao_dist[ao] = 0;

    dfs(ta, ta_dist, g);
    dfs(ao, ao_dist, g);

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] == -1 || ao_dist[i] == -1 || ta_dist[i] > ao_dist[i]) continue;
        res = max(res, ao_dist[i]);
    }

    cout << res - 1 << endl;

    return 0;
}

// <END-OF-CODE>
