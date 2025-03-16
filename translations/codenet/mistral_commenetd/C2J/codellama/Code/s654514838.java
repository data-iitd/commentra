#include <stdio.h>
#include <stdlib.h>
#define NIL null

// Define a structure for a node in the AVL tree
class Node{
	int key;      // The key value of the node
	int priority; // The priority value of the node
	Node left, right; // Pointers to the left and right children

	public Node(int x, int y) {
		key = x;
		priority = y;
		left = NIL;
		right = NIL;
	}
}

// Function to delete a node from the AVL tree
Node delete(Node t, int key) {
	// If the tree is empty, do nothing
	if (t == NIL) return NIL;
	// Recursively search for the node to delete
	if (key < t.key) t.left = delete(t.left, key);
	else if (key > t.key) t.right = delete(t.right, key);
	// If the node to be deleted was found, delete it and update the tree
	else {
		Node q = t;
		t = delete(t, key);
		q = null;
	}
	// If the deleted node was a rotated node, check if the tree needs to be rotated
	if (t.priority < t.left.priority || t.priority < t.right.priority) {
		// Perform a right rotation if the left child has a higher priority
		if (t.left.priority > t.right.priority)
			t = rightRotate(t);
		// Perform a left rotation if the right child has a higher priority
		t = leftRotate(t);
	}
	// Return the updated tree
	return t;
}

// Function to perform a right rotation on an AVL tree
Node rightRotate(Node p) {
	// Save a reference to the left child
	Node q = p.left;
	// Make the left child's right subtree the new root
	p.left = q.right;
	// Make the old root the new left child of the left child
	q.right = p;
	// Return the new root
	return q;
}

// Function to perform a left rotation on an AVL tree
Node leftRotate(Node p) {
	// Save a reference to the right child
	Node q = p.right;
	// Make the right child's left subtree the new root
	p.right = q.left;
	// Make the old root the new right child of the right child
	q.left = p;
	// Return the new root
	return q;
}

// Function to insert a new node into the AVL tree
Node insert(Node t, int key, int priority) {
	// If the tree is empty, create a new node and return it
	if (t == NIL) return new Node(key, priority);
	// Recursively search for the location to insert the new node
	t = insert(t, key, priority);
	// If the new node becomes the root, check if it needs to be rotated
	if (t.priority < t.left.priority || t.priority < t.right.priority) {
		// Perform a right rotation if the left child has a higher priority
		if (t.left.priority > t.right.priority)
			t = rightRotate(t);
		// Perform a left rotation if the right child has a higher priority
		t = leftRotate(t);
	}
	// Return the updated tree
	return t;
}

// Function to perform an inorder traversal of the AVL tree and print the keys
void inorder(Node a) {
	// While the current node is not NULL
	while (a != NIL) {
		// If the left subtree is not NULL, recursively traverse the left subtree
		if (a.left != NIL) inorder(a.left);
		// Print the current node's key
		System.out.print(" " + a.key);
		// If the right subtree is not NULL, recursively traverse the right subtree
		if (a.right != NIL) inorder(a.right);
		// Return from the function
		return;
	}
}

// Function to perform a preorder traversal of the AVL tree and print the keys
void preorder(Node p) {
	// Print the current node's key
	System.out.print(" " + p.key);
	// If the left subtree is not NULL, recursively traverse the left subtree
	if (p.left != NIL) preorder(p.left);
	// If the right subtree is not NULL, recursively traverse the right subtree
	if (p.right != NIL) preorder(p.right);
	// Return from the function
	return;
}

// Function to print the AVL tree
void print(Node p) {
	// Perform an inorder traversal of the AVL tree and print the keys
	inorder(p);
	// Perform a preorder traversal of the AVL tree and print the keys
	preorder(p);
	// Return from the function
	return;
}

// Function to check if a key is present in the AVL tree
boolean find(Node p, int x) {
	// While the current node is not NULL
	while (p != NIL) {
		// If the key is found, return 1
		if (p.key == x) return true;
		// If the key is smaller than the current node's key, move to the left
		else if (p.key > x) p = p.left;
		// Otherwise, move to the right
		else p = p.right;
	}
	// If the key is not found, return 0
	return false;
}

// Main function to read commands and perform the corresponding operations on the AVL tree
public static void main(String[] args) {
	// Initialize the AVL tree to be empty
	int num, x, y;
	String com;
	Node root = NIL;
	// Read the number of commands
	Scanner sc = new Scanner(System.in);
	num = sc.nextInt();
	// Process each command
	for (int i = 0; i < num; i++) {
		com = sc.next();
		// Based on the command, perform the corresponding operation on the AVL tree
		switch (com.charAt(0)) {
			case 'i': // Insert a new node
				x = sc.nextInt();
				y = sc.nextInt();
				root = insert(root, x, y);
				break;
			case 'd': // Delete a node
				x = sc.nextInt();
				root = delete(root, x);
				break;
			case 'f': // Find a node
				x = sc.nextInt();
				if (find(root, x)) System.out.println("yes");
				else System.out.println("no");
				break;
			case 'p': // Print the AVL tree
				print(root);
				break;
		}
	}
	// Return from the main function
	return;
}

