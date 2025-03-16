
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	id  int
	l   int
	r   int
	par int
}

var N [100000]Node

func init(n int) {
	for i := 0; i < n; i++ {
		N[i].id = -1
		N[i].l = -1
		N[i].r = -1
		N[i].par = -1
	}
}

func Preorder(u int) {
	if u == -1 {
		return
	}
	fmt.Printf(" %d", N[u].id)
	Preorder(N[u].l)
	Preorder(N[u].r)
}

func Inorder(u int) {
	if u == -1 {
		return
	}
	Inorder(N[u].l)
	fmt.Printf(" %d", N[u].id)
	Inorder(N[u].r)
}

func Postorder(u int) {
	if u == -1 {
		return
	}
	Postorder(N[u].l)
	Postorder(N[u].r)
	fmt.Printf(" %d", N[u].id)
}

func main() {
	// Declare and initialize variables
	var n, i, id, l, r, p int

	// Read the number of nodes in the tree
	fmt.Scan(&n)

	// Initialize the tree
	init(n)

	// Read the input and build the tree
	for i = 0; i < n; i++ {
		// Read the id, left child, and right child of the current node
		fmt.Scan(&id, &l, &r)
		N[id].id = id
		N[id].l = l
		N[id].r = r
		if l!= -1 {
			N[l].par = id
		}
		if r!= -1 {
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
	fmt.Println()

	fmt.Println("Inorder")
	Inorder(p)
	fmt.Println()

	fmt.Println("Postorder")
	Postorder(p)
	fmt.Println()
}

// Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.