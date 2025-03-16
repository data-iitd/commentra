
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Define a structure for a node in the binary tree
struct Node {
    int key; // The key value of the node
    Node* parent; // Pointer to the parent node
    Node* left; // Pointer to the left child node
    Node* right; // Pointer to the right child node
};

// Define a structure for the binary tree
struct Tree {
    Node* root; // Pointer to the root node of the tree
};

// Insert a new key into the binary tree
void insert(Tree* tree, int key) {
    // If the tree is empty, create a new root node
    if (tree->root == nullptr) {
        tree->root = new Node{key: key};
        return;
    }

    Node* currentNode = tree->root;
    Node* prevNode = nullptr;
    // Traverse the tree to find the correct position for the new key
    while (currentNode!= nullptr) {
        prevNode = currentNode;
        if (currentNode->key < key) {
            currentNode = currentNode->right; // Move to the right child
        } else {
            currentNode = currentNode->left; // Move to the left child
        }
    }

    // Create a new node for the key and set its parent
    Node* newNode = new Node{key: key};
    newNode->parent = prevNode;
    // Attach the new node to the correct position in the tree
    if (prevNode->key < key) {
        prevNode->right = newNode; // Insert as right child
    } else {
        prevNode->left = newNode; // Insert as left child
    }
}

// Print the keys in the tree in both inorder and preorder traversal
void print(Tree tree) {
    std::vector<int> acc;
    // Check if the tree is empty
    if (tree.root == nullptr) {
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
    } else {
        // Print inorder traversal
        std::cout << " " << join(inorder(tree.root, acc), " ") << std::endl;
        // Print preorder traversal
        std::cout << " " << join(preorder(tree.root, acc), " ") << std::endl;
    }
}

// Perform a preorder traversal of the tree
std::vector<int> preorder(Node* node, std::vector<int>& acc) {
    if (node == nullptr) {
        return acc; // Return accumulated keys if node is nullptr
    }
    acc.push_back(node->key); // Add the current node's key
    if (node->left!= nullptr) {
        acc = preorder(node->left, acc); // Traverse left subtree
    }
    if (node->right!= nullptr) {
        acc = preorder(node->right, acc); // Traverse right subtree
    }
    return acc;
}

// Perform an inorder traversal of the tree
std::vector<int> inorder(Node* node, std::vector<int>& acc) {
    if (node == nullptr) {
        return acc; // Return accumulated keys if node is nullptr
    }
    if (node->left!= nullptr) {
        acc = inorder(node->left, acc); // Traverse left subtree
    }
    acc.push_back(node->key); // Add the current node's key
    if (node->right!= nullptr) {
        acc = inorder(node->right, acc); // Traverse right subtree
    }
    return acc;
}

// Join a vector of integers to a string with a given delimiter
std::string join(const std::vector<int>& is, const std::string& delimiter) {
    std::stringstream ss;
    for (size_t i = 0; i < is.size(); i++) {
        ss << is[i];
        if (i < is.size() - 1) {
            ss << delimiter;
        }
    }
    return ss.str();
}

// Main function to read commands and manipulate the binary tree
int main() {
    std::cin.tie(nullptr); // Disable buffering for input/output
    std::ios::sync_with_stdio(false); // Disable synchronization between C++ and C streams

    int n;
    std::cin >> n; // Read the number of commands

    Tree tree; // Initialize a new binary tree
    // Process each command
    for (int i = 0; i < n; i++) {
        std::string command;
        std::cin >> command; // Read the command
        if (command == "insert") {
            int key;
            std::cin >> key; // Read the key to insert
            insert(&tree, key); // Insert the key into the tree
        } else if (command == "print") {
            print(tree); // Print the tree's keys
        } else {
            std::cerr << "unknown command: " << command << std::endl; // Handle unknown commands
        }
    }

    return 0;
}

