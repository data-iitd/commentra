#include <iostream> // For input/output operations
#include <string>   // For string manipulation
#include <vector>   // For using vectors
#include <sstream>  // For string stream operations

// Node represents a node in a binary search tree (BST)
struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;

    Node(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};

// Tree represents a binary search tree
class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {}

    // Insert adds a new node with the given key to the BST
    void insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
            return;
        }

        Node* currentNode = root;
        Node* prevNode = nullptr;

        while (currentNode != nullptr) {
            prevNode = currentNode;
            if (currentNode->key < key) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }

        Node* newNode = new Node(key);
        newNode->parent = prevNode;
        if (prevNode->key < key) {
            prevNode->right = newNode;
        } else {
            prevNode->left = newNode;
        }
    }

    // Print the tree using inorder and preorder traversals
    void print() {
        if (root == nullptr) {
            std::cout << "\n\n";
        } else {
            std::vector<int> inorderAcc;
            std::vector<int> preorderAcc;
            visitInorder(root, inorderAcc);
            visitPreorder(root, preorderAcc);
            printVector(inorderAcc);
            printVector(preorderAcc);
        }
    }

private:
    // Helper function for preorder traversal
    void visitPreorder(Node* node, std::vector<int>& acc) {
        if (node == nullptr) return;
        acc.push_back(node->key);
        visitPreorder(node->left, acc);
        visitPreorder(node->right, acc);
    }

    // Helper function for inorder traversal
    void visitInorder(Node* node, std::vector<int>& acc) {
        if (node == nullptr) return;
        visitInorder(node->left, acc);
        acc.push_back(node->key);
        visitInorder(node->right, acc);
    }

    // Helper function to print a vector of integers
    void printVector(const std::vector<int>& vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << vec[i];
        }
        std::cout << "\n";
    }
};

// Main function reads commands from standard input
int main() {
    int n;
    std::cin >> n;

    Tree tree;
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
