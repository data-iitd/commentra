package main

import (
	"fmt"
)

// Define the structure Node
type Node struct {
	parent, left, right int
}

// Declare an array of Node structures and an integer variable n
var R [10000]Node
var n int

// Declare the traversal functions
func preorder(x int)
func inorder(x int)
func postorder(x int)

// Implement the preorder function
func preorder(x int) {
	if x == -1 {
		return
	}
	fmt.Printf(" %d", x)
	preorder(R[x].left)
	preorder(R[x].right)
}

// Implement the inorder function
func inorder(x int) {
	if x == -1 {
		return
	}
	inorder(R[x].left)
	fmt.Printf(" %d", x)
	inorder(R[x].right)
}

// Implement the postorder function
func postorder(x int) {
	if x == -1 {
		return
	}
	postorder(R[x].left)
	postorder(R[x].right)
	fmt.Printf(" %d", x)
}

// Implement the main function
func main() {
	var i, a, b, c, root int
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		R[i].parent = -1
	}
	for i = 0; i < n; i++ {
		fmt.Scan(&a, &b, &c)
		R[a].left = b
		R[a].right = c
		if b != -1 {
			R[b].parent = a
		}
		if c != -1 {
			R[c].parent = a
		}
	}
	for i = 0; i < n; i++ {
		if R[i].parent == -1 {
			root = i
		}
	}
	fmt.Println("Preorder")
	preorder(root)
	fmt.Println()
	fmt.Println("Inorder")
	inorder(root)
	fmt.Println()
	fmt.Println("Postorder")
	postorder(root)
	fmt.Println()
}

