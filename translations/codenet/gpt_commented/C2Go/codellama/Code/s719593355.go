
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a doubly linked list node structure
type node struct {
	key  int
	next *node
	prev *node
}

var nil *node // Sentinel node to represent the head and tail of the list

// Function to search for a node with a specific key
func listSearch(key int) *node {
	cur := nil.next // Start searching from the first node

	// Traverse the list until the end or until the key is found
	for cur != nil && cur.key != key {
		cur = cur.next
	}

	return cur // Return the found node or nil if not found
}

// Function to initialize the doubly linked list
func init() {
	nil = &node{} // Allocate memory for the sentinel node
	nil.next = nil
	nil.prev = nil
}

// Function to print the contents of the list
func printList() {
	cur := nil.next // Start from the first node
	isf := 1        // Flag to manage spacing between numbers

	// Loop to print each node's key
	for {
		if cur == nil {
			break // Stop if we reach the sentinel node
		}
		if isf == 0 {
			fmt.Print(" ") // Print space before subsequent numbers
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next      // Move to the next node
		isf = 0             // Set flag to indicate that the first number has been printed
	}
	fmt.Println() // Print a newline at the end
}

// Function to delete a specific node from the list
func deleteNode(t *node) {
	t.prev.next = t.next // Bypass the node to be deleted
	t.next.prev = t.prev // Bypass the node to be deleted
	t = nil              // Free the memory allocated for the node
}

// Function to delete the first node in the list
func deleteFirst() {
	t := nil.next // Get the first node
	if t == nil { // Check if the list is empty
		return
	}

	deleteNode(t) // Delete the first node
}

// Function to delete the last node in the list
func deleteLast() {
	t := nil.prev // Get the last node
	if t == nil { // Check if the list is empty
		return
	}

	deleteNode(t) // Delete the last node
}

// Function to delete a node with a specific key
func delete(key int) {
	t := listSearch(key) // Search for the node with the given key

	if t == nil { // If the node is not found, return
		return
	}

	deleteNode(t) // Delete the found node
}

// Function to insert a new node with a specific key at the beginning of the list
func insert(key int) {
	x := &node{} // Pointer for the new node
	x.key = key  // Set the key of the new node

	// Insert the new node at the beginning of the list
	x.next = nil.next // Point the new node's next to the current first node
	nil.next.prev = x // Update the current first node's previous to point to the new node
	nil.next = x      // Update the sentinel's next to point to the new node
	x.prev = nil      // Set the new node's previous to the sentinel
}

func main() {
	var key, n, i int // Variables for key, number of operations, and loop index
	var size int      // Variable to keep track of the size of the list
	var com string    // Array to hold command strings
	var np, nd int    // Counters for number of insertions and deletions

	// Read the number of operations to perform
	fmt.Scan(&n)

	// Initialize the doubly linked list
	init()

	// Loop to process each operation
	for i = 0; i < n; i++ {
		// Read command and key value
		fmt.Scan(&com, &key)

		// If the command is to insert a node
		if com[0] == 'i' {
			insert(key) // Insert the key into the list
			np++        // Increment the insertion counter
			size++      // Increment the size of the list
		}
		// If the command is to delete a node
		if com[0] == 'd' {
			// Check for specific delete commands (delete first or last)
			if len(com) > 6 {
				if com[6] == 'F' {
					deleteFirst() // Delete the first node
				} else if com[6] == 'L' {
					deleteLast() // Delete the last node
				}
			} else {
				delete(key) // Delete the node with the specified key
				nd++        // Increment the deletion counter
			}
			size-- // Decrement the size of the list
		}
	}

	// Print the final state of the list
	printList()
}

