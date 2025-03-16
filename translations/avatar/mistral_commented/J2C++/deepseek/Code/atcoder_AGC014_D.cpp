#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

// Declaring static variables
vector<int> g[100005];
int maxMatching; // To store the maximum number of edges that can be matched in a bipartite graph

// Function to find the maximum number of edges that can be matched in a bipartite graph
int maxMatching(int v, int p) {
    int a = 0; // Number of edges matched from the neighboring vertices of 'v'
    int o = 0; // Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

    // Iterating through all the neighbors of 'v'
    for (int w : g[v]) {
        if (w == p) continue; // Skip if the neighbor is 'p' (self-loop)

        // Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
    }

    // Returning the result based on the parity of 'o'
    return 2 * a + min(1, o);
}

int main() {
    // Reading the number of vertices in the graph
    int n;
    cin >> n;

    // Reading the edges and adding them to the graph
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b); // Adding the edge from 'a' to 'b'
        g[b].push_back(a); // Adding the edge from 'b' to 'a'
    }

    // Finding the maximum number of edges that can be matched in the graph
    maxMatching = maxMatching(1, -1) / 2;

    // Printing the result based on whether all vertices have even degree or not
    if (2 * maxMatching == n) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }

    return 0;
}

