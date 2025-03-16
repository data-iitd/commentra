// Importing necessary headers
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

// Defining node and tree structures
struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;

    Node(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {}

    // Method to insert a new node into the tree
    void insert(int key) {
        // Base case: If the tree is empty, create a new root node
        if (root == nullptr) {
            root = new Node(key);
            return;
        }

        // Variables to keep track of current and previous nodes
        Node* currentNode = root;
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
        Node* newNode = new Node(key);
        newNode->parent = prevNode;

        // Set the new node's parent to the previous node
        if (prevNode->key < key) {
            prevNode->right = newNode;
        } else {
            prevNode->left = newNode;
        }
    }

    // Method to print the tree in inorder and preorder traversals
    void print() {
        if (root == nullptr) {
            std::cout << "\n\n";
            return;
        }

        // Vectors to store the visited nodes in inorder and preorder traversals
        std::vector<int> inorderAcc;
        std::vector<int> preorderAcc;

        // Print the tree in inorder and preorder traversals
        std::cout << "Inorder traversal: ";
        visitInorder(root, inorderAcc);
        printVector(inorderAcc);

        std::cout << "Preorder traversal: ";
        visitPreorder(root, preorderAcc);
        printVector(preorderAcc);
    }

private:
    // Helper functions for depth-first traversals of the tree
    void visitPreorder(Node* node, std::vector<int>& acc) {
        if (node == nullptr) return;

        acc.push_back(node->key);
        visitPreorder(node->left, acc);
        visitPreorder(node->right, acc);
    }

    void visitInorder(Node* node, std::vector<int>& acc) {
        if (node == nullptr) return;

        visitInorder(node->left, acc);
        acc.push_back(node->key);
        visitInorder(node->right, acc);
    }

    // Helper function to print a vector
    void printVector(const std::vector<int>& vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
};

// Main function to read input and call the appropriate methods
int main() {
    // Creating a new tree object
    Tree tree;

    // Reading the number of nodes in the tree
    int n;
    std::cin >> n;

    // Reading the commands and calling the appropriate methods
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "insert") {
            int key;
            std::cin >> key;
            tree.insert(key);
        } else if (command == "print") {
            tree.print();
        } else {
            throw std::runtime_error("unknown command: " + command);
        }
    }

    return 0;
}

// <END-OF-CODE>
