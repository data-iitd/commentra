
package main

import (
	"fmt"
)

// Definition of the node structure for the treap
type Node struct {
	key       int
	priority  int
	right     *Node
	left      *Node
}

// Function prototypes for delete operations
func Delete(t **Node, x int) *Node
func delete(t **Node, x int) *Node

// Function to find a key in the treap
func find(p *Node, x int) int {
	for p != nil { // Traverse until a leaf is reached
		if p.key == x {
			return 1 // Key found
		} else if p.key > x {
			p = p.left // Move to the left child
		} else {
			p = p.right // Move to the right child
		}
	}
	return 0 // Key not found
}

// Function for inorder traversal of the treap
func inorder(a *Node) {
	if a.left != nil { // Traverse left subtree
		inorder(a.left)
	}
	fmt.Printf(" %d", a.key) // Print the current node's key
	if a.right != nil { // Traverse right subtree
		inorder(a.right)
	}
	return
}

// Function for preorder traversal of the treap
func preorder(p *Node) {
	fmt.Printf(" %d", p.key) // Print the current node's key
	if p.left != nil { // Traverse left subtree
		preorder(p.left)
	}
	if p.right != nil { // Traverse right subtree
		preorder(p.right)
	}
	return
}

// Function to print the treap in both inorder and preorder
func print(p *Node) {
	inorder(p) // Print inorder
	fmt.Println()
	preorder(p) // Print preorder
	fmt.Println()
	return
}

// Function to create a new node with given key and priority
func makenode(x, y int) *Node {
	new := &Node{key: x, priority: y, right: nil, left: nil} // Allocate memory for a new node
	return new                                               // Return the new node
}

// Function to perform a right rotation on the treap
func rightRotate(p *Node) *Node {
	q := p.left // Store the left child
	p.left = q.right                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       