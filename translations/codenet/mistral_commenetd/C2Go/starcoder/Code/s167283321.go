<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

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
	if x == -1 {
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
	if x == -1 {
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
	if x == -1 {
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
	fmt.Scanf("%d", &n)

	// Initialize all nodes as NIL
	for i = 0; i < n; i++ {
		R[i].parent = -1
	}

	// Read the edges and build the tree
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d %d", &a, &b, &c)
		R[a].left = b
		R[a].right = c
		if b!= -1 {
			R[b].parent = a // Set the parent of left child
		}
		if c!= -1 {
			R[c].parent = a // Set the parent of right child
		}
	}

	// Find the root node by searching for the node with no parent
	for i = 0; i < n; i++ {
		if R[i].parent == -1 {
			root = i
			break
		}
	}

	// Perform preorder traversal and print the result
	fmt.Printf("Preorder\n")
	preorder(root)
	fmt.Printf("\n")

	// Perform inorder traversal and print the result
	fmt.Printf("Inorder\n")
	inorder(root)
	fmt.Printf("\n")

	// Perform postorder traversal and print the result
	fmt.Printf("Postorder\n")
	postorder(root)
	fmt.Printf("\n")
}

