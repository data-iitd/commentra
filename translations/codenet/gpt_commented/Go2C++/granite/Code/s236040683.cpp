
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// out is a helper function to print output to the console.
void out(string x) {
    cout << x << endl;
}

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
int getInt() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    int i;
    ss >> i;
    if (ss.fail()) {
        panic("Input is not an integer");
    }
    return i;
}

// getString reads a string from standard input and returns it.
string getString() {
    string s;
    getline(cin, s);
    return s;
}

// Node represents a graph node with a vector of connected nodes.
struct Node {
    vector<int> to; // Vector to hold indices of connected nodes
};

int main() {
    // Read the number of nodes (N) and edges (M) from input
    int N, M;
    cin >> N >> M;
    // Create a vector of Node structures to represent the graph
    vector<Node> n(N);

    // Read M edges and populate the graph
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to; // Read the edge endpoints (0-indexed)
        n[from - 1].to.push_back(to - 1); // Add the connection from 'from' to 'to'
        n[to - 1].to.push_back(from - 1); // Add the connection from 'to' to 'from' (undirected graph)
    }

    // Output the degree (number of connections) of each node
    for (int i = 0; i < N; i++) {
        out(to_string(n[i].to.size())); // Print the number of connections for node i
    }
}

