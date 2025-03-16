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
		tree->root = malloc(sizeof(node));
		tree->root->key = key;
		tree->root->parent = NULL;
		tree->root->left = NULL;
		tree->root->right = NULL;
	} else {
		node *currentNode = tree->root;
		node *prevNode = NULL;
		while (currentNode!= NULL) {
			prevNode = currentNode;
			if (currentNode->key < key) {
				currentNode = currentNode->right;
			} else {
				currentNode = currentNode->left;
			}
		}
		node *newNode = malloc(sizeof(node));
		newNode->key = key;
		newNode->parent = prevNode;
		if (prevNode->key < key) {
			prevNode->right = newNode;
		} else {
			prevNode->left = newNode;
		}
	}
}

// print prints the tree using inorder and preorder traversals.
// It uses helper functions to collect the keys in the respective orders and then converts them to strings for printing.
void print(tree tree) {
	int *acc = malloc(sizeof(int) * 1000);
	int accSize = 0;
	if (tree.root == NULL) {
		printf("\n");
		printf("\n");
	} else {
		accSize = visitInorder(tree.root, acc, accSize);
		printf(" ");
		for (int i = 0; i < accSize; i++) {
			printf("%d ", acc[i]);
		}
		printf("\n");
		accSize = visitPreorder(tree.root, acc, accSize);
		printf(" ");
		for (int i = 0; i < accSize; i++) {
			printf("%d ", acc[i]);
		}
		printf("\n");
	}
	free(acc);
}

// visitPreorder is a helper function that performs a preorder traversal of the tree.
// It recursively visits nodes in the order: node, left subtree, right subtree.
int visitPreorder(node *node, int *acc, int accSize) {
	if (node == NULL) {
		return accSize;
	}
	acc[accSize] = node->key;
	accSize++;
	if (node->left!= NULL) {
		accSize = visitPreorder(node->left, acc, accSize);
	}
	if (node->right!= NULL) {
		accSize = visitPreorder(node->right, acc, accSize);
	}
	return accSize;
}

// visitInorder is a helper function that performs an inorder traversal of the tree.
// It recursively visits nodes in the order: left subtree, node, right subtree.
int visitInorder(node *node, int *acc, int accSize) {
	if (node == NULL) {
		return accSize;
	}
	if (node->left!= NULL) {
		accSize = visitInorder(node->left, acc, accSize);
	}
	acc[accSize] = node->key;
	accSize++;
	if (node->right!= NULL) {
		accSize = visitInorder(node->right, acc, accSize);
	}
	return accSize;
}

// main function reads commands from standard input.
// It supports two commands: insert to add a key to the tree and print to print the tree.
// It uses helper functions nextText and nextInt to read input values.
int main() {
	tree *tree = malloc(sizeof(tree));
	tree->root = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char *command = malloc(sizeof(char) * 100);
		scanf("%s", command);
		if (strcmp(command, "insert") == 0) {
			int key;
			scanf("%d", &key);
			insert(tree, key);
		} else if (strcmp(command, "print") == 0) {
			print(*tree);
		} else {
			printf("unknown command: %s\n", command);
		}
		free(command);
	}
	free(tree);
	return 0;
}

// nextText reads a single word from the scanner.
char *nextText(char *s) {
	char *word = malloc(sizeof(char) * 100);
	scanf("%s", word);
	return word;
}

// nextInt reads an integer from the scanner by converting the text output of nextText to an integer.
int nextInt(char *s) {
	char *word = nextText(s);
	int n = atoi(word);
	free(word);
	return n;
}

