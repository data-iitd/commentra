#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void dfs(int u, vector<int>& d, const vector<vector<int>>& edges) {
    for (int nu : edges[u]) {
        if (d[nu] == numeric_limits<int>::max()) {
            d[nu] = d[u] + 1;
            dfs(nu, d, edges);
        }
    }
}

int main() {
    int N, u, v;
    cin >> N >> u >> v;
    u--; // Convert to 0-based index
    v--; // Convert to 0-based index

    vector<vector<int>> edges(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> d(N, numeric_limits<int>::max());
    d[u] = 0;
    dfs(u, d, edges);

    vector<int> e(N, numeric_limits<int>::max());
    e[v] = 0;
    dfs(v, e, edges);

    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    if (q <= 0) {
        cout << 0 << endl;
    } else {
        cout << q - 1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
