#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    long pattern = 0;
    int index;
    vector<int> children;
    int parent = -1;

    Node(int i) : index(i) {}

    void setParent(int K, int parent, int use, vector<Node>& nodes) {
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
            nodes[n].setParent(K, index, count, nodes);
            count++;
        }
    }
};

class Main {
public:
    void solve() {
        int N, K;
        cin >> N >> K;
        vector<Node> nodes(N);
        for (int i = 0; i < N; i++) {
            nodes[i] = Node(i);
        }
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--; // Convert to 0-based index
            nodes[a].children.push_back(b);
            nodes[b].children.push_back(a);
        }
        nodes[0].setParent(K, -1, 0, nodes);
        long patterns = 1;
        for (int i = 0; i < N; i++) {
            patterns = (patterns * nodes[i].pattern) % 1'000'000'007;
        }
        cout << patterns << endl;
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}

// <END-OF-CODE>
