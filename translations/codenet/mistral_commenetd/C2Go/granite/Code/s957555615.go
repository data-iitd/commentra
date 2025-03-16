
package main

import "fmt"

// Define a node structure for AVL tree
type Node struct {
	Right  *Node
	Left   *Node
	Parent *Node
	Key    int
}

var root *Node

// Function to find the minimum node in the tree
func treeMinimum(x *Node) *Node {
	// Traverse to the left most node
	for x.Left!= nil {
		x = x.Left
	}
	// Return the minimum node
	return x
}

// Function to find the maximum node in the tree
func treeMaximum(x *Node) *Node {
	// Traverse to the right most node
	for x.Right!= nil {
		x = x.Right
	}
	// Return the maximum node
	return x
}

func main() {
	// Initialize root as NULL
	root = nil

	// Create a new node
	node := &Node{
		Right:  nil,
		Left:   nil,
		Parent: nil,
		Key:    0,
	}

	// Find the minimum node
	minNode := treeMinimum(root)
	fmt.Println("Minimum node:", minNode)

	// Find the maximum node
	maxNode := treeMaximum(root)
	fmt.Println("Maximum node:", maxNode)
}

// 