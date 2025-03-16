
package main

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
func Delete(t **Node, key int) *Node {
	// If the tree is empty, do nothing
	if *t == nil {
		return nil
	}
	// Recursively search for the node to delete
	if key < (*t).key {
		(*t).left = Delete(&(*t).left, key)
	} else if key > (*t).key {
		(*t).right = Delete(&(*t).right, key)
	} else {
		// If the node to be deleted was found, delete it and update the tree
		y := (*t)
		if y.left == nil {
			x := y.right
			y.right = nil
			return x
		} else if y.right == nil {
			x := y.left
			y.left = nil
			return x
		}
		// Find the inorder successor (smallest in the right subtree)
		z := y.right
		for z.left!= nil {
			z = z.left
		}
		// Copy the inorder successor's content to the node to be deleted
		y.key = z.key
		// Delete the inorder successor
		y.right = Delete(&y.right, z.key)
	}
	// If the deleted node was a rotated node, check if the tree needs to be rotated
	if (*t).priority < (*t).left.priority || (*t).priority < (*t).right.priority {
		// Perform a right rotation if the left child has a higher priority
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		} else {
			*t = leftRotate(*t)
		}
	}
	// Return the updated tree
	return *t
}

// Function to perform a left rotation on an AVL tree
func leftRotate(t *Node) *Node {
	// Save a reference to the right child
	y := t.right
	// Make the right child's left subtree the new root
	t.right = y.left
	// Make the old root the new right child of the right child
	y.left = t
	// Return the new root
	return y
}

// Function to perform a right rotation on an AVL tree
func rightRotate(t *Node) *Node {
	// Save a reference to the left child
	y := t.left
	// Make the left child's right subtree the new root
	t.left = y.right
	// Make the old root the new left child of the left child
	y.right = t
	// Return the new root
	return y
}

// Function to insert a new node into the AVL tree
func insert(t **Node, key int, priority int) *Node {
	// If the tree is empty, create a new node and return it
	if *t == nil {
		return &Node{key, priority, nil, nil}
	}
	// Recursively search for the location to insert the new node
	if key < (*t).key {
		(*t).left = insert(&(*t).left, key, priority)
	} else if key > (*t).key {
		(*t).right = insert(&(*t).right, key, priority)
	}
	// If the new node becomes the root, check if it needs to be rotated
	if (*t).priority < (*t).left.priority || (*t).priority < (*t).right.priority {
		// Perform a right rotation if the left child has a higher priority
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		} else {
			*t = leftRotate(*t)
		}
	}
	// Return the updated tree
	return *t
}

// Function to find a node in the AVL tree
func find(t *Node, key int) bool {
	// While the current node is not nil
	for t!= nil {
		// If the key is found, return true
		if t.key == key {
			return true
		}
		// If the key is smaller than the current node's key, move to the left
		if t.key > key {
			t = t.left
		} else {
			// Otherwise, move to the right
			t = t.right
		}
	}
	// If the key is not found, return false
	return false
}

// Function to perform an inorder traversal of the AVL tree and print the keys
func inorder(t *Node) {
	// If the left subtree is not nil, recursively traverse the left subtree
	if t.left!= nil {
		inorder(t.left)
	}
	// Print the current node's key
	fmt.Printf(" %d", t.key)
	// If the right subtree is not nil, recursively traverse the right subtree
	if t.right!= nil {
		inorder(t.right)
	}
}

// Function to perform a preorder traversal of the AVL tree and print the keys
func preorder(t *Node) {
	// Print the current node's key
	fmt.Printf(" %d", t.key)
	// If the left subtree is not nil, recursively traverse the left subtree
	if t.left!= nil {
		preorder(t.left)
	}
	// If the right subtree is not nil, recursively traverse the right subtree
	if t.right!= nil {
		preorder(t.right)
	}
}

// Function to print the AVL tree
func print(t *Node) {
	// Perform an inorder traversal of the AVL tree and print the keys
	inorder(t)
	// Perform a preorder traversal of the AVL tree and print the keys
	preorder(t)
}

// Main function to read commands and perform the corresponding operations on the AVL tree
func main() {
	// Initialize the AVL tree to be empty
	var root *Node
	// Read the number of commands
	num, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
	// Process each command
	for i := 0; i < num; i++ {
		// Read the command and perform the corresponding operation on the AVL tree
		com, _ := bufio.NewReader(os.Stdin).ReadString('\n')
		com = strings.TrimSpace(com)
		switch com[0] {
		case 'i':
			// Insert a new node
			fields := strings.Fields(com[2:])
			key, _ := strconv.Atoi(fields[0])
			priority, _ := strconv.Atoi(fields[1])
			root = insert(&root, key, priority)
		case 'd':
			// Delete a node
			fields := strings.Fields(com[2:])
			key, _ := strconv.Atoi(fields[0])
			root = Delete(&root, key)
		case 'f':
			// Find a node
			fields := strings.Fields(com[2:])
			key, _ := strconv.Atoi(fields[0])
			if find(root, key) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		case 'p':
			// Print the AVL tree
			print(root)
		}
	}
}

