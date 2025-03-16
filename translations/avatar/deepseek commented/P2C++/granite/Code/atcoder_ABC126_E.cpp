
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
        int X, Y, Z;
        cin >> X >> Y >> Z;
        X--;
        Y--;
        edge[X].push_back(Y);
        edge[Y].push_back(X);
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
                if (!used[node]) {
                    used[node] = true;
                    for (int nextnode : edge[node]) {
                        if (!used[nextnode]) {
                            que.push(nextnode);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
