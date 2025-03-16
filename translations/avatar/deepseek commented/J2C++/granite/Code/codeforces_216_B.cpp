

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Main {
public:
    int count; // To count the number of nodes in a cycle
    vector<bool> seen; // To keep track of visited nodes
    int path = 0, cycle = 1; // Constants for path and cycle
    vector<vector<int>> graph; // Graph represented as an adjacency list

    // Breadth-first search method to detect cycles
    int bfs(int child, int par) {
        if (seen[child]) return cycle; // If child is already seen, return cycle
        seen[child] = true; // Mark the child as seen
        queue<int> q; // Initialize queue for BFS
        q.push(child); // Add child to queue
        while (!q.empty()) { // Iterate over queue until empty
            int node = q.front(); // Get the front node from queue
            q.pop(); // Remove the front node from queue
            for (int i : graph[node]) { // Iterate over neighbors of node
                if (i!= par) { // Avoid going back to parent
                    this.count++; // Increment count for each edge traversed
                    if (bfs(i, node) == cycle) return cycle; // If cycle is detected, return cycle
                }
            }
        }
        return path; // Return path if no cycle is detected
    }

    // Main method to handle input and output
    int main() {
        int m, n; // Number of nodes and edges
        cin >> m >> n; // Read number of nodes and edges
        Main ft;
        ft.graph = vector<vector<int>>(m + 1); // Initialize adjacency list for each node
        ft.seen = vector<bool>(m + 1); // Initialize seen array
        for (int i = 0; i < n; i++) {
            int x, y; // Read edge from and to
            cin >> x >> y;
            ft.graph[x].push_back(y); // Add edge to adjacency list of node x
            ft.graph[y].push_back(x); // Add edge to adjacency list of node y
        }
        int toremove = 0; // Initialize removal count
        for (int i = 1; i <= m; i++) {
            if (!ft.seen[i]) { // If node is not visited
                ft.count = 0; // Reset count for each BFS call
                if (ft.bfs(i, 0) == ft.cycle) { // If cycle is detected
                    if (ft.count % 2 == 1) toremove++; // Increment removal count if cycle length is odd
                }
            }
        }
        if ((m - toremove) % 2 == 1) toremove++; // Adjust removal count if total nodes minus removed nodes is odd
        cout << toremove << endl; // Print the final removal count
        return 0;
    }
};

int main() {
    Main obj;
    obj.main();
    return 0;
}

