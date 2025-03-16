#include <iostream>
#include <vector>

#define MAX 25 // Define the maximum number of nodes

// Define the node structure
struct Node {
    int l, r, par; // l: left child, r: right child, par: parent
};

std::vector<Node> N(MAX); // Vector of nodes

// Function declarations
void init(int);
void Preorder(int);
void Inorder(int);
void Postorder(int);

int main() {
    int n, id, l, r;
    int p;

    std::cin >> n; // Read the number of nodes
    init(n); // Initialize the nodes

    // Read each node's id, left child, and right child
    for (int i = 0; i < n; i++) {
        std::cin >> id >> l >> r;

        if (l != -1) {
            N[id].l = l; // Set left child
            N[l].par = id; // Set parent of left child
        }
        if (r != -1) {
            N[id].r = r; // Set right child
            N[r].par = id; // Set parent of right child
        }
    }

    // Find the root node (the node with no parent)
    for (int i = 0; i < n; i++) {
        if (N[i].par == -1) {
            p = i; // Store the index of the root node
            break;
        }
    }

    // Print the preorder, inorder, and postorder traversals
    std::cout << "Preorder";
    Preorder(p);
    std::cout << std::endl;

    std::cout << "Inorder";
    Inorder(p);
    std::cout << std::endl;

    std::cout << "Postorder";
    Postorder(p);
    std::cout << std::endl;

    return 0;
}

// Initialize all nodes
void init(int n) {
    for (int i = 0; i < n; i++) {
        N[i].par = N[i].l = N[i].r = -1;
    }
}

// Preorder traversal: root, left, right
void Preorder(int p) {
    if (p != -1) {
        std::cout << " " << p; // Print current node
        Preorder(N[p].l); // Recursively traverse left subtree
        Preorder(N[p].r); // Recursively traverse right subtree
    }
}

// Inorder traversal: left, root, right
void Inorder(int p) {
    if (p != -1) {
        Inorder(N[p].l); // Recursively traverse left subtree
        std::cout << " " << p; // Print current node
        Inorder(N[p].r); // Recursively traverse right subtree
    }
}

// Postorder traversal: left, right, root
void Postorder(int p) {
    if (p != -1) {
        Postorder(N[p].l); // Recursively traverse left subtree
        Postorder(N[p].r); // Recursively traverse right subtree
        std::cout << " " << p; // Print current node
    }
}

// <END-OF-CODE>
