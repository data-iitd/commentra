package main

import (
	"fmt"
)

type STNode struct {
	parent *STNode
	left   *STNode
	right  *STNode
	key    int
}

func main() {
	var root *STNode
	var numCommands int
	var command string

	// Read the number of commands
	fmt.Scan(&numCommands)

	// Execute commands
	for i := 0; i < numCommands; i++ {
		// Read the command
		fmt.Scan(&command)

		// Execute the command based on its type
		if command == "insert" {
			var insertKey int
			// If the command is "insert", read the key value and insert it into the tree
			fmt.Scan(&insertKey)
			insert(&root, insertKey)
		} else {
			// If the command is "print", print the tree
			printTree(root)
		}
	}
}

// Insert a new node into the binary search tree
func insert(root **STNode, key int) {
	newNode := newSTNode(key) // Create a new node with the given key

	var parentNode *STNode
	indexNode := *root

	for indexNode != nil {
		parentNode = indexNode
		if newNode.key < indexNode.key {
			indexNode = indexNode.left
		} else {
			indexNode = indexNode.right
		}
	}
	newNode.parent = parentNode // Set the parent of the new node

	if parentNode == nil {
		*root = newNode // If the tree was empty, set the root to the new node
	} else if key < parentNode.key {
		parentNode.left = newNode // Insert the new node as the left child
	} else {
		parentNode.right = newNode // Insert the new node as the right child
	}
}

// Print the tree in both pre-order and in-order traversal
func printTree(root *STNode) {
	printInOrder(root) // Print the tree in in-order traversal
	fmt.Println()
	printPreOrder(root) // Print the tree in pre-order traversal
	fmt.Println()
}

// Pre-order traversal of the tree
func printPreOrder(node *STNode) {
	if node == nil {
		return
	}

	fmt.Printf(" %d", node.key) // Print the current node's key
	printPreOrder(node.left)     // Recursively print the left subtree
	printPreOrder(node.right)    // Recursively print the right subtree
}

// In-order traversal of the tree
func printInOrder(node *STNode) {
	if node == nil {
		return
	}

	printInOrder(node.left) // Recursively print the left subtree
	fmt.Printf(" %d", node.key) // Print the current node's key
	printInOrder(node.right) // Recursively print the right subtree
}

// Constructor-like function to create a new STNode
func newSTNode(key int) *STNode {
	return &STNode{
		parent: nil,
		left:   nil,
		right:  nil,
		key:    key,
	}
}
