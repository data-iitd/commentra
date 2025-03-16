#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<vector<int>> connect; // Adjacency list
vector<int> visited; // Visited nodes
vector<bool> odd; // Odd flag for nodes
stringstream print; // String stream for output

void dfs(int crt, int parent) {
    visited[crt] = 1; // Marking the current node as visited
    vector<int>& crtConnect = connect[crt]; // Getting the adjacency list of the current node

    // Traversing each child node of the current node
    for (int child : crtConnect) {
        if (child == parent || visited[child] == 1) { // Skipping if the child is the parent or already visited
            continue;
        } else if (visited[child] == 2) { // Handling the case where the child is part of an already visited cycle
            print << (crt + 1) << " " << (child + 1) << "\n";
            odd[crt] = !odd[crt];
        } else { // Recursively calling dfs for unvisited child nodes
            dfs(child, crt);
            if (odd[child]) { // Updating the print and odd arrays based on the child's result
                print << (child + 1) << " " << (crt + 1) << "\n";
                odd[child] = !odd[child];
            } else {
                print << (crt + 1) << " " << (child + 1) << "\n";
                odd[crt] = !odd[crt];
            }
        }
    }
    visited[crt] = 2; // Marking the current node as fully processed
}

int main() {
    int numNode, numEdge;
    cin >> numNode >> numEdge; // Reading the number of nodes and edges

    // Initializing adjacency lists for each node
    connect.resize(numNode);
    
    // Reading edges and populating the adjacency lists
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        cin >> a >> b; // Reading node a and b
        a--; b--; // Converting to zero-based index
        connect[a].push_back(b); // Adding edge from a to b
        connect[b].push_back(a); // Adding edge from b to a
    }

    // Checking if the number of edges is odd
    if (numEdge % 2 != 0) {
        cout << -1 << endl; // Printing -1 if the number of edges is odd
        return 0; // Returning from the main method
    }

    // Initializing arrays for DFS
    visited.resize(numNode, 0);
    odd.resize(numNode, false);
    
    // Performing DFS starting from node 0
    dfs(0, -1);
    
    // Outputting the result
    cout << print.str(); // Output the collected results
    return 0;
}

// <END-OF-CODE>
