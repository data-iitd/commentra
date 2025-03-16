#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

class Node {
public:
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

    void print() {
        if (root == nullptr) {
            std::cout << "\n\n";
        } else {
            std::vector<int> inorderResult;
            std::vector<int> preorderResult;
            visitInorder(root, inorderResult);
            visitPreorder(root, preorderResult);
            printVector(inorderResult);
            printVector(preorderResult);
        }
    }

private:
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

    void printVector(const std::vector<int>& vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << vec[i];
        }
        std::cout << "\n";
    }
};

int main() {
    std::string line;
    std::getline(std::cin, line);
    int n = std::stoi(line);

    Tree tree;
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "insert") {
            int key;
            iss >> key;
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
