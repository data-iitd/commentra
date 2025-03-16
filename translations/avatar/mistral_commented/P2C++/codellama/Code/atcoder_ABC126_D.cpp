
#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// Define a Node class
class Node {
public:
    int val;
    bool color;
    vector<pair<Node*, int>> adjacencies;

    // Initialize the root node
    Node() {
        val = 0;
        color = true;
    }
};

// Read input and initialize nodes
int n;
cin >> n;
vector<Node> nodes(n);

// Read edges and add adjacencies to nodes
for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    Node* node_u = &nodes[u - 1];
    Node* node_v = &nodes[v - 1];
    node_u->val = u;
    node_v->val = v;
    node_u->adjacencies.push_back(make_pair(node_v, w));
    node_v->adjacencies.push_back(make_pair(node_u, w));
}

// Set the root node and color it
Node* root = &nodes[0];
root->color = true;

// Traverse the graph and color nodes based on their distance from the root
void traverse(Node* node, int distance) {
    // Check if node has already been visited
    if (visited.find(node) != visited.end()) {
        return;
    }
    // Mark node as visited
    visited.insert(node);
    // Color node based on its distance from the root
    for (auto adj : node->adjacencies) {
        Node* adj_node = adj.first;
        int adj_distance = adj.second;
        if ((distance + adj_distance) % 2 == 0) {
            adj_node->color = root->color;
        } else {
            adj_node->color = !root->color;
        }
        traverse(adj_node, distance + adj_distance);
    }
}

// Traverse the graph starting from the root
set<Node*> visited;
traverse(root, 0);

// Print the color of each node
for (auto node : nodes) {
    if (node.color) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

