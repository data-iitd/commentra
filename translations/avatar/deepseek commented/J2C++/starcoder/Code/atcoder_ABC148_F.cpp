
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

int main() {
    int N, u, v;
    cin >> N >> u >> v;
    u--;
    v--;
    vector<list<int>> edges(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int d[N];
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u] = 0;
    dfs(u, d, edges);
    int e[N];
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
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

void dfs(int u, int d[], vector<list<int>> &edges) {
    for (auto it = edges[u].begin(); it!= edges[u].end(); it++) {
        if (d[*it] == INT_MAX) {
            d[*it] = d[u] + 1;
            dfs(*it, d, edges);
        }
    }
}

