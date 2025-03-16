#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* readInts() {
    // Reads a line of input, splits it into components, and converts them to integers
    int* arr = (int*)malloc(1000 * sizeof(int)); // Allocate memory for the array
    char buffer[1000];
    fgets(buffer, sizeof(buffer), stdin);
    char* token = strtok(buffer, " ");
    int count = 0;
    while (token != NULL) {
        arr[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

void dfs(int** g, int* seen, int i, int* nodes, int* edges) {
    // Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
    // 'seen' keeps track of visited nodes to avoid cycles
    if (seen[i]) {
        // If the node has already been visited, return 0 nodes and 0 edges
        *nodes = 0;
        *edges = 0;
        return;
    }
    seen[i] = 1;  // Mark the current node as seen
    (*nodes)++;  // Count the current node
    (*edges) += g[i][0];  // Count the edges connected to the current node
    for (int j = 1; j <= g[i][0]; j++) {
        // Recursively visit all adjacent nodes
        int x = 0, y = 0;
        dfs(g, seen, g[i][j], &x, &y);
        *nodes += x;  // Accumulate the number of nodes found
        *edges += y;  // Accumulate the number of edges found
    }
}

int solve() {
    // Main function to solve the problem
    int* line0 = readInts();
    if (line0 == NULL) {
        // If end of input is reached, return 0 to stop processing
        return 0;
    }
    int n = line0[0], m = line0[1];  // Unpack the number of nodes (n) and edges (m)
    free(line0);  // Free the memory allocated for line0

    int** g = (int**)malloc((n + 1) * sizeof(int*));  // Initialize the graph as an array of pointers
    int* seen = (int*)calloc(n + 1, sizeof(int));  // Initialize a array to keep track of seen nodes
    for (int i = 1; i <= n; i++) {
        // Initialize each node's adjacency list
        g[i] = (int*)malloc(n * sizeof(int));
        g[i][0] = 0;  // Set the first element to store the degree of the node
    }

    for (int i = 0; i < m; i++) {
        // Read each edge and add it to the graph (undirected)
        int* ab = readInts();
        int a = ab[0], b = ab[1];
        free(ab);  // Free the memory allocated for ab
        g[a][++g[a][0]] = b;
        g[b][++g[b][0]] = a;
    }

    int ans = 0;  // Initialize the answer counter
    for (int i = 1; i <= n; i++) {
        // Iterate through each node to find connected components
        if (!seen[i]) {
            // If the node has not been seen, perform DFS
            int nodes = 0, edges = 0;
            dfs(g, seen, i, &nodes, &edges);
            // Check the conditions for counting valid components
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;  // Increment the answer if conditions are met
            }
        }
    }

    if ((n - ans) % 2 == 1) {
        // Adjust the answer if the remaining nodes are odd
        ans++;
    }
    printf("%d\n", ans);  // Output the final answer

    for (int i = 1; i <= n; i++) {
        free(g[i]);  // Free the memory allocated for each node's adjacency list
    }
    free(g);  // Free the memory allocated for the graph
    free(seen);  // Free the memory allocated for the seen array
    return 1;  // Return 1 to indicate successful processing
}

int main() {
    // Continuously solve the problem until EOF is reached
    while (solve()) {}
    return 0;
}
