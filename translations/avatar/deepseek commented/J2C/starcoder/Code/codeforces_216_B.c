
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

#define MAX 1000000

int count; // To count the number of nodes in a cycle
bool seen[MAX]; // To keep track of visited nodes
int path = 0, cycle = 1; // Constants for path and cycle
int graph[MAX][MAX]; // Graph represented as an adjacency list

// Depth-first search method to detect cycles
int dfs(int child, int par) {
    if (seen[child]) return cycle; // If child is already seen, return cycle
    seen[child] = true; // Mark the child as seen
    for (int i = 0; i < graph[child].size(); i++) { // Iterate over neighbors of child
        if (graph[child][i]!= par) { // Avoid going back to parent
            count++; // Increment count for each edge traversed
            if (dfs(graph[child][i], child) == cycle) return cycle; // If cycle is detected, return cycle
        }
    }
    return path; // Return path if no cycle is detected
}

// Main method to handle input and output
int main(int argc, char *argv[]) {
    int m, n, toremove = 0; // Number of nodes and edges, and removal count
    scanf("%d %d", &m, &n); // Read number of nodes and edges
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            graph[i][j] = 0; // Initialize adjacency list for each node
        }
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y); // Read edge from
        scanf("%d %d", &x, &y); // Read edge to
        graph[x][y] = 1; // Add edge to adjacency list of node x
        graph[y][x] = 1; // Add edge to adjacency list of node y
    }
    for (int i = 1; i <= m; i++) {
        if (!seen[i]) { // If node is not visited
            count = 0; // Reset count for each DFS call
            if (dfs(i, 0) == cycle) { // If cycle is detected
                if (count % 2 == 1) toremove++; // Increment removal count if cycle length is odd
            }
        }
    }
    if ((m - toremove) % 2 == 1) toremove++; // Adjust removal count if total nodes minus removed nodes is odd
    printf("%d", toremove); // Print the final removal count
    return 0;
}

