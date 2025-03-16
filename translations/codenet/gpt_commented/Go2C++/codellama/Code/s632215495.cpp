
#include <iostream>
#include <string>
#include <vector>

// Define a structure for a node in the binary tree
struct node {
	int key; // The key value of the node
	node* parent; // Pointer to the parent node
	node* left; // Pointer to the left child node
	node* right; // Pointer to the right child node
};

// Define a structure for the binary tree
struct tree {
	node* root; // Pointer to the root node of the tree
};

// Insert a new key into the binary tree
void insert(tree* tree, int key) {
	// If the tree is empty, create a new root node
	if (tree->root == nullptr) {
		tree->root = new node{key, nullptr, nullptr, nullptr};
		return;
	}

	node* currentNode = tree->root;
	node* prevNode = nullptr;
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
	node* newNode = new node{key, prevNode, nullptr, nullptr};
	// Attach the new node to the correct position in the tree
	if (prevNode->key < key) {
		prevNode->right = newNode; // Insert as right child
	} else {
		prevNode->left = newNode; // Insert as left child
	}
}

// Print the keys in the tree in both inorder and preorder traversal
void print(tree* tree) {
	std::vector<int> acc;
	// Check if the tree is empty
	if (tree->root == nullptr) {
		std::cout << std::endl;
		std::cout << std::endl;
	} else {
		// Print inorder traversal
		std::cout << " " << inorder(tree->root, acc);
		// Print preorder traversal
		std::cout << " " << preorder(tree->root, acc);
	}
}

// Perform a preorder traversal of the tree
std::string preorder(node* node, std::vector<int>& acc) {
	if (node == nullptr) {
		return ""; // Return accumulated keys if node is nil
	}
	acc.push_back(node->key); // Add the current node's key
	if (node->left != nullptr) {
		preorder(node->left, acc); // Traverse left subtree
	}
	if (node->right != nullptr) {
		preorder(node->right, acc); // Traverse right subtree
	}
	return std::to_string(acc[0]); // Return the accumulated keys
}

// Perform an inorder traversal of the tree
std::string inorder(node* node, std::vector<int>& acc) {
	if (node == nullptr) {
		return ""; // Return accumulated keys if node is nil
	}
	if (node->left != nullptr) {
		inorder(node->left, acc); // Traverse left subtree
	}
	acc.push_back(node->key); // Add the current node's key
	if (node->right != nullptr) {
		inorder(node->right, acc); // Traverse right subtree
	}
	return std::to_string(acc[0]); // Return the accumulated keys
}

// Main function to read commands and manipulate the binary tree
int main() {
	std::string command; // Define a string to store the command
	int n; // Define an integer to store the number of commands
	std::cin >> n; // Read the number of commands

	tree* tree = new tree{nullptr}; // Initialize a new binary tree
	// Process each command
	for (int i = 0; i < n; i++) {
		std::cin >> command; // Read the command
		switch (command[0]) {
		case 'i':
			int key; // Define an integer to store the key to insert
			std::cin >> key; // Read the key to insert
			insert(tree, key); // Insert the key into the tree
			break;
		case 'p':
			print(tree); // Print the tree's keys
			break;
		default:
			std::cout << "unknown command: " << command << std::endl; // Handle unknown commands
		}
	}
	return 0;
}

