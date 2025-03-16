#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <cstdlib>

using namespace std;

// Function to read an array of integers from standard input
vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> ints;
    int num;
    while (ss >> num) {
        ints.push_back(num);
    }
    return ints;
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
pair<int, int> dfs(const vector<set<int>>& g, vector<bool>& seen, int i) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen[i]) {
        return make_pair(0, 0);
    }

    // Mark the current vertex as visited by setting the corresponding index in the seen vector to true
    seen[i] = true;

    // Initialize nodes and edges counters
    int nodes = 1;
    int edges = g[i].size();

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j : g[i]) {
        // Recursive call to DFS function for the neighbor vertex
        auto [x, y] = dfs(g, seen, j);

        // Update nodes and edges counters based on the result of the recursive call
        nodes += x;
        edges += y;
    }

    // Return the final count of nodes and edges for the current vertex
    return make_pair(nodes, edges);
}

// Main function to solve the problem
bool solve() {
    // Read the first line of input containing the number of vertices and edges in the graph
    vector<int> line0 = readInts();
    if (line0.empty()) {
        // If there is no more input, return false to indicate the end of the program
        return false;
    }

    int n = line0[0]; // Extract the number of vertices from the input line
    int m = line0[1]; // Extract the number of edges from the input line

    // Initialize the graph as a vector of sets with vertices as indices
    vector<set<int>> g(n + 1);
    vector<bool> seen(n + 1, false);

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int i = 0; i < m; ++i) {
        vector<int> edge = readInts();
        int a = edge[0];
        int b = edge[1];
        g[a].insert(b);
        g[b].insert(a);
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            auto [nodes, edges] = dfs(g, seen, i);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ++ans;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ++ans;
    }

    // Print the final answer and return true to indicate the success of the program
    cout << ans << endl;
    return true;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve()) {}
    return 0;
}

