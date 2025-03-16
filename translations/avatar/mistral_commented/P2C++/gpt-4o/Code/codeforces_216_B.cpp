#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

// Function to read an array of integers from standard input
vector<int> readInts() {
    vector<int> result;
    int x;
    while (cin >> x) {
        result.push_back(x);
    }
    return result;
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
pair<int, int> dfs(const map<int, set<int>>& g, set<int>& seen, int i) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen.count(i)) {
        return {0, 0};
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen.insert(i);

    // Initialize nodes and edges counters
    int nodes = 1;
    int edges = g.at(i).size();

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j : g.at(i)) {
        // Recursive call to DFS function for the neighbor vertex
        auto [x, y] = dfs(g, seen, j);

        // Update nodes and edges counters based on the result of the recursive call
        nodes += x;
        edges += y;
    }

    // Return the final count of nodes and edges for the current vertex
    return {nodes, edges};
}

// Main function to solve the problem
bool solve() {
    // Read the first line of input containing the number of vertices and edges in the graph
    vector<int> line0 = readInts();
    if (line0.empty()) {
        // If there is no more input, return false to indicate the end of the program
        return false;
    }

    int n = line0[0], m = line0[1]; // Extract the number of vertices and edges from the input line

    // Initialize the graph as a map with vertices as keys and empty sets as values
    map<int, set<int>> g;
    set<int> seen;

    // Initialize an empty map to store the neighbors of each vertex
    for (int i = 1; i <= n; ++i) {
        g[i] = set<int>();
    }

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int i = 0; i < m; ++i) {
        vector<int> edge = readInts();
        g[edge[0]].insert(edge[1]);
        g[edge[1]].insert(edge[0]);
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (int i = 1; i <= n; ++i) {
        if (seen.count(i) == 0) {
            auto [nodes, edges] = dfs(g, seen, i);
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans += 1;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ans += 1;
    }

    // Print the final answer and return true to indicate the success of the program
    cout << ans << endl;
    return true;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve()) {
        // Continue until there is no more input
    }
    return 0;
}

// <END-OF-CODE>
