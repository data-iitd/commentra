
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Define a struct to represent each node in the graph
struct Node {
    int val;  // Value of the node
    bool color;  // Color of the node (True/False)
    vector<pair<Node*, int>> a;  // Adjacency list to store connected nodes and weights
};

int main() {
    int n;  // Number of nodes
    cin >> n;

    vector<Node> nodes(n);  // Initialize nodes

    // Read edges and construct the graph
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;  // Adjust for 0-indexing
        v--;  // Adjust for 0-indexing
        nodes[u].val = u;  // Set the value of the first node
        nodes[v].val = v;  // Set the value of the second node
        // Add the edge to both nodes' adjacency lists
        nodes[u].a.push_back({&nodes[v], w});
        nodes[v].a.push_back({&nodes[u], w});
    }

    // Set the root node and initialize its color
    Node* root = &nodes[0];
    root->color = true;  // Color the root node as True
    set<Node*> nodeSet;  // Set to keep track of visited nodes

    // Define a recursive function to traverse the graph
    function<void(Node*, int)> traverse = [&](Node* node, int distance) {
        // If the node has already been visited, return
        if (nodeSet.count(node)) {
            return;
        } else {
            nodeSet.insert(node);  // Mark the node as visited
        }

        // Iterate through each adjacent node
        for (auto pair : node->a) {
            Node* adjNode = pair.first;  // Get the adjacent node
            int dis = pair.second;  // Get the distance (weight) to the adjacent node
            // Determine the color of the adjacent node based on the distance
            if ((distance + dis) % 2 == 0) {
                adjNode->color = root->color;  // Same color as root
            } else {
                adjNode->color =!root->color;  // Opposite color to root
            }
            // Recursively traverse to the adjacent node
            traverse(adjNode, distance + dis);
        }
    };

    // Start the traversal from the root node with an initial distance of 0
    traverse(root, 0);

    // Output the color of each node
    for (int i = 0; i < n; i++) {
        if (nodes[i].color) {
            cout << 1 << endl;  // Print 1 for True color
        } else {
            cout << 0 << endl;  // Print 0 for False color
        }
    }

    return 0;
}
