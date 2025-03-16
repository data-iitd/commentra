#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

void initArrayList(ArrayList *list) {
    list->size = 0;
    list->capacity = 10;
    list->data = (int *)malloc(list->capacity * sizeof(int));
}

void addToArrayList(ArrayList *list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

ArrayList graph[MAX_N];
bool visited[MAX_N];
int color[MAX_N];
long one, bipartite, count;
bool mujun;

int dfs(int a, int c) {
    if (visited[a]) {
        if (color[a] >= 0 && color[a] != c) {
            mujun = true;
        }
        return 0;
    }
    visited[a] = true;
    color[a] = c;
    int total = 1;
    for (int i = 0; i < graph[a].size; ++i) {
        total += dfs(graph[a].data[i], 1 - c);
    }
    return total;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        initArrayList(&graph[i]);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--; // Convert to 0-based index
        addToArrayList(&graph[u], v);
        addToArrayList(&graph[v], u);
    }

    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        color[i] = -1;
    }

    one = 0;
    bipartite = 0;
    count = 0;

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        count++;
        mujun = false;
        int kind = dfs(i, 0);
        if (kind == 1) {
            one++;
        } else if (!mujun) {
            bipartite++;
        }
    }

    long total = one * (2 * n - one);
    total += (count - one) * (count - one);
    total += bipartite * bipartite;

    printf("%ld\n", total);

    // Free allocated memory
    for (int i = 0; i < n; ++i) {
        free(graph[i].data);
    }

    return 0;
}

// <END-OF-CODE>
