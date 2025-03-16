package main

import (
	"fmt"
)

// Define a structure for a node in the AVL tree
type Node struct {
	key      int
	priority int
	left     *Node
	right    *Node
}

// Function to check if a key is present in the AVL tree
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

// Function to perform an inorder traversal of the AVL tree and print the keys
func inorder(a *Node) {
	if a != nil {
		inorder(a.left)
		fmt.Printf(" %d", a.key)
		inorder(a.right)
	}
}

// Function to perform a preorder traversal of the AVL tree and print the keys
func preorder(p *Node) {
	if p != nil {
		fmt.Printf(" %d", p.key)
		preorder(p.left)
		preorder(p.right)
	}
}

// Function to print the AVL tree
func print(p *Node) {
	inorder(p)
	preorder(p)
}

// Function to create a new node in the AVL tree
func makenode(x, y int) *Node {
	return &Node{key: x, priority: y, left: nil, right: nil}
}

// Function to perform a right rotation on an AVL tree
func rightRotate(p *Node) *Node {
	q := p.left
	p.left = q.right
	q.right = p
	return q
}

// Function to perform a left rotation on an AVL tree
func leftRotate(p *Node) *Node {
	q := p.right
	p.right = q.left
	q.left = p
	return q
}

// Function to insert a new node into the AVL tree
func insert(t **Node, key, priority int) *Node {
	if *t == nil {
		return makenode(key, priority)
	}
	*t = insert(&(*t), key, priority)
	if (*t).priority < (*t).left.priority || (*t).priority < (*t).right.priority {
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		} else {
			*t = leftRotate(*t)
		}
	}
	return *t
}

// Function to delete a node from the AVL tree
func Delete(t **Node, key int) *Node {
	if *t == nil {
		return nil
	}
	if key < (*t).key {
		(*t).left = Delete(&(*t).left, key)
	} else if key > (*t).key {
		(*t).right = Delete(&(*t).right, key)
	} else {
		q := *t
		if (*t).left == nil {
			*t = (*t).right
		} else if (*t).right == nil {
			*t = (*t).left
		} else {
			*t = (*t).left
			(*t).right = q.right
		}
		q = nil
	}
	if *t != nil && ((*t).priority < (*t).left.priority || (*t).priority < (*t).right.priority) {
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		} else {
			*t = leftRotate(*t)
		}
	}
	return *t
}

// Main function to read commands and perform the corresponding operations on the AVL tree
func main() {
	var num, x, y int
	var com string
	var root *Node

	// Read the number of commands
	fmt.Scan(&num)
	// Process each command
	for i := 0; i < num; i++ {
		fmt.Scan(&com)
		switch com[0] {
		case 'i': // Insert a new node
			fmt.Scan(&x, &y)
			root = insert(&root, x, y)
		case 'd': // Delete a node
			fmt.Scan(&x)
			root = Delete(&root, x)
		case 'f': // Find a node
			fmt.Scan(&x)
			if find(root, x) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		case 'p': // Print the AVL tree
			print(root)
		}
	}
}

// <END-OF-CODE>
