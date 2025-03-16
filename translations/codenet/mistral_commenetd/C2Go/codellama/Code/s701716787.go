
package main

import (
	"fmt"
	"strconv"
)

type Node struct {
	parent *Node
	left   *Node
	right  *Node
	key    int
}

func insert(root **Node, key int) {
	node := &Node{key: key}

	parent := (*Node)(nil)
	index := *root

	for index != nil {
		parent = index

		if node.key < index.key {
			index = index.left
		} else {
			index = index.right
		}
	}

	node.parent = parent

	if parent == nil {
		*root = node
	} else if node.key < parent.key {
		parent.left = node
	} else {
		parent.right = node
	}
}

func print(root *Node) {
	printInOrder(root)
	fmt.Println()
	printPreOrder(root)
	fmt.Println()
}

func printPreOrder(node *Node) {
	if node == nil {
		return
	}

	fmt.Printf(" %d", node.key)
	printPreOrder(node.left)
	printPreOrder(node.right)
}

func printInOrder(node *Node) {
	if node == nil {
		return
	}

	printInOrder(node.left)
	fmt.Printf(" %d", node.key)
	printInOrder(node.right)
}

func newNode(key int) *Node {
	return &Node{key: key}
}

func main() {
	var root *Node

	var numCommand int
	fmt.Scanln(&numCommand)

	for i := 0; i < numCommand; i++ {
		var command string
		fmt.Scanln(&command)

		if command == "insert" {
			var key int
			fmt.Scanln(&key)

			insert(&root, key)
		} else {
			print(root)
		}
	}
}

