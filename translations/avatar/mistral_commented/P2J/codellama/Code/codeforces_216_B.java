#######
# Code
#######

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
private static int[] dfs(int[][] g, boolean[] seen, int i) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen[i]) {
        return new int[] { 0, 0 };
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen[i] = true;

    // Initialize nodes and edges counters
    int nodes = 1;
    int edges = g[i].length;

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j : g[i]) {
        // Recursive call to DFS function for the neighbor vertex
        int[] xy = dfs(g, seen, j);

        // Update nodes and edges counters based on the result of the recursive call
        nodes += xy[0];
        edges += xy[1];
    }

    // Return the final count of nodes and edges for the current vertex
    return new int[] { nodes, edges };
}

// Main function to solve the problem
private static void solve() {
    // Read the first line of input containing the number of vertices and edges in the graph
    String[] line0 = sc.nextLine().split(" ");

    // Extract the number of vertices and edges from the input line
    int n = Integer.parseInt(line0[0]);
    int m = Integer.parseInt(line0[1]);

    // Initialize the graph as a 2D array with vertices as rows and empty arrays as columns
    int[][] g = new int[n+1][];
    boolean[] seen = new boolean[n+1];

    // Initialize an empty array to store the neighbors of each vertex
    for (int i = 1; i <= n; i++) {
        g[i] = new int[0];
    }

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int i = 0; i < m; i++) {
        String[] line = sc.nextLine().split(" ");
        int a = Integer.parseInt(line[0]);
        int b = Integer.parseInt(line[1]);
        g[a] = Arrays.copyOf(g[a], g[a].length + 1);
        g[a][g[a].length - 1] = b;
        g[b] = Arrays.copyOf(g[b], g[b].length + 1);
        g[b][g[b].length - 1] = a;
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            int[] xy = dfs(g, seen, i);
            if (xy[0] > 1 && xy[0] % 2 == 1 && 2 * xy[0] == xy[1]) {
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
while (sc.hasNext()) {
    solve();
}

