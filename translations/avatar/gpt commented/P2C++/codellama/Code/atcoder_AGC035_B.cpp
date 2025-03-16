#include <iostream>
#include <vector>
#include <queue>

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
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
        degs[a - 1]++;
        degs[b - 1]++;
    }

    if (M % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    priority_queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) {
        Q.push(make_pair(degs[i], i));
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
            edges[v].erase(remove(edges[v].begin(), edges[v].end(), u), edges[v].end());
            if (parity[u] != 0 && i == 0) {
                cout << u + 1 << " " << v + 1 << endl;
                parity[u] = 1 - parity[u];
            } else {
                cout << v + 1 << " " << u + 1 << endl;
                parity[v] = 1 - parity[v];
            }
            degs[v]--;
            Q.push(make_pair(degs[v], v));
        }
    }

    return 0;
}

