

#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
 int id;
 int to;
} Edge;

typedef struct {
 int *ans;
 int n;
 int **g;
} Graph;

void dfs(Graph *g, int to, int color, int parents) {
 int k = 1;
 for (int i = 0; i < g->n; i++) {
 Edge e = g->g[to][i];
 if (e.to == parents) continue;
 if (k == color) k++;
 g->ans[e.id] = k;
 dfs(g, e.to, k, to);
 k++;
 }
}

int main() {
 int n;
 scanf("%d", &n);
 Graph g;
 g.n = n;
 g.ans = (int *)malloc(sizeof(int) * (n - 1));
 g.g = (int **)malloc(sizeof(int *) * n);
 for (int i = 0; i < n; i++) {
 g.g[i] = (int *)malloc(sizeof(int) * n);
 }
 for (int i = 0; i < n - 1; i++) {
 int a, b;
 scanf("%d %d", &a, &b);
 g.g[a - 1][b - 1] = i;
 g.g[b - 1][a - 1] = i;
 }
 dfs(&g, 0, -1, -1);
 int max = 0;
 for (int i = 0; i < n - 1; i++) {
 if (g.ans[i] > max) max = g.ans[i];
 }
 printf("%d\n", max);
 for (int i = 0; i < n - 1; i++) {
 printf("%d\n", g.ans[i]);
 }
 return 0;
}

