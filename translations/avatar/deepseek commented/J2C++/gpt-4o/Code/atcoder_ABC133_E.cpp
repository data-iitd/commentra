#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    long pattern = 0; // Stores the pattern for the node
    int index; // Index of the node in the tree
    vector<int> children; // List of children nodes
    int parent = -1; // Index of the parent node, initialized to -1 for root

    // Constructor to initialize the node with a given index
    Node(int i) : index(i) {}

    // Method to set the parent of the node recursively
    void setParent(int K, int parent, int use, vector<Node>& nodes) {
        this->pattern = K - use; // Set the pattern for the node
        this->parent = parent; // Set the parent index
        int count = 1; // Initialize count of children
        if (parent != -1) {
            count++; // Increment count if the node has a parent
        }
        for (int n : children) { // Iterate through children
            if (n == this->parent) {
                continue; // Skip the current parent to avoid recursion loop
            }
            nodes[n].setParent(K, index, count, nodes); // Recursively set parent for children
            count++; // Increment count for the next child
        }
    }
};

// Method to solve the problem
void solve() {
    int N, K;
    cin >> N >> K; // Read number of nodes and parameter K
    vector<Node> nodes(N); // Initialize vector of nodes
    for (int i = 0; i < N; i++) {
        nodes[i] = Node(i); // Initialize each node
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b; // Read edge node a and b
        a--; b--; // Convert to 0-based index
        nodes[a].children.push_back(b); // Add b as a child of a
        nodes[b].children.push_back(a); // Add a as a child of b
    }
    nodes[0].setParent(K, -1, 0, nodes); // Set parent for the root node
    long patterns = 1; // Initialize patterns variable
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % 1'000'000'007; // Calculate total patterns
    }
    cout << patterns << endl; // Print the result
}

// Main method to execute the program
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
