#include <iostream>
#include <memory>

// Define the structure for a node in the binary search tree
struct Node {
    std::shared_ptr<Node> right; // Pointer to the right child
    std::shared_ptr<Node> left;  // Pointer to the left child
    std::shared_ptr<Node> parent; // Pointer to the parent node
    int key;                     // Key value of the node

    Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

std::shared_ptr<Node> root; // Root of the binary search tree

// Function to find the minimum node in a subtree
std::shared_ptr<Node> treeMinimum(std::shared_ptr<Node> x) {
    while (x->left != nullptr) // Traverse to the leftmost node
        x = x->left;
    return x; // Return the minimum node
}

// Function to find the maximum node in a subtree
std::shared_ptr<Node> treeMaximum(std::shared_ptr<Node> x) {
    while (x->right != nullptr) // Traverse to the rightmost node
        x = x->right;
    return x; // Return the maximum node
}

// Function to search for a node with a specific key in the tree
std::shared_ptr<Node> treeSearch(std::shared_ptr<Node> u, int k) {
    if (u == nullptr || k == u->key) // Base case: found the node or reached a leaf
        return u;

    // Recursively search in the left or right subtree based on the key
    if (k < u->key)
        return treeSearch(u->left, k);
    else
        return treeSearch(u->right, k);
}

// Function to find the successor of a given node in the binary search tree
std::shared_ptr<Node> treeSuccessor(std::shared_ptr<Node> x) {
    std::shared_ptr<Node> y;
    if (x->right != nullptr) // If right child exists, successor is the minimum in the right subtree
        return treeMinimum(x->right);

    y = x->parent; // Start with the parent of the current node
    // Traverse up the tree until we find a node that is a left child
    while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y; // Return the successor node
}

// Function to delete a node from the binary search tree
void treeDelete(std::shared_ptr<Node> z) {
    std::shared_ptr<Node> y; // Node to be deleted
    std::shared_ptr<Node> x; // Child of y

    // Determine the node to delete (y) based on the number of children
    if (z->left == nullptr || z->right == nullptr)
        y = z; // If z has one or no children, y is z
    else
        y = treeSuccessor(z); // If z has two children, find its successor

    // Determine the child of y
    if (y->left != nullptr)
        x = y->left;
    else
        x = y->right;

    // Update the parent of x if it exists
    if (x != nullptr)
        x->parent = y->parent;

    // Update the parent's child pointer to x
    if (y->parent == nullptr)
        root = x; // If y is root, update root
    else if (y == y->parent->left)
        y->parent->left = x; // If y is a left child, update left pointer
    else
        y->parent->right = x; // If y is a right child, update right pointer

    // Copy the key from y to z if they are different
    if (y != z)
        z->key = y->key;
}

// Function to insert a new key into the binary search tree
void insert(int k) {
    std::shared_ptr<Node> y = nullptr; // Parent node
    std::shared_ptr<Node> x = root; // Current node
    auto z = std::make_shared<Node>(k); // New node to be inserted

    // Find the appropriate position for the new node
    while (x != nullptr) {
        y = x; // Keep track of the parent
        if (z->key < x->key) {
            x = x->left; // Move to the left child
        } else {
            x = x->right; // Move to the right child
        }
    }
    z->parent = y; // Set the parent of the new node
    if (y == nullptr)
        root = z; // If tree was empty, new node is root
    else if (z->key < y->key)
        y->left = z; // Insert as left child
    else
        y->right = z; // Insert as right child
}

// Function for inorder traversal of the tree
void inorder(std::shared_ptr<Node> u) {
    if (u == nullptr) return; // Base case: if the node is nullptr, return
    inorder(u->left); // Traverse left subtree
    std::cout << " " << u->key; // Print the key of the current node
    inorder(u->right); // Traverse right subtree
}

// Function for preorder traversal of the tree
void preorder(std::shared_ptr<Node> u) {
    if (u == nullptr) return; // Base case: if the node is nullptr, return
    std::cout << " " << u->key; // Print the key of the current node
    preorder(u->left); // Traverse left subtree
    preorder(u->right); // Traverse right subtree
}

// Main function to execute the program
int main() {
    int n, x; // Variables for number of commands and key value
    std::string com; // String to hold command

    std::cin >> n; // Read the number of commands

    // Loop to process each command
    for (int i = 0; i < n; i++) {
        std::cin >> com; // Read the command
        if (com[0] == 'f') { // If command is 'find'
            std::cin >> x; // Read the key to find
            auto t = treeSearch(root, x); // Search for the key
            if (t != nullptr)
                std::cout << "yes\n"; // Key found
            else
                std::cout << "no\n"; // Key not found
        } else if (com[0] == 'i') { // If command is 'insert'
            std::cin >> x; // Read the key to insert
            insert(x); // Insert the key into the tree
        } else if (com[0] == 'p') { // If command is 'print'
            inorder(root); // Print the tree in inorder
            std::cout << "\n";
            preorder(root); // Print the tree in preorder
            std::cout << "\n";
        } else if (com[0] == 'd') { // If command is 'delete'
            std::cin >> x; // Read the key to delete
            treeDelete(treeSearch(root, x)); // Delete the node with the key
        }
    }

    return 0; // Exit the program
}

// <END-OF-CODE>
