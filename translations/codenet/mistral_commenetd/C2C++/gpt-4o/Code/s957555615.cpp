#include <iostream>
#include <cstdlib>

// Define a node structure for AVL tree
struct Node {
    Node* right;  // pointer to the right child
    Node* left;   // pointer to the left child
    Node* parent; // pointer to the parent node
    int key;      // key value of the node

    // Constructor to initialize a node
    Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node* root = nullptr; // Initialize root as nullptr

// Function to find the minimum node in the tree
Node* treeMinimum(Node* x) {
    // Traverse to the left most node
    while (x->left != nullptr) {
        x = x->left;
    }
    // Return the minimum node
    return x;
}

// Function to find the maximum node in the tree
Node* treeMaximum(Node* x) {
    // Traverse to the right most node
    while (x->right != nullptr) {
        x = x->right;
    }
    // Return the maximum node
    return x;
}

// Note: The rest of the AVL tree implementation (insert, delete, balance, etc.) is not included.

