#include <iostream>
#include <vector>
#define NIL -1

// Define a structure to represent a node in the tree
struct Node {
    int parent, left, right; // parent, left child, and right child indices
};

// Class to represent the tree
class Tree {
public:
    std::vector<Node> R; // Vector to hold the nodes of the tree
    int n; // Number of nodes in the tree

    Tree(int size) : n(size), R(size) {
        for (int i = 0; i < n; i++) {
            R[i].parent = NIL; // Initialize all nodes' parents to NIL
        }
    }

    void preorder(int x) {
        if (x == NIL) return; // Base case
        std::cout << " " << x; // Print the current node's value
        preorder(R[x].left); // Traverse left subtree
        preorder(R[x].right); // Traverse right subtree
    }

    void inorder(int x) {
        if (x == NIL) return; // Base case
        inorder(R[x].left); // Traverse left subtree
        std::cout << " " << x; // Print the current node's value
        inorder(R[x].right); // Traverse right subtree
    }

    void postorder(int x) {
        if (x == NIL) return; // Base case
        postorder(R[x].left); // Traverse left subtree
        postorder(R[x].right); // Traverse right subtree
        std::cout << " " << x; // Print the current node's value
    }
};

int main() {
    int n, a, b, c, root;

    // Read the number of nodes in the tree
    std::cin >> n;
    Tree tree(n); // Create a tree with n nodes

    // Read the tree structure from input
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b >> c; // Read current node and its children
        tree.R[a].left = b; // Set left child
        tree.R[a].right = c; // Set right child
        if (b != NIL) tree.R[b].parent = a; // Update left child's parent
        if (c != NIL) tree.R[c].parent = a; // Update right child's parent
    }

    // Find the root of the tree (the node with no parent)
    for (int i = 0; i < n; i++) {
        if (tree.R[i].parent == NIL) {
            root = i; // Assign root node
            break; // Exit loop once root is found
        }
    }

    // Perform and print the results of the tree traversals
    std::cout << "Preorder\n";
    tree.preorder(root); // Call preorder traversal
    std::cout << "\n";

    std::cout << "Inorder\n";
    tree.inorder(root); // Call inorder traversal
    std::cout << "\n";

    std::cout << "Postorder\n";
    tree.postorder(root); // Call postorder traversal
    std::cout << "\n";

    return 0; // End of the program
}

// <END-OF-CODE>
