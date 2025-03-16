#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int **g; // Step 1: Declare the graph as an adjacency list
int *ans; // Step 3: Declare the answer array to store edge colors

void dfs(int to, int color, int parent); // Step 4: Define the DFS function

int main() {
    scanf("%d", &n); // Read the number of nodes
    g = (int **) malloc(n * sizeof(int *)); // Initialize the graph
    for (int i = 0; i < n; i++) {
        g[i] = (int *) malloc(n * sizeof(int)); // Initialize each node's adjacency list
        memset(g[i], -1, n * sizeof(int)); // Initialize each node's adjacency list to -1
    }
    for (int i = 0; i < n - 1; i++) { // Step 2: Read and populate the graph
        int a, b; // Read node a and node b
        scanf("%d %d", &a, &b);
        g[a][b] = i; // Add edge from a to b
        g[b][a] = i; // Add edge from b to a
    }
    ans = (int *) malloc(n * sizeof(int)); // Step 3: Initialize the answer array
    dfs(0, -1, -1); // Step 3: Call DFS with root node 0, initial color -1, and parent -1
    int max = 0; // Step 5: Initialize max to find the maximum color used
    for (int i = 0; i < n - 1; i++) {
        max = max > ans[i] ? max : ans[i]; // Step 5: Find the maximum color used
    }
    printf("%d\n", max); // Step 5: Print the maximum color used
    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", ans[i]); // Step 5: Print the colors assigned to each edge
    }
    return 0;
}

void dfs(int to, int color, int parent) { // Step 4: Define the DFS function
    int k = 1; // Initialize the color counter
    for (int i = 0; i < n; i++) { // Iterate through the adjacency list of the current node
        if (i == parent) continue; // Skip if the neighbor is the parent
        if (k == color) k++; // Ensure the color is not the same as the parent's color
        ans[g[to][i]] = k; // Assign the color to the edge
        dfs(i, k, to); // Recursively call DFS for the neighbor
        k++; // Increment the color counter for the next edge
    }
}

