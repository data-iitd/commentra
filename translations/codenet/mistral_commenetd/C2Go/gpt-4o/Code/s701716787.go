package main

import (
	"fmt"
)

type STNode struct {
	Parent *STNode
	Left   *STNode
	Right  *STNode
	Key    int
}

func newSTNode(key int) *STNode {
	return &STNode{
		Parent: nil,
		Left:   nil,
		Right:  nil,
		Key:    key,
	}
}

func insert(root **STNode, key int) {
	insertNode := newSTNode(key)
	var parentNode *STNode
	indexNode := *root

	// Search for the position to insert the new node
	for indexNode != nil {
		parentNode = indexNode
		if insertNode.Key < indexNode.Key {
			indexNode = indexNode.Left
		} else {
			indexNode = indexNode.Right
		}
	}

	// Insert the new node at the appropriate position
	insertNode.Parent = parentNode

	if parentNode == nil {
		*root = insertNode
	} else if key < parentNode.Key {
		parentNode.Left = insertNode
	} else {
		parentNode.Right = insertNode
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
	fmt.Printf(" %d", node.Key)
	printPreOrder(node.Left)
	printPreOrder(node.Right)
}

func printInOrder(node *STNode) {
	if node == nil {
		return
	}
	printInOrder(node.Left)
	fmt.Printf(" %d", node.Key)
	printInOrder(node.Right)
}

func main() {
	var root *STNode
	var numCommands int

	// Read the number of commands from the standard input
	fmt.Print("Enter the number of commands: ")
	fmt.Scan(&numCommands)

	// Process each command
	for i := 0; i < numCommands; i++ {
		var command string
		fmt.Print("Enter the command (insert or print): ")
		fmt.Scan(&command)

		if command == "insert" {
			var key int
			fmt.Print("Enter the key to be inserted: ")
			fmt.Scan(&key)
			insert(&root, key)
		} else if command == "print" {
			printTree(root)
		}
	}
}

// <END-OF-CODE>
