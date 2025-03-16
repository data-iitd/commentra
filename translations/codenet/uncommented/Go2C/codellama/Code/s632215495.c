#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int key;
	struct node *parent;
	struct node *left;
	struct node *right;
} node;

typedef struct tree {
	node *root;
} tree;

void insert(tree *tree, int key) {
	if (tree->root == NULL) {
		tree->root = malloc(sizeof(node));
		tree->root->key = key;
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

	node *newNode = malloc(sizeof(node));
	newNode->key = key;
	newNode->parent = prevNode;
	if (prevNode->key < key) {
		prevNode->right = newNode;
	} else {
		prevNode->left = newNode;
	}
}

void print(tree *tree) {
	if (tree->root == NULL) {
		printf("\n");
		printf("\n");
	} else {
		int *acc = malloc(sizeof(int) * 1000);
		int n = 0;
		visitInorder(tree->root, acc, &n);
		printf(" ");
		for (int i = 0; i < n; i++) {
			printf("%d ", acc[i]);
		}
		printf("\n");
		printf(" ");
		n = 0;
		visitPreorder(tree->root, acc, &n);
		for (int i = 0; i < n; i++) {
			printf("%d ", acc[i]);
		}
		printf("\n");
	}
}

void visitPreorder(node *node, int *acc, int *n) {
	if (node == NULL) {
		return;
	}
	acc[*n] = node->key;
	(*n)++;
	if (node->left != NULL) {
		visitPreorder(node->left, acc, n);
	}
	if (node->right != NULL) {
		visitPreorder(node->right, acc, n);
	}
}

void visitInorder(node *node, int *acc, int *n) {
	if (node == NULL) {
		return;
	}
	if (node->left != NULL) {
		visitInorder(node->left, acc, n);
	}
	acc[*n] = node->key;
	(*n)++;
	if (node->right != NULL) {
		visitInorder(node->right, acc, n);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	tree *tree = malloc(sizeof(tree));
	tree->root = NULL;
	for (int i = 0; i < n; i++) {
		char command[10];
		scanf("%s", command);
		if (strcmp(command, "insert") == 0) {
			int key;
			scanf("%d", &key);
			insert(tree, key);
		} else if (strcmp(command, "print") == 0) {
			print(tree);
		} else {
			printf("unknown command: %s\n", command);
		}
	}
	return 0;
}

