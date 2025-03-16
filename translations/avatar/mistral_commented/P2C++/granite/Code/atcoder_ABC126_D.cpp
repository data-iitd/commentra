

#include <iostream>
#include <vector>
#include <set>

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

int main() {
    int n;
    cin >> n;

    // Read input and initialize nodes
    vector<Node> nodes(n);

    // Read edges and add adjacencies to nodes
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        nodes[u].adjacencies.push_back({&nodes[v], w});
        nodes[v].adjacencies.push_back({&nodes[u], w});
    }

    // Set the root node and color it
    Node* root = &nodes[0];
    root->color = true;

    // Traverse the graph and color nodes based on their distance from the root
    set<Node*> visited;
    function<void(Node*, int)> traverse = [&](Node* node, int distance) {
        // Check if node has already been visited
        if (visited.count(node)) {
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
                adj_node->color =!root->color;
            }
            traverse(adj_node, distance + adj_distance);
        }
    };

    // Traverse the graph starting from the root
    visited.clear();
    traverse(root, 0);

    // Print the color of each node
    for (auto node : nodes) {
        if (node.color) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}

