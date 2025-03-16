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

	node *newNode = malloc(sizeof(node));
	newNode->key = key;
	newNode->parent = prevNode;
	if (prevNode->key < key) {
		prevNode->right = newNode;
	} else {
		prevNode->left = newNode;
	}
}

void print(tree tree) {
	int acc[10000];
	if (tree.root == NULL) {
		printf("\n");
		printf("\n");
	} else {
		printf(" %s", isToAs(visitInorder(tree.root, acc)));
		printf(" %s", isToAs(visitPreorder(tree.root, acc)));
	}
}

int *visitPreorder(node *node, int *acc) {
	if (node == NULL) {
		return acc;
	}
	*acc = *acc + 1;
	acc[*acc] = node->key;
	if (node->left!= NULL) {
		acc = visitPreorder(node->left, acc);
	}
	if (node->right!= NULL) {
		acc = visitPreorder(node->right, acc);
	}
	return acc;
}

int *visitInorder(node *node, int *acc) {
	if (node == NULL) {
		return acc;
	}
	if (node->left!= NULL) {
		acc = visitInorder(node->left, acc);
	}
	*acc = *acc + 1;
	acc[*acc] = node->key;
	if (node->right!= NULL) {
		acc = visitInorder(node->right, acc);
	}
	return acc;
}

int main() {
	tree tree;
	tree.root = NULL;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char command[100];
		scanf("%s", command);
		if (strcmp(command, "insert") == 0) {
			int key;
			scanf("%d", &key);
			insert(&tree, key);
		} else if (strcmp(command, "print") == 0) {
			print(tree);
		} else {
			printf("unknown command: %s", command);
		}
	}
}

int *isToAs(int *is) {
	int n = *is;
	char *as = malloc(sizeof(char) * (n + 1));
	for (int i = 0; i < n; i++) {
		as[i] = is[i] + '0';
	}
	as[n] = '\0';
	return as;
}

