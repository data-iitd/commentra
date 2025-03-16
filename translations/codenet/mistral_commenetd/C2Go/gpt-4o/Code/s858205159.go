package main

import (
	"fmt"
)

// Define a structure for a node
type Node struct {
	key  uint // Key value of the node
	next *Node // Pointer to the next node
	prev *Node // Pointer to the previous node
}

// Initialize nil node
var nilNode *Node

// Function to search a node with given key
func listSearch(key int) *Node {
	cur := nilNode.next // Initialize current node as the first node after nil
	for cur != nilNode { // Traverse the list until nil is reached
		if cur.key == uint(key) {
			return cur // Return the found node
		}
		cur = cur.next // Move to the next node
	}
	return nil // Return nil if not found
}

// Initialize the linked list with a nil node
func initList() {
	nilNode = &Node{} // Create a nil node
	nilNode.next = nilNode // Initialize next pointer of nil to itself
	nilNode.prev = nilNode // Initialize prev pointer of nil to itself
}

// Function to print the linked list
func printList() {
	cur := nilNode.next // Initialize current node as the first node after nil
	isFirst := true // Initialize isFirst flag to true
	for {
		if cur == nilNode {
			break // If the current node is nil, break the loop
		}
		if isFirst {
			fmt.Printf("[%d] ", cur.key) // If it's the first node, print its key with brackets
		} else {
			fmt.Printf("%d ", cur.key) // Otherwise, print only the key
		}
		cur = cur.next // Move to the next node
		isFirst = false // Set isFirst flag to false
	}
	fmt.Println() // Print a newline after the list is printed
}

// Function to delete a node from the linked list
func deleteNode(t *Node) {
	if t == nilNode {
		return // Return if the node to be deleted is nil
	}
	t.prev.next = t.next // Update the next pointer of the previous node
	t.next.prev = t.prev // Update the prev pointer of the next node
}

// Function to delete the first node from the linked list
func deleteFirst() {
	t := nilNode.next // Initialize the node to be deleted as the first node
	if t == nilNode {
		return // Return if the list is empty
	}
	deleteNode(t) // Delete the first node
}

// Function to delete the last node from the linked list
func deleteLast() {
	t := nilNode.prev // Initialize the node to be deleted as the last node
	if t == nilNode {
		return // Return if the list is empty
	}
	deleteNode(t) // Delete the last node
}

// Function to delete a node with the given key from the linked list
func deleteKey(key int) {
	t := listSearch(key) // Search for the node with the given key
	if t != nil {
		deleteNode(t) // Delete the node if it's found
	}
}

// Function to insert a new node with the given key into the linked list
func insert(key int) {
	x := &Node{key: uint(key)} // Allocate memory for the new node
	x.prev = nilNode // Set the prev pointer of the new node to nil
	x.next = nilNode.next // Set the next pointer of the new node to the first node after nil
	nilNode.next.prev = x // Update the prev pointer of the first node after nil
	nilNode.next = x // Update the next pointer of nil to point to the new node
}

// Main function to read commands and perform the corresponding actions
func main() {
	var key, n int // Initialize variables for reading commands
	var command string // Initialize a string to store the command
	initList() // Initialize the linked list
	fmt.Scan(&n) // Read the number of commands
	for i := 0; i < n; i++ { // Traverse the commands
		fmt.Scan(&command, &key) // Read the command and the key value
		if command[0] == 'i' { // If the command is 'i', insert a new node
			insert(key)
		} else if command[0] == 'd' { // If the command is 'd', delete a node
			if len(command) > 6 { // If the command is 'd F' or 'd L', delete the first or last node
				if command[6] == 'F' {
					deleteFirst()
				} else if command[6] == 'L' {
					deleteLast()
				}
			} else { // Otherwise, delete a node with the given key
				deleteKey(key)
			}
		}
	}

	printList() // Print the updated linked list
}

// <END-OF-CODE>
