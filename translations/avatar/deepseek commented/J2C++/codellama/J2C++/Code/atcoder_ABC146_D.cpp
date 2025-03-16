#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

int n;
vector<list<Edge>> g; // Step 1: Declare the graph as an adjacency list
int* ans; // Step 3: Declare the answer array to store edge colors

int main() {
    cin >> n; // Read the number of nodes
    g = vector<list<Edge>>(n); // Initialize the graph
    for (int i = 0; i < n; i++) {
        g[i] = list<Edge>(); // Initialize each node's adjacency list
    }
    for (int i = 0; i < n - 1; i++) { // Step 2: Read and populate the graph
        int a, b; // Read node a and b
        cin >> a >> b;
        g[a - 1].push_back(Edge(i, b - 1)); // Add edge from a to b
        g[b - 1].push_back(Edge(i, a - 1)); // Add edge from b to a
    }
    ans = new int[n - 1]; // Step 3: Initialize the answer array
    dfs(0, -1, -1); // Step 3: Call DFS with root node 0, initial color -1, and parent -1
    int max = 0; // Step 5: Initialize max to find the maximum color used
    for (int temp : ans) {
        max = max(max, temp); // Step 5: Find the maximum color used
    }
    cout << max << endl; // Step 5: Print the maximum color used
    for (int c : ans) {
        cout << c << endl; // Step 5: Print the colors assigned to each edge
    }
    return 0;
}

void dfs(int to, int color, int parent) { // Step 4: Define the DFS function
    int k = 1; // Initialize the color counter
    for (Edge e : g[to]) { // Iterate through the adjacency list of the current node
        if (e.to == parent) continue; // Skip if the neighbor is the parent
        if (k == color) k++; // Ensure the color is not the same as the parent's color
        ans[e.id] = k; // Assign the color to the edge
        dfs(e.to, k, to); // Recursively call DFS for the neighbor
        k++; // Increment the color counter for the next edge
    }
}

class Edge { // Define the Edge class
public:
    int id;
    int to;

    Edge(int id, int to) {
        this->id = id;
        this->to = to;
    }
};

