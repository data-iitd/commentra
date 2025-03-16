package main

import (
	"fmt"
)

type Node struct {
	id, l, r, par int
}

var N [100000]Node

func init(n int) {
	for i := 0; i < n; i++ {
		N[i] = Node{l: -1, r: -1, par: -1}
	}
}

func Preorder(id int) {
	if id == -1 {
		return
	}
	fmt.Printf(" %d", id)
	Preorder(N[id].l)
	Preorder(N[id].r)
}

func Inorder(id int) {
	if id == -1 {
		return
	}
	Inorder(N[id].l)
	fmt.Printf(" %d", id)
	Inorder(N[id].r)
}

func Postorder(id int) {
	if id == -1 {
		return
	}
	Postorder(N[id].l)
	Postorder(N[id].r)
	fmt.Printf(" %d", id)
}

func main() {
	var n, i, id, l, r int

	// Read the number of nodes in the tree
	fmt.Scan(&n)

	// Initialize the tree
	init(n)

	// Read the input and build the tree
	for i = 0; i < n; i++ {
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

	// Find the root node and perform tree traversals
	var p int
	for i = 0; i < n; i++ {
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

