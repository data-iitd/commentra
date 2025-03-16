package main

import (
	"fmt"
	"os"
)

// Define a structure for a doubly linked list node
type Node struct {
	key  uint // Key value of the node
	next *Node // Pointer to the next node
	prev *Node // Pointer to the previous node
}

// Define a sentinel node to represent the head and tail of the list
var nilNode *Node

// Function to search for a node with a specific key
func listSearch(key int) *Node {
	cur := nilNode.next // Start from the first node
	for cur != nilNode { // Traverse until the sentinel node
		if cur.key == uint(key) {
			return cur // Return the found node
		}
		cur = cur.next // Move to the next node
	}
	return nilNode // Return sentinel if not found
}

// Function to initialize the linked list
func initList() {
	nilNode = &Node{} // Create the sentinel node
	nilNode.next = nilNode // Point next of sentinel to itself
	nilNode.prev = nilNode // Point prev of sentinel to itself
}

// Function to print all the keys in the linked list
func printList() {
	cur := nilNode.next // Start from the first node
	isFirst := true     // Flag to manage spacing between numbers
	for {
		if cur == nilNode {
			break // Stop if we reach the sentinel node
		}
		if !isFirst {
			fmt.Print(" ") // Print space before the next number if not the first
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next     // Move to the next node
		isFirst = false    // Set flag to indicate that we have printed at least one number
	}
	fmt.Println() // Print a new line after printing all keys
}

// Function to delete a specific node from the list
func deleteNode(t *Node) {
	if t == nilNode {
		return // Do nothing if the node is the sentinel
	}
	t.prev.next = t.next // Bypass the node in the next pointer of the previous node
	t.next.prev = t.prev // Bypass the node in the prev pointer of the next node
}

// Function to delete the first node in the list
func deleteFirst() {
	t := nilNode.next // Get the first node
	if t == nilNode {
		return // Do nothing if the list is empty
	}
	deleteNode(t) // Delete the first node
}

// Function to delete the last node in the list
func deleteLast() {
	t := nilNode.prev // Get the last node
	if t == nilNode {
		return // Do nothing if the list is empty
	}
	deleteNode(t) // Delete the last node
}

// Function to delete a node with a specific key
func deleteKey(key int) {
	t := listSearch(key) // Search for the node with the key
	if t != nilNode {
		deleteNode(t) // If found, delete the node
	}
}

// Function to insert a new node with a specific key at the beginning of the list
func insert(key int) {
	x := &Node{key: uint(key)} // Allocate memory for the new node
	x.prev = nilNode          // Set the previous pointer to the sentinel
	x.next = nilNode.next     // Set the next pointer to the current first node
	x.next.prev = x          // Update the previous pointer of the current first node to point to the new node
	nilNode.next = x         // Update the sentinel's next pointer to point to the new node
}

// Main function to execute the program
func main() {
	var key, n int // Variables for key and number of operations
	var command string // Variable to store command strings
	initList() // Initialize the linked list
	fmt.Scan(&n) // Read the number of operations
	for i := 0; i < n; i++ { // Loop through each operation
		fmt.Scan(&command, &key) // Read the command and key
		if command[0] == 'i' { // If the command is 'insert'
			insert(key) // Insert the key
		} else if command[0] == 'd' { // If the command is 'delete'
			if len(command) > 6 { // Check if the command specifies 'First' or 'Last'
				if command[6] == 'F' {
					deleteFirst() // Delete the first node
				} else if command[6] == 'L' {
					deleteLast() // Delete the last node
				}
			} else {
				deleteKey(key) // Delete the node with the specified key
			}
		}
	}
	printList() // Print the final state of the list
}
