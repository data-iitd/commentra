#include <iostream> // Importing necessary libraries
#include <vector>
#include <string>

using namespace std; // Using standard namespace

int main() {
    int numNode, numEdge; // Declaring variables for number of nodes and edges
    cin >> numNode >> numEdge; // Reading the number of nodes and edges
    
    // Initializing adjacency lists for each node
    vector<int> connect[numNode];
    for (int i = 0; i < numNode; i++) {
        connect[i] = vector<int>();
    }
    
    // Reading edges and populating the adjacency lists
    for (int i = 0; i < numEdge; i++) {
        int a, b; // Declaring variables for node a and b
        cin >> a >> b; // Reading node a and b
        connect[a - 1].push_back(b - 1); // Adding edge from a to b
        connect[b - 1].push_back(a - 1); // Adding edge from b to a
    }
    
    // Checking if the number of edges is odd
    if (numEdge % 2 != 0) {
        cout << -1 << endl; // Printing -1 if the number of edges is odd
        return 0; // Returning from the main method
    }
    
    // Initializing arrays for DFS
    int visited[numNode];
    bool odd[numNode];
    string print;
    
    // Performing DFS starting from node 0
    dfs(0, -1);
    
    // Outputting the result
    cout << print << endl;
    
    return 0;
}

// DFS method to traverse the graph
void dfs(int crt, int parent) {
    visited[crt] = 1; // Marking the current node as visited
    vector<int> crtConnect = connect[crt]; // Getting the adjacency list of the current node
    
    // Traversing each child node of the current node
    for (int child : crtConnect) {
        if (child == parent || visited[child] == 1) { // Skipping if the child is the parent or already visited
            continue;
        } else if (visited[child] == 2) { // Handling the case where the child is part of an already visited cycle
            print += to_string(crt + 1) + " " + to_string(child + 1) + "\n";
            odd[crt] = !odd[crt];
        } else { // Recursively calling dfs for unvisited child nodes
            dfs(child, crt);
            if (odd[child]) { // Updating the print and odd arrays based on the child's result
                print += to_string(child + 1) + " " + to_string(crt + 1) + "\n";
                odd[child] = !odd[child];
            } else {
                print += to_string(crt + 1) + " " + to_string(child + 1) + "\n";
                odd[crt] = !odd[crt];
            }
        }
    }
    visited[crt] = 2; // Marking the current node as fully processed
}

