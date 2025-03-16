#include <stdio.h>
#include <stdlib.h>

int n;
struct Edge {
    int id;
    int to;
};

struct Edge *g[100000];
int ans[100000];

void dfs(int to, int color, int parent) {
    int k = 1;
    for (int i = 0; i < g[to].size(); i++) {
        struct Edge *e = g[to][i];
        if (e->to == parent) continue;
        if (k == color) k++;
        ans[e->id] = k;
        dfs(e->to, k, to);
        k++;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        g[i] = malloc(sizeof(struct Edge) * 100000);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a - 1][i].id = i;
        g[a - 1][i].to = b - 1;
        g[b - 1][i].id = i;
        g[b - 1][i].to = a - 1;
    }
    dfs(0, -1, -1);
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        max = max > ans[i]? max : ans[i];
    }
    printf("%d\n", max);
    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

