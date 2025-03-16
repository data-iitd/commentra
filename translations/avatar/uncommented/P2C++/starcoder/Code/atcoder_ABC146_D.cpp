#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> G(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int K = -1;
    vector<int> node2color(N, -1);
    queue<int> queue;
    queue.push(0);
    vector<int> visited(N, 0);
    visited[0] = 1;
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
            queue.push(nex);
        }
        K = max(K, color);
    }
    cout << K << "\n";
    for (auto value : node2color) cout << value << " ";
    cout << "\n";
    return 0;
}
