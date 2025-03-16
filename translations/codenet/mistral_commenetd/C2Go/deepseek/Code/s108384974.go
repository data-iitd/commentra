package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define the structure for a node in the AVL tree
type Node struct {
	key int // The key value of the node
	p   *Node // Pointer to the parent node
	l   *Node // Pointer to the left child node
	r   *Node // Pointer to the right child node
}

var r *Node = nil // Initialize the root pointer
var NIL *Node = nil // Initialize the NIL pointer

// Function to find a node with given key in the AVL tree
func find(x *Node, k int) *Node {
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
	var y *Node = nil
	var x *Node = r
	var z *Node = &Node{key: k, l: NIL, r: NIL} // Allocate memory for the new node

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
func inorder(u *Node) {
	if u == NIL { // Base case: if the tree is empty, return
		return
	}
	inorder(u.l) // Recursively traverse the left subtree
	fmt.Print(" ", u.key) // Print the key of the current node
	inorder(u.r) // Recursively traverse the right subtree
}

// Function to perform preorder traversal of the AVL tree and print the keys
func preorder(u *Node) {
	if u == NIL { // Base case: if the tree is empty, return
		return
	}
	fmt.Print(" ", u.key) // Print the key of the current node
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
	var n, i, z, x int // Declare variables for the number of commands and their arguments
	var s string // Declare a string to read the command string
	reader := bufio.NewReader(os.Stdin) // Create a new reader for standard input

	fmt.Fscan(reader, &n) // Read the number of commands from the standard input
	for i = 0; i < n; i++ { // Iterate through each command
		s, _ = reader.ReadString('\n') // Read the command string from the standard input
		s = s[:len(s)-1] // Remove the newline character from the command string

		if s[0] == 'f' { // If the command is to find a node
			fmt.Fscan(reader, &x) // Read the key value to search for
			var t = find(r, x) // Find the node with the given key
			if t == NIL { // If the node is not found
				fmt.Println("no")
			} else { // If the node is found
				fmt.Println("yes")
			}

		} else if s[0] == 'i' { // If the command is to insert a new node
			fmt.Fscan(reader, &z) // Read the key value of the new node
			insert(z) // Insert the new node into the AVL tree

		} else { // If the command is to print the keys of the AVL tree
			print() // Print the keys in inorder and preorder traversals
		}
	}
}

