
###
# Code
###

# Function to read an array of integers from standard input
void readInts(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
void dfs(int **g, int *seen, int i, int *nodes, int *edges) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen[i]) {
        return;
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen[i] = 1;

    // Initialize nodes and edges counters
    *nodes += 1;
    *edges += g[i][0];

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j = 1; j <= g[i][0]; j++) {
        // Recursive call to DFS function for the neighbor vertex
        dfs(g, seen, g[i][j], nodes, edges);
    }
}

// Main function to solve the problem
int solve() {
    // Read the first line of input containing the number of vertices and edges in the graph
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize the graph as a 2D array with vertices as rows and columns representing neighbors
    int **g = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 1; i <= n; i++) {
        g[i] = (int *)malloc(sizeof(int) * (m + 1));
        g[i][0] = 0;
    }

    // Initialize an array to store the neighbors of each vertex
    int *seen = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) {
        seen[i] = 0;
    }

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a][0]++;
        g[a][g[a][0]] = b;
        g[b][0]++;
        g[b][g[b][0]] = a;
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
    return 1;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve());
    return 0;
}

