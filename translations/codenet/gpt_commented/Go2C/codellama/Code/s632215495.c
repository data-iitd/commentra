
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the binary tree
typedef struct node {
	int key; // The key value of the node
	struct node *parent; // Pointer to the parent node
	struct node *left; // Pointer to the left child node
	struct node *right; // Pointer to the right child node
} node;

// Define a structure for the binary tree
typedef struct tree {
	node *root; // Pointer to the root node of the tree
} tree;

// Insert a new key into the binary tree
void insert(tree *tree, int key) {
	// If the tree is empty, create a new root node
	if (tree->root == NULL) {
		tree->root = (node *)malloc(sizeof(node));
		tree->root->key = key;
		return;
	}

	node *currentNode, *prevNode;
	currentNode = tree->root;
	// Traverse the tree to find the correct position for the new key
	while (currentNode != NULL) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right; // Move to the right child
		} else {
			currentNode = currentNode->left; // Move to the left child
		}
	}

	// Create a new node for the key and set its parent
	node *newNode = (node *)malloc(sizeof(node));
	newNode->key = key;
	newNode->parent = prevNode;
	// Attach the new node to the correct position in the tree
	if (prevNode->key < key) {
		prevNode->right = newNode; // Insert as right child
	} else {
		prevNode->left = newNode; // Insert as left child
	}
}

// Print the keys in the tree in both inorder and preorder traversal
void print(tree *tree) {
	int *acc;
	// Check if the tree is empty
	if (tree->root == NULL) {
		printf("\n");
		printf("\n");
	} else {
		// Print inorder traversal
		acc = visitInorder(tree->root, NULL);
		printf(" ");
		for (int i = 0; i < sizeof(acc) / sizeof(int); i++) {
			printf("%d ", acc[i]);
		}
		printf("\n");
		// Print preorder traversal
		acc = visitPreorder(tree->root, NULL);
		printf(" ");
		for (int i = 0; i < sizeof(acc) / sizeof(int); i++) {
			printf("%d ", acc[i]);
		}
		printf("\n");
	}
}

// Perform a preorder traversal of the tree
int *visitPreorder(node *node, int *acc) {
	if (node == NULL) {
		return acc; // Return accumulated keys if node is nil
	}
	acc = (int *)realloc(acc, sizeof(int) * (sizeof(acc) / sizeof(int) + 1));
	acc[sizeof(acc) / sizeof(int) - 1] = node->key; // Add the current node's key
	if (node->left != NULL) {
		acc = visitPreorder(node->left, acc); // Traverse left subtree
	}
	if (node->right != NULL) {
		acc = visitPreorder(node->right, acc); // Traverse right subtree
	}
	return acc;
}

// Perform an inorder traversal of the tree
int *visitInorder(node *node, int *acc) {
	if (node == NULL) {
		return acc; // Return accumulated keys if node is nil
	}
	if (node->left != NULL) {
		acc = visitInorder(node->left, acc); // Traverse left subtree
	}
	acc = (int *)realloc(acc, sizeof(int) * (sizeof(acc) / sizeof(int) + 1));
	acc[sizeof(acc) / sizeof(int) - 1] = node->key; // Add the current node's key
	if (node->right != NULL) {
		acc = visitInorder(node->right, acc); // Traverse right subtree
	}
	return acc;
}

// Main function to read commands and manipulate the binary tree
int main() {
	int n;
	scanf("%d", &n); // Read the number of commands

	tree *tree = (tree *)malloc(sizeof(tree)); // Initialize a new binary tree
	// Process each command
	for (int i = 0; i < n; i++) {
		char command[10];
		scanf("%s", command); // Read the command
		switch (command[0]) {
		case 'i':
			int key;
			scanf("%d", &key); // Read the key to insert
			insert(tree, key); // Insert the key into the tree
			break;
		case 'p':
			print(tree); // Print the tree's keys
			break;
		default:
			printf("unknown command: %s\n", command); // Handle unknown commands
			break;
		}
	}
	return 0;
}

