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

// Define a structure for a node in the AVL tree
type Node struct {
	key      int
	priority int
	left     *Node
	right    *Node
}

// Function to delete a node from the AVL tree
<<<<<<< HEAD
func Delete(t *Node, key int) *Node {
=======
func delete(t *Node, key int) *Node {
>>>>>>> 98c87cb78a (data updated)
	// If the tree is empty, do nothing
	if t == nil {
		return nil
	}
	// Recursively search for the node to delete
	if key < t.key {
<<<<<<< HEAD
		t.left = Delete(t.left, key)
	} else if key > t.key {
		t.right = Delete(t.right, key)
	} else {
		// If the node to be deleted has only one child, make the child the new root
		if t.left == nil {
			temp := t.right
			t = nil
			return temp
		} else if t.right == nil {
			temp := t.left
			t = nil
			return temp
		}
		// If the node to be deleted has two children, find the inorder successor
		temp := t.right
		for temp.left!= nil {
			temp = temp.left
		}
		// Replace the node to be deleted with its inorder successor
		t.key = temp.key
		// Delete the inorder successor
		t.right = Delete(t.right, temp.key)
=======
		t.left = delete(t.left, key)
	} else if key > t.key {
		t.right = delete(t.right, key)
	} else {
		// If the node to be deleted has no children, delete it and update the tree
		if t.left == nil && t.right == nil {
			return nil
		}
		// If the node to be deleted has only one child, delete it and update the tree
		if t.left == nil {
			return t.right
		}
		if t.right == nil {
			return t.left
		}
		// If the node to be deleted has two children, delete it and update the tree
		q := t.right
		for q.left!= nil {
			q = q.left
		}
		t.key = q.key
		t.right = delete(t.right, q.key)
>>>>>>> 98c87cb78a (data updated)
	}
	// If the deleted node was a rotated node, check if the tree needs to be rotated
	if t.priority < t.left.priority || t.priority < t.right.priority {
		// Perform a right rotation if the left child has a higher priority
		if t.left.priority > t.right.priority {
			t = rightRotate(t)
		}
		// Perform a left rotation if the right child has a higher priority
		t = leftRotate(t)
	}
	// Return the updated tree
	return t
}

// Function to perform a right rotation on an AVL tree
func rightRotate(t *Node) *Node {
	// Save a reference to the left child
	q := t.left
	// Make the left child's right subtree the new root
	t.left = q.right
	// Make the old root the new left child of the left child
	q.right = t
	// Return the new root
	return q
}

// Function to perform a left rotation on an AVL tree
func leftRotate(t *Node) *Node {
	// Save a reference to the right child
	q := t.right
	// Make the right child's left subtree the new root
	t.right = q.left
	// Make the old root the new right child of the right child
	q.left = t
	// Return the new root
	return q
}

// Function to insert a new node into the AVL tree
func insert(t *Node, key int, priority int) *Node {
	// If the tree is empty, create a new node and return it
	if t == nil {
<<<<<<< HEAD
		return &Node{key, priority, nil, nil}
=======
		return &Node{key: key, priority: priority, left: nil, right: nil}
>>>>>>> 98c87cb78a (data updated)
	}
	// Recursively search for the location to insert the new node
	t = insert(t, key, priority)
	// If the new node becomes the root, check if it needs to be rotated
	if t.priority < t.left.priority || t.priority < t.right.priority {
		// Perform a right rotation if the left child has a higher priority
		if t.left.priority > t.right.priority {
			t = rightRotate(t)
		}
		// Perform a left rotation if the right child has a higher priority
		t = leftRotate(t)
	}
	// Return the updated tree
	return t
}

// Function to check if a key is present in the AVL tree
func find(t *Node, x int) bool {
	// While the current node is not NULL
	for t!= nil {
		// If the key is found, return 1
		if t.key == x {
			return true
		}
		// If the key is smaller than the current node's key, move to the left
		if t.key > x {
			t = t.left
		}
		// Otherwise, move to the right
		else {
			t = t.right
		}
	}
	// If the key is not found, return 0
	return false
}

// Function to perform an inorder traversal of the AVL tree and print the keys
func inorder(t *Node) {
	// If the left subtree is not NULL, recursively traverse the left subtree
	if t.left!= nil {
		inorder(t.left)
	}
	// Print the current node's key
	fmt.Printf(" %d", t.key)
	// If the right subtree is not NULL, recursively traverse the right subtree
	if t.right!= nil {
		inorder(t.right)
	}
	// Return from the function
	return
}

// Function to perform a preorder traversal of the AVL tree and print the keys
func preorder(t *Node) {
	// Print the current node's key
	fmt.Printf(" %d", t.key)
	// If the left subtree is not NULL, recursively traverse the left subtree
	if t.left!= nil {
		preorder(t.left)
	}
	// If the right subtree is not NULL, recursively traverse the right subtree
	if t.right!= nil {
		preorder(t.right)
	}
	// Return from the function
	return
}

// Function to print the AVL tree
func print(t *Node) {
	// Perform an inorder traversal of the AVL tree and print the keys
	inorder(t)
	// Perform a preorder traversal of the AVL tree and print the keys
	preorder(t)
	// Return from the function
	return
}

// Main function to read commands and perform the corresponding operations on the AVL tree
func main() {
	// Initialize the AVL tree to be empty
	var num, x, y int
	var com string
	var root *Node = nil
	// Read the number of commands
	fmt.Scanf("%d", &num)
	// Process each command
	for i := 0; i < num; i++ {
		fmt.Scanf("%s", &com)
		// Based on the command, perform the corresponding operation on the AVL tree
		switch com[0] {
		case 'i': // Insert a new node
			fmt.Scanf("%d %d", &x, &y)
			root = insert(root, x, y)
		case 'd': // Delete a node
			fmt.Scanf("%d", &x)
<<<<<<< HEAD
			root = Delete(root, x)
=======
			root = delete(root, x)
>>>>>>> 98c87cb78a (data updated)
		case 'f': // Find a node
			fmt.Scanf("%d", &x)
			if find(root, x) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		case 'p': // Print the AVL tree
			print(root)
		}
	}
	// Return from the main function
	return
}

