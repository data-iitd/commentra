package main

import (
	"fmt"
	"strings"
)

// Define a doubly linked list node structure
type Node struct {
	key  int   // Value of the node
	next *Node // Pointer to the next node
	prev *Node // Pointer to the previous node
}

var head *Node // Pointer to the head of the doubly linked list

// Function prototypes for node operations
func makeNode(a int) *Node {
	return &Node{key: a}
}

func insert(a int) {
	x := makeNode(a) // Create a new node
	x.next = head.next // Set the new node's next to the current first node
	head.next.prev = x // Update the current first node's previous to the new node
	head.next = x // Update head's next to the new node
	x.prev = head // Set the new node's previous to head
}

func delete(a int) {
	x := head // Start from the head

	// Traverse the list to find the node with the given key
	for x.next != head {
		x = x.next // Move to the next node
		if x.key == a { // Check if the current node's key matches the key to delete
			// Update the pointers to remove the node from the list
			x.prev.next = x.next // Bypass the node to delete it
			x.next.prev = x.prev // Update the previous node's next pointer
			return // Exit the function after deletion
		}
	}
}

func deleteFirst() {
	x := head.next // Get the first node
	head.next = x.next // Update head's next to the second node
	x.next.prev = head // Update the new first node's previous to head
}

func deleteLast() {
	x := head.prev // Get the last node
	head.prev = x.prev // Update head's previous to the second last node
	x.prev.next = head // Update the new last node's next to head
}

func main() {
	var n, a int // Variables for number of operations and value to insert/delete
	var op string // Variable to hold operation commands

	// Initialize the head node of the doubly linked list
	head = makeNode(0)
	head.next = head // Point next of head to itself (circular)
	head.prev = head // Point prev of head to itself (circular)

	// Read the number of operations to perform
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		// Read the operation command
		fmt.Scan(&op)
		if op == "insert" { // Check if the operation is "insert"
			fmt.Scan(&a) // Read the value to insert
			insert(a) // Call insert function
		} else if op == "delete" { // Check if the operation is "delete"
			fmt.Scan(&a) // Read the value to delete
			delete(a) // Call delete function
		} else if op == "deleteFirst" { // Check if the operation is "deleteFirst"
			deleteFirst() // Call function to delete the first node
		} else if op == "deleteLast" { // Check if the operation is "deleteLast"
			deleteLast() // Call function to delete the last node
		}
	}

	// Print the remaining elements in the list
	x := head
	for x.next != head { // Traverse the list until we reach the head again
		fmt.Print(x.next.key) // Print the key of the next node
		x = x.next // Move to the next node
		if x.next != head { // Check if we are not at the head node
			fmt.Print(" ") // Print space between numbers
		}
	}
	fmt.Println() // Print newline after all elements
}

// <END-OF-CODE>
