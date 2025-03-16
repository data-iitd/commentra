#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void readInts() {  // Function to read integers from input
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

void dfs(map<int, set<int>> g, set<int> &seen, int i) {  // Depth-First Search to count nodes and edges in a graph
    if (seen.find(i) != seen.end()) {  // If node is already seen, return 0, 0
        return make_pair(0, 0);
    }
    seen.insert(i);  // Mark the node as seen
    int nodes = 1;  // Initialize node count
    int edges = g[i].size();  // Count edges from the current node
    for (int j : g[i]) {  // Traverse all adjacent nodes
        pair<int, int> x = dfs(g, seen, j);  // Recursively call dfs for each adjacent node
        nodes += x.first;  // Update node count
        edges += x.second;  // Update edge count
    }
    return make_pair(nodes, edges);  // Return the count of nodes and edges
}

void solve() {  // Main function to solve the problem
    vector<int> line0 = readInts();  // Read the first line of input
    int n = line0[0];  // Unpack the number of nodes and edges
    int m = line0[1];
    map<int, set<int>> g;  // Initialize an empty graph
    set<int> seen;  // Initialize an empty set to keep track of visited nodes
    for (int i = 1; i <= n; i++) {  // Initialize the graph with empty sets for each node
        g[i] = set<int>();
    }
    for (int i = 0; i < m; i++) {  // Read each edge and add it to the graph
        vector<int> line = readInts();
        int a = line[0];
        int b = line[1];
        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;  // Initialize the answer variable
    for (int i = 1; i <= n; i++) {  // Traverse each node in the graph
        if (seen.find(i) == seen.end()) {  // If the node is not seen, perform DFS
            pair<int, int> x = dfs(g, seen, i);  // Get the count of nodes and edges
            if (x.first > 1 && x.first % 2 == 1 && 2 * x.first == x.second) {  // Check the conditions
                ans += 1;  // Increment the answer if the conditions are met
            }
        }
    }
    if ((n - ans) % 2 == 1) {  // Check if the number of disconnected components is odd
        ans += 1;  // Increment the answer if necessary
    }
    cout << ans << endl;  // Print the final answer
}

int main() {  // Main function
    while (true) {  // Continuously call solve until it returns False
        solve();
    }
    return 0;  // Return 0 to end the program
}

