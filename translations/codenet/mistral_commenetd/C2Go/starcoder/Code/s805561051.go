
<<<<<<< HEAD

import (
	"bufio"
=======
package main

import (
>>>>>>> 98c87cb78a (data updated)
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a binary tree node
type BT struct {
	parent int
	right  int
	left   int
}

var bt [26]BT
var n int

// Recursive function to print tree in preorder traversal
func Preorder(a int) {
	// Base case: if current node index is -1, return
	if a == -1 {
		return
	}

	// Print the current node value
	fmt.Printf(" %d", a)

	// Recursively call for left and right subtrees
	Preorder(bt[a].left)
	Preorder(bt[a].right)
}

// Recursive function to print tree in inorder traversal
func Inorder(a int) {
	// Base case: if current node index is -1, return
	if a == -1 {
		return
	}

	// Recursively call for left subtree
	Inorder(bt[a].left)

	// Print the current node value
	fmt.Printf(" %d", a)

	// Recursively call for right subtree
	Inorder(bt[a].right)
}

// Recursive function to print tree in postorder traversal
func Postorder(a int) {
	// Base case: if current node index is -1, return
	if a == -1 {
		return
	}

	// Recursively call for left and right subtrees
	Postorder(bt[a].left)
	Postorder(bt[a].right)

	// Print the current node value
	fmt.Printf(" %d", a)
}

// Main function to read input and print tree traversals
func main() {
	var i, j, num int
	var depth int

	// Read number of nodes in the binary tree
	fmt.Scanf("%d", &n)

	// Initialize all nodes as root
	for i = 0; i < n; i++ {
		bt[i].parent = -1
	}

	// Read node values and their left and right children
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &num) // Read node value

		// Initialize left and right children as -1
		bt[num].left = -1
		bt[num].right = -1

		// Read left and right child indices if they exist
		if _, err := fmt.Scanf("%d%d", &bt[num].left, &bt[num].right); err!= nil {
			break
		}

		// Set parent of left and right children to current node
		if bt[num].left!= -1 && bt[num].right!= -1 {
			bt[bt[num].left].parent = num
			bt[bt[num].right].parent = num
		}
		// Set parent of left child if it exists
		else if bt[num].left!= -1 {
			bt[bt[num].left].parent = num
		}
		// Set parent of right child if it exists
		else if bt[num].right!= -1 {
			bt[bt[num].right].parent = num
		}
	}

	// Find the index of the last node (root) in the tree
	for i = 0; bt[i].parent!= -1; i++ {
	}

	// Print tree traversals
	fmt.Printf("Preorder\n")
	Preorder(i)
	fmt.Printf("\n")

	fmt.Printf("Inorder\n")
	Inorder(i)
	fmt.Printf("\n")

	fmt.Printf("Postorder\n")
	Postorder(i)
	fmt.Printf("\n")
}

