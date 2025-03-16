#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node represents a node in a binary search tree (BST)
// It contains an integer key, and pointers to its parent, left child, and right child.
typedef struct node {
	int key;
	struct node *parent;
	struct node *left;
	struct node *right;
} node;

// tree represents a binary search tree
// It contains a root node, which is the topmost node in the tree.
typedef struct tree {
	node *root;
} tree;

// insert adds a new node with the given key to the BST.
// If the tree is empty, it sets the new node as the root.
// Otherwise, it traverses the tree to find the correct position for the new node.
void insert(tree *tree, int key) {
	if (tree->root == NULL) {
		tree->root = (node *)malloc(sizeof(node));
		tree->root->key = key;
		tree->root->parent = NULL;
		tree->root->left = NULL;
		tree->root->right = NULL;
		return;
	}

	node *currentNode, *prevNode;
	currentNode = tree->root;
	while (currentNode != NULL) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right;
		} else {
			currentNode = currentNode->left;
		}
	}

	node *newNode = (node *)malloc(sizeof(node));
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
void print(tree tree) {
	int *acc = (int *)malloc(sizeof(int) * 1000);
	if (tree.root == NULL) {
		printf("\n");
		printf("\n");
	} else {
		printf(" ");
		printInorder(tree.root, acc);
		printf("\n");
		printf(" ");
		printPreorder(tree.root, acc);
		printf("\n");
	}
}

// printInorder is a helper function that performs an inorder traversal of the tree.
// It recursively visits nodes in the order: left subtree, node, right subtree.
void printInorder(node *node, int *acc) {
	if (node == NULL) {
		return;
	}
	if (node->left != NULL) {
		printInorder(node->left, acc);
	}
	acc[*acc] = node->key;
	*acc += 1;
	if (node->right != NULL) {
		printInorder(node->right, acc);
	}
}

// printPreorder is a helper function that performs a preorder traversal of the tree.
// It recursively visits nodes in the order: node, left subtree, right subtree.
void printPreorder(node *node, int *acc) {
	if (node == NULL) {
		return;
	}
	acc[*acc] = node->key;
	*acc += 1;
	if (node->left != NULL) {
		printPreorder(node->left, acc);
	}
	if (node->right != NULL) {
		printPreorder(node->right, acc);
	}
}

// main function reads commands from standard input.
// It supports two commands: insert to add a key to the tree and print to print the tree.
// It uses helper functions nextText and nextInt to read input values.
int main() {
	int n;
	scanf("%d", &n);

	tree tree;
	tree.root = NULL;
	for (int i = 0; i < n; i++) {
		char command[10];
		scanf("%s", command);
		if (strcmp(command, "insert") == 0) {
			int key;
			scanf("%d", &key);
			insert(&tree, key);
		} else if (strcmp(command, "print") == 0) {
			print(tree);
		} else {
			printf("unknown command: %s\n", command);
		}
	}
	return 0;
}

// nextText reads a single word from the scanner.
char *nextText(char *text) {
	scanf("%s", text);
	return text;
}

// nextInt reads an integer from the scanner by converting the text output of nextText to an integer.
int nextInt(char *text) {
	int key;
	scanf("%d", &key);
	return key;
}

// isToAs converts a slice of integers to a slice of strings.
char **isToAs(int *is, int n) {
	char **as = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++) {
		as[i] = (char *)malloc(sizeof(char) * 10);
		sprintf(as[i], "%d", is[i]);
	}
	return as;
}

