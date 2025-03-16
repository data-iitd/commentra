
#include <iostream> 
#include <vector> 
#include <list> 
#include <cmath> 

using namespace std; 

// Number of nodes in the graph
int n; 
// Adjacency list representation of the graph, where each node points to a list of edges
vector<list<Edge>> g; 
// Array to store the answer for each edge
int* ans; 

int main() { 
    // Create a Scanner object for input
    // Scanner sc = new Scanner(System.in); 
    
    // Read the number of nodes
    // int n = Integer.parseInt(sc.next()); 
    cin >> n; 
    
    // Initialize the adjacency list for the graph
    g = vector<list<Edge>>(n); 
    for (int i = 0; i < n; i++) { 
        g[i] = list<Edge>(); 
    } 
    
    // Read edges and populate the adjacency list
    for (int i = 0; i < n - 1; i++) { 
        // Read the two endpoints of the edge, adjusting for 0-based indexing
        // int a = Integer.parseInt(sc.next()) - 1; 
        // int b = Integer.parseInt(sc.next()) - 1; 
        int a, b; 
        cin >> a >> b; 
        a--; 
        b--; 
        // Add the edge to both endpoints' adjacency lists
        g[a].push_back(Edge(i, b)); 
        g[b].push_back(Edge(i, a)); 
    } 
    
    // Initialize the answer array to store results for each edge
    ans = new int[n - 1]; 
    
    // Perform a depth-first search starting from node 0
    dfs(0, -1, -1); 
    
    // Find the maximum value in the ans array
    int max = 0; 
    for (int temp : ans) { 
        max = max(max, temp); 
    } 
    
    // Output the maximum value found
    // System.out.println(max); 
    cout << max << endl; 
    
    // Output the results for each edge
    for (int c : ans) { 
        // System.out.println(c); 
        cout << c << endl; 
    } 
    
    return 0; 
} 

// Depth-first search function to traverse the graph and assign colors to edges
void dfs(int to, int color, int parents) { 
    int k = 1; // Start coloring with color 1
    for (Edge e : g[to]) { 
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

// Class to represent an edge in the graph
class Edge { 
    // Constructor to initialize edge with id and destination
    Edge(int id, int to) { 
        this->id = id; 
        this->to = to; 
    } 
    int id; // Unique identifier for the edge
    int to; // Destination node of the edge
};

