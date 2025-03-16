
#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

// Declare global variables for the graph representation and state tracking
vector<int> connect[100000]; 
int visited[100000]; 
bool odd[100000]; 
string print; 

// Depth-first search method to explore the graph
void dfs(int crt, int parent) { 
    visited[crt] = 1; // Mark the current node as visited
    vector<int> crtConnect = connect[crt]; // Get the current node's connections
    
    // Iterate through each child node connected to the current node
    for (int child : crtConnect) { 
        // Skip the parent node and already visited nodes
        if (child == parent || visited[child] == 1) { 
            continue; 
        } else if (visited[child] == 2) { 
            // If the child has been fully processed, append the edge to output
            print += to_string(crt + 1) + " " + to_string(child + 1) + "\n"; 
            odd[crt] = !odd[crt]; // Toggle the odd/even state
        } else { 
            // Recursively call DFS on the child node
            dfs(child, crt); 
            
            // Check the odd/even state of the child node after DFS
            if (odd[child]) { 
                print += to_string(child + 1) + " " + to_string(crt + 1) + "\n"; 
                odd[child] = !odd[child]; // Toggle the state
            } else { 
                print += to_string(crt + 1) + " " + to_string(child + 1) + "\n"; 
                odd[crt] = !odd[crt]; // Toggle the state
            } 
        } 
    } 
    visited[crt] = 2; // Mark the current node as fully processed
} 

int main() { 
    // Initialize scanner to read input
    int numNode, numEdge; 
    cin >> numNode >> numEdge; 
    
    // Read edges and populate the adjacency list
    for (int i = 0; i < numEdge; i++) { 
        int a, b; 
        cin >> a >> b; 
        connect[a - 1].push_back(b - 1); // Add edge in both directions (undirected graph)
        connect[b - 1].push_back(a - 1); 
    } 
    
    // Check if the number of edges is odd; if so, output -1 and exit
    if (numEdge % 2 != 0) { 
        cout << -1 << endl; 
        return 0; 
    } 
    
    // Initialize arrays for tracking visited nodes and odd/even connections
    for (int i = 0; i < numNode; i++) { 
        visited[i] = 0; 
        odd[i] = false; 
    } 
    
    // Perform depth-first search starting from node 0
    dfs(0, -1); 
    
    // Output the result
    cout << print << endl; 
    return 0; 
} 

