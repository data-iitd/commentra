package main

import (
	"fmt"
)

// Define the structure for a node in the binary search tree
type Node struct {
	key int    // The key value of the node
	p   *Node  // Pointer to the parent node
	l   *Node  // Pointer to the left child node
	r   *Node  // Pointer to the right child node
}

// Global variables for the root of the tree and a NIL pointer
var r *Node
var NIL = &Node{} // Create a NIL node

// Function to find a node with a given key in the binary search tree
func find(x *Node, k int) *Node {
	for x != NIL && k != x.key {
		if k < x.key {
			x = x.l // Move to the left child if the key is smaller
		} else {
			x = x.r // Move to the right child if the key is larger
		}
	}
	return x // Return the node with the key or NIL if not found
}

// Function to insert a new key into the binary search tree
func insert(k int) {
	var y *Node = NIL // Parent of the new node
	x := r            // Start from the root

	z := &Node{key: k, l: NIL, r: NIL} // Create a new node

	// Find the position to insert the new node
	for x != NIL {
		y = x // Update the parent of the new node
		if z.key < x.key {
			x = x.l // Move to the left child if the key is smaller
		} else {
			x = x.r // Move to the right child if the key is larger
		}
	}
	z.p = y // Set the parent of the new node

	if y == NIL {
		r = z // If the tree was empty, the new node becomes the root
	} else if z.key < y.key {
		y.l = z // Insert as the left child if the key is smaller
	} else {
		y.r = z // Insert as the right child if the key is larger
	}
}

// Function to perform an inorder traversal of the tree and print the keys
func inorder(u *Node) {
	if u == NIL {
		return // Base case: if the node is NIL, return
	}
	inorder(u.l) // Recursively traverse the left subtree
	fmt.Printf(" %d", u.key) // Print the key of the current node
	inorder(u.r) // Recursively traverse the right subtree
}

// Function to perform a preorder traversal of the tree and print the keys
func preorder(u *Node) {
	if u == NIL {
		return // Base case: if the node is NIL, return
	}
	fmt.Printf(" %d", u.key) // Print the key of the current node
	preorder(u.l) // Recursively traverse the left subtree
	preorder(u.r) // Recursively traverse the right subtree
}

// Function to print the tree in both inorder and preorder traversals
func print() {
	inorder(r) // Perform inorder traversal
	fmt.Println() // Print a newline
	preorder(r) // Perform preorder traversal
	fmt.Println() // Print a newline
}

// Main function to execute the program
func main() {
	var n, z, x int
	var command string

	fmt.Scan(&n) // Read the number of operations
	for i := 0; i < n; i++ {
		fmt.Scan(&command) // Read the command
		if command[0] == 'f' {
			fmt.Scan(&x) // Read the key to find
			t := find(r, x) // Find the key in the tree
			if t == NIL {
				fmt.Println("no") // Print "no" if not found
			} else {
				fmt.Println("yes") // Print "yes" if found
			}
		} else if command[0] == 'i' {
			fmt.Scan(&z) // Read the key to insert
			insert(z) // Insert the key into the tree
		} else {
			print() // Print the tree in both traversals
		}
	}
}

// <END-OF-CODE>
