
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges(N);
    vector<int> degs(N, 0);
    vector<int> parity(N, 0);
    vector<bool> flag(N, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        degs[a]++;
        degs[b]++;
    }

    if (M % 2!= 0) {
        cout << -1 << endl;
        return 0;
    }

    priority_queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) {
        Q.push({degs[i], i});
    }

    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        if (flag[u]) {
            continue;
        }
        flag[u] = true;
        for (int i = 0; i < edges[u].size(); i++) {
            int v = edges[u][i];
            if (flag[v]) {
                continue;
            }
            if (parity[u]!= 0 && i == 0) {
                cout << u + 1 << " " << v + 1 << endl;
                parity[u] = 1 - parity[u];
            } else {
                cout << v + 1 << " " << u + 1 << endl;
                parity[v] = 1 - parity[v];
            }
            degs[v]--;
            Q.push({degs[v], v});
        }
    }

    return 0;
}
