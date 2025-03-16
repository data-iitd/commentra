#include <iostream>
#include <memory>

// Define the structure for a node in the binary search tree
struct Node {
    int key;                // The key value of the node
    std::shared_ptr<Node> p; // Pointer to the parent node
    std::shared_ptr<Node> l; // Pointer to the left child node
    std::shared_ptr<Node> r; // Pointer to the right child node

    Node(int k) : key(k), p(nullptr), l(nullptr), r(nullptr) {} // Constructor
};

// Global variables for the root of the tree and a NIL pointer
std::shared_ptr<Node> r = nullptr; // Root of the tree

// Function to find a node with a given key in the binary search tree
std::shared_ptr<Node> find(std::shared_ptr<Node> x, int k) {
    while (x != nullptr && k != x->key) {
        if (k < x->key) {
            x = x->l;  // Move to the left child if the key is smaller
        } else {
            x = x->r;  // Move to the right child if the key is larger
        }
    }
    return x;  // Return the node with the key or nullptr if not found
}

// Function to insert a new key into the binary search tree
void insert(int k) {
    std::shared_ptr<Node> y = nullptr;  // Parent of the new node
    std::shared_ptr<Node> x = r;        // Start from the root

    auto z = std::make_shared<Node>(k); // Create a new node

    // Find the position to insert the new node
    while (x != nullptr) {
        y = x;  // Update the parent of the new node
        if (z->key < x->key) {
            x = x->l;  // Move to the left child if the key is smaller
        } else {
            x = x->r;  // Move to the right child if the key is larger
        }
    }
    z->p = y;  // Set the parent of the new node

    if (y == nullptr) {
        r = z;  // If the tree was empty, the new node becomes the root
    } else if (z->key < y->key) {
        y->l = z;  // Insert as the left child if the key is smaller
    } else {
        y->r = z;  // Insert as the right child if the key is larger
    }
}

// Function to perform an inorder traversal of the tree and print the keys
void inorder(std::shared_ptr<Node> u) {
    if (u == nullptr) {
        return;  // Base case: if the node is nullptr, return
    }
    inorder(u->l);  // Recursively traverse the left subtree
    std::cout << " " << u->key;  // Print the key of the current node
    inorder(u->r);  // Recursively traverse the right subtree
}

// Function to perform a preorder traversal of the tree and print the keys
void preorder(std::shared_ptr<Node> u) {
    if (u == nullptr) {
        return;  // Base case: if the node is nullptr, return
    }
    std::cout << " " << u->key;  // Print the key of the current node
    preorder(u->l);  // Recursively traverse the left subtree
    preorder(u->r);  // Recursively traverse the right subtree
}

// Function to print the tree in both inorder and preorder traversals
void print() {
    inorder(r);  // Perform inorder traversal
    std::cout << std::endl;  // Print a newline
    preorder(r);  // Perform preorder traversal
    std::cout << std::endl;  // Print a newline
}

// Main function to execute the program
int main() {
    int n, z, x;
    std::string s;

    std::cin >> n;  // Read the number of operations
    for (int i = 0; i < n; i++) {
        std::cin >> s;  // Read the command
        if (s[0] == 'f') {
            std::cin >> x;  // Read the key to find
            std::shared_ptr<Node> t = find(r, x);  // Find the key in the tree
            if (t == nullptr) std::cout << "no" << std::endl;  // Print "no" if not found
            else std::cout << "yes" << std::endl;  // Print "yes" if found

        } else if (s[0] == 'i') {
            std::cin >> z;  // Read the key to insert
            insert(z);  // Insert the key into the tree
        } else {
            print();  // Print the tree in both traversals
        }
    }

    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
