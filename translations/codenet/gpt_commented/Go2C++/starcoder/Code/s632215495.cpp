#include <iostream>
#include <string>
#include <vector>

// Define a structure for a node in the binary tree
struct node {
	int key; // The key value of the node
	node *parent; // Pointer to the parent node
	node *left; // Pointer to the left child node
	node *right; // Pointer to the right child node
};

// Define a structure for the binary tree
struct tree {
	node *root; // Pointer to the root node of the tree
};

// Insert a new key into the binary tree
void insert(tree &t, int key) {
	// If the tree is empty, create a new root node
	if (t.root == nullptr) {
		t.root = new node{key, nullptr, nullptr, nullptr};
		return;
	}

	node *currentNode = t.root;
	node *prevNode = nullptr;
	// Traverse the tree to find the correct position for the new key
	while (currentNode!= nullptr) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right; // Move to the right child
		} else {
			currentNode = currentNode->left; // Move to the left child
		}
	}

	// Create a new node for the key and set its parent
	node *newNode = new node{key, prevNode, nullptr, nullptr};
	if (prevNode->key < key) {
		prevNode->right = newNode; // Insert as right child
	} else {
		prevNode->left = newNode; // Insert as left child
	}
}

// Print the keys in the tree in both inorder and preorder traversal
void print(tree t) {
	std::vector<int> acc;
	// Check if the tree is empty
	if (t.root == nullptr) {
		std::cout << std::endl;
		std::cout << std::endl;
	} else {
		// Print inorder traversal
		std::cout << " " << std::join(isToAs(visitInorder(t.root, acc)), " ");
		// Print preorder traversal
		std::cout << " " << std::join(isToAs(visitPreorder(t.root, acc)), " ");
	}
}

// Perform a preorder traversal of the tree
std::vector<int> visitPreorder(node *node, std::vector<int> acc) {
	if (node == nullptr) {
		return acc; // Return accumulated keys if node is nullptr
	}
	acc.push_back(node->key); // Add the current node's key
	if (node->left!= nullptr) {
		acc = visitPreorder(node->left, acc); // Traverse left subtree
	}
	if (node->right!= nullptr) {
		acc = visitPreorder(node->right, acc); // Traverse right subtree
	}
	return acc;
}

// Perform an inorder traversal of the tree
std::vector<int> visitInorder(node *node, std::vector<int> acc) {
	if (node == nullptr) {
		return acc; // Return accumulated keys if node is nullptr
	}
	if (node->left!= nullptr) {
		acc = visitInorder(node->left, acc); // Traverse left subtree
	}
	acc.push_back(node->key); // Add the current node's key
	if (node->right!= nullptr) {
		acc = visitInorder(node->right, acc); // Traverse right subtree
	}
	return acc;
}

// Main function to read commands and manipulate the binary tree
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin.exceptions(std::ios_base::failbit);
	std::cout.exceptions(std::ios_base::failbit);

	std::cin.exceptions(std::ios_base::badbit);
	std::cout.exceptions(std::ios_base::badbit);

	std::cin.exceptions(std::ios_base::eofbit);
	std::cout.exceptions(std::ios_base::eofbit);

	std::cin.exceptions(std::ios_base::goodbit);
	std::cout.exceptions(std::ios_base::goodbit);

	std::cin.exceptions(std::ios_base::app);
	std::cout.exceptions(std::ios_base::app);

	std::cin.exceptions(std::ios_base::ate);
	std::cout.exceptions(std::ios_base::ate);

	std::cin.exceptions(std::ios_base::binary);
	std::cout.exceptions(std::ios_base::binary);

	std::cin.exceptions(std::ios_base::in);
	std::cout.exceptions(std::ios_base::in);

	std::cin.exceptions(std::ios_base::out);
	std::cout.exceptions(std::ios_base::out);

	std::cin.exceptions(std::ios_base::trunc);
	std::cout.exceptions(std::ios_base::trunc);

	std::cin.exceptions(std::ios_base::unitbuf);
	std::cout.exceptions(std::ios_base::unitbuf);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::failbit);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::failbit);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::eofbit);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::eofbit);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::goodbit);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::goodbit);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::app);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::app);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::ate);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::ate);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::binary);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::binary);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::in);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::in);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::out);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::out);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::trunc);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::trunc);

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::unitbuf);
	std::cout.exceptions(std::ios_base::badbit | std::ios_base::unitbuf);

	std::cin.exceptions(std::ios_base::eofbit | std::ios_base::failbit);
	std::cout.exceptions(std::ios_base::eofbit | std::ios_base::failbit);

	std::cin.exceptions(std::ios_base::eofbit | std::ios_base::goodbit);
	std::cout.exceptions(std::ios_base::eofbit | std::ios_base::goodbit);

	std::cin.exceptions(std::ios_base::eofbit | std::ios_base::app);
	std::cout.exceptions(std::ios_base::eofbit | std::ios_base::app);

	std::cin.exceptions(std::ios_base::eofbit | std::ios_base::ate);
	std::cout.exceptions(std::ios_base::eofbit | std::ios_base::ate);

	std::cin.exceptions(std::ios_base::eofbit | std::ios_base::binary);
	std::cout.exceptions(std::ios_base::eofbit | std::ios_base::binary);

	std::cin.exceptions(std::ios_base::eofbit | std::ios_base::in);
	std::cout.exceptions(std::ios_base::eofbit | std::ios_base::in);

	std::cin.exceptions(std::ios_base::eofbit | std::ios_base::out);
	std::cout.exceptions(std::ios_base::eofbit | std::ios_base::out);

	std::cin.exceptions(std::ios_base::eofbit | std::ios_base::trunc);
	std::cout.exceptions(std::ios_base::eofbit | std::ios_base::trunc);

	std::cin.exceptions(std::ios_base::eofbit | std::ios_base::unitbuf);
	std::cout.exceptions(std::ios_base::eofbit | std::ios_base::unitbuf);

	std::cin.exceptions(std::ios_base::goodbit | std::ios_base::failbit);
	std::cout.exceptions(std::ios_base::goodbit | std::ios_base::failbit);

	std::cin.exceptions(std::ios_base::goodbit | std::ios_base::eofbit);
	std::cout.exceptions(std::ios_base::goodbit | std::ios_base::eofbit);

	std::cin.exceptions(std::ios_base::goodbit | std::ios_base::app);
	std::cout.exceptions(std::ios_base::goodbit | std::ios_base::app);

	std::cin.exceptions(std::ios_base::goodbit | std::ios_base::ate);
	std::cout.exceptions(std::ios_base::goodbit | std::ios_base::ate);

	std::cin.exceptions(std::ios_base::goodbit | std::ios_base::binary);
	std::cout.exceptions(std::ios_base::goodbit | std::ios_base::binary);

	std::cin.exceptions(std::ios_base::goodbit | std::ios_base::in);
	std::cout.exceptions(std::ios_base::goodbit | std::ios_base::in);

	std::cin.exceptions(std::ios_base::goodbit | std::ios_base::out);
	std::cout.exceptions(std::ios_base::goodbit | std::ios_base::out);

	std::cin.exceptions(std::ios_base::goodbit | std::ios_base::trunc);
	std::cout.exceptions(std::ios_base::goodbit | std::ios_base::trunc);

	std::cin.exceptions(std::ios_base::goodbit | std::ios_base::unitbuf);
	std::cout.exceptions(std::ios_base::goodbit | std::ios_base::unitbuf);

	std::cin.exceptions(std::ios_base::app | std::ios_base::failbit);
	std::cout.exceptions(std::ios_base::app | std::ios_base::failbit);

	std::cin.exceptions(std::ios_base::app | std::ios_base::eofbit);
	std::cout.exceptions(std::ios_base::app | std::ios_base::eofbit);

	std::cin.exceptions(std::ios_base::app | std::ios_base::goodbit);
	std::cout.exceptions(std::ios_base::app | std::ios_base::goodbit);

	std::cin.exceptions(std::ios_base::app | std::ios_base::ate);
	std::cout.exceptions(std::ios_base::app | std::ios_base::ate);

	std::cin.exceptions(std::ios_base::app | std::ios_base::binary);
	std::cout.exceptions(std::ios_base::app | std::ios_base::binary);

	std::cin.exceptions(std::ios_base::app | std::ios_base::in);
	std::cout.exceptions(std::ios_base::app | std::ios_base::in);

	std::cin.exceptions(std::ios_base::app | std::ios_base::out);
	std::cout.exceptions(std::ios_base::app | std::ios_base::out);

	std::cin.exceptions(std::ios_base::app | std::ios_base::trunc);
	std::cout.exceptions(std::ios_base::app | std::ios_base::trunc);

	std::cin.exceptions(std::ios_base::app | std::ios_base::unitbuf);
	std::cout.exceptions(std::ios_base::app | std::ios_base::unitbuf);

	std::cin.exceptions(std::ios_base::ate | std::ios_base::failbit);
	std::cout.exceptions(std::ios_base::ate | std::ios_base::failbit);

	std::cin.exceptions(std::ios_base::ate | std::ios_base::eofbit);
	std::cout.exceptions(std::ios_base::ate | std::ios_base::eofbit);

	std::cin.exceptions(std::ios_base::ate | std::ios_base::goodbit);
	std::cout.exceptions(std::ios_base::ate | std::ios_base::goodbit);

	std::cin.exceptions(std::ios_base::ate | std::ios_base::app);
	std::cout.exceptions(std::ios_base::ate | std::ios_base::app);

	std::cin.exceptions(std::ios_base::ate | std::ios_base::binary);
	std::cout.exceptions(std::ios_base::ate | std::ios_base::binary);

	std::cin.exceptions(std::ios_base::ate | std::ios_base::in);
	std::cout.exceptions(std::ios_base::ate | std::ios_base::in);

	std::cin.exceptions(std::ios_base::ate | std::ios_base::out);
	std::cout.exceptions(std::ios_base::ate | std::ios_base::out);

	std::cin.exceptions(std::ios_base::ate | std::ios_base::trunc);
	std::cout.exceptions(std::ios_base::ate | std::ios_base::trunc);

	std::cin.exceptions(std::ios_base::ate | std::ios_base::unitbuf);
	std::cout.exceptions(std::