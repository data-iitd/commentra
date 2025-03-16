#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList(int capacity) {
    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = (int*)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void addEdge(ArrayList *list, int u, int v) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = v;
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
        graph[i] = createArrayList(10);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        addEdge(graph[u], v);
        addEdge(graph[v], u);
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
