
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

// node represents a node in a binary search tree (BST)
// It contains an integer key, and pointers to its parent, left child, and right child.
struct node {
	int key;
	node* parent;
	node* left;
	node* right;
};

// tree represents a binary search tree
// It contains a root node, which is the topmost node in the tree.
struct tree {
	node* root;
};

// insert adds a new node with the given key to the BST.
// If the tree is empty, it sets the new node as the root.
// Otherwise, it traverses the tree to find the correct position for the new node.
void insert(tree* tree, int key) {
	if (tree->root == NULL) {
		tree->root = new node;
		tree->root->key = key;
		return;
	}

	node* currentNode = tree->root;
	node* prevNode = NULL;
	while (currentNode != NULL) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right;
		} else {
			currentNode = currentNode->left;
		}
	}

	node* newNode = new node;
	newNode->key = key;
	newNode->parent = prevNode;
	if (prevNode->key < key) {
		prevNode->right = newNode;
	} else {
		prevNode->left = newNode;
	}
}

// print prints the tree using inorder and preorder traversals.
// It uses helper functions to collect the keys in the respective orders and then converts them to strings for printing.
void print(tree* tree) {
	vector<int> inorder;
	vector<int> preorder;
	if (tree->root == NULL) {
		cout << endl;
		cout << endl;
	} else {
		visitInorder(tree->root, inorder);
		visitPreorder(tree->root, preorder);
		cout << " " << join(inorder, " ");
		cout << endl;
		cout << " " << join(preorder, " ");
	}
}

// visitPreorder is a helper function that performs a preorder traversal of the tree.
// It recursively visits nodes in the order: node, left subtree, right subtree.
void visitPreorder(node* node, vector<int>& acc) {
	if (node == NULL) {
		return;
	}
	acc.push_back(node->key);
	if (node->left != NULL) {
		visitPreorder(node->left, acc);
	}
	if (node->right != NULL) {
		visitPreorder(node->right, acc);
	}
}

// visitInorder is a helper function that performs an inorder traversal of the tree.
// It recursively visits nodes in the order: left subtree, node, right subtree.
void visitInorder(node* node, vector<int>& acc) {
	if (node == NULL) {
		return;
	}
	if (node->left != NULL) {
		visitInorder(node->left, acc);
	}
	acc.push_back(node->key);
	if (node->right != NULL) {
		visitInorder(node->right, acc);
	}
}

// join is a helper function that joins a vector of integers to a string.
string join(vector<int> is, string delim) {
	ostringstream oss;
	for (int i = 0; i < is.size(); i++) {
		oss << is[i];
		if (i < is.size() - 1) {
			oss << delim;
		}
	}
	return oss.str();
}

// main function reads commands from standard input.
// It supports two commands: insert to add a key to the tree and print to print the tree.
// It uses helper functions nextText and nextInt to read input values.
int main() {
	int n;
	cin >> n;

	tree* tree = new tree;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "insert") {
			int key;
			cin >> key;
			insert(tree, key);
		} else if (command == "print") {
			print(tree);
		} else {
			cout << "unknown command: " << command << endl;
		}
	}

	return 0;
}

// nextText reads a single word from the input stream.
string nextText(istream& is) {
	string text;
	is >> text;
	return text;
}

// nextInt reads an integer from the input stream by converting the text output of nextText to an integer.
int nextInt(istream& is) {
	return atoi(nextText(is).c_str());
}

