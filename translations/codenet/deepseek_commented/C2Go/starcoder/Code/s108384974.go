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

// Define the structure for a node in the binary search tree
type node struct {
	key  int
	p    *node
	l, r *node
}

// Global variables for the root of the tree and a NIL pointer
var r, NIL *node

// Function to find a node with a given key in the binary search tree
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

// Function to insert a new key into the binary search tree
func insert(k int) {
	y := NIL
	x := r
	z := new(node)
	z.key = k
	z.l = NIL
	z.r = NIL

	// Find the position to insert the new node
	for x!= NIL {
		y = x
		if z.key < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}
	z.p = y

	if y == NIL {
		r = z
	} else if z.key < y.key {
		y.l = z
	} else {
		y.r = z
	}
}

// Function to perform an inorder traversal of the tree and print the keys
func inorder(u *node) {
	if u == NIL {
		return
	}
	inorder(u.l)
	fmt.Printf(" %d", u.key)
	inorder(u.r)
}

// Function to perform a preorder traversal of the tree and print the keys
func preorder(u *node) {
	if u == NIL {
		return
	}
	fmt.Printf(" %d", u.key)
	preorder(u.l)
	preorder(u.r)
}

// Function to print the tree in both inorder and preorder traversals
func print() {
	inorder(r)
	fmt.Println("")
	preorder(r)
	fmt.Println("")
}

// Main function to execute the program
func main() {
	var n, i, j, z, x int
	var s string

	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%s", &s)
		if s[0] == 'f' {
			fmt.Scanf("%d", &x)
			t := find(r, x)
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

