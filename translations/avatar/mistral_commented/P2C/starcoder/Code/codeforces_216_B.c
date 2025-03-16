#######
# Code
#######

# Function to read an array of integers from standard input
int* readInts() {
    int* arr = (int*)malloc(sizeof(int) * 100);
    int i = 0;
    char c;
    while ((c = getchar())!= '\n') {
        if (c =='') continue;
        arr[i++] = c - '0';
    }
    return arr;
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
void dfs(int** g, int* seen, int i, int* nodes, int* edges) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen[i]) {
        *nodes = 0;
        *edges = 0;
        return;
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen[i] = 1;

    // Initialize nodes and edges counters
    *nodes = 1;
    *edges = 0;

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j = 0; j < 100; j++) {
        if (g[i][j]) {
            // Recursive call to DFS function for the neighbor vertex
            dfs(g, seen, j, nodes, edges);

            // Update nodes and edges counters based on the result of the recursive call
            *nodes += *nodes;
            *edges += *edges;
        }
    }
}

// Main function to solve the problem
int main() {
    // Read the first line of input containing the number of vertices and edges in the graph
    int* line0 = readInts();
    int n = line0[0];
    int m = line0[1];

    // Initialize the graph as a dictionary with vertices as keys and empty sets as values
    int** g = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        g[i] = (int*)malloc(sizeof(int) * 100);
        for (int j = 0; j < 100; j++) {
            g[i][j] = 0;
        }
    }
    int* seen = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        seen[i] = 0;
    }

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int i = 0; i < m; i++) {
        int* line = readInts();
        g[line[0] - 1][line[1] - 1] = 1;
        g[line[1] - 1][line[0] - 1] = 1;
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            int nodes = 0;
            int edges = 0;
            dfs(g, seen, i, &nodes, &edges);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans += 1;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ans += 1;
    }

    // Print the final answer
    printf("%d\n", ans);

    // Free the memory allocated for the graph and seen arrays
    for (int i = 0; i < n; i++) {
        free(g[i]);
    }
    free(g);
    free(seen);

    // Return from the main function
    return 0;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve()) {
        pass;
    }
    return 0;
}

