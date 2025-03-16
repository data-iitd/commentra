
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <queue.h>

int n, m;
int vis[100005];
int ci, cb, cc;
int g[100005][2];

bool dfs(int x) {
    queue_t *stk = queue_create();
    bool flag = true;
    queue_push(stk, x);
    queue_push(stk, 1);
    while (!queue_empty(stk)) {
        int u = queue_front(stk);
        queue_pop(stk);
        int col = queue_front(stk);
        queue_pop(stk);
        if (vis[u]) {
            flag &= (vis[u] == col);
            continue;
        }
        vis[u] = col;
        for (int i = 0; i < g[u][0]; i++) {
            queue_push(stk, g[u][i + 1]);
            queue_push(stk, 3 - col);
        }
    }
    return flag;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][g[u][0]++] = v;
        g[v][g[v][0]++] = u;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
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
    printf("%d * %d + 2 * %d * (%d - %d) + %d * %d + 2 * %d * %d + 2 * %d * %d\n", ci, ci, ci, n, ci, cc, cc, cb, cc, cb, cb);
    return 0;
}
