
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a doubly linked list node
type node struct {
	key  int
	next *node
	prev *node
}

// Define a pointer type for the node structure
type NodePointer *node

// Function to initialize the doubly linked list
func init() {
	N := NodePointer(&node{}) // Allocate memory for the head node
	N.next = N                // Point next of head to itself (circular)
	N.prev = N                // Point prev of head to itself (circular)
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
		cur = cur.next      // Move to the next node
		snl = 0             // Set flag to indicate that we have printed at least one element
	}
	fmt.Println() // Print a newline after the list
}

// Function to delete the first node in the list
func deleteFirst() {
	t := N.next // Node to be deleted (first node)
	N.next = t.next
	t.next.prev = N
}

// Function to delete the last node in the list
func deleteLast() {
	delnode := N.prev // Node to be deleted (last node)
	N.prev = delnode.prev
	delnode.prev.next = N
	delnode = nil
}

// Function to delete a node with a specific key
func delete(skey int) {
	judge := 0 // Flag to check if the key exists
	t := NodePointer(nil)
	n := NodePointer(nil)

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
		t.next = n.next
		t.next.prev = t
		n = nil
	}
}

// Function to insert a new node with a specific key
func insert(skey int) {
	new := NodePointer(&node{}) // Pointer for the new node
	count := 0                  // Static variable to track the number of nodes

	// If this is the first node being inserted
	if count == 0 {
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
		count++ // Increment the count of nodes
	}
	// If there are already nodes in the list
	else {
		new.next = N.next
		N.next.prev = new
		N.next = new
		new.prev = N
		count++ // Increment the count of nodes
	}
	new.key = skey
}

// Main function to execute the program
func main() {
	var key, n, i int
	var com string

	n, _ = strconv.Atoi(os.Args[1]) // Read the number of operations
	init()                          // Initialize the doubly linked list
	for i = 0; i < n; i++ {         // Loop through each operation
		com = os.Args[2+i] // Read the command
		if com == "insert" {
			key, _ = strconv.Atoi(os.Args[3+i]) // Read the key to insert
			insert(key)                         // Call insert function
		} else if com == "deleteFirst" {
			deleteFirst() // Call deleteFirst function
		} else if com == "deleteLast" {
			deleteLast() // Call deleteLast function
		} else { // If command is 'delete'
			key, _ = strconv.Atoi(os.Args[3+i]) // Read the key to delete
			delete(key)                         // Call delete function
		}
	}
	printList() // Print the final state of the list
}

