#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MOD = 1e9 + 7;

void ta_dfs(int node, vector<int>& ta_dist, const vector<vector<int>>& g) {
    for (int v : g[node]) {
        if (ta_dist[v] != -1) continue;
        ta_dist[v] = ta_dist[node] + 1;
        ta_dfs(v, ta_dist, g);
    }
}

void ao_dfs(int node, vector<int>& ao_dist, const vector<vector<int>>& g) {
    for (int v : g[node]) {
        if (ao_dist[v] != -1) continue;
        ao_dist[v] = ao_dist[node] + 1;
        ao_dfs(v, ao_dist, g);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ta, ao;
    cin >> n >> ta >> ao;
    ta--; ao--;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<int> ta_dist(n, -1);
    ta_dist[ta] = 0;
    vector<int> ao_dist(n, -1);
    ao_dist[ao] = 0;

    ao_dfs(ao, ao_dist, g);
    ta_dfs(ta, ta_dist, g);

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) continue;
        res = max(res, ao_dist[i]);
    }

    cout << res - 1 << endl;

    return 0;
}

// <END-OF-CODE>
