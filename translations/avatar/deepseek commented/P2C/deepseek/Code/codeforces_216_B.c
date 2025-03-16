#include <stdio.h>
#include <stdlib.h>

int* readInts() {  // Function to read integers from input
    int* arr = (int*)malloc(1000 * sizeof(int));  // Allocate memory for the array
    int i = 0;
    int num;
    while (scanf("%d", &num) != EOF) {
        arr[i++] = num;
    }
    return arr;
}

void dfs(int** g, int* seen, int i, int* nodes, int* edges) {  // Depth-First Search to count nodes and edges in a graph
    if (seen[i]) {  // If node is already seen, return 0, 0
        return;
    }
    seen[i] = 1;  // Mark the node as seen
    (*nodes)++;  // Increment node count
    (*edges) += g[i][0];  // Count edges from the current node
    for (int j = 1; g[i][j] != 0; j++) {  // Traverse all adjacent nodes
        dfs(g, seen, g[i][j], nodes, edges);  // Recursively call dfs for each adjacent node
    }
}

int solve() {  // Main function to solve the problem
    int* line0 = readInts();  // Read the first line of input
    if (line0 == NULL) {  // Return -1 if EOF is encountered
        return -1;
    }
    int n = line0[0];  // Unpack the number of nodes
    int m = line0[1];  // Unpack the number of edges
    int** g = (int**)malloc((n + 1) * sizeof(int*));  // Initialize the graph with empty sets for each node
    int* seen = (int*)calloc(n + 1, sizeof(int));  // Initialize an array to keep track of visited nodes
    for (int i = 1; i <= n; i++) {
        g[i] = (int*)malloc(n * sizeof(int));  // Allocate memory for each node's adjacency list
        g[i][0] = 0;  // Initialize the adjacency list size
    }
    for (int i = 0; i < m; i++) {  // Read each edge and add it to the graph
        int* edge = readInts();
        int a = edge[0];
        int b = edge[1];
        g[a][++g[a][0]] = b;
        g[b][++g[b][0]] = a;
    }
    int ans = 0;  // Initialize the answer variable
    for (int i = 1; i <= n; i++) {  // Traverse each node in the graph
        if (!seen[i]) {  // If the node is not seen, perform DFS
            int nodes = 0;
            int edges = 0;
            dfs(g, seen, i, &nodes, &edges);  // Get the count of nodes and edges
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {  // Check the conditions
                ans++;  // Increment the answer if the conditions are met
            }
        }
    }
    if ((n - ans) % 2 == 1) {  // Check if the number of disconnected components is odd
        ans++;  // Increment the answer if necessary
    }
    printf("%d\n", ans);  // Print the final answer
    for (int i = 1; i <= n; i++) {
        free(g[i]);  // Free the memory allocated for each node's adjacency list
    }
    free(g);  // Free the memory allocated for the graph
    free(seen);  // Free the memory allocated for the visited nodes array
    free(line0);  // Free the memory allocated for the first line of input
    return 1;  // Return 1 to continue the loop
}

int main() {  // Continuously call solve until it returns -1
    while (solve() != -1) {
        ;
    }
    return 0;
}
