
package main

import (
	"fmt"
)

// Define a structure for a node in the AVL tree
type Node struct {
	key      int
	priority int
	right    *Node
	left     *Node
}

// Function to delete a node from the AVL tree
func Delete(t **Node, key int) {
	// If the tree is empty, do nothing
	if *t == nil {
		return
	}
	// Recursively search for the node to delete
	if key < (*t).key {
		Delete(&((*t).left), key)
	} else if key > (*t).key {
		Delete(&((*t).right), key)
	} else {
		q := *t
		*t = delete(t, key)
		q = nil
	}
	// If the deleted node was a rotated node, check if the tree needs to be rotated
	if (*t).priority < (*t).left.priority || (*t).priority < (*t).right.priority {
		// Perform a right rotation if the left child has a higher priority
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		}
		// Perform a left rotation if the right child has a higher priority
		*t = leftRotate(*t)
	}
	// Return the updated tree
	return
}

// Function to perform a right rotation on an AVL tree
func rightRotate(p *Node) *Node {
	// Save a reference to the left child
	q := p.left
	// Make the left child's right subtree the new root
	p.left = q.right
	// Make the old root the new left child of the left child
	q.right = p
	// Return the new root
	return q
}

// Function to perform a left rotation on an AVL tree
func leftRotate(p *Node) *Node {
	// Save a reference to the right child
	q := p.right
	// Make the right child's left subtree the new root
	p.right = q.left
	// Make the old root the new right child of the right child
	q.left = p
	// Return the new root
	return q
}

// Function to insert a new node into the AVL tree
func insert(t **Node, key int, priority int) {
	// If the tree is empty, create a new node and return it
	if *t == nil {
		*t = &Node{key, priority, nil, nil}
		return
	}
	// Recursively search for the location to insert the new node
	*t = insert(&(*t), key, priority)
	// If the new node becomes the root, check if it needs to be rotated
	if (*t).priority < (*t).left.priority || (*t).priority < (*t).right.priority {
		// Perform a right rotation if the left child has a higher priority
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		}
		// Perform a left rotation if the right child has a higher priority
		*t = leftRotate(*t)
	}
	// Return the updated tree
	return
}

// Function to perform an inorder traversal of the AVL tree and print the keys
func inorder(a *Node) {
	// If the left subtree is not NULL, recursively traverse the left subtree
	if a.left != nil {
		inorder(a.left)
	}
	// Print the current node's key
	fmt.Printf(" %d", a.key)
	// If the right subtree is not NULL, recursively traverse the right subtree
	if a.right != nil {
		inorder(a.right)
	}
	// Return from the function
	return
}

// Function to perform a preorder traversal of the AVL tree and print the keys
func preorder(p *Node) {
	// Print the current node's key
	fmt.Printf(" %d", p.key)
	// If the left subtree is not NULL, recursively traverse the left subtree
	if p.left != nil {
		preorder(p.left)
	}
	// If the right subtree is not NULL, recursively traverse the right subtree
	if p.right != nil {
		preorder(p.right)
	}
	// Return from the function
	return
}

// Function to print the AVL tree
func print(p *Node) {
	// Perform an inorder traversal of the AVL tree and print the keys
	inorder(p)
	// Perform a preorder traversal of the AVL tree and print the keys
	preorder(p)
	// Return from the function
	return
}

// Function to create a new node in the AVL tree
func makenode(x int, y int) *Node {
	// Allocate memory for a new node
	new := &Node{x, y, nil, nil}
	// Return the new node
	return new
}

// Function to find a node in the AVL tree
func find(p *Node, x int) bool {
	// While the current node is not NULL
	for p != nil {
		// If the key is found, return 1
		if p.key == x {
			return true
		}
		// If the key is smaller than the current node's key, move to the left
		if p.key > x {
			p = p.left
		}
		// Otherwise, move to the right
		else {
			p = p.right
		}
	}
	// If the key is not found, return 0
	return false
}

// Function to delete a node from the AVL tree
func delete(t **Node, key int) *Node {
	// If the tree is empty, do nothing
	if *t == nil {
		return nil
	}
	// Recursively search for the location to delete the node
	*t = delete(&(*t), key)
	// If the deleted node was a rotated node, check if the tree needs to be rotated
	if (*t).priority < (*t).left.priority || (*t).priority < (*t).right.priority {
		// Perform a right rotation if the left child has a higher priority
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		}
		// Perform a left rotation if the right child has a higher priority
		*t = leftRotate(*t)
	}
	// Return the updated tree
	return *t
}

// Main function to read commands and perform the corresponding operations on the AVL tree
func main() {
	// Initialize the AVL tree to be empty
	var num int
	var x int
	var y int
	var com string
	root := nil
	// Read the number of commands
	fmt.Scanf("%d", &num)
	// Process each command
	for i := 0; i < num; i++ {
		fmt.Scanf("%s", &com)
		// Based on the command, perform the corresponding operation on the AVL tree
		switch com[0] {
		case 'i': // Insert a new node
			fmt.Scanf("%d %d", &x, &y)
			insert(&root, x, y)
			break
		case 'd': // Delete a node
			fmt.Scanf("%d", &x)
			Delete(&root, x)
			break
		case 'f': // Find a node
			fmt.Scanf("%d", &x)
			if find(root, x) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
			break
		case 'p': // Print the AVL tree
			print(root)
			break
		}
	}
	// Return from the main function
	return
}

