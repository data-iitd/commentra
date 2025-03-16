#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int id;
    int to;
} Edge;

int n;
Edge** g;
int* ans;

void dfs(int to, int color, int parent, int* k) {
    int i;
    for (i = 0; i < n; i++) {
        if (g[to][i].to == parent) continue;
        if (*k == color) (*k)++;
        ans[g[to][i].id] = *k;
        dfs(g[to][i].to, *k, to, k);
        (*k)++;
    }
}

int main() {
    int i, a, b;
    scanf("%d", &n);
    g = (Edge**)malloc(n * sizeof(Edge*));
    for (i = 0; i < n; i++) {
        g[i] = (Edge*)malloc((n - 1) * sizeof(Edge));
    }
    for (i = 0; i < n - 1; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a][i].id = i;
        g[a][i].to = b;
        g[b][i].id = i;
        g[b][i].to = a;
    }
    ans = (int*)malloc((n - 1) * sizeof(int));
    int k = 1;
    dfs(0, -1, -1, &k);
    int max = 0;
    for (i = 0; i < n - 1; i++) {
        if (ans[i] > max) max = ans[i];
    }
    printf("%d\n", max);
    for (i = 0; i < n - 1; i++) {
        printf("%d\n", ans[i]);
    }
    for (i = 0; i < n; i++) {
        free(g[i]);
    }
    free(g);
    free(ans);
    return 0;
}
