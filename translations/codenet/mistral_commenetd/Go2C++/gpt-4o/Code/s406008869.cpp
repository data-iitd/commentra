// Include necessary headers
#include <iostream>
#include <vector>

using namespace std;

// Define a 2D vector 'e' to store the edges of the graph
vector<vector<int>> e;

// Define variables 'n' and 'm' to store the number of nodes and edges respectively
int n, m;

// Function 'printEdge' to print the edges of the graph
void printEdge(const vector<vector<int>>& e) {
    // Iterate through each node in the graph
    for (int i = 1; i <= n; i++) {
        // Print the node number and its connected nodes
        cout << i << ": ";
        for (int v : e[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// Function 'dfs' to perform Depth First Search traversal
int dfs(int v, vector<bool>& visited) {
    // Check if all nodes are visited, if yes then it's a strongly connected component
    bool comp = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp = false;
            break;
        }
    }

    // If all nodes are visited, return 1 for this strongly connected component
    if (comp) {
        return 1;
    }

    // Initialize a counter 'count' to store the size of the strongly connected component
    int count = 0;
    // Iterate through the neighbors of the current node 'v'
    for (int ne : e[v]) {
        // If the neighbor is already visited, skip it
        if (visited[ne]) {
            continue;
        }
        // Mark the neighbor as visited
        visited[ne] = true;
        // Recursively call 'dfs' on the neighbor and add its size to the counter
        int rst = dfs(ne, visited);
        count += rst;
        // Mark the neighbor as unvisited
        visited[ne] = false;
    }
    // Return the size of the strongly connected component
    return count;
}

// Function 'main' to read input and call the 'printEdge' and 'dfs' functions
int main() {
    // Read the number of nodes and edges from the standard input
    cin >> n >> m;

    // Initialize a 2D vector 'e' of size (n+1) to store the edges of the graph
    e.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        // Initialize an empty vector for each node
        e[i] = vector<int>();
    }
    // Read the edges of the graph from the standard input and add them to the 'e' vector
    for (int i = 0; i < m; i++) {
        int a, b;
        // Read the nodes of an edge from the standard input
        cin >> a >> b;
        // Add the edge to the 'e' vector for both nodes
        e[a].push_back(b);
        e[b].push_back(a);
    }
    // Call the 'printEdge' function to print the edges of the graph
    // printEdge(e);

    // Initialize a boolean vector 'visited' of size (n+1) to keep track of visited nodes
    vector<bool> visited(n + 1, false);
    // Mark the first node as visited
    visited[1] = true;
    // Call the 'dfs' function on the first node and print the size of the strongly connected component
    int count = dfs(1, visited);
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
