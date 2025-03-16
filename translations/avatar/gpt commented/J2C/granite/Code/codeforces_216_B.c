
#include <stdio.h>
#include <stdlib.h>

// Variable to count the number of nodes in the current DFS traversal
int count;
// Array to track which nodes have been visited
int *seen;
// Constants to represent the state of the traversal
#define PATH 0
#define CYCLE 1
// Adjacency list representation of the graph
int **graph;

// Depth-First Search (DFS) method to explore the graph
int dfs(int child, int par) {
    // If the current node has already been seen, return cycle indicator
    if (seen[child] == 1) return CYCLE;
    // Mark the current node as seen
    seen[child] = 1;
    
    // Iterate through all adjacent nodes of the current node
    for (int i = 0; i < graph[child].size; i++) {
        // Avoid going back to the parent node
        if (graph[child].arr[i]!= par) {
            count++; // Increment the count of nodes visited
            // Recursively call DFS on the adjacent node
            if (dfs(graph[child].arr[i], child) == CYCLE) return CYCLE; // Check for cycles
        }
    }
    // Return path indicator if no cycle is found
    return PATH;
}

int main() {
    // Create a scanner object for input
    FILE *fp = fopen("input.txt", "r");
    
    // Read the number of nodes (m) and edges (n)
    int m, n;
    fscanf(fp, "%d %d", &m, &n);
    
    // Create an instance of Main to access graph and related variables
    int **graph = (int **)malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i <= m; i++) {
        graph[i] = (int *)malloc(sizeof(int) * 100); // Assuming maximum 100 edges per node
        graph[i].size = 0;
    }
    
    // Initialize the seen array to track visited nodes
    seen = (int *)malloc(sizeof(int) * (m + 1));
    for (int i = 0; i <= m; i++) {
        seen[i] = 0;
    }
    
    // Read the edges and populate the graph
    for (int i = 0; i < n; i++) {
        int x, y;
        fscanf(fp, "%d %d", &x, &y);
        // Add the edge in both directions (undirected graph)
        graph[x].arr[graph[x].size++] = y;
        graph[y].arr[graph[y].size++] = x;
    }
    
    // Variable to count the number of nodes to remove
    int toremove = 0;
    
    // Iterate through all nodes to check for unvisited nodes
    for (int i = 1; i <= m; i++) {
        // If the node has not been seen, perform DFS
        if (seen[i] == 0) {
            count = 0; // Reset count for the new component
            // Check if the DFS from this node finds a cycle
            if (dfs(i, 0) == CYCLE) {
                // If a cycle is found and the count of nodes is odd, increment toremove
                if (count % 2 == 1) toremove++;
            }
        }
    }
    
    // Adjust the number of nodes to remove if the remaining nodes are odd
    if ((m - toremove) % 2 == 1) toremove++;
    
    // Output the result: number of nodes to remove
    printf("%d\n", toremove);
    
    // Free memory
    for (int i = 0; i <= m; i++) {
        free(graph[i]);
    }
    free(graph);
    free(seen);
    
    fclose(fp);
    return 0;
}

