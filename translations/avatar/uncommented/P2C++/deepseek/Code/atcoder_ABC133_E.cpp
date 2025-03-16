#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

vector<vector<int>> graph;
int N, K;

int dfs(int fro, int to, int f) {
    long long caseNum = f;
    int colorNum = (f == K) ? K - 1 : K - 2;
    for (int u : graph[fro]) {
        if (u == to) continue;
        long long pat = dfs(u, fro, colorNum);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = caseNum * pat % MOD;
        colorNum--;
    }
    return static_cast<int>(caseNum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    graph.resize(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    int ans = dfs(0, -1, K);
    cout << ans << '\n';

    return 0;
}
