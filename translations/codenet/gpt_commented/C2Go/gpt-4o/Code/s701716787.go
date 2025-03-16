package main

import (
	"fmt"
)

type STNode struct {
	Parent *STNode // Pointer to the parent node
	Left   *STNode // Pointer to the left child node
	Right  *STNode // Pointer to the right child node
	Key    int     // Key value of the node
}

// Function prototypes
func insert(root **STNode, key int) // Function to insert a key into the binary search tree
func printTree(root *STNode)         // Function to print the binary search tree
func newSTNode(key int) *STNode      // Function to create a new node

func main() {
	var root *STNode                   // Root of the binary search tree
	var numCommands int                 // Number of commands to process
	var command string                  // Command input buffer
	var insertKey int                   // Key to be inserted

	// Read the number of commands from user input
	fmt.Scan(&numCommands)

	// Execute commands based on user input
	for i := 0; i < numCommands; i++ {
		// Read the command (insert or print)
		fmt.Scan(&command)

		// Execute the command based on its type
		if command == "insert" {
			// If the command is "insert", read the key value to insert
			fmt.Scan(&insertKey)
			insert(&root, insertKey) // Insert the key into the tree
		} else {
			printTree(root) // Print the current state of the tree
		}
	}
}

// Function to insert a key into the binary search tree
func insert(root **STNode, key int) {
	parentNode := (*STNode)(nil) // Pointer to track the parent node
	indexNode := *root            // Start from the root
	insertNode := newSTNode(key)  // Create a new node with the given key

	// Traverse the tree to find the correct insertion point
	for indexNode != nil {
		parentNode = indexNode // Update parent node
		if insertNode.Key < indexNode.Key {
			indexNode = indexNode.Left // Go left
		} else {
			indexNode = indexNode.Right // Go right
		}
	}
	insertNode.Parent = parentNode // Set parent for the new node

	// Insert the new node in the tree
	if parentNode == nil {
		*root = insertNode // Tree was empty, new node becomes root
	} else if key < parentNode.Key {
		parentNode.Left = insertNode // Insert as left child
	} else {
		parentNode.Right = insertNode // Insert as right child
	}
}

// Function to print the binary search tree
func printTree(root *STNode) {
	printInOrder(root) // Print in-order
	fmt.Println()
	printPreOrder(root) // Print pre-order
	fmt.Println()
}

// Function to print the tree in pre-order
func printPreOrder(node *STNode) {
	if node == nil {
		return // Base case: if the node is nil, return
	}

	fmt.Printf(" %d", node.Key) // Print the key of the current node
	printPreOrder(node.Left)     // Recursively print left subtree
	printPreOrder(node.Right)    // Recursively print right subtree
}

// Function to print the tree in in-order
func printInOrder(node *STNode) {
	if node == nil {
		return // Base case: if the node is nil, return
	}

	printInOrder(node.Left) // Recursively print left subtree
	fmt.Printf(" %d", node.Key) // Print the key of the current node
	printInOrder(node.Right) // Recursively print right subtree
}

// Function to create a new node
func newSTNode(key int) *STNode {
	return &STNode{
		Parent: nil, // Initialize parent to nil
		Left:   nil, // Initialize left child to nil
		Right:  nil, // Initialize right child to nil
		Key:    key, // Set the key value
	}
}

// <END-OF-CODE>
