package main

import (
	"fmt"
	"os"
)

type STNode struct {
	parent *STNode
	left   *STNode
	right  *STNode
	key    int
}

func newSTNode(key int) *STNode {
	return &STNode{
		parent: nil,
		left:   nil,
		right:  nil,
		key:    key,
	}
}

func insert(root **STNode, key int) {
	insertNode := newSTNode(key)
	var parentNode *STNode
	indexNode := *root

	for indexNode != nil {
		parentNode = indexNode
		if insertNode.key < indexNode.key {
			indexNode = indexNode.left
		} else {
			indexNode = indexNode.right
		}
	}
	insertNode.parent = parentNode

	if parentNode == nil {
		*root = insertNode
	} else if key < parentNode.key {
		parentNode.left = insertNode
	} else {
		parentNode.right = insertNode
	}
}

func printTree(root *STNode) {
	printInOrder(root)
	fmt.Println()
	printPreOrder(root)
	fmt.Println()
}

func printPreOrder(node *STNode) {
	if node == nil {
		return
	}
	fmt.Printf(" %d", node.key)
	printPreOrder(node.left)
	printPreOrder(node.right)
}

func printInOrder(node *STNode) {
	if node == nil {
		return
	}
	printInOrder(node.left)
	fmt.Printf(" %d", node.key)
	printInOrder(node.right)
}

func main() {
	var numCommands int
	var root *STNode

	// Read number of commands
	if _, err := fmt.Scan(&numCommands); err != nil {
		fmt.Println("Error reading number of commands:", err)
		os.Exit(1)
	}

	// Execute commands
	for i := 0; i < numCommands; i++ {
		var command string
		if _, err := fmt.Scan(&command); err != nil {
			fmt.Println("Error reading command:", err)
			os.Exit(1)
		}

		if command == "insert" {
			var insertKey int
			if _, err := fmt.Scan(&insertKey); err != nil {
				fmt.Println("Error reading insert key:", err)
				os.Exit(1)
			}
			insert(&root, insertKey)
		} else {
			printTree(root)
		}
	}
}

// <END-OF-CODE>
