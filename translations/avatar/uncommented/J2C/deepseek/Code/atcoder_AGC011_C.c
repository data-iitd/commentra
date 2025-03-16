#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int size;
    int *data;
} ArrayList;

ArrayList* createArrayList(int size) {
    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
    list->size = size;
    list->data = (int*)malloc(size * sizeof(int));
    return list;
}

void addEdge(ArrayList *graph[], int u, int v) {
    graph[u]->data[graph[u]->size++] = v;
    graph[v]->data[graph[v]->size++] = u;
}

void dfs(ArrayList *graph[], bool visited[], int color[], int a, int c, int *total, bool *mujun) {
    if (visited[a]) {
        if (color[a] >= 0 && color[a] != c) *mujun = true;
        return;
    }
    visited[a] = true;
    color[a] = c;
    (*total)++;
    for (int i = 0; i < graph[a]->size; i++) {
        dfs(graph, visited, color, graph[a]->data[i], 1 - c, total, mujun);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ArrayList *graph[n];
    for (int i = 0; i < n; i++) {
        graph[i] = createArrayList(0);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u - 1, v - 1);
    }
    bool visited[n];
    int color[n];
    memset(color, -1, sizeof(color));
    long one = 0, bipartite = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        count++;
        bool mujun = false;
        int kind = 0;
        dfs(graph, visited, color, i, 0, &kind, &mujun);
        if (kind == 1) one++;
        else if (!mujun) bipartite++;
    }
    long total = one * (2 * n - one) + (count - one) * (count - one) + bipartite * bipartite;
    printf("%ld\n", total);
    for (int i = 0; i < n; i++) {
        free(graph[i]->data);
        free(graph[i]);
    }
    return 0;
}
