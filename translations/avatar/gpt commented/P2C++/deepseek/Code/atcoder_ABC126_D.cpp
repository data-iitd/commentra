#include <iostream>
#include <vector>
#include <set>
#include <cstdlib> // for std::abs

using namespace std;

// Define a class to represent each node in the graph
class Node {
public:
    int val; // Value of the node
    bool color; // Color of the node (True/False)
    vector<pair<Node*, int>> a; // Adjacency list to store connected nodes and weights
};

// Read the number of nodes from input
int n;
cin >> n;
vector<Node> nodes(n);

// Read edges and construct the graph
for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    Node* node1 = &nodes[u - 1]; // Get the first node (adjusting for 0-indexing)
    Node* node2 = &nodes[v - 1]; // Get the second node (adjusting for 0-indexing)
    node1->val = u; // Set the value of the first node
    node2->val = v; // Set the value of the second node
    // Add the edge to both nodes' adjacency lists
    node1->a.push_back(make_pair(node2, w));
    node2->a.push_back(make_pair(node1, w));
}

// Set the root node and initialize its color
Node* root = &nodes[0];
root->color = true; // Color the root node as True
set<Node*> nodeSet; // Set to keep track of visited nodes

// Define a recursive function to traverse the graph
void traverse(Node* node, int distance) {
    // If the node has already been visited, return
    if (nodeSet.find(node) != nodeSet.end()) {
        return;
    } else {
        nodeSet.insert(node); // Mark the node as visited
    }

    // Iterate through each adjacent node
    for (auto& pair : node->a) {
        Node* adjNode = pair.first; // Get the adjacent node
        int dis = pair.second; // Get the distance (weight) to the adjacent node
        // Determine the color of the adjacent node based on the distance
        if ((distance + dis) % 2 == 0) {
            adjNode->color = root->color; // Same color as root
        } else {
            adjNode->color = !root->color; // Opposite color to root
        }
        // Recursively traverse to the adjacent node
        traverse(adjNode, distance + dis);
    }
}

// Start the traversal from the root node with an initial distance of 0
traverse(root, 0);

// Output the color of each node
for (int i = 0; i < n; ++i) {
    Node& node = nodes[i];
    cout << (node.color ? 1 : 0) << endl; // Print 1 for True color, 0 for False color
}

