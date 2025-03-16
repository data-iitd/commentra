
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <queue.h>

#define MAXN 100000

int n, m, vis[MAXN + 1], ci, cb, cc;
int g[MAXN + 1][2];

bool dfs(int x) {
    queue_t *stk = queue_create();
    bool flag = true;
    queue_push(stk, x);
    queue_push(stk, 1);
    while (!queue_empty(stk)) {
        int u = queue_pop(stk);
        int col = queue_pop(stk);
        if (vis[u]) {
            flag &= (vis[u] == col);
            continue;
        }
        vis[u] = col;
        for (int i = 0; i < g[u][0]; i++) {
            int v = g[u][i + 1];
            queue_push(stk, v);
            queue_push(stk, 3 - col);
        }
    }
    return flag;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(vis, 0, sizeof(vis));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][0]++;
        g[u][g[u][0]] = v;
        g[v][0]++;
        g[v][g[v][0]] = u;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (g[i][0] == 0) {
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
    printf("%d\n", ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
    return 0;
}
