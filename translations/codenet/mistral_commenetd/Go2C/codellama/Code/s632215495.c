
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining node and tree structures
typedef struct node {
	int key;
	struct node *parent;
	struct node *left;
	struct node *right;
} node;

typedef struct tree {
	node *root;
} tree;



// Method to insert a new node into the tree
void insert(tree *tree, int key) {
	// Base case: If the tree is empty, create a new root node
	if (tree->root == NULL) {
		tree->root = (node *)malloc(sizeof(node));
		tree->root->key = key;
		tree->root->parent = NULL;
		tree->root->left = NULL;
		tree->root->right = NULL;
		return;
	}

	// Variables to keep track of current and previous nodes
	node *currentNode, *prevNode;
	currentNode = tree->root;

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
	node *newNode = (node *)malloc(sizeof(node));
	newNode->key = key;
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
void print(tree *tree) {
	// Base case: If the tree is empty, print an empty tree
	if (tree->root == NULL) {
		printf("\n");
		printf("\n");
		return;
	}

	// Variable to store the visited nodes in inorder traversal
	int *acc = (int *)malloc(sizeof(int) * 1000);
	int accSize = 0;

	// Print the tree in inorder and preorder traversals
	printf("Inorder traversal: ");
	printInorder(tree->root, acc, &accSize);
	printf("\n");
	printf("Preorder traversal: ");
	printPreorder(tree->root, acc, &accSize);
	printf("\n");

	// Free the memory allocated for the accumulator array
	free(acc);
}



// Helper functions for depth-first traversals of the tree
void printPreorder(node *node, int *acc, int *accSize) {
	// Base case: If the node is nil, return the accumulator array
	if (node == NULL) {
		return;
	}

	// Add the current node's key to the accumulator array
	acc[*accSize] = node->key;
	*accSize += 1;

	// Recursively traverse the left and right subtrees
	printPreorder(node->left, acc, accSize);
	printPreorder(node->right, acc, accSize);
}

void printInorder(node *node, int *acc, int *accSize) {
	// Base case: If the node is nil, return the accumulator array
	if (node == NULL) {
		return;
	}

	// Recursively traverse the left subtree and add its keys to the accumulator array
	printInorder(node->left, acc, accSize);

	// Add the current node's key to the accumulator array
	acc[*accSize] = node->key;
	*accSize += 1;

	// Recursively traverse the right subtree and add its keys to the accumulator array
	printInorder(node->right, acc, accSize);
}



// Main function to read input and call the appropriate methods
int main() {
	// Creating a new scanner to read input from stdin
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	// Reading the number of nodes in the tree
	read = getline(&line, &len, stdin);
	int n = atoi(line);

	// Creating a new tree object
	tree *tree = (tree *)malloc(sizeof(tree));
	tree->root = NULL;

	// Reading the commands and calling the appropriate methods
	for (int i = 0; i < n; i++) {
		read = getline(&line, &len, stdin);
		char *command = strtok(line, " ");
		if (strcmp(command, "insert") == 0) {
			int key = atoi(strtok(NULL, " "));
			insert(tree, key);
		} else if (strcmp(command, "print") == 0) {
			print(tree);
		} else {
			printf("unknown command: %s\n", command);
		}
	}

	// Free the memory allocated for the tree
	free(tree);

	// Free the memory allocated for the line
	free(line);

	return 0;
}

