#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

#define INF INT_MAX

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N);
    for (int i = 0; i < M; ++i) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        --X; --Y;
        edge[X].push_back(Y);
        edge[Y].push_back(X);
    }
    vector<bool> used(N, false);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            ++ans;
            queue<int> queue;
            queue.push(i);
            while (!queue.empty()) {
                int node = queue.front();
                queue.pop();
                used[node] = true;
                for (int nextnode : edge[node]) {
                    if (!used[nextnode]) {
                        queue.push(nextnode);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

