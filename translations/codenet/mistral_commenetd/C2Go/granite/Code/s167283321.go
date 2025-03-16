
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define a structure for a node in the binary tree
type Node struct {
	parent, left, right int
}

// Initialize an array of nodes R with size 10000
var R [10000]Node

// Set the number of nodes n
var n int

// Recursive function to perform preorder traversal
func preorder(x int) {
	// Base case: if x is NIL, return
	if x == NIL {
		return
	}

	// Print the current node x
	fmt.Printf(" %d", x)

	// Recursively traverse the left subtree
	preorder(R[x].left)

	// Recursively traverse the right subtree
	preorder(R[x].right)
}

// Recursive function to perform inorder traversal
func inorder(x int) {
	// Base case: if x is NIL, return
	if x == NIL {
		return
	}

	// Recursively traverse the left subtree
	inorder(R[x].left)

	// Print the current node x
	fmt.Printf(" %d", x)

	// Recursively traverse the right subtree
	inorder(R[x].right)
}

// Recursive function to perform postorder traversal
func postorder(x int) {
	// Base case: if x is NIL, return
	if x == NIL {
		return
	}

	// Recursively traverse the left subtree
	postorder(R[x].left)

	// Recursively traverse the right subtree
	postorder(R[x].right)

	// Print the current node x
	fmt.Printf(" %d", x)
}

// Main function to read input and call traversal functions
func main() {
	var i, a, b, c, root int

	// Read the number of nodes n
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &n)

	// Initialize all nodes as NIL
	for i = 0; i < n; i++ {
		R[i].parent = NIL
	}

	// Read the edges and build the tree
	for i = 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d", &a, &b, &c)
		R[a].left = b
		R[a].right = c
		if b!= NIL {
			R[b].parent = a // Set the parent of left child
		}
		if c!= NIL {
			R[c].parent = a // Set the parent of right child
		}
	}

	// Find the root node by searching for the node with no parent
	for i = 0; i < n; i++ {
		if R[i].parent == NIL {
			root = i
			break
		}
	}

	// Perform preorder traversal and print the result
	fmt.Println("Preorder")
	preorder(root)
	fmt.Println()

	// Perform inorder traversal and print the result
	fmt.Println("Inorder")
	inorder(root)
	fmt.Println()

	// Perform postorder traversal and print the result
	fmt.Println("Postorder")
	postorder(root)
	fmt.Println()
}

// End of code