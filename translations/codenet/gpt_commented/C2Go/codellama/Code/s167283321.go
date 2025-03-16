package main

import "fmt"

const NIL = -1

// Define a structure to represent a node in the tree
type Node struct {
	parent, left, right int
}

// Array to hold the nodes of the tree
var R [10000]Node
var n int // Number of nodes in the tree

// Function prototypes for tree traversal
func preorder(x int)
func inorder(x int)
func postorder(x int)

// Preorder traversal function
func preorder(x int) {
	// Base case: if the current node is NIL, return
	if x == NIL {
		return
	}
	// Print the current node's value
	fmt.Printf(" %d", x)
	// Recursively traverse the left subtree
	preorder(R[x].left)
	// Recursively traverse the right subtree
	preorder(R[x].right)
}

// Inorder traversal function
func inorder(x int) {
	// Base case: if the current node is NIL, return
	if x == NIL {
		return
	}
	// Recursively traverse the left subtree
	inorder(R[x].left)
	// Print the current node's value
	fmt.Printf(" %d", x)
	// Recursively traverse the right subtree
	inorder(R[x].right)
}

// Postorder traversal function
func postorder(x int) {
	// Base case: if the current node is NIL, return
	if x == NIL {
		return
	}
	// Recursively traverse the left subtree
	postorder(R[x].left)
	// Recursively traverse the right subtree
	postorder(R[x].right)
	// Print the current node's value
	fmt.Printf(" %d", x)
}

func main() {
	var i, a, b, c, root int

	// Read the number of nodes in the tree
	fmt.Scanf("%d", &n)

	// Initialize all nodes' parents to NIL
	for i = 0; i < n; i++ {
		R[i].parent = NIL
	}

	// Read the tree structure from input
	for i = 0; i < n; i++ {
		// Read the current node and its left and right children
		fmt.Scanf("%d %d %d", &a, &b, &c)
		R[a].left = b // Set left child
		R[a].right = c // Set right child
		// Update the parent of the left child if it is not NIL
		if b != NIL {
			R[b].parent = a
		}
		// Update the parent of the right child if it is not NIL
		if c != NIL {
			R[c].parent = a
		}
	}

	// Find the root of the tree (the node with no parent)
	for i = 0; i < n; i++ {
		if R[i].parent == NIL {
			root = i // Assign root node
		}
	}

	// Perform and print the results of the tree traversals
	fmt.Println("Preorder")
	preorder(root) // Call preorder traversal
	fmt.Println()

	fmt.Println("Inorder")
	inorder(root) // Call inorder traversal
	fmt.Println()

	fmt.Println("Postorder")
	postorder(root) // Call postorder traversal
	fmt.Println()

	// 