package main

import (
	"fmt"
)

// Define the structure for a node in the binary search tree
type Node struct {
	right  *Node // Pointer to the right child
	left   *Node // Pointer to the left child
	parent *Node // Pointer to the parent node
	key    int   // Key value of the node
}

var root *Node // Root of the binary search tree

// Function to find the minimum node in a subtree
func treeMinimum(x *Node) *Node {
	for x.left != nil { // Traverse to the leftmost node
		x = x.left
	}
	return x // Return the minimum node
}

// Function to find the maximum node in a subtree
func treeMaximum(x *Node) *Node {
	for x.right != nil { // Traverse to the rightmost node
		x = x.right
	}
	return x // Return the maximum node
}

// Function to search for a node with a specific key in the tree
func treeSearch(u *Node, k int) *Node {
	if u == nil || k == u.key { // Base case: found the node or reached a leaf
		return u
	}

	// Recursively search in the left or right subtree based on the key
	if k < u.key {
		return treeSearch(u.left, k)
	} else {
		return treeSearch(u.right, k)
	}
}

// Function to find the successor of a given node in the binary search tree
func treeSuccessor(x *Node) *Node {
	var y *Node
	if x.right != nil { // If right child exists, successor is the minimum in the right subtree
		return treeMinimum(x.right)
	}
	y = x.parent // Start with the parent of the current node
	// Traverse up the tree until we find a node that is a left child
	for y != nil && x == y.right {
		x = y
		y = y.parent
	}
	return y // Return the successor node
}

// Function to delete a node from the binary search tree
func treeDelete(z *Node) {
	var y *Node // Node to be deleted
	var x *Node // Child of y

	// Determine the node to delete (y) based on the number of children
	if z.left == nil || z.right == nil {
		y = z // If z has one or no children, y is z
	} else {
		y = treeSuccessor(z) // If z has two children, find its successor
	}

	// Determine the child of y
	if y.left != nil {
		x = y.left
	} else {
		x = y.right
	}

	// Update the parent of x if it exists
	if x != nil {
		x.parent = y.parent
	}

	// Update the parent's child pointer to x
	if y.parent == nil {
		root = x // If y is root, update root
	} else if y == y.parent.left {
		y.parent.left = x // If y is a left child, update left pointer
	} else {
		y.parent.right = x // If y is a right child, update right pointer
	}

	// Copy the key from y to z if they are different
	if y != z {
		z.key = y.key
	}
}

// Function to insert a new key into the binary search tree
func insert(k int) {
	var y *Node = nil // Parent node
	var x *Node = root // Current node
	z := &Node{key: k, left: nil, right: nil} // New node to be inserted

	// Find the appropriate position for the new node
	for x != nil {
		y = x // Keep track of the parent
		if z.key < x.key {
			x = x.left // Move to the left child
		} else {
			x = x.right // Move to the right child
		}
	}
	z.parent = y // Set the parent of the new node
	if y == nil {
		root = z // If tree was empty, new node is root
	} else if z.key < y.key {
		y.left = z // Insert as left child
	} else {
		y.right = z // Insert as right child
	}
}

// Function for inorder traversal of the tree
func inorder(u *Node) {
	if u == nil {
		return // Base case: if the node is nil, return
	}
	inorder(u.left) // Traverse left subtree
	fmt.Printf(" %d", u.key) // Print the key of the current node
	inorder(u.right) // Traverse right subtree
}

// Function for preorder traversal of the tree
func preorder(u *Node) {
	if u == nil {
		return // Base case: if the node is nil, return
	}
	fmt.Printf(" %d", u.key) // Print the key of the current node
	preorder(u.left) // Traverse left subtree
	preorder(u.right) // Traverse right subtree
}

// Main function to execute the program
func main() {
	var n, x int // Variables for number of commands and key value
	var com string // Variable to hold command strings
	fmt.Scan(&n) // Read the number of commands

	// Loop to process each command
	for i := 0; i < n; i++ {
		fmt.Scan(&com) // Read the command
		if com[0] == 'f' { // If command is 'find'
			fmt.Scan(&x) // Read the key to find
			t := treeSearch(root, x) // Search for the key
			if t != nil {
				fmt.Println("yes") // Key found
			} else {
				fmt.Println("no") // Key not found
			}
		} else if com[0] == 'i' { // If command is 'insert'
			fmt.Scan(&x) // Read the key to insert
			insert(x) // Insert the key into the tree
		} else if com[0] == 'p' { // If command is 'print'
			inorder(root) // Print the tree in inorder
			fmt.Println()
			preorder(root) // Print the tree in preorder
			fmt.Println()
		} else if com[0] == 'd' { // If command is 'delete'
			fmt.Scan(&x) // Read the key to delete
			treeDelete(treeSearch(root, x)) // Delete the node with the key
		}
	}
}

// <END-OF-CODE>
