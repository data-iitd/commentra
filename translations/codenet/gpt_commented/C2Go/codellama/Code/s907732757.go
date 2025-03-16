
package main

import (
	"fmt"
	"strconv"
)

// Define a doubly linked list node structure
type node struct {
	key  int
	next *node
	prev *node
}

var head *node // Pointer to the head of the doubly linked list

// Function prototypes for node operations
func makenode(a int) *node
func insert(a int)
func delete(a int)
func deleteFirst()
func deleteLast()

func main() {
	var i, n, a int // Variables for loop index, number of operations, and value to insert/delete
	var op string   // Array to hold operation commands
	var x *node     // Temporary node pointer for traversal

	// Initialize the head node of the doubly linked list
	head = makenode(0)
	head.next = head
	head.prev = head

	// Read the number of operations to perform
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		// Read the operation command
		fmt.Scan(&op)
		if op == "insert" { // Check if the operation is "insert"
			fmt.Scan(&a) // Read the value to insert
			insert(a)    // Call insert function
		} else if op == "delete" { // Check if the operation is "delete"
			fmt.Scan(&a) // Read the value to delete
			delete(a)    // Call delete function
		} else if op == "deleteFirst" { // Check if the operation is "deleteFirst"
			deleteFirst() // Call function to delete the first node
		} else if op == "deleteLast" { // Check if the operation is "deleteLast"
			deleteLast() // Call function to delete the last node
		}
	}

	// Print the remaining elements in the list
	x = head
	for x.next != head { // Traverse the list until we reach the head again
		fmt.Print(x.next.key, " ") // Print the key of the next node
		x = x.next               // Move to the next node
	}
	fmt.Println() // Print newline after all elements
}

// Function to create a new node with a given key
func makenode(a int) *node {
	x := new(node) // Allocate memory for a new node
	x.key = a      // Set the key of the new node
	return x       // Return the new node
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
	for x.next != head {
		x = x.next // Move to the next node
		if x.key == a {
			// Update the pointers to remove the node from the list
			x.prev.next = x.next
			x.next.prev = x.prev
			x = nil
			break
		}
	}
}

// Function to delete the first node in the list
func deleteFirst() {
	x := head.next
	head.next = x.next
	x.next.prev = head
	x = nil
}

// Function to delete the last node in the list
func deleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
	x = nil
}

