#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100005

int n, m, ci = 0, cb = 0, cc = 0;
int vis[MAXN], g[MAXN][MAXN];
bool flag;

void dfs(int x, int col) {
    int stack[MAXN], top = 0;
    stack[top++] = x;
    vis[x] = col;

    while (top > 0) {
        int u = stack[--top];
        int col_u = vis[u];

        for (int i = 0; i < g[u][0]; i++) {
            int v = g[u][i + 1];
            if (vis[v] == 0) {
                vis[v] = 3 - col_u;
                stack[top++] = v;
            } else {
                flag &= (vis[v] == 3 - col_u);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][++g[u][0]] = v;
        g[v][++g[v][0]] = u;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (g[i][0] == 0) {
                ci++;
            } else {
                flag = true;
                dfs(i, 1);
                if (flag) {
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
