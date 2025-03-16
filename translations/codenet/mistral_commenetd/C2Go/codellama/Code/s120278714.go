package main

import "fmt"

type Node struct {
	id, l, r, par int
}

var N []Node

func init(n int) {
	N = make([]Node, n)
	for i := 0; i < n; i++ {
		N[i].id = i
		N[i].l = -1
		N[i].r = -1
		N[i].par = -1
	}
}

func Preorder(id int) {
	fmt.Printf("%d ", id)
	if N[id].l != -1 {
		Preorder(N[id].l)
	}
	if N[id].r != -1 {
		Preorder(N[id].r)
	}
}

func Inorder(id int) {
	if N[id].l != -1 {
		Inorder(N[id].l)
	}
	fmt.Printf("%d ", id)
	if N[id].r != -1 {
		Inorder(N[id].r)
	}
}

func Postorder(id int) {
	if N[id].l != -1 {
		Postorder(N[id].l)
	}
	if N[id].r != -1 {
		Postorder(N[id].r)
	}
	fmt.Printf("%d ", id)
}

func main() {
	// Declare and initialize variables
	var n, i, id, l, r int
	var p int

	// Read the number of nodes in the tree
	fmt.Scanf("%d", &n)

	// Initialize the tree
	init(n)

	// Read the input and build the tree
	for i = 0; i < n; i++ {
		// Read the id, left child, and right child of the current node
		fmt.Scanf("%d%d%d", &id, &l, &r)

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

	// Find the root node and perform tree traversals
	for i = 0; i < n; i++ {
		if N[i].par == -1 {
			p = i
			break
		}
	}

	// Print the tree traversals in Preorder, Inorder, and Postorder
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

// Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.

