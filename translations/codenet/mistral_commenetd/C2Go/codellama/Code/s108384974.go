
package main

import "fmt"

// Define the structure for a node in the AVL tree
type node struct {
	key  int
	p    *node
	l    *node
	r    *node
}

var r *node = nil // Initialize the root and NIL pointers
var NIL *node = nil

// Function to find a node with given key in the AVL tree
func find(x *node, k int) *node {
	for x != NIL && k != x.key { // Search for the node with the given key
		if k < x.key { // If the key is less than the current node's key
			x = x.l // Move to the left subtree
		} else {
			x = x.r // Move to the right subtree
		}
	}
	return x // Return the node if found, otherwise return NIL
}

// Function to insert a new node with given key into the AVL tree
func insert(k int) {
	y := NIL
	x := r
	z := &node{k, nil, nil, nil} // Allocate memory for the new node

	z.key = k // Set the key value of the new node
	z.l = NIL // Initialize the left and right child pointers of the new node
	z.r = NIL

	// Traverse down the tree to find the position for the new node
	for x != NIL {
		y = x // Move y pointer one level up
		if z.key < x.key { // If the new key is less than the current node's key
			x = x.l // Move to the left subtree
		} else {
			x = x.r // Move to the right subtree
		}
	}

	// Link the new node to its parent node
	z.p = y

	// Update the left or right child of the parent node
	if y == nil {
		r = z // If y is NIL, the new node is the root
	} else if z.key < y.key {
		y.l = z
	} else {
		y.r = z
	}
}

// Function to perform inorder traversal of the AVL tree and print the keys
func inorder(u *node) {
	if u == nil { // Base case: if the tree is empty, return
		return
	}
	inorder(u.l) // Recursively traverse the left subtree
	fmt.Printf(" %d", u.key) // Print the key of the current node
	inorder(u.r) // Recursively traverse the right subtree
}

// Function to perform preorder traversal of the AVL tree and print the keys
func preorder(u *node) {
	if u == nil { // Base case: if the tree is empty, return
		return
	}
	fmt.Printf(" %d", u.key) // Print the key of the current node
	preorder(u.l) // Recursively traverse the left subtree
	preorder(u.r) // Recursively traverse the right subtree
}

// Function to print the keys of the AVL tree in inorder and preorder traversals
func print() {
	inorder(r) // Perform inorder traversal and print the keys
	fmt.Println() // Print a newline character
	preorder(r) // Perform preorder traversal and print the keys
	fmt.Println() // Print a newline character
}

// Main function to read commands from the standard input and perform the corresponding operations
func main() {
	var n, i, j, z, x int // Declare variables for the number of commands and their arguments
	var s string          // Declare a string to read the command string

	fmt.Scan(&n) // Read the number of commands from the standard input
	for i = 0; i < n; i++ { // Iterate through each command
		fmt.Scan(&s) // Read the command string from the standard input

		if s[0] == 'f' { // If the command is to find a node
			fmt.Scan(&x) // Read the key value to search for
			t := find(r, x) // Find the node with the given key
			if t == nil { // If the node is not found
				fmt.Println("no")
			} else { // If the node is found
				fmt.Println("yes")
			}

		} else if s[0] == 'i' { // If the command is to insert a new node
			fmt.Scan(&z) // Read the key value of the new node
			insert(z) // Insert the new node into the AVL tree

		} else { // If the command is to print the keys of the AVL tree
			print() // Print the keys in inorder and preorder traversals
		}
	}
}

