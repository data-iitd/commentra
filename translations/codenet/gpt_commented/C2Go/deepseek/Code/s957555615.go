package main

import (
	"fmt"
	"os"
)

// Define the structure for a node in the binary search tree
type Node struct {
	right, left, parent *Node
	key                 int
}

var root *Node

// Function to find the minimum node in a subtree
func treeMinimum(x *Node) *Node {
	for x.left != nil {
		x = x.left
	}
	return x
}

// Function to find the maximum node in a subtree
func treeMaximum(x *Node) *Node {
	for x.right != nil {
		x = x.right
	}
	return x
}

// Function to search for a node with a specific key in the tree
func treeSearch(u *Node, k int) *Node {
	if u == nil || k == u.key {
		return u
	}
	if k < u.key {
		return treeSearch(u.left, k)
	} else {
		return treeSearch(u.right, k)
	}
}

// Function to find the successor of a given node in the binary search tree
func treeSuccessor(x *Node) *Node {
	if x.right != nil {
		return treeMinimum(x.right)
	}
	y := x.parent
	for y != nil && x == y.right {
		x = y
		y = y.parent
	}
	return y
}

// Function to delete a node from the binary search tree
func treeDelete(z *Node) {
	var y, x *Node
	if z.left == nil || z.right == nil {
		y = z
	} else {
		y = treeSuccessor(z)
	}
	if y.left != nil {
		x = y.left
	} else {
		x = y.right
	}
	if x != nil {
		x.parent = y.parent
	}
	if y.parent == nil {
		root = x
	} else if y == y.parent.left {
		y.parent.left = x
	} else {
		y.parent.right = x
	}
	if y != z {
		z.key = y.key
	}
}

// Function to insert a new key into the binary search tree
func insert(k int) {
	var y *Node = nil
	var x *Node = root
	var z *Node
	z = &Node{key: k}
	for x != nil {
		y = x
		if z.key < x.key {
			x = x.left
		} else {
			x = x.right
		}
	}
	z.parent = y
	if y == nil {
		root = z
	} else if z.key < y.key {
		y.left = z
	} else {
		y.right = z
	}
}

// Function for inorder traversal of the tree
func inorder(u *Node) {
	if u == nil {
		return
	}
	inorder(u.left)
	fmt.Printf(" %d", u.key)
	inorder(u.right)
}

// Function for preorder traversal of the tree
func preorder(u *Node) {
	if u == nil {
		return
	}
	fmt.Printf(" %d", u.key)
	preorder(u.left)
	preorder(u.right)
}

// Main function to execute the program
func main() {
	var n, i, x int
	var com string
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&com)
		if com[0] == 'f' {
			fmt.Scan(&x)
			t := treeSearch(root, x)
			if t != nil {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		} else if com[0] == 'i' {
			fmt.Scan(&x)
			insert(x)
		} else if com[0] == 'p' {
			inorder(root)
			fmt.Println()
			preorder(root)
			fmt.Println()
		} else if com[0] == 'd' {
			fmt.Scan(&x)
			treeDelete(treeSearch(root, x))
		}
	}
}

