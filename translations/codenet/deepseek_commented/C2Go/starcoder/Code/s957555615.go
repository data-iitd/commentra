<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

type Node struct {
	key   int
	left  *Node
	right *Node
	parent *Node
}

var root *Node

<<<<<<< HEAD
=======
// This function finds the node with the minimum key in the subtree rooted at x
>>>>>>> 98c87cb78a (data updated)
func treeMinimum(x *Node) *Node {
	for x.left!= nil {
		x = x.left
	}
	return x
}

<<<<<<< HEAD
=======
// This function finds the node with the maximum key in the subtree rooted at x
>>>>>>> 98c87cb78a (data updated)
func treeMaximum(x *Node) *Node {
	for x.right!= nil {
		x = x.right
	}
	return x
}

<<<<<<< HEAD
=======
// This function searches for a node with a given key k in the subtree rooted at u
>>>>>>> 98c87cb78a (data updated)
func treeSearch(u *Node, k int) *Node {
	if u == nil || k == u.key {
		return u
	}
	if k < u.key {
		return treeSearch(u.left, k)
	}
	return treeSearch(u.right, k)
}

<<<<<<< HEAD
=======
// This function finds the successor of a given node x in the tree
>>>>>>> 98c87cb78a (data updated)
func treeSuccessor(x *Node) *Node {
	var y *Node
	if x.right!= nil {
		return treeMinimum(x.right)
	}
	y = x.parent
	for y!= nil && x == y.right {
		x = y
		y = y.parent
	}
	return y
}

<<<<<<< HEAD
=======
// This function deletes a node z from the tree
>>>>>>> 98c87cb78a (data updated)
func treeDelete(z *Node) {
	var y *Node
	var x *Node
	if z.left == nil || z.right == nil {
		y = z
	} else {
		y = treeSuccessor(z)
	}
	if y.left!= nil {
		x = y.left
	} else {
		x = y.right
	}
	if x!= nil {
		x.parent = y.parent
	}
	if y.parent == nil {
		root = x
	} else if y == y.parent.left {
		y.parent.left = x
	} else {
		y.parent.right = x
	}
	if y!= z {
		z.key = y.key
	}
}

<<<<<<< HEAD
=======
// This function inserts a new node with key k into the tree
>>>>>>> 98c87cb78a (data updated)
func insert(k int) {
	var y *Node
	var x *Node
	var z *Node
	z = new(Node)
	z.key = k
	z.left = nil
	z.right = nil
	x = root
	for x!= nil {
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

<<<<<<< HEAD
=======
// This function performs an inorder traversal of the tree and prints the keys
>>>>>>> 98c87cb78a (data updated)
func inorder(u *Node) {
	if u == nil {
		return
	}
	inorder(u.left)
	fmt.Printf(" %d", u.key)
	inorder(u.right)
}

<<<<<<< HEAD
=======
// This function performs a preorder traversal of the tree and prints the keys
>>>>>>> 98c87cb78a (data updated)
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
	var com [20]byte
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%s", &com)
		if com[0] == 'f' {
			fmt.Scanf("%d", &x)
			t := treeSearch(root, x)
			if t!= nil {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		} else if com[0] == 'i' {
			fmt.Scanf("%d", &x)
			insert(x)
		} else if com[0] == 'p' {
			inorder(root)
			fmt.Println()
			preorder(root)
			fmt.Println()
		} else if com[0] == 'd' {
			fmt.Scanf("%d", &x)
			treeDelete(treeSearch(root, x))
		}
	}
}

