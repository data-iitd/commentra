#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

// Function to initialize an ArrayList
void initArrayList(ArrayList *list) {
    list->size = 0;
    list->capacity = 10;
    list->data = (int *)malloc(list->capacity * sizeof(int));
}

// Function to add an element to the ArrayList
void addToArrayList(ArrayList *list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

// Global variables
ArrayList graph[MAX_NODES];
bool visited[MAX_NODES];
int color[MAX_NODES];
long one, bipartite, count;
bool mujun;

// Depth-First Search (DFS) function
int dfs(int a, int c) {
    if (visited[a]) {
        if (color[a] >= 0 && color[a] != c) mujun = true;
        return 0;
    }
    visited[a] = true;
    color[a] = c;
    int total = 1;

    for (int i = 0; i < graph[a].size; i++) {
        total += dfs(graph[a].data[i], 1 - c);
    }
    return total;
}

// Main function
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize the graph
    for (int i = 0; i < n; i++) {
        initArrayList(&graph[i]);
    }

    // Read edges and populate the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; // Convert to 0-based index
        v--; // Convert to 0-based index
        addToArrayList(&graph[u], v);
        addToArrayList(&graph[v], u);
    }

    // Initialize visited and color arrays
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        color[i] = -1; // Set all colors to -1 (uncolored)
    }

    // Initialize counters
    one = 0;
    bipartite = 0;
    count = 0;

    // Iterate through all nodes to find connected components
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue; // Skip already visited nodes
        count++; // Increment component count
        mujun = false; // Reset bipartite flag
        int kind = dfs(i, 0); // Perform DFS starting from node i

        // Update counters based on the results of DFS
        if (kind == 1) one++;
        else if (!mujun) bipartite++;
    }

    // Calculate the total based on the counts of components
    long total = one * (2 * n - one);
    total += (count - one) * (count - one);
    total += bipartite * bipartite;

    // Output the final result
    printf("%ld\n", total);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(graph[i].data);
    }

    return 0;
}

// <END-OF-CODE>
