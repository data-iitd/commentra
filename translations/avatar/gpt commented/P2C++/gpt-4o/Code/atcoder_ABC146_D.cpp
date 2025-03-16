#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

// Use fast input method
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

int bfs(int v, int N, vector<deque<int>>& G, map<pair<int, int>, int>& E) {
    // Initialize visited vector to keep track of visited nodes
    vector<int> visited(N, 0);
    // Initialize a queue for BFS
    deque<int> queue;
    int K = -1;  // Variable to track the maximum color used
    // Initialize a vector to store the color assigned to each node
    vector<int> node2color(N, -1);
    
    // Start BFS from the given vertex 'v'
    queue.push_back(v);
    visited[v] = 1;  // Mark the starting node as visited
    
    while (!queue.empty()) {
        // Dequeue the front node
        int q = queue.front();
        queue.pop_front();
        int color = 0;  // Initialize color counter for the current node
        
        // Explore all adjacent nodes
        for (int nex : G[q]) {
            if (visited[nex]) {
                continue;  // Skip if the node has already been visited
            }
            
            visited[nex] = 1;  // Mark the adjacent node as visited
            color++;  // Increment the color counter
            
            // Ensure the color assigned to the next node is different from the current node's color
            if (color == node2color[q]) {
                color++;
            }
            
            // Assign the color to the adjacent node
            node2color[nex] = color;
            
            // Store the color used for the edge between the current node and the adjacent node
            E[{min(q, nex), max(q, nex)}] = color;
            
            // Enqueue the adjacent node for further exploration
            queue.push_back(nex);
        }
        
        // Update the maximum color used
        K = max(K, color);
    }
    
    return K;  // Return the maximum color used
}

int main() {
    fast_io;
    // Read the number of nodes
    int N;
    cin >> N;
    // Initialize the graph as a list of deques
    vector<deque<int>> G(N);
    // Initialize a map to store edge colors
    map<pair<int, int>, int> E;
    
    // Read edges and build the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;  // Convert to 0-based index
        G[a].push_back(b);  // Add edge from a to b
        G[b].push_back(a);  // Add edge from b to a
        E[{a, b}] = 0;  // Initialize edge color to 0
    }
    
    // Perform BFS starting from node 0
    int K = bfs(0, N, G, E);
    
    // Print the maximum color used
    cout << K << endl;
    // Print the colors assigned to each edge
    for (const auto& value : E) {
        cout << value.second << endl;
    }

    return 0;
}

// <END-OF-CODE>
