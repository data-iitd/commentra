#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
#define INF 1000000000
#define MOD 1000000007
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

int n, m, ci, cb, cc;
int vis[MAX], g[MAX][MAX];

int dfs(int x) {
    int i, u, v, flag = 1;
    for (i = 0; i < n; i++) {
        if (vis[i] == 0) {
            if (len(g[i]) == 0) {
                ci++;
            } else {
                if (dfs(i)) {
                    cb++;
                } else {
                    cc++;
                }
            }
        }
    }
    return flag;
}

int main() {
    int i, j, u, v;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;
    }
    dfs(1);
    printf("%d\n", ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
    return 0;
}

