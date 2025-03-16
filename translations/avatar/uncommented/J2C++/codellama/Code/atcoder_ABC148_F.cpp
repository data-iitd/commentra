
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std;

int main() {
    int N;
    cin >> N;
    int u, v;
    cin >> u >> v;
    vector<list<int>> edges(N);
    for (int i = 0; i < N; i++) {
        edges[i] = list<int>();
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    int *d = new int[N];
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u - 1] = 0;
    dfs(u - 1, d, edges);
    int *e = new int[N];
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v - 1] = 0;
    dfs(v - 1, e, edges);
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

void dfs(int u, int *d, vector<list<int>> &edges) {
    for (int nu : edges[u]) {
        if (d[nu] == INT_MAX) {
            d[nu] = d[u] + 1;
            dfs(nu, d, edges);
        }
    }
}

