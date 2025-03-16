
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Defining node and tree structures
struct node {
	int key;
	node* parent;
	node* left;
	node* right;
};

struct tree {
	node* root;
};



// Method to insert a new node into the tree
void insert(tree* tree, int key) {
	// Base case: If the tree is empty, create a new root node
	if (tree->root == NULL) {
		tree->root = new node;
		tree->root->key = key;
		return;
	}

	// Variables to keep track of current and previous nodes
	node* currentNode = tree->root;
	node* prevNode = NULL;

	// Traverse the tree to find the correct position for the new node
	while (currentNode != NULL) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right;
		} else {
			currentNode = currentNode->left;
		}
	}

	// Create a new node with the given key
	node* newNode = new node;
	newNode->key = key;

	// Set the new node's parent to the previous node
	newNode->parent = prevNode;

	// If the previous node's key is less than the new node's key,
	// set the previous node's right child to the new node
	if (prevNode->key < key) {
		prevNode->right = newNode;
	} else {
		// Otherwise, set the previous node's left child to the new node
		prevNode->left = newNode;
	}
}



// Method to print the tree in inorder and preorder traversals
void print(tree* tree) {
	// Base case: If the tree is empty, print an empty tree
	if (tree->root == NULL) {
		cout << endl;
		cout << endl;
		return;
	}

	// Variable to store the visited nodes in inorder traversal
	vector<int> acc;

	// Print the tree in inorder and preorder traversals
	cout << "Inorder traversal: ";
	printInorder(tree->root, acc);
	cout << endl;
	cout << "Preorder traversal: ";
	printPreorder(tree->root, acc);
	cout << endl;
}



// Helper functions for depth-first traversals of the tree
void printPreorder(node* node, vector<int>& acc) {
	// Base case: If the node is NULL, return the accumulator array
	if (node == NULL) {
		return;
	}

	// Add the current node's key to the accumulator array
	acc.push_back(node->key);

	// Recursively traverse the left and right subtrees
	printPreorder(node->left, acc);
	printPreorder(node->right, acc);
}

void printInorder(node* node, vector<int>& acc) {
	// Base case: If the node is NULL, return the accumulator array
	if (node == NULL) {
		return;
	}

	// Recursively traverse the left subtree and add its keys to the accumulator array
	printInorder(node->left, acc);

	// Add the current node's key to the accumulator array
	acc.push_back(node->key);

	// Recursively traverse the right subtree and add its keys to the accumulator array
	printInorder(node->right, acc);
}



// Main function to read input and call the appropriate methods
int main() {
	// Creating a new scanner to read input from stdin
	string command;
	int key;

	// Reading the number of nodes in the tree
	int n;
	cin >> n;

	// Creating a new tree object
	tree* tree = new tree;

	// Reading the commands and calling the appropriate methods
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "insert") {
			cin >> key;
			insert(tree, key);
		} else if (command == "print") {
			print(tree);
		} else {
			cout << "unknown command: " << command << endl;
		}
	}

	// Deleting the tree object
	delete tree;

	return 0;
}

