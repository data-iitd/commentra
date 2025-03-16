#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

int bfs(int v, int N, vector<deque<int>>& G, map<pair<int, int>, int>& E) {
    vector<int> visited(N, 0);
    deque<int> queue;
    int K = -1;
    vector<int> node2color(N, -1);
    queue.push_back(v);
    visited[v] = 1;

    while (!queue.empty()) {
        int q = queue.front();
        queue.pop_front();
        int color = 0;

        for (int nex : G[q]) {
            if (visited[nex]) {
                continue;
            }
            visited[nex] = 1;
            color += 1;

            if (color == node2color[q]) {
                color += 1;
            }
            node2color[nex] = color;
            E[{min(q, nex), max(q, nex)}] = color;
            queue.push_back(nex);
        }
        K = max(K, color);
    }
    return K;
}

int main() {
    int N;
    cin >> N;
    vector<deque<int>> G(N);
    map<pair<int, int>, int> E;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        G[a].push_back(b);
        G[b].push_back(a);
        E[{a, b}] = 0;
    }

    int K = bfs(0, N, G, E);
    cout << K << endl;

    for (const auto& value : E) {
        cout << value.second << endl;
    }

    return 0;
}

// <END-OF-CODE>
