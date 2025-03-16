#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MOD = 1000000007;

vector<vector<int>> graph;
vector<int> colors;
int N, K;

long long dfs(int fro, int to, int f) {
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

    return caseNum;
}

int main() {
    cin >> N >> K;
    graph.resize(N);
    colors.resize(N);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    long long ans = dfs(0, -1, K);
    cout << ans << endl;

    return 0;
}
