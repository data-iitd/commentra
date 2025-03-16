#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<set<int>> edges(N);
    vector<int> degs(N, 0);
    vector<int> parity(N, 0);
    vector<bool> flag(N, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].insert(b - 1);
        edges[b - 1].insert(a - 1);
        degs[a - 1]++;
        degs[b - 1]++;
    }

    if (M % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for (int i = 0; i < N; i++) {
        Q.push(make_pair(degs[i], i));
    }

    while (!Q.empty()) {
        auto top = Q.top();
        Q.pop();
        int u = top.second;

        if (flag[u]) {
            continue;
        }
        flag[u] = true;

        int i = 0;
        for (int v : edges[u]) {
            edges[v].erase(u);
            if (parity[u] != 0 && i == 0) {
                cout << u + 1 << " " << v + 1 << endl;
                parity[u] = 1 - parity[u];
            } else {
                cout << v + 1 << " " << u + 1 << endl;
                parity[v] = 1 - parity[v];
            }
            degs[v]--;
            Q.push(make_pair(degs[v], v));
            i++;
        }
    }

    return 0;
}

// <END-OF-CODE>
