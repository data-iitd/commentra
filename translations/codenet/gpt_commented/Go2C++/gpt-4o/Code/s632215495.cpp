#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

// Define a structure for a node in the binary tree
struct Node {
    int key; // The key value of the node
    shared_ptr<Node> parent; // Pointer to the parent node
    shared_ptr<Node> left; // Pointer to the left child node
    shared_ptr<Node> right; // Pointer to the right child node

    Node(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};

// Define a structure for the binary tree
class Tree {
public:
    shared_ptr<Node> root; // Pointer to the root node of the tree

    Tree() : root(nullptr) {}

    // Insert a new key into the binary tree
    void insert(int key) {
        // If the tree is empty, create a new root node
        if (root == nullptr) {
            root = make_shared<Node>(key);
            return;
        }

        shared_ptr<Node> currentNode = root;
        shared_ptr<Node> prevNode = nullptr;

        // Traverse the tree to find the correct position for the new key
        while (currentNode != nullptr) {
            prevNode = currentNode;
            if (currentNode->key < key) {
                currentNode = currentNode->right; // Move to the right child
            } else {
                currentNode = currentNode->left; // Move to the left child
            }
        }

        // Create a new node for the key and set its parent
        shared_ptr<Node> newNode = make_shared<Node>(key);
        newNode->parent = prevNode;

        // Attach the new node to the correct position in the tree
        if (prevNode->key < key) {
            prevNode->right = newNode; // Insert as right child
        } else {
            prevNode->left = newNode; // Insert as left child
        }
    }

    // Print the keys in the tree in both inorder and preorder traversal
    void print() {
        vector<int> acc;
        // Check if the tree is empty
        if (root == nullptr) {
            cout << "\n\n";
        } else {
            // Print inorder traversal
            cout << " " << join(visitInorder(root, acc)) << "\n";
            // Print preorder traversal
            cout << " " << join(visitPreorder(root, acc)) << "\n";
        }
    }

private:
    // Perform a preorder traversal of the tree
    vector<int> visitPreorder(shared_ptr<Node> node, vector<int>& acc) {
        if (node == nullptr) {
            return acc; // Return accumulated keys if node is nil
        }
        acc.push_back(node->key); // Add the current node's key
        visitPreorder(node->left, acc); // Traverse left subtree
        visitPreorder(node->right, acc); // Traverse right subtree
        return acc;
    }

    // Perform an inorder traversal of the tree
    vector<int> visitInorder(shared_ptr<Node> node, vector<int>& acc) {
        if (node == nullptr) {
            return acc; // Return accumulated keys if node is nil
        }
        visitInorder(node->left, acc); // Traverse left subtree
        acc.push_back(node->key); // Add the current node's key
        visitInorder(node->right, acc); // Traverse right subtree
        return acc;
    }

    // Convert a vector of integers to a string
    string join(const vector<int>& vec) {
        stringstream ss;
        for (size_t i = 0; i < vec.size(); ++i) {
            if (i != 0) ss << " ";
            ss << vec[i];
        }
        return ss.str();
    }
};

// Main function to read commands and manipulate the binary tree
int main() {
    int n;
    cin >> n; // Read the number of commands
    Tree tree; // Initialize a new binary tree

    // Process each command
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command; // Read the command
        if (command == "insert") {
            int key;
            cin >> key; // Read the key to insert
            tree.insert(key); // Insert the key into the tree
        } else if (command == "print") {
            tree.print(); // Print the tree's keys
        } else {
            cerr << "unknown command: " << command << endl; // Handle unknown commands
            return 1;
        }
    }
    return 0;
}

// <END-OF-CODE>
