#include <iostream>
#define NIL -1

// Define a structure to represent a node in the tree
struct Node {
    int parent, left, right; // parent, left child, and right child indices
};

// Array to hold the nodes of the tree
Node R[10000];
int n; // Number of nodes in the tree

// Function prototypes for tree traversal
void preorder(int);
void inorder(int);
void postorder(int);

// Preorder traversal function
void preorder(int x) {
    // Base case: if the current node is NIL, return
    if (x == NIL)
        return;
    // Print the current node's value
    std::cout << " " << x;
    // Recursively traverse the left subtree
    preorder(R[x].left);
    // Recursively traverse the right subtree
    preorder(R[x].right);
}

// Inorder traversal function
void inorder(int x) {
    // Base case: if the current node is NIL, return
    if (x == NIL)
        return;
    // Recursively traverse the left subtree
    inorder(R[x].left);
    // Print the current node's value
    std::cout << " " << x;
    // Recursively traverse the right subtree
    inorder(R[x].right);
}

// Postorder traversal function
void postorder(int x) {
    // Base case: if the current node is NIL, return
    if (x == NIL)
        return;
    // Recursively traverse the left subtree
    postorder(R[x].left);
    // Recursively traverse the right subtree
    postorder(R[x].right);
    // Print the current node's value
    std::cout << " " << x;
}

int main() {
    int i, a, b, c, root;

    // Read the number of nodes in the tree
    std::cin >> n;
    
    // Initialize all nodes' parents to NIL
    for (i = 0; i < n; i++)
        R[i].parent = NIL;

    // Read the tree structure from input
    for (i = 0; i < n; i++) {
        // Read the current node and its left and right children
        std::cin >> a >> b >> c;
        R[a].left = b; // Set left child
        R[a].right = c; // Set right child
        // Update the parent of the left child if it is not NIL
        if (b != NIL) R[b].parent = a;
        // Update the parent of the right child if it is not NIL
        if (c != NIL) R[c].parent = a;
    }

    // Find the root of the tree (the node with no parent)
    for (i = 0; i < n; i++) {
        if (R[i].parent == NIL)
            root = i; // Assign root node
    }

    // Perform and print the results of the tree traversals
    std::cout << "Preorder" << std::endl;
    preorder(root); // Call preorder traversal
    std::cout << std::endl;
    
    std::cout << "Inorder" << std::endl;
    inorder(root); // Call inorder traversal
    std::cout << std::endl;
    
    std::cout << "Postorder" << std::endl;
    postorder(root); // Call postorder traversal
    std::cout << std::endl;

    return 0; // End of the program
}

