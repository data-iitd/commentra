#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

// Adjacency list to represent the graph
vector<int> g[100000]; // Assuming a maximum of 100000 vertices

// Function to calculate the maximum matching in the graph
int maxMatching(int v, int p) {
    int a = 0; // Count of pairs in matching
    int o = 0; // Count of unmatched vertices
    
    // Iterate through all adjacent vertices of v
    for (int w : g[v]) {
        // Skip the parent vertex to avoid cycles
        if (w == p) continue; 
        
        // Recursively find the matching for the adjacent vertex
        int r = maxMatching(w, v); 
        a += r / 2; // Update count of pairs
        o += r % 2; // Update count of unmatched vertices
    }
    
    // Return the total matching count
    return 2 * a + min(1, o) + 1; 
} 

int main() {
    // Initialize input
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read the number of vertices
    int n;
    cin >> n; 
    
    // Read edges and populate the adjacency list
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        g[a].push_back(b); // Add edge to the graph
        g[b].push_back(a); // Add edge to the graph (undirected)
    }
    
    // Calculate maximum matching starting from vertex 0
    int m = maxMatching(0, -1) / 2; 
    
    // Determine the winner based on the matching result
    cout << (2 * m == n ? "Second" : "First") << endl; 
    
    return 0; 
}

// <END-OF-CODE>
