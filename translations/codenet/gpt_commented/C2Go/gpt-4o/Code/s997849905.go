package main

import (
	"fmt"
	"os"
)

// Define a structure for a doubly linked list node
type Node struct {
	key  int   // Key value of the node
	next *Node // Pointer to the next node
	prev *Node // Pointer to the previous node
}

// Define a pointer type for the node structure
type NodePointer *Node

var N NodePointer // Head of the doubly linked list

// Function to initialize the doubly linked list
func initList() {
	N = &Node{} // Allocate memory for the head node
	N.next = N  // Point next of head to itself (circular)
	N.prev = N  // Point prev of head to itself (circular)
}

// Function to print the elements of the list
func printList() {
	cur := N.next // Start from the first node
	snl := 1      // Flag to manage spacing
	for cur != N { // Traverse until we reach the head again
		if snl == 0 {
			fmt.Print(" ") // Print space before the next number
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next     // Move to the next node
		snl = 0           // Set flag to indicate that we have printed at least one element
	}
	fmt.Println() // Print a newline after the list
}

// Function to delete the first node in the list
func deleteFirst() {
	t := N.next // Node to be deleted (first node)
	N.next = t.next // Update head's next to the second node
	t.next.prev = N // Update the new first node's prev to head
}

// Function to delete the last node in the list
func deleteLast() {
	delnode := N.prev // Node to be deleted (last node)
	N.prev = delnode.prev // Update head's prev to the second last node
	delnode.prev.next = N // Update the new last node's next to head
}

// Function to delete a node with a specific key
func delete(skey int) {
	judge := 0 // Flag to check if the key exists
	var t, n NodePointer // Temporary pointer for node manipulation

	// Traverse the list to check if the key exists
	for n = N.next; n != N; n = n.next {
		if n.key == skey {
			judge = 1 // Key found
		}
	}

	// If the key exists, proceed to delete the node
	if judge == 1 {
		n = N.next // Start from the first node
		for n != N { // Traverse until we find the key
			if n.key == skey {
				break // Break if key is found
			}
			n = n.next // Move to the next node
		}
		t = n.prev // Get the previous node
		t.next = n.next // Bypass the node to be deleted
		t.next.prev = t // Update the next node's prev pointer
	}
}

// Function to insert a new node with a specific key
func insert(skey int) {
	newNode := &Node{key: skey} // Allocate memory for the new node
	staticCount := 0            // Variable to track the number of nodes

	// If this is the first node being inserted
	if staticCount == 0 {
		newNode.next = N // Point new node's next to head
		N.next = newNode  // Update head's next to new node
		newNode.prev = N  // Point new node's prev to head
		N.prev = newNode  // Update head's prev to new node
		staticCount++     // Increment the count of nodes
	} else {
		newNode.next = N.next // Point new node's next to the first node
		N.next.prev = newNode // Update the first node's prev to new node
		N.next = newNode      // Update head's next to new node
		newNode.prev = N      // Point new node's prev to head
		staticCount++         // Increment the count of nodes
	}
}

// Main function to execute the program
func main() {
	var key, n int // Variables for key and number of operations
	var com string // Variable to store command input

	fmt.Scan(&n) // Read the number of operations
	initList()   // Initialize the doubly linked list
	for i := 0; i < n; i++ { // Loop through each operation
		fmt.Scan(&com) // Read the command
		switch com {
		case "insert": // Check if command is 'insert'
			fmt.Scan(&key) // Read the key to insert
			insert(key)    // Call insert function
		case "deleteFirst": // Check if command is 'deleteFirst'
			deleteFirst()    // Call deleteFirst function
		case "deleteLast":  // Check if command is 'deleteLast'
			deleteLast()     // Call deleteLast function
		default: // If command is 'delete'
			fmt.Scan(&key) // Read the key to delete
			delete(key)    // Call delete function
		}
	}
	printList() // Print the final state of the list
}

// <END-OF-CODE>
