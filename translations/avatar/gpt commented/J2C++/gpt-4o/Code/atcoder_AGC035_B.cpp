#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<vector<int>> connect; // Adjacency list for the graph
vector<int> visited; // Array to track visited nodes
vector<bool> odd; // Array to track odd/even connections
ostringstream print; // String stream to accumulate output

void dfs(int crt, int parent) {
    visited[crt] = 1; // Mark the current node as visited
    vector<int>& crtConnect = connect[crt]; // Get the current node's connections

    // Iterate through each child node connected to the current node
    for (int child : crtConnect) {
        // Skip the parent node and already visited nodes
        if (child == parent || visited[child] == 1) {
            continue;
        } else if (visited[child] == 2) {
            // If the child has been fully processed, append the edge to output
            print << (crt + 1) << " " << (child + 1) << "\n";
            odd[crt] = !odd[crt]; // Toggle the odd/even state
        } else {
            // Recursively call DFS on the child node
            dfs(child, crt);

            // Check the odd/even state of the child node after DFS
            if (odd[child]) {
                print << (child + 1) << " " << (crt + 1) << "\n";
                odd[child] = !odd[child]; // Toggle the state
            } else {
                print << (crt + 1) << " " << (child + 1) << "\n";
                odd[crt] = !odd[crt]; // Toggle the state
            }
        }
    }
    visited[crt] = 2; // Mark the current node as fully processed
}

int main() {
    // Initialize input stream
    int numNode, numEdge;
    cin >> numNode >> numEdge;

    // Create an adjacency list to represent the graph
    connect.resize(numNode);
    
    // Read edges and populate the adjacency list
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-indexed
        b--; // Convert to 0-indexed
        connect[a].push_back(b); // Add edge in both directions (undirected graph)
        connect[b].push_back(a);
    }

    // Check if the number of edges is odd; if so, output -1 and exit
    if (numEdge % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    // Initialize arrays for tracking visited nodes and odd/even connections
    visited.resize(numNode, 0);
    odd.resize(numNode, false);

    // Perform depth-first search starting from node 0
    dfs(0, -1);

    // Output the result
    cout << print.str();
    return 0;
}

// <END-OF-CODE>
