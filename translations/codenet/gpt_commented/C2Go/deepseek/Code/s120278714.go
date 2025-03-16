package main

import (
	"fmt"
)

const MAX = 25 // Define the maximum number of nodes in the tree

// Define a structure to represent a node in the tree
type node struct {
	l, r, par int // l: left child, r: right child, par: parent
}

var N [MAX]node // Array to hold the nodes of the tree

// Function prototypes for tree operations
func init(n int)
func Preorder(p int)
func Inorder(p int)
func Postorder(p int)

func main() {
	var n, i, id, l, r int // Variables for number of nodes, node id, left and right children
	var p int // Variable to hold the root node id

	// Read the number of nodes in the tree
	fmt.Scan(&n)
	init(n) // Initialize the tree nodes

	// Read the tree structure from input
	for i = 0; i < n; i++ {
		fmt.Scan(&id, &l, &r) // Read node id and its left and right children

		// If left child is not -1, set the left child and parent
		if l != -1 {
			N[id].l = l // Set left child
			N[l].par = id // Set parent of left child
		}
		// If right child is not -1, set the right child and parent
		if r != -1 {
			N[id].r = r // Set right child
			N[r].par = id // Set parent of right child
		}
	}

	// Find the root of the tree (the node with no parent)
	for i = 0; i < n; i++ {
		if N[i].par == -1 {
			p = i // Store the root node id
			break // Exit the loop once the root is found
		}
	}

	// Perform and display the tree traversals
	fmt.Println("Preorder")
	Preorder(p) // Call Preorder traversal starting from the root
	fmt.Println()

	fmt.Println("Inorder")
	Inorder(p) // Call Inorder traversal starting from the root
	fmt.Println()

	fmt.Println("Postorder")
	Postorder(p) // Call Postorder traversal starting from the root
	fmt.Println()
}

// Function to initialize the tree nodes
func init(n int) {
	for i := 0; i < n; i++ {
		N[i].par = N[i].l = N[i].r = -1
	}
}

// Preorder traversal: Root -> Left -> Right
func Preorder(p int) {
	if p != -1 { // Check if the node is valid
		fmt.Print(" ", p) // Print the current node
		Preorder(N[p].l) // Recursively traverse the left subtree
		Preorder(N[p].r) // Recursively traverse the right subtree
	}
}

// Inorder traversal: Left -> Root -> Right
func Inorder(p int) {
	if p != -1 { // Check if the node is valid
		Inorder(N[p].l) // Recursively traverse the left subtree
		fmt.Print(" ", p) // Print the current node
		Inorder(N[p].r) // Recursively traverse the right subtree
	}
}

// Postorder traversal: Left -> Right -> Root
func Postorder(p int) {
	if p != -1 { // Check if the node is valid
		Postorder(N[p].l) // Recursively traverse the left subtree
		Postorder(N[p].r) // Recursively traverse the right subtree
		fmt.Print(" ", p) // Print the current node
	}
}

