#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class to represent an edge in the graph
class Edge {
public:
    int id; // Unique identifier for the edge
    int to; // Destination node of the edge

    // Constructor to initialize edge with id and destination
    Edge(int id, int to) : id(id), to(to) {}
};

class Main {
public:
    // Number of nodes in the graph
    static int n; 
    // Adjacency list representation of the graph
    static vector<vector<Edge>> g; 
    // Array to store the answer for each edge
    static vector<int> ans; 

    static void dfs(int to, int color, int parents) {
        int k = 1; // Start coloring with color 1
        for (const Edge& e : g[to]) {
            // Skip the edge leading back to the parent node
            if (e.to == parents) continue; 
            // If the current color is the same as the edge color, increment it
            if (k == color) k++; 
            // Assign the color to the edge
            ans[e.id] = k; 
            // Recursively call dfs for the connected node
            dfs(e.to, k, to); 
            k++; // Increment color for the next edge
        }
    }

    static void run() {
        // Read the number of nodes
        cin >> n; 
        
        // Initialize the adjacency list for the graph
        g.resize(n); 
        
        // Read edges and populate the adjacency list
        for (int i = 0; i < n - 1; i++) { 
            int a, b;
            cin >> a >> b; 
            // Adjust for 0-based indexing
            a--; 
            b--; 
            // Add the edge to both endpoints' adjacency lists
            g[a].emplace_back(i, b); 
            g[b].emplace_back(i, a); 
        } 
        
        // Initialize the answer array to store results for each edge
        ans.resize(n - 1); 
        
        // Perform a depth-first search starting from node 0
        dfs(0, -1, -1); 
        
        // Find the maximum value in the ans array
        int max = 0; 
        for (int temp : ans) { 
            max = std::max(max, temp); 
        } 
        
        // Output the maximum value found
        cout << max << endl; 
        
        // Output the results for each edge
        for (int c : ans) { 
            cout << c << endl; 
        } 
    }
};

// Initialize static members
int Main::n;
vector<vector<Edge>> Main::g;
vector<int> Main::ans;

int main() {
    Main::run();
    return 0;
}

// <END-OF-CODE>
