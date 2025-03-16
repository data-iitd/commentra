
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a node in the linked list
type node struct {
	key  int
	next *node
	prev *node
}

// Define a typedef for a pointer to a node
type NodePointer *node

// Initialize the linked list with a nil node
var nil *node

// Function to search for a node with a given key in the list
func listSearch(key int) NodePointer {
	cur := nil.next // Initialize a pointer to the first node in the list

	// Search for the node with the given key
	for cur != nil && cur.key != key {
		cur = cur.next
	}

	// Return the found node or nil if not found
	return cur
}

// Initialize the linked list with a nil node
func init() {
	nil = &node{} // Allocate memory for the nil node
	nil.next = nil
	nil.prev = nil
}

// Print the contents of the linked list
func printList() {
	cur := nil.next // Initialize a pointer to the first node in the list
	isf := 1        // Flag to indicate if this is the first node to be printed

	// Traverse the list and print each node
	for {
		if cur == nil {
			break
		}
		if isf == 0 {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		isf = 0
	}
	fmt.Println() // Print a newline at the end
}

// Delete a node from the linked list
func deleteNode(t NodePointer) {
	t.prev.next = t.next
	t.next.prev = t.prev
	t = nil
}

// Delete and free the first node in the list
func deleteFirst() {
	t := nil.next // Initialize a pointer to the first node in the list

	// If the list is empty, return
	if t == nil {
		return
	}

	// Delete and free the first node
	deleteNode(t)
}

// Delete and free the last node in the list
func deleteLast() {
	t := nil.prev // Initialize a pointer to the last node in the list

	// If the list is empty, return
	if t == nil {
		return
	}

	// Delete and free the last node
	deleteNode(t)
}

// Delete a node with the given key from the list
func delete(key int) {
	t := listSearch(key) // Search for the node with the given key

	// If the node is not found, return
	if t == nil {
		return
	}

	// Delete and free the node
	deleteNode(t)
}

// Allocate memory for a new node and insert it into the list
func insert(key int) {
	x := &node{} // Allocate memory for the new node

	// Initialize the new node with the given key
	x.key = key

	// Insert the new node at the end of the list
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
	x.prev = nil
}

// Main function to read commands from standard input and perform the corresponding actions
func main() {
	var key, n, i int // Declare variables to store the number of commands, the current command, and a counter
	var size int      // Initialize a variable to store the current size of the list
	var com string    // Declare a variable to store the command as a string
	var np, nd int    // Initialize counters for the number of insert and delete operations

	// Read the number of commands from standard input
	n, _ = strconv.Atoi(os.Args[1])

	// Initialize the linked list
	init()

	// Process each command in the input
	for i = 0; i < n; i++ {
		com = strings.Split(os.Args[2+i], " ")[0] // Read the command and the key (if any) from standard input
		key, _ = strconv.Atoi(strings.Split(os.Args[2+i], " ")[1])

		// If the command is an insert command, increment the np counter and insert the key into the list
		if com == "i" {
			insert(key)
			np++
			size++
		}

		// If the command is a delete command, increment the nd counter and delete the node with the given key from the list
		if com == "d" {
			if len(os.Args[2+i]) > 6 { // If the command is a delete first or delete last command, process it accordingly
				if strings.Split(os.Args[2+i], " ")[1] == "F" {
					deleteFirst()
				} else if strings.Split(os.Args[2+i], " ")[1] == "L" {
					deleteLast()
				}
			} else { // If the command is a delete command with a key, delete the node with the given key from the list
				delete(key)
				nd++
			}
			size-- // Decrement the size of the list after the delete operation
		}
	}

	// Print the final size of the list and the number of insert and delete operations
	fmt.Printf("Size: %d, Number of insert operations: %d, Number of delete operations: %d\n", size, np, nd)

	// Free the memory occupied by the linked list
	for nil.next != nil {
		t := nil.next
		nil.next = nil.next.next
		t = nil
	}
}

