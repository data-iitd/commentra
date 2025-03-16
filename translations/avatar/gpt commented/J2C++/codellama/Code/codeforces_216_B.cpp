#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class Main {
    // Variable to count the number of nodes in the current DFS traversal
    int count;
    // Array to track which nodes have been visited
    bool* seen;
    // Constants to represent the state of the traversal
    int path = 0, cycle = 1;
    // Adjacency list representation of the graph
    vector<list<int>> graph;

    // Depth-First Search (DFS) method to explore the graph
    int dfs(int child, int par) {
        // If the current node has already been seen, return cycle indicator
        if (seen[child] == true) return cycle;
        // Mark the current node as seen
        seen[child] = true;
        
        // Iterate through all adjacent nodes of the current node
        for (auto i : graph[child]) {
            // Avoid going back to the parent node
            if (i != par) {
                this->count++; // Increment the count of nodes visited
                // Recursively call DFS on the adjacent node
                if (dfs(i, child) == cycle) return cycle; // Check for cycles
            }
        }
        // Return path indicator if no cycle is found
        return path;
    }

public:
    Main() {
        // Initialize the graph with empty linked lists for each node
        for (int i = 0; i <= m; i++) {
            graph.push_back(list<int>());
        }
        
        // Initialize the seen array to track visited nodes
        seen = new bool[m + 1];
    }

    ~Main() {
        delete[] seen;
    }

    // Main method to read input and perform DFS
    void solve() {
        // Read the number of nodes (m) and edges (n)
        int m, n;
        cin >> m >> n;
        
        // Read the edges and populate the graph
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            // Add the edge in both directions (undirected graph)
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        // Variable to count the number of nodes to remove
        int toremove = 0;
        
        // Iterate through all nodes to check for unvisited nodes
        for (int i = 1; i <= m; i++) {
            // If the node has not been seen, perform DFS
            if (!seen[i]) {
                count = 0; // Reset count for the new component
                // Check if the DFS from this node finds a cycle
                if (dfs(i, 0) == cycle) {
                    // If a cycle is found and the count of nodes is odd, increment toremove
                    if (count % 2 == 1) toremove++;
                }
            }
        }
        
        // Adjust the number of nodes to remove if the remaining nodes are odd
        if ((m - toremove) % 2 == 1) toremove++;
        
        // Output the result: number of nodes to remove
        cout << toremove << endl;
    }
};

int main() {
    Main ft;
    ft.solve();
    return 0;
}

