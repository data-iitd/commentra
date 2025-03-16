#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

// Defining node and tree structures
struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;
};

struct Tree {
    Node* root;
};

// Method to insert a new node into the tree
void insert(Tree& tree, int key) {
    // Base case: If the tree is empty, create a new root node
    if (tree.root == nullptr) {
        tree.root = new Node{key, nullptr, nullptr, nullptr};
        return;
    }

    // Variables to keep track of current and previous nodes
    Node* currentNode = tree.root;
    Node* prevNode = nullptr;

    // Traverse the tree to find the correct position for the new node
    while (currentNode != nullptr) {
        prevNode = currentNode;
        if (currentNode->key < key) {
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }

    // Create a new node with the given key
    Node* newNode = new Node{key, prevNode, nullptr, nullptr};

    // Set the new node's parent to the previous node
    if (prevNode->key < key) {
        prevNode->right = newNode;
    } else {
        prevNode->left = newNode;
    }
}

// Method to print the tree in inorder and preorder traversals
void print(const Tree& tree) {
    // Base case: If the tree is empty, print an empty tree
    if (tree.root == nullptr) {
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        return;
    }

    // Variable to store the visited nodes in inorder traversal
    std::vector<int> acc;

    // Print the tree in inorder and preorder traversals
    std::cout << "Inorder traversal: ";
    inorderTraversal(tree.root, acc);
    std::cout << join(acc) << std::endl;

    std::cout << "Preorder traversal: ";
    preorderTraversal(tree.root, acc);
    std::cout << join(acc) << std::endl;
}

// Helper functions for depth-first traversals of the tree
void preorderTraversal(Node* node, std::vector<int>& acc) {
    // Base case: If the node is nullptr, return
    if (node == nullptr) {
        return;
    }

    // Add the current node's key to the accumulator array
    acc.push_back(node->key);

    // Recursively traverse the left and right subtrees
    preorderTraversal(node->left, acc);
    preorderTraversal(node->right, acc);
}

void inorderTraversal(Node* node, std::vector<int>& acc) {
    // Base case: If the node is nullptr, return
    if (node == nullptr) {
        return;
    }

    // Recursively traverse the left subtree and add its keys to the accumulator array
    inorderTraversal(node->left, acc);

    // Add the current node's key to the accumulator array
    acc.push_back(node->key);

    // Recursively traverse the right subtree and add its keys to the accumulator array
    inorderTraversal(node->right, acc);
}

// Helper function to convert an integer array to a string array
std::string join(const std::vector<int>& is) {
    std::ostringstream oss;
    for (size_t i = 0; i < is.size(); ++i) {
        if (i > 0) {
            oss << " ";
        }
        oss << is[i];
    }
    return oss.str();
}

// Main function to read input and call the appropriate methods
int main() {
    Tree tree = {nullptr};
    std::string command;
    int key;

    while (std::cin >> command) {
        if (command == "insert") {
            std::cin >> key;
            insert(tree, key);
        } else if (command == "print") {
            print(tree);
        } else {
            std::cerr << "unknown command: " << command << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
