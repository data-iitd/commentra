#include <iostream>
#include <string>
#include <vector>

using namespace std;

// node represents a node in a binary search tree (BST)
// It contains an integer key, and pointers to its parent, left child, and right child.
struct node {
	int key;
	node *parent;
	node *left;
	node *right;
};

// tree represents a binary search tree
// It contains a root node, which is the topmost node in the tree.
struct tree {
	node *root;
};

// insert adds a new node with the given key to the BST.
// If the tree is empty, it sets the new node as the root.
// Otherwise, it traverses the tree to find the correct position for the new node.
void insert(tree *tree, int key) {
	if (tree->root == nullptr) {
		tree->root = new node{key, nullptr, nullptr, nullptr};
		return;
	}

	node *currentNode = tree->root;
	node *prevNode = nullptr;
	while (currentNode!= nullptr) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right;
		} else {
			currentNode = currentNode->left;
		}
	}

	node *newNode = new node{key, prevNode, nullptr, nullptr};
	if (prevNode->key < key) {
		prevNode->right = newNode;
	} else {
		prevNode->left = newNode;
	}
}

// print prints the tree using inorder and preorder traversals.
// It uses helper functions to collect the keys in the respective orders and then converts them to strings for printing.
void print(tree tree) {
	vector<int> acc;
	if (tree.root == nullptr) {
		cout << endl;
		cout << endl;
	} else {
		cout << " " << join(isToAs(visitInorder(tree.root, acc)), " ");
		cout << " " << join(isToAs(visitPreorder(tree.root, acc)), " ");
	}
}

// visitPreorder is a helper function that performs a preorder traversal of the tree.
// It recursively visits nodes in the order: node, left subtree, right subtree.
vector<int> visitPreorder(node *node, vector<int> acc) {
	if (node == nullptr) {
		return acc;
	}
	acc.push_back(node->key);
	if (node->left!= nullptr) {
		acc = visitPreorder(node->left, acc);
	}
	if (node->right!= nullptr) {
		acc = visitPreorder(node->right, acc);
	}
	return acc;
}

// visitInorder is a helper function that performs an inorder traversal of the tree.
// It recursively visits nodes in the order: left subtree, node, right subtree.
vector<int> visitInorder(node *node, vector<int> acc) {
	if (node == nullptr) {
		return acc;
	}
	if (node->left!= nullptr) {
		acc = visitInorder(node->left, acc);
	}
	acc.push_back(node->key);
	if (node->right!= nullptr) {
		acc = visitInorder(node->right, acc);
	}
	return acc;
}

// main function reads commands from standard input.
// It supports two commands: insert to add a key to the tree and print to print the tree.
// It uses helper functions nextText and nextInt to read input values.
int main() {
	int n;
	cin >> n;

	tree *tree = new tree{nullptr};
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "insert") {
			int key;
			cin >> key;
			insert(tree, key);
		} else if (command == "print") {
			print(*tree);
		} else {
			throw runtime_error("unknown command: " + command);
		}
	}
}

// nextText reads a single word from the scanner.
string nextText(istream &is) {
	string s;
	is >> s;
	return s;
}

// nextInt reads an integer from the scanner by converting the text output of nextText to an integer.
int nextInt(istream &is) {
	return stoi(nextText(is));
}

// isToAs converts a slice of integers to a slice of strings.
vector<string> isToAs(vector<int> is) {
	vector<string> as;
	for (int i = 0; i < is.size(); i++) {
		as.push_back(to_string(is[i]));
	}
	return as;
}

