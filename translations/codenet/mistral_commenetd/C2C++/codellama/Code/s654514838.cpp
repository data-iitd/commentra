#include <iostream>
#include <cstdlib>
#define NIL NULL

// Define a structure for a node in the AVL tree
struct node{
	int key;      // The key value of the node
	int priority; // The priority value of the node
	struct node *right, *left; // Pointers to the right and left children
};

// Function to delete a node from the AVL tree
node * Delete(node **t, int key);
node * delete(node **t, int key);

// Function to check if a key is present in the AVL tree
int find(node *p, int x)
{
	// While the current node is not NULL
	while (p != NIL) {
		// If the key is found, return 1
		if (p->key == x) return 1;
		// If the key is smaller than the current node's key, move to the left
		else if (p->key > x) p = p->left;
		// Otherwise, move to the right
		else p = p->right;
	}
	// If the key is not found, return 0
	return 0;
}

// Function to perform an inorder traversal of the AVL tree and print the keys
void inorder(node *a)
{
	// If the left subtree is not NULL, recursively traverse the left subtree
	if (a->left != NIL) inorder(a->left);
	// Print the current node's key
	std::cout << " " << a->key;
	// If the right subtree is not NULL, recursively traverse the right subtree
	if (a->right != NIL) inorder(a->right);
	// Return from the function
	return;
}

// Function to perform a preorder traversal of the AVL tree and print the keys
void preorder(node *p)
{
	// Print the current node's key
	std::cout << " " << p->key;
	// If the left subtree is not NULL, recursively traverse the left subtree
	if (p->left != NIL) preorder(p->left);
	// If the right subtree is not NULL, recursively traverse the right subtree
	if (p->right != NIL) preorder(p->right);
	// Return from the function
	return;
}

// Function to print the AVL tree
void print(node *p)
{
	// Perform an inorder traversal of the AVL tree and print the keys
	inorder(p);
	// Perform a preorder traversal of the AVL tree and print the keys
	preorder(p);
	// Return from the function
	return;
}

// Function to create a new node in the AVL tree
node * makenode(int x, int y)
{
	// Allocate memory for a new node
	node *new = (node *)malloc(sizeof(node));
	// Initialize the new node's fields
	new->key = x;
	new->priority = y;
	new->left = NIL;
	new->right = NIL;
	// Return the new node
	return new;
}

// Function to perform a right rotation on an AVL tree
node *rightRotate(node *p)
{
	// Save a reference to the left child
	node *q = p->left;
	// Make the left child's right subtree the new root
	p->left = q->right;
	// Make the old root the new left child of the left child
	q->right = p;
	// Return the new root
	return q;
}

// Function to perform a left rotation on an AVL tree
node *leftRotate(node *p)
{
	// Save a reference to the right child
	node *q = p->right;
	// Make the right child's left subtree the new root
	p->right = q->left;
	// Make the old root the new right child of the right child
	q->left = p;
	// Return the new root
	return q;
}

// Function to insert a new node into the AVL tree
node *insert(node **t, int key, int priority)
{
	// If the tree is empty, create a new node and return it
	if (*t == NIL) return makenode(key, priority);
	// Recursively search for the location to insert the new node
	*t = insert(&(*t), key, priority);
	// If the new node becomes the root, check if it needs to be rotated
	if ((*t)->priority < (*t)->left->priority || (*t)->priority < (*t)->right->priority) {
		// Perform a right rotation if the left child has a higher priority
		if ((*t)->left->priority > (*t)->right->priority)
			*t = rightRotate(*t);
		// Perform a left rotation if the right child has a higher priority
		*t = leftRotate(*t);
	}
	// Return the updated tree
	return *t;
}

// Function to delete a node from the AVL tree
node * Delete(node **t, int key)
{
	// If the tree is empty, do nothing
	if (*t == NIL) return NIL;
	// Recursively search for the node to delete
	if (key < (*t)->key) (*t) = Delete(&((*t)->left), key);
	else if (key > (*t)->key) (*t) = Delete(&((*t)->right), key);
	// If the node to be deleted was found, delete it and update the tree
	else {
		node *q = (*t);
		*t = delete(&(*t), key);
		free(q);
	}
	// If the deleted node was a rotated node, check if the tree needs to be rotated
	if ((*t)->priority < (*t)->left->priority || (*t)->priority < (*t)->right->priority) {
		// Perform a right rotation if the left child has a higher priority
		if ((*t)->left->priority > (*t)->right->priority)
			*t = rightRotate(*t);
		// Perform a left rotation if the right child has a higher priority
		*t = leftRotate(*t);
	}
	// Return the updated tree
	return *t;
}

// Main function to read commands and perform the corresponding operations on the AVL tree
int main(void)
{
	// Initialize the AVL tree to be empty
	int num, x, y;
	char com[8];
	node *root = NIL;
	// Read the number of commands
	std::cin >> num;
	// Process each command
	for (int i = 0; i < num; i++) {
		std::cin >> com;
		// Based on the command, perform the corresponding operation on the AVL tree
		switch (com[0]) {
			case 'i': // Insert a new node
				std::cin >> x >> y;
				root = insert(&root, x, y);
				break;
			case 'd': // Delete a node
				std::cin >> x;
				root = Delete(&root, x);
				break;
			case 'f': // Find a node
				std::cin >> x;
				if (find(root, x)) std::cout << "yes\n";
				else std::cout << "no\n";
				break;
			case 'p': // Print the AVL tree
				print(root);
				break;
		}
	}
	// Return from the main function
	return 0;
}

