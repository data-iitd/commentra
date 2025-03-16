#include <iostream>
#include <memory>
#include <string>

// Define the structure for a node in the binary search tree
struct Node {
    int key;                // The key value of the node
    Node* p;               // Pointer to the parent node
    Node* l;               // Pointer to the left child
    Node* r;               // Pointer to the right child

    Node(int k) : key(k), p(nullptr), l(nullptr), r(nullptr) {} // Constructor
};

// Define a type for a pointer to a node
using NodePointer = Node*;

// Global variables for the root of the tree and a sentinel NIL node
NodePointer r = nullptr; // Root of the tree

// Function to find a node with a specific key in the binary search tree
NodePointer find(NodePointer x, int k) {
    // Traverse the tree until the key is found or a nullptr is reached
    while (x != nullptr && k != x->key) {
        if (k < x->key) {
            x = x->l;  // Move to the left child if the key is smaller
        } else {
            x = x->r;  // Move to the right child if the key is larger
        }
    }
    return x;  // Return the found node or nullptr if not found
}

// Function to insert a new key into the binary search tree
void insert(int k) {
    NodePointer y = nullptr;  // Parent node of the new node
    NodePointer x = r;        // Start from the root

    // Allocate memory for the new node
    NodePointer z = new Node(k);

    // Find the appropriate position for the new node
    while (x != nullptr) {
        y = x;  // Keep track of the parent node
        if (z->key < x->key) {
            x = x->l;  // Move to the left child
        } else {
            x = x->r;  // Move to the right child
        }
    }
    z->p = y;  // Set the parent of the new node

    // Insert the new node in the tree
    if (y == nullptr) {
        r = z;  // Tree was empty, new node becomes the root
    } else if (z->key < y->key) {
        y->l = z;  // Insert as the left child
    } else {
        y->r = z;  // Insert as the right child
    }
}

// Function to perform an inorder traversal of the tree
void inorder(NodePointer u) {
    if (u == nullptr) {
        return;  // Base case: if the node is nullptr, return
    }
    inorder(u->l);  // Traverse the left subtree
    std::cout << " " << u->key;  // Visit the current node
    inorder(u->r);  // Traverse the right subtree
}

// Function to perform a preorder traversal of the tree
void preorder(NodePointer u) {
    if (u == nullptr) {
        return;  // Base case: if the node is nullptr, return
    }
    std::cout << " " << u->key;  // Visit the current node
    preorder(u->l);  // Traverse the left subtree
    preorder(u->r);  // Traverse the right subtree
}

// Function to print the tree in both inorder and preorder
void print() {
    inorder(r);  // Print the inorder traversal
    std::cout << std::endl; // New line after inorder
    preorder(r); // Print the preorder traversal
    std::cout << std::endl; // New line after preorder
}

// Main function to drive the program
int main() {
    int n, z, x;  // Declare variables for input
    std::string s; // String to hold command

    // Read the number of operations to perform
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s;  // Read the command
        if (s[0] == 'f') {  // If the command is 'find'
            std::cin >> x;  // Read the key to find
            NodePointer t = find(r, x);  // Search for the key
            if (t == nullptr) std::cout << "no" << std::endl;  // Key not found
            else std::cout << "yes" << std::endl;  // Key found

        } else if (s[0] == 'i') {  // If the command is 'insert'
            std::cin >> z;  // Read the key to insert
            insert(z);  // Insert the key into the tree
        } else {  // If the command is 'print'
            print();  // Print the tree
        }
    }

    return 0;  // Exit the program
}

// <END-OF-CODE>
