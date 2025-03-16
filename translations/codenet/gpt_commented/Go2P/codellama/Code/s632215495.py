
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

# Define a structure for a node in the binary tree
class node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

# Define a structure for the binary tree
class tree:
    def __init__(self):
        self.root = None

# Insert a new key into the binary tree
def (tree *tree) insert(key int) {
    # If the tree is empty, create a new root node
    if tree.root == nil {
        tree.root = &node{key: key}
        return
    }

    var currentNode, prevNode *node
    currentNode = tree.root
    # Traverse the tree to find the correct position for the new key
    for currentNode != nil {
        prevNode = currentNode
        if currentNode.key < key {
            currentNode = currentNode.right // Move to the right child
        } else {
            currentNode = currentNode.left // Move to the left child
        }
    }

    # Create a new node for the key and set its parent
    newNode := &node{key: key}
    newNode.parent = prevNode
    # Attach the new node to the correct position in the tree
    if prevNode.key < key {
        prevNode.right = newNode // Insert as right child
    } else {
        prevNode.left = newNode // Insert as left child
    }
}

# Print the keys in the tree in both inorder and preorder traversal
def (tree tree) print() {
    var acc []int
    # Check if the tree is empty
    if tree.root == nil {
        fmt.Println("")
        fmt.Println("")
    } else {
        # Print inorder traversal
        fmt.Println(" " + strings.Join(isToAs(visitInorder(tree.root, acc)), " "))
        # Print preorder traversal
        fmt.Println(" " + strings.Join(isToAs(visitPreorder(tree.root, acc)), " "))
    }
}

# Perform a preorder traversal of the tree
def visitPreorder(node *node, acc []int) []int {
    if node == nil {
        return acc // Return accumulated keys if node is nil
    }
    acc = append(acc, int(node.key)) // Add the current node's key
    if node.left != nil {
        acc = visitPreorder(node.left, acc) // Traverse left subtree
    }
    if node.right != nil {
        acc = visitPreorder(node.right, acc) // Traverse right subtree
    }
    return acc
}

# Perform an inorder traversal of the tree
def visitInorder(node *node, acc []int) []int {
    if node == nil {
        return acc // Return accumulated keys if node is nil
    }
    if node.left != nil {
        acc = visitInorder(node.left, acc) // Traverse left subtree
    }
    acc = append(acc, int(node.key)) // Add the current node's key
    if node.right != nil {
        acc = visitInorder(node.right, acc) // Traverse right subtree
    }
    return acc
}

# Main function to read commands and manipulate the binary tree
def main():
    sc = bufio.NewScanner(os.Stdin) // Create a new scanner for standard input
    sc.Split(bufio.ScanWords)          // Split input into words

    n, err := nextInt(sc) // Read the number of commands
    if err != nil {
        panic(err) // Handle error if reading fails
    }

    tree := &tree{} // Initialize a new binary tree
    # Process each command
    for i := 0; i < n; i++ {
        command := nextText(sc) // Read the command
        switch command {
        case "insert":
            key, err := nextInt(sc) // Read the key to insert
            if err != nil {
                panic(err) // Handle error if reading fails
            }
            tree.insert(key) // Insert the key into the tree
        case "print":
            tree.print() // Print the tree's keys
        default:
            panic("unknown command: " + command) // Handle unknown commands
        }
    }

# Read the next text input from the scanner
def nextText(sc *bufio.Scanner) string {
    sc.Scan() // Scan the next token
    return sc.Text() // Return the scanned text
}

# Read the next integer input from the scanner
def nextInt(sc *bufio.Scanner) (int, error) {
    return strconv.Atoi(nextText(sc)) // Convert the scanned text to an integer
}

# Convert a slice of integers to a slice of strings
def isToAs(is []int) []string {
    n := len(is)
    as := make([]string, n) // Create a new slice of strings
    for i := 0; i < n; i++ {
        as[i] = strconv.Itoa(is[i]) // Convert each integer to a string
    }
    return as // Return the slice of strings
}

# 