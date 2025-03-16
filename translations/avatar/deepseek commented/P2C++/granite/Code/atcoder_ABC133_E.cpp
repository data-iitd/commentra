
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;
vector<int> G[N];
int n, k, ans;

void dfs(int u, int f, int c) {
    int tmp = c;
    for (int v : G[u]) {
        if (v == f) continue;
        if (c == k) {
            dfs(v, u, 1);
        } else {
            dfs(v, u, c + 1);
        }
    }
    if (c == k) {
        ans = 1ll * ans * tmp % mod;
    } else {
        ans = 1ll * ans * (k - c) % mod;
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = 1;
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}

