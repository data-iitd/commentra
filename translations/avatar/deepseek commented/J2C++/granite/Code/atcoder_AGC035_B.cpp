
#include <iostream> // Including necessary libraries
#include <vector>
#include <string>

using namespace std;

int main() {
    int numNode, numEdge;
    cin >> numNode >> numEdge; // Reading the number of nodes and edges
    
    // Initializing adjacency lists for each node
    vector<vector<int>> connect(numNode);
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        cin >> a >> b; // Reading node a and b
        connect[a - 1].push_back(b - 1); // Adding edge from a to b
        connect[b - 1].push_back(a - 1); // Adding edge from b to a
    }
    
    // Checking if the number of edges is odd
    if (numEdge % 2!= 0) {
        cout << -1 << endl; // Printing -1 if the number of edges is odd
        return 0; // Returning from the main method
    }
    
    // Initializing arrays for DFS
    vector<int> visited(numNode);
    vector<bool> odd(numNode);
    stringstream print;
    
    // Performing DFS starting from node 0
    dfs(0, -1, connect, visited, odd, print);
    
    // Outputting the result
    cout << print.str() << endl;
    
    return 0;
}

// DFS method to traverse the graph
void dfs(int crt, int parent, vector<vector<int>>& connect, vector<int>& visited, vector<bool>& odd, stringstream& print) {
    visited[crt] = 1; // Marking the current node as visited
    vector<int>& crtConnect = connect[crt]; // Getting the adjacency list of the current node
    
    // Traversing each child node of the current node
    for (int child : crtConnect) {
        if (child == parent || visited[child] == 1) { // Skipping if the child is the parent or already visited
            continue;
        } else if (visited[child] == 2) { // Handling the case where the child is part of an already visited cycle
            print << (crt + 1) << " " << (child + 1) << endl;
            odd[crt] =!odd[crt];
        } else { // Recursively calling dfs for unvisited child nodes
            dfs(child, crt, connect, visited, odd, print);
            if (odd[child]) { // Updating the print and odd arrays based on the child's result
                print << (child + 1) << " " << (crt + 1) << endl;
                odd[child] =!odd[child];
            } else {
                print << (crt + 1) << " " << (child + 1) << endl;
                odd[crt] =!odd[crt];
            }
        }
    }
    visited[crt] = 2; // Marking the current node as fully processed
}

