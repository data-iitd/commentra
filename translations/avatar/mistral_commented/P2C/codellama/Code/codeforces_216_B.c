#######
# Code
#######

# Include header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to read an array of integers from standard input
int* readInts() {
    // Declare variables
    int n, i, j, k;
    char str[100000];
    int* arr;

    // Read the first line of input containing the number of vertices and edges in the graph
    scanf("%d %d", &n, &m);

    // Allocate memory for the array of integers
    arr = (int*)malloc(n * sizeof(int));

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr[a]++;
        arr[b]++;
    }

    // Return the array of integers
    return arr;
}

// Function to traverse the graph and calculate nodes and edges for a given vertex
void dfs(int* g, int* seen, int i) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen[i]) {
        return 0, 0;
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen[i] = 1;

    // Initialize nodes and edges counters
    int nodes = 1;
    int edges = g[i];

    // Recursively traverse the graph for all neighbors of the current vertex
    for (j = 0; j < g[i]; j++) {
        // Recursive call to DFS function for the neighbor vertex
        int x, y = dfs(g, seen, g[i + j]);

        // Update nodes and edges counters based on the result of the recursive call
        nodes += x;
        edges += y;
    }

    // Return the final count of nodes and edges for the current vertex
    return nodes, edges;
}

// Main function to solve the problem
bool solve() {
    // Declare variables
    int n, m, i, j, k;
    int* g;
    int* seen;

    // Read the first line of input containing the number of vertices and edges in the graph
    scanf("%d %d", &n, &m);

    // Initialize the graph as a dictionary with vertices as keys and empty sets as values
    g = (int*)malloc(n * sizeof(int));
    seen = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        g[i] = 0;
        seen[i] = 0;
    }

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a]++;
        g[b]++;
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (i = 0; i < n; i++) {
        if (!seen[i]) {
            int nodes, edges = dfs(g, seen, i);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ans++;
    }

    // Print the final answer and return True to indicate the success of the program
    printf("%d\n", ans);
    return true;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve()) {
        ;
    }
    return 0;
}

