#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    // Read the values of n (number of nodes) and m (number of edges) from input
    int n, m;
    cin >> n >> m;

    // Create a vector of nodes from 1 to n
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }

    // Read the health points for each node from input
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Create a map to store health points for each node
    unordered_map<int, int> hp;
    for (int i = 0; i < n; ++i) {
        hp[p[i]] = h[i];
    }

    // Initialize a map to represent the graph as an adjacency list
    unordered_map<int, vector<int>> path;
    
    // Read m edges from input and populate the adjacency list
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);  // Add edge from a to b
        path[b].push_back(a);  // Add edge from b to a (undirected graph)
    }

    // Initialize a counter for nodes that have no neighbors with equal or higher health points
    int c = 0;

    // Iterate through each node and its connected nodes
    for (const auto& entry : path) {
        int i = entry.first;
        const vector<int>& v = entry.second;
        bool hasHigherOrEqual = false;  // Flag to check if any neighbor has equal or higher health points
        
        for (int j : v) {
            // Check if the current node's health is less than or equal to any of its neighbors
            if (hp[i] <= hp[j]) {
                hasHigherOrEqual = true;  // Set flag if a neighbor with equal or higher health is found
                break;  // No need to check further neighbors
            }
        }
        
        // If no neighbors have equal or higher health points, increment the counter
        if (!hasHigherOrEqual) {
            c++;
        }
    }

    // Print the count of nodes that have no neighbors with equal or higher health points
    cout << c << endl;

    return 0;
}

// <END-OF-CODE>
