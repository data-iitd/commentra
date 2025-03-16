<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the structure of the node
type Node struct {
	parent *Node
	left   *Node
	right  *Node
	key    int
}

// Define the structure of the tree
type Tree struct {
	root *Node
}

// Constructor-like function to create a new node
func newNode(key int) *Node {
	node := new(Node)
	node.parent = nil
	node.left = nil
	node.right = nil
	node.key = key
	return node
}

// Constructor-like function to create a new tree
func newTree() *Tree {
	tree := new(Tree)
	tree.root = nil
	return tree
}

// Insert a new node into the binary search tree
func insert(tree *Tree, key int) {
	node := newNode(key)
	parentNode := (*Node)(nil)
	indexNode := tree.root
	for indexNode!= nil {
		parentNode = indexNode
		if node.key < indexNode.key {
			indexNode = indexNode.left
		} else {
			indexNode = indexNode.right
		}
	}
	node.parent = parentNode
	if parentNode == nil {
		tree.root = node
	} else if node.key < parentNode.key {
		parentNode.left = node
	} else {
		parentNode.right = node
	}
}

// Print the tree in both pre-order and in-order traversal
func printTree(tree *Tree) {
	printInOrder(tree.root)
	fmt.Println()
	printPreOrder(tree.root)
	fmt.Println()
}

// Pre-order traversal of the tree
func printPreOrder(node *Node) {
	if node == nil {
		return
	}
	fmt.Printf(" %d", node.key)
	printPreOrder(node.left)
	printPreOrder(node.right)
}

// In-order traversal of the tree
func printInOrder(node *Node) {
	if node == nil {
		return
	}
	printInOrder(node.left)
	fmt.Printf(" %d", node.key)
	printInOrder(node.right)
}

func main() {
	tree := newTree()
	reader := bufio.NewReader(os.Stdin)
<<<<<<< HEAD
	fmt.Print("Enter the number of commands: ")
	numCommand, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	for iCommand := 0; iCommand < numCommand; iCommand++ {
		fmt.Print("Enter the command: ")
		command, _ := reader.ReadString('\n')
		command = strings.TrimSpace(command)
		if command == "insert" {
			fmt.Print("Enter the key value: ")
			key, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
=======
	numCommand, _ := strconv.Atoi(readLine(reader))
	for i := 0; i < numCommand; i++ {
		command := readLine(reader)
		if command == "insert" {
			key, _ := strconv.Atoi(readLine(reader))
>>>>>>> 98c87cb78a (data updated)
			insert(tree, key)
		} else {
			printTree(tree)
		}
	}
}

<<<<<<< HEAD
=======
// Read a string from stdin
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

>>>>>>> 98c87cb78a (data updated)
