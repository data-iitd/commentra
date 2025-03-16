
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
		tree->root = malloc(sizeof(node));
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
	while (currentNode!= NULL) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right;
		} else {
			currentNode = currentNode->left;
		}
	}

	// Create a new node with the given key
	node *newNode = malloc(sizeof(node));
	newNode->key = key;
	newNode->parent = prevNode;
	newNode->left = NULL;
	newNode->right = NULL;

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
void print(tree tree) {
	// Base case: If the tree is empty, print an empty tree
	if (tree.root == NULL) {
		printf("\n");
		printf("\n");
		return;
	}

	// Variable to store the visited nodes in inorder traversal
	int *acc = malloc(sizeof(int) * 1000);

	// Print the tree in inorder and preorder traversals
	printf("Inorder traversal: ");
	for (int i = 0; i < 1000; i++) {
		acc[i] = 0;
	}
	printInorder(tree.root, acc);
	printf("\n");
	printf("Preorder traversal: ");
	for (int i = 0; i < 1000; i++) {
		acc[i] = 0;
	}
	printPreorder(tree.root, acc);
	printf("\n");
}



// Helper functions for depth-first traversals of the tree
void printPreorder(node *node, int *acc) {
	// Base case: If the node is nil, return
	if (node == NULL) {
		return;
	}

	// Add the current node's key to the accumulator array
	acc[node->key] = 1;

	// Recursively traverse the left and right subtrees
	if (node->left!= NULL) {
		printPreorder(node->left, acc);
	}
	if (node->right!= NULL) {
		printPreorder(node->right, acc);
	}

	// Print the keys of the visited nodes
	for (int i = 0; i < 1000; i++) {
		if (acc[i] == 1) {
			printf("%d ", i);
		}
	}
}

void printInorder(node *node, int *acc) {
	// Base case: If the node is nil, return
	if (node == NULL) {
		return;
	}

	// Recursively traverse the left subtree and add its keys to the accumulator array
	if (node->left!= NULL) {
		printInorder(node->left, acc);
	}

	// Add the current node's key to the accumulator array
	acc[node->key] = 1;

	// Recursively traverse the right subtree and add its keys to the accumulator array
	if (node->right!= NULL) {
		printInorder(node->right, acc);
	}

	// Print the keys of the visited nodes
	for (int i = 0; i < 1000; i++) {
		if (acc[i] == 1) {
			printf("%d ", i);
		}
	}
}



// Main function to read input and call the appropriate methods
int main() {
	// Creating a new scanner to read input from stdin
	FILE *f = fopen("input.txt", "r");
	if (f == NULL) {
		printf("Failed to open input.txt");
		return 1;
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int n;
	char *command;
	tree tree;
	tree.root = NULL;
	while ((read = getline(&line, &len, f))!= -1) {
		// Reading the number of nodes in the tree
		if (sscanf(line, "%d", &n) == 1) {
			continue;
		}

		// Reading the commands and calling the appropriate methods
		command = strtok(line, " ");
		if (strcmp(command, "insert") == 0) {
			int key;
			if (sscanf(strtok(NULL, " "), "%d", &key) == 1) {
				insert(&tree, key);
			}
		} else if (strcmp(command, "print") == 0) {
			print(tree);
		} else {
			printf("unknown command: %s", command);
		}
	}
	fclose(f);
	return 0;
}

