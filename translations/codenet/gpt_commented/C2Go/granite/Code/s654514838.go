
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Definition of the node structure for the treap
type Node struct {
	key      int
	priority int
	left     *Node
	right    *Node
}

// Function prototypes for delete operations
func delete(t **Node, x int) *Node
func Delete(t **Node, x int) *Node

// Function to find a key in the treap
func find(x *Node, k int) bool {
	for x!= nil {
		if x.key == k {
			return true
		} else if x.key > k {
			x = x.left
		} else {
			x = x.right
		}
	}
	return false
}

// Function for inorder traversal of the treap
func inorder(x *Node) {
	if x.left!= nil {
		inorder(x.left)
	}
	fmt.Printf(" %d", x.key)
	if x.right!= nil {
		inorder(x.right)
	}
}

// Function for preorder traversal of the treap
func preorder(x *Node) {
	fmt.Printf(" %d", x.key)
	if x.left!= nil {
		preorder(x.left)
	}
	if x.right!= nil {
		preorder(x.right)
	}
}

// Function to print the treap in both inorder and preorder
func print(x *Node) {
	inorder(x)
	fmt.Println()
	preorder(x)
	fmt.Println()
}

// Function to create a new node with given key and priority
func makeNode(key, priority int) *Node {
	z := new(Node)
	z.key = key
	z.priority = priority
	z.left = nil
	z.right = nil
	return z
}

// Function to perform a right rotation on the treap
func rightRotate(t **Node) *Node {
	y := (*t).left
	x := y.right
	y.right = (*t)
	(*t).left = x
	*t = y
	return *t
}

// Function to perform a left rotation on the treap
func leftRotate(t **Node) *Node {
	y := (*t).right
	x := y.left
	y.left = (*t)
	(*t).right = x
	*t = y
	return *t
}

// Function to insert a new node into the treap
func insert(t **Node, key, priority int) *Node {
	if *t == nil {
		return makeNode(key, priority)
	}
	if (*t).key == key {
		return *t
	}
	if key < (*t).key {
		(*t).left = insert(&(*t).left, key, priority)
		if (*t).priority < (*t).left.priority {
			*t = rightRotate(t)
		}
	} else {
		(*t).right = insert(&(*t).right, key, priority)
		if (*t).priority < (*t).right.priority {
			*t = leftRotate(t)
		}
	}
	return *t
}

// Function to delete a node from the treap
func Delete(t **Node, key int) *Node {
	if *t == nil {
		return nil
	}
	if key < (*t).key {
		(*t).left = Delete(&(*t).left, key)
	} else if key > (*t).key {
		(*t).right = Delete(&(*t).right, key)
	} else {
		return delete(t, key)
	}
	return *t
}

// Helper function to handle the actual deletion of a node
func delete(t **Node, key int) *Node {
	if (*t).left == nil && (*t).right == nil {
		return nil
	} else if (*t).left == nil {
		*t = leftRotate(t)
	} else if (*t).right == nil {
		*t = rightRotate(t)
	} else {
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(t)
		} else {
			*t = leftRotate(t)
		}
	}
	return Delete(t, key)
}

// Main function to execute the program
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var root *Node
	var num, x, y int
	var com string
	fmt.Scan(&num)
	for i := 0; i < num; i++ {
		fmt.Scan(&com)
		switch com[0] {
		case 'i':
			fmt.Scan(&x, &y)
			root = insert(&root, x, y)
		case 'd':
			fmt.Scan(&x)
			root = Delete(&root, x)
		case 'f':
			fmt.Scan(&x)
			if find(root, x) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		case 'p':
			print(root)
		}
	}
}

