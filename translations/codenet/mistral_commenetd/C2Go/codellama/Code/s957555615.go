package main

import "fmt"

// Define a node structure for AVL tree
type node struct {
	right  *node // pointer to the right child
	left   *node // pointer to the left child
	parent *node // pointer to the parent node
	key    int   // key value of the node
}

var root *node // Initialize root as NULL

// Function to find the minimum node in the tree
func treeMinimum(x *node) *node {
	// Traverse to the left most node
	for x.left != nil {
		x = x.left
	}
	// Return the minimum node
	return x
}

// Function to find the maximum node in the tree
func treeMaximum(x *node) *node {
	// Traverse to the right most node
	for x.right != nil {
		x = x.right
	}
	// Return the maximum node
	return x
}

