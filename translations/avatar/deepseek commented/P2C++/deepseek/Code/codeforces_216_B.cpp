#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> readInts() {  // Function to read integers from input
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> result;
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

void dfs(const vector<unordered_set<int>>& g, unordered_set<int>& seen, int i, int& nodes, int& edges) {  // Depth-First Search to count nodes and edges in a graph
    if (seen.find(i) != seen.end()) {  // If node is already seen, return 0, 0
        return;
    }
    seen.insert(i);  // Mark the node as seen
    nodes++;  // Increment node count
    edges += g[i].size();  // Count edges from the current node
    for (int j : g[i]) {  // Traverse all adjacent nodes
        dfs(g, seen, j, nodes, edges);  // Recursively call dfs for each adjacent node
    }
}

bool solve() {  // Main function to solve the problem
    vector<int> line0 = readInts();  // Read the first line of input
    if (line0.empty()) {  // Return False if EOF is encountered
        return false;
    }
    int n = line0[0], m = line0[1];  // Unpack the number of nodes and edges
    vector<unordered_set<int>> g(n + 1);  // Initialize the graph with empty sets for each node
    unordered_set<int> seen;  // Initialize an empty set to keep track of visited nodes
    for (int i = 0; i < m; i++) {  // Read each edge and add it to the graph
        vector<int> edge = readInts();
        g[edge[0]].insert(edge[1]);
        g[edge[1]].insert(edge[0]);
    }
    int ans = 0;  // Initialize the answer variable
    for (int i = 1; i <= n; i++) {  // Traverse each node in the graph
        if (seen.find(i) == seen.end()) {  // If the node is not seen, perform DFS
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
    return true;  // Return True to continue the loop
}

int main() {
    while (solve()) {  // Continuously call solve until it returns False
        // Do nothing
    }
    return 0;
}
