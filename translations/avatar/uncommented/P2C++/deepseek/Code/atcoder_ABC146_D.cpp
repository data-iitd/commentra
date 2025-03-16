#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int bfs(int v, int N, vector<vector<int>>& G, map<pair<int, int>, int>& E) {
    vector<int> visited(N, 0);
    queue<int> queue;
    int K = -1;
    vector<int> node2color(N, -1);
    queue.push(v);
    visited[v] = 1;
    while (!queue.empty()) {
        int q = queue.front();
        queue.pop();
        int color = 0;
        for (int nex : G[q]) {
            if (visited[nex]) continue;
            visited[nex] = 1;
            color++;
            if (color == node2color[q]) color++;
            node2color[nex] = color;
            E[{min(q, nex), max(q, nex)}] = color;
            queue.push(nex);
        }
        K = max(K, color);
    }
    return K;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    map<pair<int, int>, int> E;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        E[{a, b}] = 0;
    }
    int K = bfs(0, N, G, E);
    cout << K << endl;
    for (auto& value : E) {
        cout << value.second << endl;
    }
    return 0;
}

