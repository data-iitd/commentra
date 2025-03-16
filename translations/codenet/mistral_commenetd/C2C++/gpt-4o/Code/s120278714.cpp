#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int l = -1; // left child
    int r = -1; // right child
    int par = -1; // parent
};

vector<Node> N;

void init(int n) {
    N.resize(n);
}

void Preorder(int node) {
    if (node == -1) return;
    cout << node << " ";
    Preorder(N[node].l);
    Preorder(N[node].r);
}

void Inorder(int node) {
    if (node == -1) return;
    Inorder(N[node].l);
    cout << node << " ";
    Inorder(N[node].r);
}

void Postorder(int node) {
    if (node == -1) return;
    Postorder(N[node].l);
    Postorder(N[node].r);
    cout << node << " ";
}

int main() {
    // Declare and initialize variables
    int n, i, id, l, r;
    int p;

    // Read the number of nodes in the tree
    cin >> n;

    // Initialize the tree
    init(n);

    // Read the input and build the tree
    for (i = 0; i < n; i++) {
        // Read the id, left child, and right child of the current node
        cin >> id >> l >> r;

        // If the left child is not -1, assign it to the left child of the current node
        if (l != -1) {
            N[id].l = l;
            N[l].par = id;
        }

        // If the right child is not -1, assign it to the right child of the current node
        if (r != -1) {
            N[id].r = r;
            N[r].par = id;
        }
    }

    // Find the root node and perform tree traversals
    for (i = 0; i < n; i++) {
        if (N[i].par == -1) {
            p = i;
            break;
        }
    }

    // Print the tree traversals in Preorder, Inorder, and Postorder
    cout << "Preorder" << endl;
    Preorder(p);
    cout << endl;

    cout << "Inorder" << endl;
    Inorder(p);
    cout << endl;

    cout << "Postorder" << endl;
    Postorder(p);
    cout << endl;

    return 0;
}

// <END-OF-CODE>
