#######
# Code
#######

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to read an array of integers from standard input
vector<int> readInts() {
    vector<int> res;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            res.push_back(stoi(s.substr(0, i)));
            s = s.substr(i + 1);
            i = -1;
        }
    }
    res.push_back(stoi(s));
    return res;
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
pair<int, int> dfs(vector<vector<int>> &g, set<int> &seen, int i) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if (seen.find(i) != seen.end()) {
        return make_pair(0, 0);
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen.insert(i);

    // Initialize nodes and edges counters
    int nodes = 1;
    int edges = g[i].size();

    // Recursively traverse the graph for all neighbors of the current vertex
    for (int j : g[i]) {
        // Recursive call to DFS function for the neighbor vertex
        pair<int, int> p = dfs(g, seen, j);

        // Update nodes and edges counters based on the result of the recursive call
        nodes += p.first;
        edges += p.second;
    }

    // Return the final count of nodes and edges for the current vertex
    return make_pair(nodes, edges);
}

// Main function to solve the problem
bool solve() {
    // Read the first line of input containing the number of vertices and edges in the graph
    vector<int> line0;
    try {
        line0 = readInts();
    } catch (...) {
        // If there is no more input, return False to indicate the end of the program
        return false;
    }

    int n = line0[0];
    int m = line0[1];

    // Initialize the graph as a vector of vectors with vertices as indices and empty sets as values
    vector<vector<int>> g(n + 1);
    set<int> seen;

    // Initialize an empty vector to store the neighbors of each vertex
    for (int i = 1; i <= n; i++) {
        g[i] = vector<int>();
    }

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for (int i = 0; i < m; i++) {
        vector<int> line = readInts();
        int a = line[0];
        int b = line[1];
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Initialize the answer counter to 0
    int ans = 0;

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for (int i = 1; i <= n; i++) {
        if (seen.find(i) == seen.end()) {
            pair<int, int> p = dfs(g, seen, i);
            if (p.first > 1 && p.first % 2 == 1 && 2 * p.first == p.second) {
                ans++;
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if ((n - ans) % 2 == 1) {
        ans++;
    }

    // Print the final answer and return True to indicate the success of the program
    cout << ans << endl;
    return true;
}

// Main loop to repeatedly call the solve function until there is no more input
int main() {
    while (solve()) {
    }
    return 0;
}

