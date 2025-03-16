#include <iostream>
#include <memory> // For std::shared_ptr
#include <string>

using namespace std;

// Define the structure for a node in the AVL tree
struct Node {
    int key; // The key value of the node
    shared_ptr<Node> p; // Pointer to the parent node
    shared_ptr<Node> l; // Pointer to the left child node
    shared_ptr<Node> r; // Pointer to the right child node

    Node(int k) : key(k), p(nullptr), l(nullptr), r(nullptr) {} // Constructor
};

class AVLTree {
private:
    shared_ptr<Node> r; // Root pointer
    shared_ptr<Node> NIL; // NIL pointer

public:
    AVLTree() : r(nullptr), NIL(nullptr) {} // Constructor

    // Function to find a node with given key in the AVL tree
    shared_ptr<Node> find(shared_ptr<Node> x, int k) {
        while (x != NIL && k != x->key) { // Search for the node with the given key
            if (k < x->key) { // If the key is less than the current node's key
                x = x->l; // Move to the left subtree
            } else {
                x = x->r; // Move to the right subtree
            }
        }
        return x; // Return the node if found, otherwise return NIL
    }

    // Function to insert a new node with given key into the AVL tree
    void insert(int k) {
        shared_ptr<Node> y = NIL, x = r; // Initialize y and x pointers
        shared_ptr<Node> z = make_shared<Node>(k); // Create a new node

        // Traverse down the tree to find the position for the new node
        while (x != NIL) {
            y = x; // Move y pointer one level up
            if (z->key < x->key) { // If the new key is less than the current node's key
                x = x->l; // Move to the left subtree
            } else {
                x = x->r; // Move to the right subtree
            }
        }

        // Link the new node to its parent node
        z->p = y;

        // Update the left or right child of the parent node
        if (y == nullptr) {
            r = z; // If y is NIL, the new node is the root
        } else if (z->key < y->key) {
            y->l = z;
        } else {
            y->r = z;
        }
    }

    // Function to perform inorder traversal of the AVL tree and print the keys
    void inorder(shared_ptr<Node> u) {
        if (u == nullptr) { // Base case: if the tree is empty, return
            return;
        }
        inorder(u->l); // Recursively traverse the left subtree
        cout << " " << u->key; // Print the key of the current node
        inorder(u->r); // Recursively traverse the right subtree
    }

    // Function to perform preorder traversal of the AVL tree and print the keys
    void preorder(shared_ptr<Node> u) {
        if (u == nullptr) { // Base case: if the tree is empty, return
            return;
        }
        cout << " " << u->key; // Print the key of the current node
        preorder(u->l); // Recursively traverse the left subtree
        preorder(u->r); // Recursively traverse the right subtree
    }

    // Function to print the keys of the AVL tree in inorder and preorder traversals
    void print() {
        inorder(r); // Perform inorder traversal and print the keys
        cout << endl; // Print a newline character
        preorder(r); // Perform preorder traversal and print the keys
        cout << endl; // Print a newline character
    }

    // Main function to read commands from the standard input and perform the corresponding operations
    void processCommands() {
        int n, z, x; // Declare variables for the number of commands and their arguments
        string s; // Declare a string to read the command

        cin >> n; // Read the number of commands from the standard input
        for (int i = 0; i < n; i++) { // Iterate through each command
            cin >> s; // Read the command string from the standard input

            if (s[0] == 'f') { // If the command is to find a node
                cin >> x; // Read the key value to search for
                shared_ptr<Node> t = find(r, x); // Find the node with the given key
                if (t == nullptr) { // If the node is not found
                    cout << "no" << endl;
                } else { // If the node is found
                    cout << "yes" << endl;
                }

            } else if (s[0] == 'i') { // If the command is to insert a new node
                cin >> z; // Read the key value of the new node
                insert(z); // Insert the new node into the AVL tree

            } else { // If the command is to print the keys of the AVL tree
                print(); // Print the keys in inorder and preorder traversals
            }
        }
    }
};

int main() {
    AVLTree tree; // Create an instance of the AVLTree
    tree.processCommands(); // Process commands
    return 0; // Return 0 to indicate successful execution of the program
}

// <END-OF-CODE>
