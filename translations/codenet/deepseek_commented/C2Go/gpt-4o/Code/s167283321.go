package main

import (
	"fmt"
)

const NIL = -1

// Define the structure Node
type Node struct {
	parent, left, right int
}

// Declare an array of Node structures and an integer variable n
var R [10000]Node
var n int

// Declare the traversal functions
func preorder(x int) {
	if x == NIL {
		return
	}
	fmt.Printf(" %d", x)
	preorder(R[x].left)
	preorder(R[x].right)
}

func inorder(x int) {
	if x == NIL {
		return
	}
	inorder(R[x].left)
	fmt.Printf(" %d", x)
	inorder(R[x].right)
}

func postorder(x int) {
	if x == NIL {
		return
	}
	postorder(R[x].left)
	postorder(R[x].right)
	fmt.Printf(" %d", x)
}

// Implement the main function
func main() {
	var a, b, c, root int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		R[i].parent = NIL
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&a, &b, &c)
		R[a].left = b
		R[a].right = c
		if b != NIL {
			R[b].parent = a
		}
		if c != NIL {
			R[c].parent = a
		}
	}
	for i := 0; i < n; i++ {
		if R[i].parent == NIL {
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

// <END-OF-CODE>
