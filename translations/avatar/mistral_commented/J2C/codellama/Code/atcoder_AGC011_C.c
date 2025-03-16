
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000000

typedef struct {
  int *graph;
  bool *visited;
  int *color;
  long one;
  long bipartite;
  long count;
  bool mujun;
} Graph;

void dfs(Graph *g, int a, int c) {
  if (g->visited[a]) {
    if (g->color[a] >= 0 && g->color[a] != c) g->mujun = true;
    return;
  }
  g->visited[a] = true;
  g->color[a] = c;
  int total = 1;
  for (int b = 0; b < g->graph[a]; b++) {
    total += dfs(g, b, 1 - c);
  }
  return total;
}

int main() {
  Graph g;
  g.graph = (int *)malloc(MAX * sizeof(int));
  g.visited = (bool *)malloc(MAX * sizeof(bool));
  g.color = (int *)malloc(MAX * sizeof(int));
  g.one = 0;
  g.bipartite = 0;
  g.count = 0;
  g.mujun = false;
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    g.graph[i] = 0;
    g.visited[i] = false;
    g.color[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g.graph[u]++;
    g.graph[v]++;
  }
  for (int i = 0; i < n; i++) {
    if (g.visited[i]) continue;
    g.count++;
    g.mujun = false;
    int kind = dfs(&g, i, 0);
    if (kind == 1) g.one++;
    else if (!g.mujun) g.bipartite++;
  }
  long total = g.one * (2 * n - g.one);
  total += (g.count - g.one) * (g.count - g.one);
  total += g.bipartite * g.bipartite;
  printf("%ld\n", total);
  return 0;
}

