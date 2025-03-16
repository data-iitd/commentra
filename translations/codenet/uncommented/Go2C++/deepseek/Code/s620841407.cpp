#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF_INT 2147483647
#define INF_LONG 9223372036854775807

struct Edge {
    int to, rev;
};

vector<Edge> G[100000];
int dp[100000][2];

void dfs1(int v, int p) {
    dp[v][0] = 1;
    dp[v][1] = 0;
    for (auto &e : G[v]) {
        if (e.to == p) continue;
        dfs1(e.to, v);
        dp[v][0] += min(dp[e.to][0] + e.rev, dp[e.to][1]);
        dp[v][1] += dp[e.to][0] + e.rev;
    }
}

void dfs2(int v, int p) {
    for (auto &e : G[v]) {
        if (e.to == p) continue;
        int to = e.to;
        int rev = e.rev;
        dp[to][0] += min(dp[v][0] + rev, dp[v][1]);
        dp[to][1] += dp[v][0] + rev;
        dfs2(to, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back((Edge){y, 1});
        G[y].push_back((Edge){x, 1});
    }

    dfs1(0, -1);
    dfs2(0, -1);

    for (int i = 0; i < n; i++) {
        cout << min(dp[i][0], dp[i][1]) << endl;
    }

    return 0;
}
