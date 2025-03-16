#include <iostream> // For input and output
#include <vector>   // For using vectors
#include <algorithm> // For using algorithms like min
#include <iomanip>  // For output formatting
#include <sstream>  // For string stream
using namespace std;

// Declaring global variables
vector<vector<int>> g; // Adjacency list for the graph
int maxMatching; // To store the maximum number of edges that can be matched in a bipartite graph

// Function to find the maximum number of edges that can be matched in a bipartite graph
int maxMatchingFunc(int v, int p) {
    int a = 0; // Number of edges matched from the neighboring vertices of 'v'
    int o = 0; // Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

    // Iterating through all the neighbors of 'v'
    for (int w : g[v]) {
        if (w == p) continue; // Skip if the neighbor is 'p' (self-loop)

        // Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
        int r = maxMatchingFunc(w, v);
        a += r / 2;
        o += r % 2;
    }

    // Returning the result based on the parity of 'o'
    return 2 * a + min(1, o);
}

int main() {
    ios::sync_with_stdio(false); // For faster input/output
    cin.tie(nullptr); // Untie cin from cout

    // Reading the number of vertices in the graph
    int n;
    cin >> n;

    // Initializing the graph as a vector of vectors
    g.resize(n);

    // Reading the edges and adding them to the graph
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b; // Reading the vertices of the edge
        g[a - 1].push_back(b - 1); // Adding the edge from 'a' to 'b'
        g[b - 1].push_back(a - 1); // Adding the edge from 'b' to 'a'
    }

    // Finding the maximum number of edges that can be matched in the graph
    maxMatching = maxMatchingFunc(0, -1) / 2;

    // Printing the result based on whether all vertices have even degree or not
    cout << (2 * maxMatching == n ? "Second" : "First") << endl;

    return 0; // Indicating successful completion
}

// <END-OF-CODE>
