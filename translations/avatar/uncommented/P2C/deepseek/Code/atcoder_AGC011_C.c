#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int n, m;
int vis[MAXN];
int ci, cb, cc;
int g[MAXN][MAXN];
int gr[MAXN];

int dfs(int x, int col) {
    int flag = 1;
    int stack[MAXN], top = 0;
    stack[top++] = x;
    vis[x] = col;

    while (top > 0) {
        int u = stack[--top];
        for (int i = 0; i < gr[u]; i++) {
            int v = g[u][i];
            if (vis[v] == 0) {
                stack[top++] = v;
                vis[v] = 3 - col;
            } else {
                flag &= (vis[v] == 3 - col);
            }
        }
    }
    return flag;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][gr[u]++] = v;
        g[v][gr[v]++] = u;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (gr[i] == 0) {
                ci++;
            } else {
                if (dfs(i, 1)) {
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
