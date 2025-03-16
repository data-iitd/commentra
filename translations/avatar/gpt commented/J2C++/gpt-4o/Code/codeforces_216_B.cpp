#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Main {
public:
    // Variable to count the number of nodes in the current DFS traversal
    int count;
    // Array to track which nodes have been visited
    vector<bool> seen;
    // Constants to represent the state of the traversal
    const int path = 0, cycle = 1;
    // Adjacency list representation of the graph
    vector<list<int>> graph;

    // Depth-First Search (DFS) method to explore the graph
    int dfs(int child, int par) {
        // If the current node has already been seen, return cycle indicator
        if (seen[child]) return cycle;
        // Mark the current node as seen
        seen[child] = true;

        // Iterate through all adjacent nodes of the current node
        for (int i : graph[child]) {
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
};

int main() {
    // Create a scanner object for input
    int m, n;
    cin >> m >> n;

    // Create an instance of Main to access graph and related variables
    Main ft;
    ft.graph.resize(m + 1); // Resize the graph to hold m nodes

    // Initialize the seen array to track visited nodes
    ft.seen.resize(m + 1, false);

    // Read the edges and populate the graph
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        // Add the edge in both directions (undirected graph)
        ft.graph[x].push_back(y);
        ft.graph[y].push_back(x);
    }

    // Variable to count the number of nodes to remove
    int toremove = 0;

    // Iterate through all nodes to check for unvisited nodes
    for (int i = 1; i <= m; i++) {
        // If the node has not been seen, perform DFS
        if (!ft.seen[i]) {
            ft.count = 0; // Reset count for the new component
            // Check if the DFS from this node finds a cycle
            if (ft.dfs(i, 0) == ft.cycle) {
                // If a cycle is found and the count of nodes is odd, increment toremove
                if (ft.count % 2 == 1) toremove++;
            }
        }
    }

    // Adjust the number of nodes to remove if the remaining nodes are odd
    if ((m - toremove) % 2 == 1) toremove++;

    // Output the result: number of nodes to remove
    cout << toremove << endl;

    return 0;
}

// <END-OF-CODE>
