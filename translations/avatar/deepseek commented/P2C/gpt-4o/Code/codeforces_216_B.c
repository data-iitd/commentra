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

void dfs(int g[MAX_NODES][MAX_NODES], Set *seen, int *nodes, int *edges, int i, int n) {
    if (contains(seen, i)) return;
    addToSet(seen, i);
    (*nodes)++;
    *edges += g[i][0]; // Count edges from the current node
    for (int j = 1; j <= g[i][0]; j++) {
        dfs(g, seen, g[i][j], nodes, edges, n);
    }
}

bool solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return false; // Read the first line of input

    int g[MAX_NODES][MAX_NODES] = {0}; // Initialize the graph
    Set seen;
    initSet(&seen);

    for (int i = 0; i < m; i++) { // Read each edge and add it to the graph
        int a, b;
        scanf("%d %d", &a, &b);
        g[a][0]++; // Increment edge count for node a
        g[a][g[a][0]] = b; // Add b to adjacency list of a
        g[b][0]++; // Increment edge count for node b
        g[b][g[b][0]] = a; // Add a to adjacency list of b
    }

    int ans = 0; // Initialize the answer variable
    for (int i = 1; i <= n; i++) { // Traverse each node in the graph
        if (!contains(&seen, i)) { // If the node is not seen, perform DFS
            int nodes = 0, edges = 0;
            dfs(g, &seen, &nodes, &edges, i, n); // Get the count of nodes and edges
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) { // Check the conditions
                ans++; // Increment the answer if the conditions are met
            }
        }
    }

    if ((n - ans) % 2 == 1) { // Check if the number of disconnected components is odd
        ans++; // Increment the answer if necessary
    }
    printf("%d\n", ans); // Print the final answer
    freeSet(&seen);
    return true; // Return true to continue the loop
}

int main() {
    while (solve()); // Continuously call solve until it returns false
    return 0;
}

// <END-OF-CODE>
