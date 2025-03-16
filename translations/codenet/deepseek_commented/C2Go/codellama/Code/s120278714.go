
package main

import (
	"fmt"
)

const MAX = 25 // Define the maximum number of nodes

// Define the node structure
type node struct {
	l, r, par int // l: left child, r: right child, par: parent
}

var N [MAX]node // Array of nodes

// Function declarations
func init(n int)
func Preorder(p int)
func Inorder(p int)
func Postorder(p int)

func main() {
	var n, i, id, l, r int
	var p int

	fmt.Scanf("%d", &n) // Read the number of nodes
	init(n)             // Initialize the nodes

	// Read each node's id, left child, and right child
	for i = 0; i < n; i++ {
		fmt.Scanf("%d%d%d", &id, &l, &r)

		if l != -1 {
			N[id].l = l // Set left child
			N[l].par = id
		}
		if r != -1 {
			N[id].r = r // Set right child
			N[r].par = id
		}
	}

	// Find the root node (the node with no parent)
	for i = 0; i < n; i++ {
		if N[i].par == -1 {
			p = i // Store the index of the root node
			break
		}
	}

	// Print the preorder, inorder, and postorder traversals
	fmt.Println("Preorder")
	Preorder(p)
	fmt.Println("")

	fmt.Println("Inorder")
	Inorder(p)
	fmt.Println("")

	fmt.Println("Postorder")
	Postorder(p)
	fmt.Println("")
}

// Initialize all nodes
func init(n int) {
	var i int

	for i = 0; i < n; i++ {
		N[i].par = N[i].l = N[i].r = -1
	}
}

// Preorder traversal: root, left, right
func Preorder(p int) {
	if p != -1 {
		fmt.Printf(" %d", p) // Print current node
		Preorder(N[p].l)     // Recursively traverse left subtree
		Preorder(N[p].r)     // Recursively traverse right subtree
	}
}

// Inorder traversal: left, root, right
func Inorder(p int) {
	if p != -1 {
		Inorder(N[p].l) // Recursively traverse left subtree
		fmt.Printf(" %d", p)
		Inorder(N[p].r) // Recursively traverse right subtree
	}
}

// Postorder traversal: left, right, root
func Postorder(p int) {
	if p != -1 {
		Postorder(N[p].l) // Recursively traverse left subtree
		Postorder(N[p].r) // Recursively traverse right subtree
		fmt.Printf(" %d", p)
	}
}

