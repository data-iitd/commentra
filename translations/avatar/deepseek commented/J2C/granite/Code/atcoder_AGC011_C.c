
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList(int capacity) {
    ArrayList *arrList = (ArrayList*)malloc(sizeof(ArrayList));
    arrList->arr = (int*)malloc(sizeof(int) * capacity);
    arrList->size = 0;
    arrList->capacity = capacity;
    return arrList;
}

void add(ArrayList *arrList, int value) {
    if (arrList->size == arrList->capacity) {
        arrList->capacity *= 2;
        arrList->arr = (int*)realloc(arrList->arr, sizeof(int) * arrList->capacity);
    }
    arrList->arr[arrList->size++] = value;
}

void dfs(ArrayList **graph, bool *visited, int *color, int node, int c) {
    if (visited[node]) {
        if (color[node] >= 0 && color[node]!= c) {
            mujun = true;
        }
        return;
    }
    visited[node] = true;
    color[node] = c;
    int total = 1;
    for (int i = 0; i < graph[node]->size; i++) {
        int neighbor = graph[node]->arr[i];
        total += dfs(graph, visited, color, neighbor, 1 - c);
    }
    return total;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ArrayList **graph = (ArrayList**)malloc(sizeof(ArrayList*) * n);
    for (int i = 0; i < n; i++) {
        graph[i] = createArrayList(n);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add(graph[u - 1], v - 1);
        add(graph[v - 1], u - 1);
    }
    bool *visited = (bool*)malloc(sizeof(bool) * n);
    int *color = (int*)malloc(sizeof(int) * n);
    memset(color, -1, sizeof(int) * n);
    long one = 0, bipartite = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        count++;
        mujun = false;
        int kind = dfs(graph, visited, color, i, 0);
        if (kind == 1) one++;
        else if (!mujun) bipartite++;
    }
    long total = one * (2 * n - one) + (count - one) * (count - one) + bipartite * bipartite;
    printf("%ld\n", total);
    return 0;
}

