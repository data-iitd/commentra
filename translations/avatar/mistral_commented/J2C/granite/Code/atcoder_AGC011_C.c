

#include < stdio.h >
#include < stdbool.h >
#include < string.h >
#include < math.h >
#include < time.h >
#include < assert.h >
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>

typedef int64_t Int;
typedef uint64_t UInt;

typedef struct {
  int size;
  int *arr;
} ArrayList;

ArrayList* newArrayList(int size,...) {
  ArrayList *arr = (ArrayList*)malloc(sizeof(ArrayList));
  arr->size = size;
  arr->arr = (int*)malloc(sizeof(int) * size);
  va_list args;
  va_start(args, size);
  for (int i = 0; i < size; i++) {
    arr->arr[i] = va_arg(args, int);
  }
  va_end(args);
  return arr;
}

void add(ArrayList *arr, int val) {
  arr->arr[arr->size++] = val;
}

typedef struct {
  bool *visited;
  int *color;
  int count;
  bool mujun;
  int one;
  int bipartite;
} Graph;

Graph* newGraph(int n) {
  Graph *graph = (Graph*)malloc(sizeof(Graph));
  graph->visited = (bool*)malloc(sizeof(bool) * n);
  graph->color = (int*)malloc(sizeof(int) * n);
  memset(graph->visited, 0, sizeof(bool) * n);
  memset(graph->color, -1, sizeof(int) * n);
  graph->count = 0;
  graph->mujun = false;
  graph->one = 0;
  graph->bipartite = 0;
  return graph;
}

void dfs(Graph *graph, int a, int c) {
  if (graph->visited[a]) {
    if (graph->color[a] >= 0 && graph->color[a]!= c) {
      graph->mujun = true;
    }
    return;
  }
  graph->visited[a] = true;
  graph->color[a] = c;
  graph->count++;
  for (int i = 0; i < graph->graph[a].size; i++) {
    int b = graph->graph[a].arr[i];
    dfs(graph, b, 1 - c);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Graph *graph = newGraph(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    add(&graph->graph[u - 1], v - 1);
    add(&graph->graph[v - 1], u - 1);
  }
  for (int i = 0; i < n; i++) {
    if (!graph->visited[i]) {
      dfs(graph, i, 0);
      if (graph->count == 1) {
        graph->one++;
      } else if (!graph->mujun) {
        graph->bipartite++;
      }
    }
  }
  long total = (long)graph->one * (2 * n - graph->one);
  total += (long)(n - graph->one) * (n - graph->one);
  total += (long)graph->bipartite * graph->bipartite;
  printf("%ld\n", total);
  return 0;
}

Translate the above C code to Python and end with comment "