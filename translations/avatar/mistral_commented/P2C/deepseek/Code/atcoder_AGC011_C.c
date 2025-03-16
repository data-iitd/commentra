#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100001

int n, m;
int vis[MAX_N];
int ci, cb, cc;
int g[MAX_N][MAX_N];
int g_size[MAX_N];

void dfs(int x, int col) {
    int stack[MAX_N];
    int top = -1;
    int flag = 1;

    stack[++top] = x;
    vis[x] = col;

    while (top >= 0) {
        int u = stack[top--];

        for (int i = 0; i < g_size[u]; i++) {
            int v = g[u][i];
            if (vis[v]) {
                flag &= (vis[v] == 3 - col);
                continue;
            }
            vis[v] = 3 - col;
            stack[++top] = v;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][g_size[u]++] = v;
        g[v][g_size[v]++] = u;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (g_size[i] == 0) {
                ci++;
            } else {
                dfs(i, 1);
                cb++;
            }
        }
    }

    printf("%d\n", ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);

    return 0;
}
