#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int N, K;
vector<vector<int>> graph;

int dfs(int fro, int to, int f) {
    int caseNum = f;
    int colorNum = K - 1;
    if (f == K) {
        colorNum = K - 2;
    }
    for (int u : graph[fro]) {
        if (u == to) {
            continue;
        }
        int pat = dfs(u, fro, colorNum);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % mod;
        colorNum--;
    }
    return caseNum;
}

int main() {
    cin >> N >> K;
    graph.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    int ans = dfs(0, -1, K);
    cout << ans << endl;
    return 0;
}

