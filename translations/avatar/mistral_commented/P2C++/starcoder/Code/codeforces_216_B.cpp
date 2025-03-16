#######
# Code
#######

# Function to read an array of integers from standard input
void readInts(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
void dfs(vector<int> &g, set<int> &seen, int i, int &nodes, int &edges) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen.find(i)!= seen.end()) {
        return;
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen.insert(i);

    // Initialize nodes and edges counters
    nodes++;
    edges += g[i].size();

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j : g[i]) {
        // Recursive call to DFS function for the neighbor vertex
        dfs(g, seen, j, nodes, edges);
    }
}

// Main function to solve the problem
void solve() {
    // Read the first line of input containing the number of vertices and edges in the graph
    int n, m;
    cin >> n >> m;

    // Initialize the graph as a vector of vectors with vertices as keys and empty sets as values
    vector<vector<int>> g(n + 1);
    set<int> seen;

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (int i = 1; i <= n; i++) {
        if (seen.find(i) == seen.end()) {
            int nodes = 0;
            int edges = 0;
            dfs(g, seen, i, nodes, edges);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ans++;
    }

    // Print the final answer
    cout << ans << endl;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve()) {
    }
    return 0;
}

