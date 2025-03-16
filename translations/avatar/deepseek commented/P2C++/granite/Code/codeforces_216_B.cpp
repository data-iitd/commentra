
#include <bits/stdc++.h>
using namespace std;

vector<int> readInts() {  // Function to read integers from input
    vector<int> ans;
    int x;
    while (cin >> x) {
        ans.push_back(x);
    }
    return ans;
}

void dfs(vector<vector<int>>& g, vector<bool>& seen, int i, int& nodes, int& edges) {  // Depth-First Search to count nodes and edges in a graph
    if (seen[i]) {  // If node is already seen, return 0, 0
        return;
    }
    seen[i] = true;  // Mark the node as seen
    nodes++;  // Increment node count
    edges += g[i].size();  // Count edges from the current node
    for (int j : g[i]) {  // Traverse all adjacent nodes
        dfs(g, seen, j, nodes, edges);  // Recursively call dfs for each adjacent node
    }
}

void solve() {  // Main function to solve the problem
    vector<int> line0;
    try {
        line0 = readInts();  // Read the first line of input
    } catch (exception& e) {
        return;  // Return if EOF is encountered
    }
    int n = line0[0], m = line0[1];  // Unpack the number of nodes and edges
    vector<vector<int>> g(n);  // Initialize an empty graph
    vector<bool> seen(n);  // Initialize an empty vector to keep track of visited nodes
    for (int i = 0; i < n; i++) {  // Initialize the graph with empty vectors for each node
        g[i] = vector<int>();
    }
    for (int i = 0; i < m; i++) {  // Read each edge and add it to the graph
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;  // Initialize the answer variable
    for (int i = 0; i < n; i++) {  // Traverse each node in the graph
        if (!seen[i]) {  // If the node is not seen, perform DFS
            int nodes = 0, edges = 0;
            dfs(g, seen, i, nodes, edges);  // Get the count of nodes and edges
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {  // Check the conditions
                ans++;  // Increment the answer if the conditions are met
            }
        }
    }
    if ((n - ans) % 2 == 1) {  // Check if the number of disconnected components is odd
        ans++;  // Increment the answer if necessary
    }
    cout << ans << endl;  // Print the final answer
}

int main() {
    while (solve()) {  // Continuously call solve until it returns false
        // Do nothing
    }
    return 0;
}

