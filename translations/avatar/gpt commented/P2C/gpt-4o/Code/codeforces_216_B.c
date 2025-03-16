#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

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
        if (set->data[i] == value) return; // Avoid duplicates
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
    Set adj[MAX_NODES + 1];
} Graph;

void initGraph(Graph *g, int n) {
    for (int i = 1; i <= n; i++) {
        initSet(&g->adj[i]);
    }
}

void addEdge(Graph *g, int a, int b) {
    addToSet(&g->adj[a], b);
    addToSet(&g->adj[b], a);
}

void dfs(Graph *g, Set *seen, int i, int *nodes, int *edges) {
    if (contains(seen, i)) return; // If already seen, return
    addToSet(seen, i); // Mark the current node as seen
    (*nodes)++; // Count the current node
    *edges += g->adj[i].size; // Count the edges connected to the current node
    for (int j = 0; j < g->adj[i].size; j++) {
        dfs(g, seen, g->adj[i].data[j], nodes, edges); // Recursively visit all adjacent nodes
    }
}

bool solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return false; // Read n and m
    Graph g;
    initGraph(&g, n);
    Set seen;
    initSet(&seen);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Read each edge
        addEdge(&g, a, b);
    }
    
    int ans = 0; // Initialize the answer counter
    for (int i = 1; i <= n; i++) {
        if (!contains(&seen, i)) {
            int nodes = 0, edges = 0;
            dfs(&g, &seen, i, &nodes, &edges); // Perform DFS
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++; // Increment the answer if conditions are met
            }
        }
    }
    
    if ((n - ans) % 2 == 1) {
        ans++; // Adjust the answer if the remaining nodes are odd
    }
    
    printf("%d\n", ans); // Output the final answer
    freeSet(&seen);
    for (int i = 1; i <= n; i++) {
        freeSet(&g.adj[i]); // Free each adjacency set
    }
    return true; // Return true to indicate successful processing
}

int main() {
    while (solve()) {
        // Continuously solve the problem until EOF is reached
    }
    return 0;
}

// <END-OF-CODE>
