
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
vector<int> G[MAXN];
ll dfs(int u, int p, int k) {
    ll ret = 1;
    int c = k - 1;
    for (int v : G[u]) {
        if (v == p) continue;
        if (c == 0) return 0;
        ret = ret * dfs(v, u, c - 1) % MOD;
        c--;
    }
    return ret;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    printf("%lld\n", dfs(1, 0, k));
    return 0;
}

