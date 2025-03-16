

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
		tree->root = malloc(sizeof(node));
		tree->root->key = key;
		tree->root->parent = NULL;
		tree->root->left = NULL;
		tree->root->right = NULL;
		return;
	}

	node *currentNode, *prevNode;
	currentNode = tree->root;
	// Traverse the tree to find the correct position for the new key
	while (currentNode!= NULL) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right; // Move to the right child
		} else {
			currentNode = currentNode->left; // Move to the left child
		}
	}

	// Create a new node for the key and set its parent
	node *newNode = malloc(sizeof(node));
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
void print(tree tree) {
	int acc[100000];
	// Check if the tree is empty
	if (tree.root == NULL) {
		printf("\n");
		printf("\n");
	} else {
		// Print inorder traversal
		printf(" %s", join(isToAs(visitInorder(tree.root, acc)), " "));
		// Print preorder traversal
		printf(" %s", join(isToAs(visitPreorder(tree.root, acc)), " "));
	}
}

// Perform a preorder traversal of the tree
int *visitPreorder(node *node, int *acc) {
	if (node == NULL) {
		return acc; // Return accumulated keys if node is nil
	}
	acc = append(acc, node->key); // Add the current node's key
	if (node->left!= NULL) {
		acc = visitPreorder(node->left, acc); // Traverse left subtree
	}
	if (node->right!= NULL) {
		acc = visitPreorder(node->right, acc); // Traverse right subtree
	}
	return acc;
}

// Perform an inorder traversal of the tree
int *visitInorder(node *node, int *acc) {
	if (node == NULL) {
		return acc; // Return accumulated keys if node is nil
	}
	if (node->left!= NULL) {
		acc = visitInorder(node->left, acc); // Traverse left subtree
	}
	acc = append(acc, node->key); // Add the current node's key
	if (node->right!= NULL) {
		acc = visitInorder(node->right, acc); // Traverse right subtree
	}
	return acc;
}

// Convert a slice of integers to a slice of strings
char **isToAs(int *is) {
	int n = 0;
	while (is[n]!= 0) {
		n++;
	}
	char **as = malloc(sizeof(char *) * (n + 1));
	for (int i = 0; i < n; i++) {
		as[i] = malloc(sizeof(char) * 10);
		sprintf(as[i], "%d", is[i]);
	}
	as[n] = NULL;
	return as;
}

// Join a slice of strings into a single string
char *join(char **as, char *sep) {
	int n = 0;
	while (as[n]!= NULL) {
		n++;
	}
	char *s = malloc(sizeof(char) * (n * strlen(sep) + 1));
	s[0] = '\0';
	for (int i = 0; i < n; i++) {
		strcat(s, as[i]);
		if (i < n - 1) {
			strcat(s, sep);
		}
	}
	return s;
}

// Main function to read commands and manipulate the binary tree
int main(int argc, char *argv[]) {
	tree tree;
	tree.root = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char *command = malloc(sizeof(char) * 10);
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
		tree->root = malloc(sizeof(node));
		tree->root->key = key;
		tree->root->parent = NULL;
		tree->root->left = NULL;
		tree->root->right = NULL;
		return;
	}

	node *currentNode, *prevNode;
	currentNode = tree->root;
	// Traverse the tree to find the correct position for the new key
	while (currentNode!= NULL) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right; // Move to the right child
		} else {
			currentNode = currentNode->left; // Move to the left child
		}
	}

	// Create a new node for the key and set its parent
	node *newNode = malloc(sizeof(node));
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
void print(tree tree) {
	int acc[100000];
	// Check if the tree is empty
	if (tree.root == NULL) {
		printf("\n");
		printf("\n");
	} else {
		// Print inorder traversal
		printf(" %s", join(isToAs(visitInorder(tree.root, acc)), " "));
		// Print preorder traversal
		printf(" %s", join(isToAs(visitPreorder(tree.root, acc)), " "));
	}
}

// Perform a preorder traversal of the tree
int *visitPreorder(node *node, int *acc) {
	if (node == NULL) {
		return acc; // Return accumulated keys if node is nil
	}
	acc = append(acc, node->key); // Add the current node's key
	if (node->left!= NULL) {
		acc = visitPreorder(node->left, acc); // Traverse left subtree
	}
	if (node->right!= NULL) {
		acc = visitPreorder(node->right, acc); // Traverse right subtree
	}
	return acc;
}

// Perform an inorder traversal of the tree
int *visitInorder(node *node, int *acc) {
	if (node == NULL) {
		return acc; // Return accumulated keys if node is nil
	}
	if (node->left!= NULL) {
		acc = visitInorder(node->left, acc); // Traverse left subtree
	}
	acc = append(acc, node->key); // Add the current node's key
	if (node->right!= NULL) {
		acc = visitInorder(node->right, acc); // Traverse right subtree
	}
	return acc;
}

// Convert a slice of integers to a slice of strings
char **isToAs(int *is) {
	int n = 0;
	while (is[n]!= 0) {
		n++;
	}
	char **as = malloc(sizeof(char *) * (n + 1));
	for (int i = 0; i < n; i++) {
		as[i] = malloc(sizeof(char) * 10);
		sprintf(as[i], "%d", is[i]);
	}
	as[n] = NULL;
	return as;
}

// Join a slice of strings into a single string
char *join(char **as, char *sep) {
	int n = 0;
	while (as[n]!= NULL) {
		n++;
	}
	char *s = malloc(sizeof(char) * (n * strlen(sep) + 1));
	s[0] = '\0';
	for (int i = 0; i < n; i++) {
		strcat(s, as[i]);
		if (i < n - 1) {
			strcat(s, sep);
		}
	}
	return s;
}

// Main function to read commands and manipulate the binary tree
int main(int argc, char *argv[]) {
	tree tree;
	tree.root = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char *command = malloc(sizeof(char) * 10);
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
		tree->root = malloc(sizeof(node));
		tree->root->key = key;
		tree->root->parent = NULL;
		tree->root->left = NULL;
		tree->root->right = NULL;
		return;
	}

	node *currentNode, *prevNode;
	currentNode = tree->root;
	// Traverse the tree to find the correct position for the new key
	while (currentNode!= NULL) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right; // Move to the right child
		} else {
			currentNode = currentNode->left; // Move to the left child
		}
	}

	// Create a new node for the key and set its parent
	node *newNode = malloc(sizeof(node));
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
void print(tree tree) {
	int acc[100000];
	// Check if the tree is empty
	if (tree.root == NULL) {
		printf("\n");
		printf("\n");
	} else {
		// Print inorder traversal
		printf(" %s", join(isToAs(visitInorder(tree.root, acc)), " "));
		// Print preorder traversal
		printf(" %s", join(isToAs(visitPreorder(tree.root, acc)), " "));
	}
}

// Perform a preorder traversal of the tree
int *visitPreorder(node *node, int *acc) {
	if (node == NULL) {
		return acc; // Return accumulated keys if node is nil
	}
	acc = append(acc, node->key); // Add the current node's key
	if (node->left!= NULL) {
		acc = visitPreorder(node->left, acc); // Traverse left subtree
	}
	if (node->right!= NULL) {
		acc = visitPreorder(node->rig