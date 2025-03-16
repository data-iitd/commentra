
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<set<int>> edges(N);
    vector<int> degs(N);
    vector<int> parity(N);
    vector<bool> flag(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].insert(b);
        edges[b].insert(a);
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

        int i = 0;
        for (int v : edges[u]) {
            edges[v].erase(u);
            if (parity[u]!= 0 && i == 0) {
                cout << u + 1 << " " << v + 1 << endl;
                parity[u] = 1 - parity[u];
            } else {
                cout << v + 1 << " " << u + 1 << endl;
                parity[v] = 1 - parity[v];
            }

            degs[v]--;
            Q.push({degs[v], v});
            i++;
        }
    }

    return 0;
}
