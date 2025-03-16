#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

vector<vector<int>> graph;
vector<int> color;
vector<int> visited;

int dfs(int fro, int to, int f) {
    int caseNum = f;
    int colorNum = (f == color.size()) ? (K - 1) : (K - 2);
    for (int u : graph[fro]) {
        if (u == to) continue;
        int pat = dfs(u, fro, colorNum);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = (long long)caseNum * pat % MOD;
        colorNum--;
    }
    return caseNum;
}

int main() {
    int N, K;
    cin >> N >> K;

    graph.resize(N);
    color.resize(N);
    visited.resize(N, 0);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    int ans = dfs(0, -1, K);
    cout << ans << endl;

    return 0;
}
