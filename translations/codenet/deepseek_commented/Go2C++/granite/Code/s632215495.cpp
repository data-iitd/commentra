
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node *parent, *left, *right;
};

struct Tree {
    Node *root;
};

void insert(Tree *tree, int key) {
    if (tree->root == nullptr) {
        tree->root = new Node{key, nullptr, nullptr, nullptr};
        return;
    }

    Node *parent = nullptr, *node = tree->root;
    while (node!= nullptr) {
        parent = node;
        if (node->key < key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    Node *newNode = new Node{key, parent, nullptr, nullptr};
    if (parent->key < key) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
}

void print(Tree tree) {
    vector<int> inorder, preorder;
    function<void(Node *, vector<int> &)> visitInorder = [&](Node *node, vector<int> &acc) {
        if (node == nullptr) {
            return;
        }
        visitInorder(node->left, acc);
        acc.push_back(node->key);
        visitInorder(node->right, acc);
    };
    function<void(Node *, vector<int> &)> visitPreorder = [&](Node *node, vector<int> &acc) {
        if (node == nullptr) {
            return;
        }
        acc.push_back(node->key);
        visitPreorder(node->left, acc);
        visitPreorder(node->right, acc);
    };
    visitInorder(tree.root, inorder);
    visitPreorder(tree.root, preorder);
    cout << " " << accumulate(inorder.begin(), inorder.end(), string(), [](string s, int i) { return s + to_string(i) + " "; });
    cout << endl;
    cout << " " << accumulate(preorder.begin(), preorder.end(), string(), [](string s, int i) { return s + to_string(i) + " "; });
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Tree tree;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "insert") {
            int key;
            cin >> key;
            insert(&tree, key);
        } else if (command == "print") {
            print(tree);
        } else {
            cout << "unknown command: " << command << endl;
        }
    }

    return 0;
}

