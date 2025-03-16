
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
    Node() {
        val = 0;
        color = false;
    }
};

// Read the number of nodes in the graph
int n;
cin >> n;

// Create a list to store all nodes
vector<Node> nodes(n);
for (int i = 0; i < n; i++) {
    nodes[i].val = i + 1;
}

// Read each edge in the graph and establish connections between nodes
for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    Node* node1 = &nodes[u - 1];
    Node* node2 = &nodes[v - 1];
    node1->a.push_back(make_pair(node2, w));
    node2->a.push_back(make_pair(node1, w));
}

// Set the root node to the first node in the list
Node* root = &nodes[0];

// Set the color of the root node to True
root->color = true;

// Initialize a set to keep track of visited nodes
set<Node*> nodeSet;

// Define the traverse function to recursively traverse the graph
void traverse(Node* node, int distance) {
    if (nodeSet.find(node) != nodeSet.end()) {
        return;
    } else {
        nodeSet.insert(node);
    }
    for (auto pair : node->a) {
        Node* adjNode = pair.first;
        int dis = pair.second;
        if ((distance + dis) % 2 == 0) {
            adjNode->color = root->color;
        } else {
            adjNode->color = !root->color;
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

