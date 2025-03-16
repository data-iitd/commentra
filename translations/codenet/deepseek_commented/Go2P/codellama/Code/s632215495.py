
# Go:
# package main

# import (
# 	"bufio" // For buffered I/O operations
# 	"fmt"   // For formatted I/O operations
# 	"os"    // For OS-related functions
# 	"strconv" // For string conversion functions
# 	"strings" // For string manipulation
# )

# // node represents a node in a binary search tree (BST)
# // It contains an integer key, and pointers to its parent, left child, and right child.
# type node struct {
# 	key    int
# 	parent *node
# 	left   *node
# 	right  *node
# }

# // tree represents a binary search tree
# // It contains a root node, which is the topmost node in the tree.
# type tree struct {
# 	root *node
# }

# // insert adds a new node with the given key to the BST.
# // If the tree is empty, it sets the new node as the root.
# // Otherwise, it traverses the tree to find the correct position for the new node.
# func (tree *tree) insert(key int) {
# 	if tree.root == nil {
# 		tree.root = &node{key: key}
# 		return
# 	}

# 	var currentNode, prevNode *node
# 	currentNode = tree.root
# 	for currentNode != nil {
# 		prevNode = currentNode
# 		if currentNode.key < key {
# 			currentNode = currentNode.right
# 		} else {
# 			currentNode = currentNode.left
# 		}
# 	}

# 	newNode := &node{key: key}
# 	newNode.parent = prevNode
# 	if prevNode.key < key {
# 		prevNode.right = newNode
# 	} else {
# 		prevNode.left = newNode
# 	}
# }

# // print prints the tree using inorder and preorder traversals.
# // It uses helper functions to collect the keys in the respective orders and then converts them to strings for printing.
# func (tree tree) print() {
# 	var acc []int
# 	if tree.root == nil {
# 		fmt.Println("")
# 		fmt.Println("")
# 	} else {
# 		fmt.Println(" " + strings.Join(isToAs(visitInorder(tree.root, acc)), " "))
# 		fmt.Println(" " + strings.Join(isToAs(visitPreorder(tree.root, acc)), " "))
# 	}
# }

# // visitPreorder is a helper function that performs a preorder traversal of the tree.
# // It recursively visits nodes in the order: node, left subtree, right subtree.
# func visitPreorder(node *node, acc []int) []int {
# 	if node == nil {
# 		return acc
# 	}
# 	acc = append(acc, int(node.key))
# 	if node.left != nil {
# 		acc = visitPreorder(node.left, acc)
# 	}
# 	if node.right != nil {
# 		acc = visitPreorder(node.right, acc)
# 	}
# 	return acc
# }

# // visitInorder is a helper function that performs an inorder traversal of the tree.
# // It recursively visits nodes in the order: left subtree, node, right subtree.
# func visitInorder(node *node, acc []int) []int {
# 	if node == nil {
# 		return acc
# 	}
# 	if node.left != nil {
# 		acc = visitInorder(node.left, acc)
# 	}
# 	acc = append(acc, int(node.key))
# 	if node.right != nil {
# 		acc = visitInorder(node.right, acc)
# 	}
# 	return acc
# }

# // main function reads commands from standard input.
# // It supports two commands: insert to add a key to the tree and print to print the tree.
# // It uses helper functions nextText and nextInt to read input values.
# func main() {
# 	sc := bufio.NewScanner(os.Stdin)
# 	sc.Split(bufio.ScanWords)

# 	n, err := nextInt(sc)
# 	if err != nil {
# 		panic(err)
# 	}

# 	tree := &tree{}
# 	for i := 0; i < n; i++ {
# 		command := nextText(sc)
# 		switch command {
# 		case "insert":
# 			key, err := nextInt(sc)
# 			if err != nil {
# 				panic(err)
# 			}
# 			tree.insert(key)
# 		case "print":
# 			tree.print()
# 		default:
# 			panic("unknown command: " + command)
# 		}
# 	}
# }

# // nextText reads a single word from the scanner.
# func nextText(sc *bufio.Scanner) string {
# 	sc.Scan()
# 	return sc.Text()
# }

# // nextInt reads an integer from the scanner by converting the text output of nextText to an integer.
# func nextInt(sc *bufio.Scanner) (int, error) {
# 	return strconv.Atoi(nextText(sc))
# }

# // isToAs converts a slice of integers to a slice of strings.
# func isToAs(is []int) []string {
# 	n := len(is)
# 	as := make([]string, n)
# 	for i := 0; i < n; i++ {
# 		as[i] = strconv.Itoa(is[i])
# 	}
# 	return as
# }

# 