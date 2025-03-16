
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

vector<vector<int>> graph;

ll dfs(int fro, int to, int f) {
    ll caseNum = f;
    int colorNum = K - 1;
    if (f == K) colorNum--;

    for (int u : graph[fro]) {
        if (u == to) continue;
        ll pat = dfs(u, fro, colorNum);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = caseNum * pat % MOD;
        colorNum--;
    }

    return caseNum;
}

int main() {
    int N, K;
    cin >> N >> K;

    graph.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll ans = dfs(0, -1, K);
    cout << ans << endl;

    return 0;
}

