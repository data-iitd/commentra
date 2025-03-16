#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

void readInts(int &n, int &m) {  // Function to read integers from input
    cin >> n >> m;
}

pair<int, int> dfs(const map<int, set<int>>& g, set<int>& seen, int i) {  // Depth-First Search to count nodes and edges in a graph
    if (seen.count(i))  // If node is already seen, return 0, 0
        return {0, 0};
    seen.insert(i);  // Mark the node as seen
    int nodes = 1;  // Initialize node count
    int edges = g.at(i).size();  // Count edges from the current node
    for (int j : g.at(i)) {  // Traverse all adjacent nodes
        auto [x, y] = dfs(g, seen, j);  // Recursively call dfs for each adjacent node
        nodes += x;  // Update node count
        edges += y;  // Update edge count
    }
    return {nodes, edges};  // Return the count of nodes and edges
}

bool solve() {  // Main function to solve the problem
    int n, m;
    try {
        readInts(n, m);  // Read the first line of input
    } catch (...) {
        return false;  // Return false if an error occurs
    }
    
    map<int, set<int>> g;  // Initialize an empty graph
    set<int> seen;  // Initialize an empty set to keep track of visited nodes
    for (int i = 1; i <= n; ++i)  // Initialize the graph with empty sets for each node
        g[i] = set<int>();
    
    for (int i = 0; i < m; ++i) {  // Read each edge and add it to the graph
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    
    int ans = 0;  // Initialize the answer variable
    for (int i = 1; i <= n; ++i) {  // Traverse each node in the graph
        if (seen.count(i) == 0) {  // If the node is not seen, perform DFS
            auto [nodes, edges] = dfs(g, seen, i);  // Get the count of nodes and edges
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges)  // Check the conditions
                ans++;  // Increment the answer if the conditions are met
        }
    }
    
    if ((n - ans) % 2 == 1)  // Check if the number of disconnected components is odd
        ans++;  // Increment the answer if necessary
    
    cout << ans << endl;  // Print the final answer
    return true;  // Return true to continue the loop
}

int main() {
    while (solve())  // Continuously call solve until it returns false
        ;
    return 0;
}

// <END-OF-CODE>
