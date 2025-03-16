
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MAX = 25

type Node struct {
	l, r, par int
}

var N [MAX]Node

func main() {
	var n, i, id, l, r, p int
	var s string

	// Read the number of nodes in the tree
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	init(n) // Initialize the tree nodes

	// Read the tree structure from input
	for i = 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &id, &l, &r)

		// If left child is not -1, set the left child and parent
		if l!= -1 {
			N[id].l = l
			N[l].par = id
		}

		// If right child is not -1, set the right child and parent
		if r!= -1 {
			N[id].r = r
			N[r].par = id
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
	var i int

	// Set parent, left, and right of each node to -1 (indicating no children)
	for i = 0; i < n; i++ {
		N[i].par = N[i].l = N[i].r = -1
	}
}

// Preorder traversal: Root -> Left -> Right
func Preorder(p int) {
	if p!= -1 { // Check if the node is valid
		fmt.Printf(" %d", p) // Print the current node
		Preorder(N[p].l) // Recursively traverse the left subtree
		Preorder(N[p].r) // Recursively traverse the right subtree
	}
}

// Inorder traversal: Left -> Root -> Right
func Inorder(p int) {
	if p!= -1 { // Check if the node is valid
		Inorder(N[p].l) // Recursively traverse the left subtree
		fmt.Printf(" %d", p) // Print the current node
		Inorder(N[p].r) // Recursively traverse the right subtree
	}
}

// Postorder traversal: Left -> Right -> Root
func Postorder(p int) {
	if p!= -1 { // Check if the node is valid
		Postorder(N[p].l) // Recursively traverse the left subtree
		Postorder(N[p].r) // Recursively traverse the right subtree
		fmt.Printf(" %d", p) // Print the current node
	}
}

// END-OF-CODE