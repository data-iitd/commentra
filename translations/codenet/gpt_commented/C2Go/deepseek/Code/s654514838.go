package main

import (
	"fmt"
	"math/rand"
)

// Definition of the node structure for the treap
type Node struct {
	key      int
	priority int
	left     *Node
	right    *Node
}

// Function prototypes for delete operations
func Delete(t **Node, key int) *Node
func delete(t **Node, key int) *Node

// Function to find a key in the treap
func find(p *Node, x int) bool {
	for p != nil {
		if p.key == x {
			return true
		} else if p.key > x {
			p = p.left
		} else {
			p = p.right
		}
	}
	return false
}

// Function for inorder traversal of the treap
func inorder(a *Node) {
	if a.left != nil {
		inorder(a.left)
	}
	fmt.Printf(" %d", a.key)
	if a.right != nil {
		inorder(a.right)
	}
}

// Function for preorder traversal of the treap
func preorder(p *Node) {
	fmt.Printf(" %d", p.key)
	if p.left != nil {
		preorder(p.left)
	}
	if p.right != nil {
		preorder(p.right)
	}
}

// Function to print the treap in both inorder and preorder
func print(p *Node) {
	inorder(p)
	fmt.Println()
	preorder(p)
	fmt.Println()
}

// Function to create a new node with given key and priority
func makenode(x, y int) *Node {
	return &Node{key: x, priority: y, left: nil, right: nil}
}

// Function to perform a right rotation on the treap
func rightRotate(p *Node) *Node {
	q := p.left
	p.left = q.right
	q.right = p
	return q
}

// Function to perform a left rotation on the treap
func leftRotate(p *Node) *Node {
	q := p.right
	p.right = q.left
	q.left = p
	return q
}

// Function to insert a new node into the treap
func insert(t **Node, key, priority int) *Node {
	if *t == nil {
		return makenode(key, priority)
	}
	if (*t).key == key {
		return *t
	}

	if key < (*t).key {
		(*t).left = insert(&(*t).left, key, priority)
		if (*t).priority < (*t).left.priority {
			*t = rightRotate(*t)
		}
	} else {
		(*t).right = insert(&(*t).right, key, priority)
		if (*t).priority < (*t).right.priority {
			*t = leftRotate(*t)
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
		*t = leftRotate(*t)
	} else if (*t).right == nil {
		*t = rightRotate(*t)
	} else {
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		} else {
			*t = leftRotate(*t)
		}
	}
	return Delete(t, key)
}

// Main function to execute the program
func main() {
	var num int
	var com string
	var x, y int
	var root *Node

	fmt.Scan(&num)
	for i := 0; i < num; i++ {
		fmt.Scan(&com)
		switch com {
		case "i":
			fmt.Scan(&x, &y)
			root = insert(&root, x, y)
		case "d":
			fmt.Scan(&x)
			root = Delete(&root, x)
		case "f":
			fmt.Scan(&x)
			if find(root, x) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		case "p":
			print(root)
		}
	}
}

