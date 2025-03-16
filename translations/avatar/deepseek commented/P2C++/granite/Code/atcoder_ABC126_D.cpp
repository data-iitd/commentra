

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Define the Node class to represent each node in the graph
class Node {
public:
    int val;
    bool color;
    vector<pair<Node*, int>> a;
};

// Read the number of nodes in the graph
int n;
cin >> n;

// Create a vector to store all nodes
vector<Node> nodes(n);

// Read each edge in the graph and establish connections between nodes
for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    nodes[u].val = u;
    nodes[v].val = v;
    nodes[u].a.push_back({&nodes[v], w});
    nodes[v].a.push_back({&nodes[u], w});
}

// Set the root node to the first node in the vector
Node* root = &nodes[0];

// Set the color of the root node to True
root->color = true;

// Initialize a set to keep track of visited nodes
set<Node*> nodeSet;

// Define the traverse function to recursively traverse the graph
void traverse(Node* node, int distance) {
    if (nodeSet.count(node) > 0) {
        return;
    }
    nodeSet.insert(node);
    for (auto pair : node->a) {
        Node* adjNode = pair.first;
        int dis = pair.second;
        if ((distance + dis) % 2 == 0) {
            adjNode->color = root->color;
        } else {
            adjNode->color =!root->color;
        }
        traverse(adjNode, distance + dis);
    }
}

// Call the traverse function starting from the root node with a distance of 0
traverse(root, 0);

// Print the color of each node
for (int i = 0; i < n; i++) {
    Node* node = &nodes[i];
    if (node->color) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

