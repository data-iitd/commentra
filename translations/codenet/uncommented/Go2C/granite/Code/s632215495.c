
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
		tree->root = (node *)malloc(sizeof(node));
		tree->root->key = key;
		tree->root->parent = NULL;
		tree->root->left = NULL;
		tree->root->right = NULL;
		return;
	}

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

	node *newNode = (node *)malloc(sizeof(node));
	newNode->key = key;
	newNode->parent = prevNode;
	if (prevNode->key < key) {
		prevNode->right = newNode;
	} else {
		prevNode->left = newNode;
	}
}

void print(tree tree) {
	int acc[1000];
	int accSize = 0;
	if (tree.root == NULL) {
		printf("\n");
		printf("\n");
	} else {
		printf(" %s\n", intsToAs(visitInorder(tree.root, acc, &accSize)));
		printf(" %s\n", intsToAs(visitPreorder(tree.root, acc, &accSize)));
	}
}

int *visitPreorder(node *node, int *acc, int *accSize) {
	if (node == NULL) {
		return acc;
	}
	acc[*accSize] = node->key;
	(*accSize)++;
	if (node->left!= NULL) {
		acc = visitPreorder(node->left, acc, accSize);
	}
	if (node->right!= NULL) {
		acc = visitPreorder(node->right, acc, accSize);
	}
	return acc;
}

int *visitInorder(node *node, int *acc, int *accSize) {
	if (node == NULL) {
		return acc;
	}
	if (node->left!= NULL) {
		acc = visitInorder(node->left, acc, accSize);
	}
	acc[*accSize] = node->key;
	(*accSize)++;
	if (node->right!= NULL) {
		acc = visitInorder(node->right, acc, accSize);
	}
	return acc;
}

char *intsToAs(int *is, int n) {
	char *as = (char *)malloc(sizeof(char) * (n + 1));
	for (int i = 0; i < n; i++) {
		sprintf(as + i * 4, "%d", is[i]);
	}
	as[n * 4] = '\0';
	return as;
}

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
}

