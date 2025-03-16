package main

import (
	"fmt"
)

type Node struct {
	right, left, parent *Node
	key                 int
}

var root *Node

// This function finds the node with the minimum key in the subtree rooted at x
func treeMinimum(x *Node) *Node {
	for x.left != nil {
		x = x.left
	}
	return x
}

// This function finds the node with the maximum key in the subtree rooted at x
func treeMaximum(x *Node) *Node {
	for x.right != nil {
		x = x.right
	}
	return x
}

// This function searches for a node with a given key k in the subtree rooted at u
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

// This function finds the successor of a given node x in the tree
func treeSuccessor(x *Node) *Node {
	var y *Node
	if x.right != nil {
		return treeMinimum(x.right)
	}
	y = x.parent
	for y != nil && x == y.right {
		x = y
		y = y.parent
	}
	return y
}

// This function deletes a node z from the tree
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

// This function inserts a new node with key k into the tree
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

// This function performs an inorder traversal of the tree and prints the keys
func inorder(u *Node) {
	if u == nil {
		return
	}
	inorder(u.left)
	fmt.Printf(" %d", u.key)
	inorder(u.right)
}

// This function performs a preorder traversal of the tree and prints the keys
func preorder(u *Node) {
	if u == nil {
		return
	}
	fmt.Printf(" %d", u.key)
	preorder(u.left)
	preorder(u.right)
}

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

