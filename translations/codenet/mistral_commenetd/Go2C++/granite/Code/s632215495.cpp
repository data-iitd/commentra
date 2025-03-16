
// Importing necessary libraries
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Defining node and tree structures
struct Node {
	int key;
	Node* parent;
	Node* left;
	Node* right;
};

class Tree {
public:
	Node* root;

	// Method to insert a new node into the tree
	void insert(int key) {
		// Base case: If the tree is empty, create a new root node
		if (root == nullptr) {
			root = new Node{ key: key };
			return;
		}

		// Variables to keep track of current and previous nodes
		Node* currentNode = root;
		Node* prevNode = nullptr;

		// Traverse the tree to find the correct position for the new node
		while (currentNode!= nullptr) {
			prevNode = currentNode;
			if (currentNode->key < key) {
				currentNode = currentNode->right;
			} else {
				currentNode = currentNode->left;
			}
		}

		// Create a new node with the given key
		Node* newNode = new Node{ key: key };

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
	void print() {
		// Base case: If the tree is empty, print an empty tree
		if (root == nullptr) {
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			return;
		}

		// Variable to store the visited nodes in inorder traversal
		std::vector<int> acc;

		// Print the tree in inorder and preorder traversals
		std::cout << "Inorder traversal: " << isToAs(visitInorder(root, acc)) << std::endl;
		std::cout << "Preorder traversal: " << isToAs(visitPreorder(root, acc)) << std::endl;
	}

private:
	// Helper functions for depth-first traversals of the tree
	std::vector<int> visitPreorder(Node* node, std::vector<int>& acc) {
		// Base case: If the node is nullptr, return the accumulator array
		if (node == nullptr) {
			return acc;
		}

		// Add the current node's key to the accumulator array
		acc.push_back(node->key);

		// Recursively traverse the left and right subtrees
		if (node->left!= nullptr) {
			acc = visitPreorder(node->left, acc);
		}
		if (node->right!= nullptr) {
			acc = visitPreorder(node->right, acc);
		}

		// Return the updated accumulator array
		return acc;
	}

	std::vector<int> visitInorder(Node* node, std::vector<int>& acc) {
		// Base case: If the node is nullptr, return the accumulator array
		if (node == nullptr) {
			return acc;
		}

		// Recursively traverse the left subtree and add its keys to the accumulator array
		if (node->left!= nullptr) {
			acc = visitInorder(node->left, acc);
		}

		// Add the current node's key to the accumulator array
		acc.push_back(node->key);

		// Recursively traverse the right subtree and add its keys to the accumulator array
		if (node->right!= nullptr) {
			acc = visitInorder(node->right, acc);
		}

		// Return the updated accumulator array
		return acc;
	}

	// Helper function to convert an integer array to a string array
	std::vector<std::string> isToAs(const std::vector<int>& is) {
		std::vector<std::string> as;
		for (int i : is) {
			as.push_back(std::to_string(i));
		}
		return as;
	}
};

// Main function to read input and call the appropriate methods
int main() {
	// Creating a new scanner to read input from stdin
	std::istringstream input("5 insert 8 insert 2 insert 5 insert 10 insert 1 print");
	std::string line;
	while (std::getline(input, line)) {
		std::stringstream ss(line);
		std::string command;
		ss >> command;
		if (command == "insert") {
			int key;
			ss >> key;
			tree.insert(key);
		} else if (command == "print") {
			tree.print();
		} else {
			std::cerr << "unknown command: " << command << std::endl;
			return 1;
		}
	}
	return 0;
}

// End of code
