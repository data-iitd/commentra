#######
# Code
#######

// Function to read an array of integers from standard input
public static int[] readInts() {
    return Stream.of(input().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
public static int[] dfs(int[][] g, Set<Integer> seen, int i) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen.contains(i)) {
        return new int[]{0, 0};
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen.add(i);

    // Initialize nodes and edges counters
    int nodes = 1;
    int edges = g[i].length;

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j : g[i]) {
        // Recursive call to DFS function for the neighbor vertex
        int[] x = dfs(g, seen, j);

        // Update nodes and edges counters based on the result of the recursive call
        nodes += x[0];
        edges += x[1];
    }

    // Return the final count of nodes and edges for the current vertex
    return new int[]{nodes, edges};
}

// Main function to solve the problem
public static void main(String[] args) {
    // Read the first line of input containing the number of vertices and edges in the graph
    int[] line0 = readInts();
    int n = line0[0];
    int m = line0[1];

    // Initialize the graph as a 2D array with vertices as rows and columns as neighbors
    int[][] g = new int[n + 1][];
    for (int i = 1; i <= n; i++) {
        g[i] = new int[0];
    }

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int i = 0; i < m; i++) {
        int[] line = readInts();
        int a = line[0];
        int b = line[1];
        int[] g_a = g[a];
        int[] g_b = g[b];
        g[a] = Arrays.copyOf(g_a, g_a.length + 1);
        g[b] = Arrays.copyOf(g_b, g_b.length + 1);
        g[a][g[a].length - 1] = b;
        g[b][g[b].length - 1] = a;
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (int i = 1; i <= n; i++) {
        if (!seen.contains(i)) {
            int[] x = dfs(g, seen, i);
            if (x[0] > 1 && x[0] % 2 == 1 && 2 * x[0] == x[1]) {
                ans++;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ans++;
    }

    // Print the final answer
    System.out.println(ans);
}

// Main loop to repeatedly call the solve function until there is no more input
public static void main(String[] args) {
    while (solve()) {
    }
}

