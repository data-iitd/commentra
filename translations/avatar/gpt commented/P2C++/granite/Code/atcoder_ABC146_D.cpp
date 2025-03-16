
#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent a node in the graph
struct Node {
    int color;  // Color assigned to the node
    vector<int> adj;  // List of adjacent nodes
    bool visited;  // Flag to mark the node as visited
};

// Function to perform BFS and find the maximum color used
int bfs(int v, int N, vector<Node>& G, unordered_map<pair<int, int>, int>& E) {
    // Initialize visited list to keep track of visited nodes
    vector<bool> visited(N, false);
    // Initialize a queue for BFS
    queue<int> queue;
    int K = -1;  // Variable to track the maximum color used
    
    // Start BFS from the given vertex 'v'
    queue.push(v);
    visited[v] = true;  // Mark the starting node as visited
    
    while (!queue.empty()) {
        // Dequeue the front node
        int q = queue.front();
        queue.pop();
        int color = 0;  // Initialize color counter for the current node
        
        // Explore all adjacent nodes
        for (int nex : G[q].adj) {
            if (visited[nex]) {
                continue;  // Skip if the node has already been visited
            }
            
            visited[nex] = true;  // Mark the adjacent node as visited
            color++;  // Increment the color counter
            
            // Ensure the color assigned to the next node is different from the current node's color
            if (color == G[q].color) {
                color++;
            }
            
            // Assign the color to the adjacent node
            G[nex].color = color;
            
            // Store the color used for the edge between the current node and the adjacent node
            E[{min(q, nex), max(q, nex)}] = color;
            
            // Enqueue the adjacent node for further exploration
            queue.push(nex);
        }
        
        // Update the maximum color used
        K = max(K, color);
    }
    
    return K;  // Return the maximum color used
}

int main() {
    // Read the number of nodes
    int N;
    cin >> N;
    // Initialize the graph as a vector of Node structures
    vector<Node> G(N);
    // Initialize a dictionary to store edge colors
    unordered_map<pair<int, int>, int> E;
    
    // Read edges and build the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].adj.push_back(b);  // Add edge from a to b
        G[b].adj.push_back(a);  // Add edge from b to a
        E[{a, b}] = 0;  // Initialize edge color to 0
    }
    
    // Perform BFS starting from node 0
    int K = bfs(0, N, G, E);
    
    // Print the maximum color used
    cout << K << endl;
    // Print the colors assigned to each edge
    for (const auto& [edge, color] : E) {
        cout << color << endl;
    }
    
    return 0;
}

