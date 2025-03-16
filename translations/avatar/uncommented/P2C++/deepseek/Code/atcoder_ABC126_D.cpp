#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

class Node {
public:
    int val;
    bool color;
    vector<pair<Node*, int>> a;
};

int main() {
    int n;
    cin >> n;
    vector<Node> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(Node());
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Node* node1 = &nodes[u - 1];
        Node* node2 = &nodes[v - 1];
        node1->val = u;
        node2->val = v;
        node1->a.push_back(make_pair(node2, w));
        node2->a.push_back(make_pair(node1, w));
    }
    Node* root = &nodes[0];
    root->color = true;
    set<Node*> nodeSet;

    function<void(Node*, int)> traverse = [&](Node* node, int distance) {
        if (nodeSet.find(node) != nodeSet.end()) {
            return;
        } else {
            nodeSet.insert(node);
        }
        for (auto& pair : node->a) {
            Node* adjNode = pair.first;
            int dis = pair.second;
            if ((distance + dis) % 2 == 0) {
                adjNode->color = root->color;
            } else {
                adjNode->color = !root->color;
            }
            traverse(adjNode, distance + dis);
        }
    };

    traverse(root, 0);

    for (int i = 0; i < n; i++) {
        Node* node = &nodes[i];
        cout << (node->color ? 1 : 0) << endl;
    }

    return 0;
}
