#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// Define a Node class
class Node {
public:
    int val;
    bool color;
    vector<tuple<Node*, int>> adjacencies;

    Node() {
        val = 0;
        color = true;
    }
};

// Read input and initialize nodes
int n;
vector<Node> nodes;

// Read edges and add adjacencies to nodes
void readInput() {
    cin >> n;
    nodes.resize(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = Node();
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        Node* node_u = &nodes[u - 1];
        Node* node_v = &nodes[v - 1];
        node_u->val = u;
        node_v->val = v;
        node_u->adjacencies.push_back(make_tuple(node_v, w));
        node_v->adjacencies.push_back(make_tuple(node_u, w));
    }
}

// Set the root node and color it
Node* root;
void setRoot() {
    root = &nodes[0];
    root->color = true;
}

// Traverse the graph and color nodes based on their distance from the root
void traverse(Node* node, int distance) {
    static vector<Node*> visited(n, nullptr);
    if (visited[node->val - 1] != nullptr) {
        return;
    }
    visited[node->val - 1] = node;
    for (auto& adj : node->adjacencies) {
        Node* adj_node = get<0>(adj);
        int adj_distance = get<1>(adj);
        if ((distance + adj_distance) % 2 == 0) {
            adj_node->color = root->color;
        } else {
            adj_node->color = !root->color;
        }
        traverse(adj_node, distance + adj_distance);
    }
}

// Print the color of each node
void printColors() {
    for (auto& node : nodes) {
        if (node.color) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int main() {
    // Set the maximum recursion depth to 10^5
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    readInput();
    setRoot();
    traverse(root, 0);
    printColors();

