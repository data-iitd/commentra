
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a structure for a binary tree node
type BT struct {
	parent int // Parent node index
	right  int // Right child index
	left   int // Left child index
}

// Array to hold the binary tree nodes
var bt [26]BT
var n int // Number of nodes in the binary tree

// Function to perform preorder traversal of the binary tree
func Preorder(a int) {
	// Base case: if the node index is -1, return
	if a == -1 {
		return
	}

	// Print the current node index
	fmt.Printf(" %d", a)
	// Recursively traverse the left subtree
	Preorder(bt[a].left)
	// Recursively traverse the right subtree
	Preorder(bt[a].right)
}

// Function to perform inorder traversal of the binary tree
func Inorder(a int) {
	// Base case: if the node index is -1, return
	if a == -1 {
		return
	}

	// Recursively traverse the left subtree
	Inorder(bt[a].left)
	// Print the current node index
	fmt.Printf(" %d", a)
	// Recursively traverse the right subtree
	Inorder(bt[a].right)
}

// Function to perform postorder traversal of the binary tree
func Postorder(a int) {
	// Base case: if the node index is -1, return
	if a == -1 {
		return
	}

	// Recursively traverse the left subtree
	Postorder(bt[a].left)
	// Recursively traverse the right subtree
	Postorder(bt[a].right)
	// Print the current node index
	fmt.Printf(" %d", a)
}

func main() {
	var i, j, num, depth int

	// Read the number of nodes in the binary tree
	fmt.Scan(&n)

	// Initialize the parent of each node to -1 (indicating no parent)
	for i = 0; i < n; i++ {
		bt[i].parent = -1
	}

	// Read the tree structure from input
	for i = 0; i < n; i++ {
		// Read the current node index
		fmt.Scan(&num)
		// Read the left and right child indices
		fmt.Scan(&bt[num].left, &bt[num].right)

		// Update the parent index for the left and right children if they exist
		if bt[num].left!= -1 && bt[num].right!= -1 {
			bt[bt[num].left].parent = num
			bt[bt[num].right].parent = num
		} else if bt[num].left!= -1 {
			bt[bt[num].left].parent = num
		} else if bt[num].right!= -1 {
			bt[bt[num].right].parent = num
		}
	}

	// Find the root of the binary tree (the node with no parent)
	for i = 0; bt[i].parent!= -1; i++ {
	}

	// Perform and print preorder traversal
	fmt.Println("Preorder")
	Preorder(i)
	fmt.Println()

	// Perform and print inorder traversal
	fmt.Println("Inorder")
	Inorder(i)
	fmt.Println()

	// Perform and print postorder traversal
	fmt.Println("Postorder")
	Postorder(i)
	fmt.Println()
}

// END-OF-CODE