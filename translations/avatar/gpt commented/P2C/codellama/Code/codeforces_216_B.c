#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int readInts(int *arr, int n) {
    // Reads a line of input, splits it into components, and converts them to integers
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
        return 0;
    }
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL && i < n) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return i;
}

int dfs(int **g, int *seen, int i) {
    // Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
    // 'seen' keeps track of visited nodes to avoid cycles
    if (seen[i]) {
        // If the node has already been visited, return 0 nodes and 0 edges
        return 0;
    }
    seen[i] = 1;  // Mark the current node as seen
    int nodes = 1;  // Count the current node
    int edges = g[i][0];  // Count the edges connected to the current node
    for (int j = 1; j < g[i][0]; j++) {
        // Recursively visit all adjacent nodes
        int x, y;
        x = dfs(g, seen, g[i][j]);
        nodes += x;  // Accumulate the number of nodes found
        edges += y;  // Accumulate the number of edges found
    }
    return nodes;
}

int solve() {
    // Main function to solve the problem
    int line0[2];
    if (readInts(line0, 2) != 2) {
        // If end of input is reached, return False to stop processing
        return 0;
    }
    int n = line0[0];  // Unpack the number of nodes (n) and edges (m)
    int m = line0[1];
    int **g = (int **)malloc(sizeof(int *) * (n + 1));  // Initialize the graph as a dictionary
    int *seen = (int *)malloc(sizeof(int) * (n + 1));  // Initialize a set to keep track of seen nodes
    for (int i = 1; i <= n; i++) {
        // Initialize each node's adjacency list as an empty set
        g[i] = (int *)malloc(sizeof(int) * 2);
        g[i][0] = 0;
    }
    for (int i = 0; i < m; i++) {
        // Read each edge and add it to the graph (undirected)
        int a, b;
        readInts(&a, 1);
        readInts(&b, 1);
        g[a][g[a][0]++] = b;
        g[b][g[b][0]++] = a;
    }
    int ans = 0;  // Initialize the answer counter
    for (int i = 1; i <= n; i++) {
        // Iterate through each node to find connected components
        if (!seen[i]) {
            // If the node has not been seen, perform DFS
            int nodes = dfs(g, seen, i);
            // Check the conditions for counting valid components
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == g[i][0]) {
                ans += 1;  // Increment the answer if conditions are met
            }
        }
    }
    if ((n - ans) % 2 == 1) {
        // Adjust the answer if the remaining nodes are odd
        ans += 1;
    }
    printf("%d\n", ans);  // Output the final answer
    return 1;  // Return True to indicate successful processing
}

int main() {
    // Continuously solve the problem until EOF is reached
    while (solve()) {
    }
    return 0;
}

