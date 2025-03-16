// Importing necessary packages
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining node and tree structures
type node struct {
	key   int
	parent *node
	left  *node
	right *node
}

type tree struct {
	root *node
}



// Method to insert a new node into the tree
func (tree *tree) insert(key int) {
	// Base case: If the tree is empty, create a new root node
	if tree.root == nil {
		tree.root = &node{key: key}
		return
	}

	// Variables to keep track of current and previous nodes
	var currentNode, prevNode *node
	currentNode = tree.root

	// Traverse the tree to find the correct position for the new node
	for currentNode != nil {
		prevNode = currentNode
		if currentNode.key < key {
			currentNode = currentNode.right
		} else {
			currentNode = currentNode.left
		}
	}

	// Create a new node with the given key
	newNode := &node{key: key}

	// Set the new node's parent to the previous node
	newNode.parent = prevNode

	// If the previous node's key is less than the new node's key,
	// set the previous node's right child to the new node
	if prevNode.key < key {
		prevNode.right = newNode
	} else {
		// Otherwise, set the previous node's left child to the new node
		prevNode.left = newNode
	}
}



// Method to print the tree in inorder and preorder traversals
func (tree tree) print() {
	// Base case: If the tree is empty, print an empty tree
	if tree.root == nil {
		fmt.Println("")
		fmt.Println("")
		return
	}

	// Variable to store the visited nodes in inorder traversal
	var acc []int

	// Print the tree in inorder and preorder traversals
	fmt.Println("Inorder traversal: ", strings.Join(isToAs(visitInorder(tree.root, acc)), " "))
	fmt.Println("Preorder traversal: ", strings.Join(isToAs(visitPreorder(tree.root, acc)), " "))
}



// Helper functions for depth-first traversals of the tree
func visitPreorder(node *node, acc []int) []int {
	// Base case: If the node is nil, return the accumulator array
	if node == nil {
		return acc
	}

	// Add the current node's key to the accumulator array
	acc = append(acc, int(node.key))

	// Recursively traverse the left and right subtrees
	if node.left != nil {
		acc = visitPreorder(node.left, acc)
	}
	if node.right != nil {
		acc = visitPreorder(node.right, acc)
	}

	// Return the updated accumulator array
	return acc
}

func visitInorder(node *node, acc []int) []int {
	// Base case: If the node is nil, return the accumulator array
	if node == nil {
		return acc
	}

	// Recursively traverse the left subtree and add its keys to the accumulator array
	if node.left != nil {
		acc = visitInorder(node.left, acc)
	}

	// Add the current node's key to the accumulator array
	acc = append(acc, int(node.key))

	// Recursively traverse the right subtree and add its keys to the accumulator array
	if node.right != nil {
		acc = visitInorder(node.right, acc)
	}

	// Return the updated accumulator array
	return acc
}



// Main function to read input and call the appropriate methods
func main() {
	// Creating a new scanner to read input from stdin
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Reading the number of nodes in the tree
	n, err := nextInt(sc)
	if err != nil {
		panic(err)
	}

	// Creating a new tree object
	tree := &tree{}

	// Reading the commands and calling the appropriate methods
	for i := 0; i < n; i++ {
		command := nextText(sc)
		switch command {
		case "insert":
			key, err := nextInt(sc)
			if err != nil {
				panic(err)
			}
			tree.insert(key)
		case "print":
			tree.print()
		default:
			panic("unknown command: " + command)
		}
	}
}

// Helper functions to read text and integers from the scanner
func nextText(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextInt(sc *bufio.Scanner) (int, error) {
	return strconv.Atoi(nextText(sc))
}

// Helper function to convert an integer array to a string array
func isToAs(is []int) []string {
	n := len(is)
	as := make([]string, n)
	for i := 0; i < n; i++ {
		as[i] = strconv.Itoa(is[i])
	}
	return as
}