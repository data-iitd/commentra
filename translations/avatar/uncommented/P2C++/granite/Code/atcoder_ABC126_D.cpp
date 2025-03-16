
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    bool color;
    vector<pair<Node*, int>> a;
};
int n;
vector<Node> nodes;
void traverse(Node* node, int distance) {
    if (find(nodes.begin(), nodes.end(), *node)!= nodes.end()) {
        return;
    }
    nodes.push_back(*node);
    for (auto pair : node->a) {
        Node* adjNode = pair.first;
        int dis = pair.second;
        if ((distance + dis) % 2 == 0) {
            adjNode->color = node->color;
        } else {
            adjNode->color =!node->color;
        }
        traverse(adjNode, distance + dis);
    }
}
int main() {
    cin >> n;
    nodes.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        nodes[u].val = u;
        nodes[v].val = v;
        nodes[u].a.push_back(make_pair(&nodes[v], w));
        nodes[v].a.push_back(make_pair(&nodes[u], w));
    }
    nodes[0].color = true;
    traverse(&nodes[0], 0);
    for (int i = 0; i < n; i++) {
        if (nodes[i].color) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
