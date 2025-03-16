#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} Set;

void initSet(Set *set) {
    set->size = 0;
    set->capacity = 10;
    set->data = (int *)malloc(set->capacity * sizeof(int));
}

void addToSet(Set *set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == value) return; // Already in set
    }
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->data = (int *)realloc(set->data, set->capacity * sizeof(int));
    }
    set->data[set->size++] = value;
}

bool contains(Set *set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == value) return true;
    }
    return false;
}

void freeSet(Set *set) {
    free(set->data);
}

typedef struct {
    Set *adj;
    int n;
} Graph;

void initGraph(Graph *g, int n) {
    g->n = n;
    g->adj = (Set *)malloc((n + 1) * sizeof(Set));
    for (int i = 1; i <= n; i++) {
        initSet(&g->adj[i]);
    }
}

void addEdge(Graph *g, int a, int b) {
    addToSet(&g->adj[a], b);
    addToSet(&g->adj[b], a);
}

void freeGraph(Graph *g) {
    for (int i = 1; i <= g->n; i++) {
        freeSet(&g->adj[i]);
    }
    free(g->adj);
}

void dfs(Graph *g, Set *seen, int i, int *nodes, int *edges) {
    if (contains(seen, i)) return;
    addToSet(seen, i);
    (*nodes)++;
    *edges += g->adj[i].size;
    for (int j = 0; j < g->adj[i].size; j++) {
        dfs(g, seen, g->adj[i].data[j], nodes, edges);
    }
}

bool solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return false;

    Graph g;
    initGraph(&g, n);
    Set seen;
    initSet(&seen);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(&g, a, b);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!contains(&seen, i)) {
            int nodes = 0, edges = 0;
            dfs(&g, &seen, i, &nodes, &edges);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;
            }
        }
    }

    if ((n - ans) % 2 == 1) {
        ans++;
    }
    printf("%d\n", ans);

    freeSet(&seen);
    freeGraph(&g);
    return true;
}

int main() {
    while (solve());
    return 0;
}

// <END-OF-CODE>
