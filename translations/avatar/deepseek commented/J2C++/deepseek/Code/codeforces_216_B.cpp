#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
public:
    int count; // To count the number of nodes in a cycle
    vector<bool> seen; // To keep track of visited nodes
    const int path = 0, cycle = 1; // Constants for path and cycle
    vector<list<int>> graph; // Graph represented as an adjacency list

    // Depth-first search method to detect cycles
    int dfs(int child, int par) {
        if (seen[child]) return cycle; // If child is already seen, return cycle
        seen[child] = true; // Mark the child as seen
        for (int i : graph[child]) { // Iterate over neighbors of child
            if (i != par) { // Avoid going back to parent
                this->count++; // Increment count for each edge traversed
                if (dfs(i, child) == cycle) return cycle; // If cycle is detected, return cycle
            }
        }
        return path; // Return path if no cycle is detected
    }
};

int main() {
    int m, n;
    cin >> m >> n; // Number of nodes and edges
    Graph ft;
    ft.graph.resize(m + 1); // Initialize adjacency list for each node
    ft.seen.resize(m + 1, false); // Initialize seen array
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y; // Read edge from and to
        ft.graph[x].push_back(y); // Add edge to adjacency list of node x
        ft.graph[y].push_back(x); // Add edge to adjacency list of node y
    }
    int toremove = 0; // Initialize removal count
    for (int i = 1; i <= m; i++) {
        if (!ft.seen[i]) { // If node is not visited
            ft.count = 0; // Reset count for each DFS call
            if (ft.dfs(i, 0) == ft.cycle) { // If cycle is detected
                if (ft.count % 2 == 1) toremove++; // Increment removal count if cycle length is odd
            }
        }
    }
    if ((m - toremove) % 2 == 1) toremove++; // Adjust removal count if total nodes minus removed nodes is odd
    cout << toremove << endl; // Print the final removal count
    return 0;
}

