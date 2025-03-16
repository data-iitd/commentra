// Include necessary headers
#include <iostream> // For input and output
#include <vector>   // For using vectors
using namespace std;

// Node is a custom data structure for representing a node in the graph.
struct Node {
    vector<int> to; // Adjacency list for the node
};

// main is the entry point of the program.
int main() {
    // Read the number of nodes N and edges M from the input.
    int N, M;
    cin >> N >> M;

    // Create a vector of Node structures to store the nodes.
    vector<Node> n(N);

    // Process each edge by adding it to the to vector of the corresponding nodes.
    for (int i = 0; i < M; i++) {
        // Read the from and to nodes from the input.
        int from, to;
        cin >> from >> to;

        // Adjust for 0-based indexing
        from--;
        to--;

        // Add the edge to the to vector of the from node.
        n[from].to.push_back(to);

        // Add the edge to the to vector of the to node.
        n[to].to.push_back(from);
    }

    // Print the number of neighbors for each node.
    for (int i = 0; i < N; i++) {
        // Print the number of neighbors of the current node.
        cout << n[i].to.size() << endl;
    }

    return 0; // Indicate successful completion
}

// <END-OF-CODE>
