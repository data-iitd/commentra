package main

import (
	"fmt"
)

type BT struct {
	parent int // To store the parent node index
	right  int // To store the index of the right child
	left   int // To store the index of the left child
}

var bt [26]BT // Array to hold the nodes of the binary tree
var n int     // Number of nodes in the binary tree

// Function to perform preorder traversal of the binary tree
func Preorder(a int) {
	if a == -1 {
		return // Base case: if the node is -1, return
	}

	fmt.Printf(" %d", a)      // Print the current node
	Preorder(bt[a].left)      // Recursively call Preorder on the left child
	Preorder(bt[a].right)     // Recursively call Preorder on the right child
}

// Function to perform inorder traversal of the binary tree
func Inorder(a int) {
	if a == -1 {
		return // Base case: if the node is -1, return
	}

	Inorder(bt[a].left)       // Recursively call Inorder on the left child
	fmt.Printf(" %d", a)      // Print the current node
	Inorder(bt[a].right)      // Recursively call Inorder on the right child
}

// Function to perform postorder traversal of the binary tree
func Postorder(a int) {
	if a == -1 {
		return // Base case: if the node is -1, return
	}

	Postorder(bt[a].left)     // Recursively call Postorder on the left child
	Postorder(bt[a].right)    // Recursively call Postorder on the right child
	fmt.Printf(" %d", a)      // Print the current node
}

// Main function to read the number of nodes, initialize the tree, and print traversals
func main() {
	var num int

	fmt.Scan(&n) // Read the number of nodes

	// Initialize all parent nodes to -1
	for i := 0; i < n; i++ {
		bt[i].parent = -1
	}

	// Read the left and right children for each node
	for i := 0; i < n; i++ {
		fmt.Scan(&num)
		fmt.Scan(&bt[num].left, &bt[num].right)

		// Update the parent pointers of the left and right children
		if bt[num].left != -1 && bt[num].right != -1 {
			bt[bt[num].left].parent = num
			bt[bt[num].right].parent = num
		} else if bt[num].left != -1 {
			bt[bt[num].left].parent = num
		} else if bt[num].right != -1 {
			bt[bt[num].right].parent = num
		}
	}

	// Find the root node (the node with no parent)
	var root int
	for i = 0; bt[i].parent != -1; i++ {
		root = i
	}

	// Print the preorder, inorder, and postorder traversals of the binary tree
	fmt.Println("Preorder")
	Preorder(root)
	fmt.Println()

	fmt.Println("Inorder")
	Inorder(root)
	fmt.Println()

	fmt.Println("Postorder")
	Postorder(root)
	fmt.Println()
}

// <END-OF-CODE>
