#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Node {
public:
    long long pattern = 0;
    int index;
    list<int> children;
    int parent = -1;

    Node(int i) : index(i) {}

    void setParent(int K, int parent, int use, vector<Node*>& nodes) {
        this->pattern = K - use;
        this->parent = parent;
        int count = 1;
        if (parent != -1) {
            count++;
        }
        for (int n : children) {
            if (n == this->parent) {
                continue;
            }
            nodes[n]->setParent(K, this->index, count, nodes);
            count++;
        }
    }

    void solve() {
        int N, K;
        cin >> N >> K;

        vector<Node*> nodes(N);
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node(i);
        }

        for (int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            nodes[a]->children.push_back(b);
            nodes[b]->children.push_back(a);
        }

        nodes[0]->setParent(K, -1, 0, nodes);
        long long patterns = 1;

        for (int i = 0; i < N; i++) {
            patterns = (patterns * nodes[i]->pattern) % 1000000007;
        }

        cout << patterns << endl;

        for (int i = 0; i < N; i++) {
            delete nodes[i];
        }
    }
};

int main() {
    Node* node = new Node(0);
    node->solve();
    delete node;
    return 0;
}

