

#include <bits/stdc++.h>

using namespace std;

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
    // Creating an instance of MyScanner class for reading input
    MyScanner sc;
    out = new PrintWriter(new BufferedOutputStream(cout)); // Creating an instance of PrintWriter for output

    // Reading the number of vertices in the graph
    int n = sc.nextInt();

    // Initializing the graph as an ArrayList of ArrayLists
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a = sc.nextInt() - 1; // Reading the first vertex of the edge
        int b = sc.nextInt() - 1; // Reading the second vertex of the edge
        g[a].push_back(b); // Adding the edge from 'a' to 'b'
        g[b].push_back(a); // Adding the edge from 'b' to 'a'
    }

    // Finding the maximum number of edges that can be matched in the graph
    maxMatching = maxMatching(0, -1) / 2;

    // Printing the result based on whether all vertices have even degree or not
    out << (2 * maxMatching == n? "Second" : "First") << endl;

    // Closing the output stream
    out->flush();
    delete out;

    return 0;
}

These comments should provide a clear understanding of the code for anyone who reads it.

