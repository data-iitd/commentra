package main

import (
	"fmt"
)

type Node struct {
	l   int
	r   int
	par int
}

var N []Node

func initTree(n int) {
	N = make([]Node, n)
}

func Preorder(node int) {
	if node == -1 {
		return
	}
	fmt.Printf("%d ", node)
	Preorder(N[node].l)
	Preorder(N[node].r)
}

func Inorder(node int) {
	if node == -1 {
		return
	}
	Inorder(N[node].l)
	fmt.Printf("%d ", node)
	Inorder(N[node].r)
}

func Postorder(node int) {
	if node == -1 {
		return
	}
	Postorder(N[node].l)
	Postorder(N[node].r)
	fmt.Printf("%d ", node)
}

func main() {
	// Declare and initialize variables
	var n, id, l, r int
	var p int

	// Read the number of nodes in the tree
	fmt.Scan(&n)

	// Initialize the tree
	initTree(n)

	// Read the input and build the tree
	for i := 0; i < n; i++ {
		// Read the id, left child, and right child of the current node
		fmt.Scan(&id, &l, &r)

		// If the left child is not -1, assign it to the left child of the current node
		if l != -1 {
			N[id].l = l
			N[l].par = id
		}

		// If the right child is not -1, assign it to the right child of the current node
		if r != -1 {
			N[id].r = r
			N[r].par = id
		}
	}

	// Find the root node
	for i := 0; i < n; i++ {
		if N[i].par == -1 {
			p = i
			break
		}
	}

	// Print the tree traversals in Preorder, Inorder, and Postorder
	fmt.Println("Preorder")
	Preorder(p)
	fmt.Println()

	fmt.Println("Inorder")
	Inorder(p)
	fmt.Println()

	fmt.Println("Postorder")
	Postorder(p)
	fmt.Println()
}

// Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.
