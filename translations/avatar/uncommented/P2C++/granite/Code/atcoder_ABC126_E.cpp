
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    vector<bool> used(N, false);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;
            queue<int> que;
            que.push(i);
            while (!que.empty()) {
                int node = que.front();
                que.pop();
                used[node] = true;
                for (int nextnode : edge[node]) {
                    if (!used[nextnode]) {
                        que.push(nextnode);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// END-OF-CODE