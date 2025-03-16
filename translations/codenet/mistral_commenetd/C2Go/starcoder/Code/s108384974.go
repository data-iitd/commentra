
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the structure for a node in the AVL tree
type node struct {
	key  int
	p    *node
	l, r *node
}

var r *node = nil
var NIL *node = nil

// Function to find a node with given key in the AVL tree
func find(x *node, k int) *node {
	for x!= NIL && k!= x.key {
		if k < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}
	return x
}

// Function to insert a new node with given key into the AVL tree
func insert(k int) {
	y := NIL
	x := r
	z := new(node)

	z.key = k
	z.l = NIL
	z.r = NIL

	// Traverse down the tree to find the position for the new node
	for x!= NIL {
		y = x
		if z.key < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}

	// Link the new node to its parent node
	z.p = y

	// Update the left or right child of the parent node
	if y == NIL {
		r = z
	} else if z.key < y.key {
		y.l = z
	} else {
		y.r = z
	}
}

// Function to perform inorder traversal of the AVL tree and print the keys
func inorder(u *node) {
	if u == NIL {
		return
	}
	inorder(u.l)
	fmt.Printf(" %d", u.key)
	inorder(u.r)
}

// Function to perform preorder traversal of the AVL tree and print the keys
func preorder(u *node) {
	if u == NIL {
		return
	}
	fmt.Printf(" %d", u.key)
	preorder(u.l)
	preorder(u.r)
}

// Function to print the keys of the AVL tree in inorder and preorder traversals
func print() {
	inorder(r)
	fmt.Println("")
	preorder(r)
	fmt.Println("")
}

// Main function to read commands from the standard input and perform the corresponding operations
func main() {
	var n, i, j, z, x int
	var s string
<<<<<<< HEAD
	var t *node
=======
>>>>>>> 98c87cb78a (data updated)

	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%s", &s)

		if s[0] == 'f' {
			fmt.Scanf("%d", &x)
<<<<<<< HEAD
			t = find(r, x)
=======
			t := find(r, x)
>>>>>>> 98c87cb78a (data updated)
			if t == NIL {
				fmt.Println("no")
			} else {
				fmt.Println("yes")
			}
		} else if s[0] == 'i' {
			fmt.Scanf("%d", &z)
			insert(z)
		} else {
			print()
		}
	}
}

