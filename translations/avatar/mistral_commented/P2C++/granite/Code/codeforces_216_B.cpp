
#####
# Code
#####

# Function to read an array of integers from standard input
vector<int> readInts() {
    vector<int> ans;
    int x;
    while (cin >> x) {
        ans.push_back(x);
    }
    return ans;
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
pair<int, int> dfs(vector<vector<int>>& g, vector<bool>& seen, int i) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen[i]) {
        return {0, 0};
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen[i] = true;

    // Initialize nodes and edges counters
    int nodes = 1;
    int edges = g[i].size();

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j : g[i]) {
        // Recursive call to DFS function for the neighbor vertex
        pair<int, int> x = dfs(g, seen, j);

        // Update nodes and edges counters based on the result of the recursive call
        nodes += x.first;
        edges += x.second;
    }

    // Return the final count of nodes and edges for the current vertex
    return {nodes, edges};
}

// Main function to solve the problem
bool solve() {
    // Read the first line of input containing the number of vertices and edges in the graph
    vector<int> line0;
    try {
        line0 = readInts();
    } catch (exception& e) {
        // If there is no more input, return false to indicate the end of the program
        return false;
    }

    int n = line0[0]; // Extract the number of vertices from the input line
    int m = line0[1]; // Extract the number of edges from the input line

    // Initialize the graph as a vector of vectors with vertices as rows and empty sets as columns
    vector<vector<int>> g(n);
    vector<bool> seen(n, false);

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int _ = 0; _ < m; _++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            pair<int, int> x = dfs(g, seen, i);
            if (x.first > 1 && x.first % 2 == 1 && 2 * x.first == x.second) {
                ans++;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ans++;
    }

    // Print the final answer and return true to indicate the success of the program
    cout << ans << endl;
    return true;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve());
    return 0;
}

