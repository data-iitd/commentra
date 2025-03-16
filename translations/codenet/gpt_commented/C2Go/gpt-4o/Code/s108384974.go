package main

import (
	"fmt"
)

// Define the structure for a node in the binary search tree
type Node struct {
	key int    // The key value of the node
	p   *Node  // Pointer to the parent node
	l   *Node  // Pointer to the left child
	r   *Node  // Pointer to the right child
}

// Global variables for the root of the tree and a sentinel NIL node
var r *Node
var NIL = &Node{} // Sentinel NIL node

// Function to find a node with a specific key in the binary search tree
func find(x *Node, k int) *Node {
	// Traverse the tree until the key is found or a NIL node is reached
	for x != NIL && k != x.key {
		if k < x.key {
			x = x.l // Move to the left child if the key is smaller
		} else {
			x = x.r // Move to the right child if the key is larger
		}
	}
	return x // Return the found node or NIL if not found
}

// Function to insert a new key into the binary search tree
func insert(k int) {
	var y *Node = NIL // Parent node of the new node
	x := r            // Start from the root

	// Allocate memory for the new node and initialize its fields
	z := &Node{key: k, l: NIL, r: NIL}

	// Find the appropriate position for the new node
	for x != NIL {
		y = x // Keep track of the parent node
		if z.key < x.key {
			x = x.l // Move to the left child
		} else {
			x = x.r // Move to the right child
		}
	}
	z.p = y // Set the parent of the new node

	// Insert the new node in the tree
	if y == NIL {
		r = z // Tree was empty, new node becomes the root
	} else if z.key < y.key {
		y.l = z // Insert as the left child
	} else {
		y.r = z // Insert as the right child
	}
}

// Function to perform an inorder traversal of the tree
func inorder(u *Node) {
	if u == NIL {
		return // Base case: if the node is NIL, return
	}
	inorder(u.l) // Traverse the left subtree
	fmt.Printf(" %d", u.key) // Visit the current node
	inorder(u.r) // Traverse the right subtree
}

// Function to perform a preorder traversal of the tree
func preorder(u *Node) {
	if u == NIL {
		return // Base case: if the node is NIL, return
	}
	fmt.Printf(" %d", u.key) // Visit the current node
	preorder(u.l) // Traverse the left subtree
	preorder(u.r) // Traverse the right subtree
}

// Function to print the tree in both inorder and preorder
func print() {
	inorder(r) // Print the inorder traversal
	fmt.Println() // New line after inorder
	preorder(r) // Print the preorder traversal
	fmt.Println() // New line after preorder
}

// Main function to drive the program
func main() {
	var n, z, x int // Declare variables for input
	var command string // Variable to hold command strings

	// Read the number of operations to perform
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&command) // Read the command
		if command[0] == 'f' { // If the command is 'find'
			fmt.Scan(&x) // Read the key to find
			t := find(r, x) // Search for the key
			if t == NIL {
				fmt.Println("no") // Key not found
			} else {
				fmt.Println("yes") // Key found
			}
		} else if command[0] == 'i' { // If the command is 'insert'
			fmt.Scan(&z) // Read the key to insert
			insert(z) // Insert the key into the tree
		} else { // If the command is 'print'
			print() // Print the tree
		}
	}
}

// <END-OF-CODE>
