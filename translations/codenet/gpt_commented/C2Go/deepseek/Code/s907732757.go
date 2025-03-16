package main

import (
	"fmt"
	"strings"
)

// Define a doubly linked list node structure
type node struct {
	key   int
	next  *node
	prev  *node
}

var head *node // Pointer to the head of the doubly linked list

// Function prototypes for node operations
func makenode(a int) *node
func insert(a int)
func delete(a int)
func deleteFirst()
func deleteLast()

func main() {
	var i, n, a int
	var op string
	var x *node // Temporary node pointer for traversal

	// Initialize the head node of the doubly linked list
	head = makenode(0)
	head.next = head
	head.prev = head

	// Read the number of operations to perform
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		// Read the operation command
		fmt.Scan(&op)
		if strings.Compare(op, "insert") == 0 { // Check if the operation is "insert"
			fmt.Scan(&a) // Read the value to insert
			insert(a)    // Call insert function
		} else if strings.Compare(op, "delete") == 0 { // Check if the operation is "delete"
			fmt.Scan(&a) // Read the value to delete
			delete(a)    // Call delete function
		} else if strings.Compare(op, "deleteFirst") == 0 { // Check if the operation is "deleteFirst"
			deleteFirst() // Call function to delete the first node
		} else if strings.Compare(op, "deleteLast") == 0 { // Check if the operation is "deleteLast"
			deleteLast() // Call function to delete the last node
		}
	}

	// Print the remaining elements in the list
	x = head
	for x.next != head { // Traverse the list until we reach the head again
		fmt.Print(x.next.key) // Print the key of the next node
		x = x.next            // Move to the next node
		if x.next != head {   // Check if we are not at the head node
			fmt.Print(" ") // Print space between numbers
		}
	}
	fmt.Println() // Print newline after all elements
}

// Function to create a new node with a given key
func makenode(a int) *node {
	x := &node{key: a} // Create a new node
	return x           // Return the new node
}

// Function to insert a new node with a given key at the beginning of the list
func insert(a int) {
	x := makenode(a) // Create a new node
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

// Function to delete a node with a given key from the list
func delete(a int) {
	x := head

	// Traverse the list to find the node with the given key
	for x.next != head {
		x = x.next
		if x.key == a { // Check if the current node's key matches the key to delete
			// Update the pointers to remove the node from the list
			x.prev.next = x.next
			x.next.prev = x.prev
			break // Exit the loop after deletion
		}
	}
}

// Function to delete the first node in the list
func deleteFirst() {
	x := head.next
	head.next = x.next
	x.next.prev = head
}

// Function to delete the last node in the list
func deleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
}

