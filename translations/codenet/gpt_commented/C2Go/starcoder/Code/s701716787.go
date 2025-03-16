package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Node structure
type Node struct {
	parent *Node
	left   *Node
	right  *Node
	key    int
}

// Function to create a new node
func newNode(key int) *Node {
	node := new(Node)
	node.parent = nil
	node.left = nil
	node.right = nil
	node.key = key
	return node
}

// Function to insert a key into the binary search tree
func insert(root **Node, key int) {
	var parent *Node
	var index *Node
	var insert *Node

	// Create a new node with the given key
	insert = newNode(key)

	parent = nil
	index = *root

	// Traverse the tree to find the correct insertion point
	for index!= nil {
		parent = index
		if insert.key < index.key {
			index = index.left
		} else {
			index = index.right
		}
	}
	insert.parent = parent

	// Insert the new node in the tree
	if parent == nil {
		*root = insert // Tree was empty, new node becomes root
	} else if insert.key < parent.key {
		parent.left = insert // Insert as left child
	} else {
		parent.right = insert // Insert as right child
	}
}

// Function to print the binary search tree
func printTree(root *Node) {
	printInOrder(root)
	fmt.Println()
	printPreOrder(root)
	fmt.Println()
}

// Function to print the tree in pre-order
func printPreOrder(node *Node) {
	if node == nil {
		return
	}

	fmt.Printf(" %d", node.key) // Print the key of the current node
	printPreOrder(node.left)     // Recursively print left subtree
	printPreOrder(node.right)    // Recursively print right subtree
}

// Function to print the tree in in-order
func printInOrder(node *Node) {
	var printedNumNode int = 0

	if node == nil {
		return
	}

	printInOrder(node.left) // Recursively print left subtree
	fmt.Printf(" %d", node.key)
	printInOrder(node.right) // Recursively print right subtree
}

func main() {
	var root *Node = nil
	var numCommand int
	var iCommand int
	var command string
	var insertKey int
	var rtnStrcmp int

	// Read the number of commands from user input
	fmt.Scanf("%d", &numCommand)

	// Execute commands based on user input
	for iCommand = 0; iCommand < numCommand; iCommand++ {
		// Read the command (insert or print)
		fmt.Scanf("%s", &command)

		// Execute the command based on its type
		// Assumes only "insert" and "print" commands are valid
		rtnStrcmp = strings.Compare(command, "insert")
		if rtnStrcmp == 0 {
			// If the command is "insert", read the key value to insert
			fmt.Scanf("%d", &insertKey)
			insert(&root, insertKey) // Insert the key into the tree
		} else {
			printTree(root) // Print the current state of the tree
		}
	}
}

