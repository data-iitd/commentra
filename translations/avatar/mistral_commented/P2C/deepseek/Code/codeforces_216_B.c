#include <stdio.h>
#include <stdlib.h>

// Function to read an array of integers from standard input
int* readInts() {
    int* arr = (int*)malloc(1000 * sizeof(int)); // Allocate memory for the array
    int n = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        ungetc(ch, stdin);
        scanf("%d", &arr[n++]);
    }
    return arr;
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
void dfs(int** g, int* seen, int i, int* nodes, int* edges) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen[i]) {
        return;
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen[i] = 1;

    // Initialize nodes and edges counters
    *nodes = 1;
    *edges = g[i][0];

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j = 1; j <= g[i][0]; j++) {
        int neighbor = g[i][j];
        // Recursive call to DFS function for the neighbor vertex
        int x = 0, y = 0;
        dfs(g, seen, neighbor, &x, &y);

        // Update nodes and edges counters based on the result of the recursive call
        *nodes += x;
        *edges += y;
    }
}

// Main function to solve the problem
int solve() {
    // Read the first line of input containing the number of vertices and edges in the graph
    int* line0 = readInts();
    if (line0 == NULL) {
        return 0; // If there is no more input, return 0 to indicate the end of the program
    }

    int n = line0[0]; // Extract the number of vertices from the input line
    int m = line0[1]; // Extract the number of edges from the input line

    // Free the memory allocated for the first line of input
    free(line0);

    // Initialize the graph as a 2D array with vertices as indices and edges as values
    int** g = (int**)malloc((n + 1) * sizeof(int*));
    int* seen = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        g[i] = (int*)malloc(n * sizeof(int));
        g[i][0] = 0; // Initialize the number of edges for vertex i to 0
    }

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int i = 0; i < m; i++) {
        int* edge = readInts();
        int a = edge[0];
        int b = edge[1];
        g[a][++g[a][0]] = b;
        g[b][++g[b][0]] = a;
        free(edge);
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            int nodes = 0, edges = 0;
            dfs(g, seen, i, &nodes, &edges);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ans++;
    }

    // Print the final answer and return 1 to indicate the success of the program
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        free(g[i]);
    }
    free(g);
    free(seen);
    return 1;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve()) {}
    return 0;
}
