#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

// Variable to count the number of nodes in the current DFS traversal
int count;
// Array to track which nodes have been visited
bool seen[1000001];
// Constants to represent the state of the traversal
int path = 0, cycle = 1;
// Adjacency list representation of the graph
int graph[1000001][1000001];

// Depth-First Search (DFS) method to explore the graph
int dfs(int child, int par) {
    // If the current node has already been seen, return cycle indicator
    if (seen[child]) return cycle;
    // Mark the current node as seen
    seen[child] = true;
    
    // Iterate through all adjacent nodes of the current node
    for (int i = 0; i < graph[child][0]; i++) {
        // Avoid going back to the parent node
        if (graph[child][i]!= par) {
            count++; // Increment the count of nodes visited
            // Recursively call DFS on the adjacent node
            if (dfs(graph[child][i], child) == cycle) return cycle; // Check for cycles
        }
    }
    // Return path indicator if no cycle is found
    return path;
}

int main(int argc, char** argv) {
    // Read the number of nodes (m) and edges (n)
    int m, n;
    scanf("%d %d", &m, &n);
    
    // Initialize the graph with empty linked lists for each node
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < 1000001; j++) {
            graph[i][j] = INT_MAX;
        }
        graph[i][0] = 0;
    }
    
    // Read the edges and populate the graph
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        // Add the edge in both directions (undirected graph)
        graph[x][graph[x][0]] = y;
        graph[x][0]++;
        graph[y][graph[y][0]] = x;
        graph[y][0]++;
    }
    
    // Variable to count the number of nodes to remove
    int toremove = 0;
    
    // Iterate through all nodes to check for unvisited nodes
    for (int i = 1; i <= m; i++) {
        // If the node has not been seen, perform DFS
        if (!seen[i]) {
            count = 0; // Reset count for the new component
            // Check if the DFS from this node finds a cycle
            if (dfs(i, 0) == cycle) {
                // If a cycle is found and the count of nodes is odd, increment toremove
                if (count % 2 == 1) toremove++;
            }
        }
    }
    
    // Adjust the number of nodes to remove if the remaining nodes are odd
    if ((m - toremove) % 2 == 1) toremove++;
    
    // Output the result: number of nodes to remove
    printf("%d\n", toremove);
    return 0;
}

