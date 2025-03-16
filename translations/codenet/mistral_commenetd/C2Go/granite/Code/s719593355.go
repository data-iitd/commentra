

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a node in the linked list
type Node struct {
	key  int
	next *Node
	prev *Node
}

// Define a type for a pointer to a node
type NodePointer *Node

// Initialize the linked list with a nil node
var nil *Node

// Function to search for a node with a given key in the list
func listSearch(key int) NodePointer {
	cur := nil.next // Initialize a pointer to the first node in the list

	// Search for the node with the given key
	for cur!= nil && cur.key!= key {
		cur = cur.next
	}

	// Return the found node or nil if not found
	return cur
}

// Initialize the linked list with a nil node
func init() {
	nil = &Node{} // Allocate memory for the nil node
	nil.next = nil // Set the next pointer of the nil node to itself
	nil.prev = nil // Set the prev pointer of the nil node to itself
}

// Print the contents of the linked list
func printList() {
	cur := nil.next // Initialize a pointer to the first node in the list
	isf := true       // Flag to indicate if this is the first node to be printed

	// Traverse the list and print each node
	for {
		if cur == nil {
			break // If we have reached the end of the list, exit the loop
		}
		if isf == false {
			fmt.Print(" ") // If this is not the first node, print a space before the key
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next    // Move to the next node
		isf = false         // Reset the flag for the next iteration
	}
	fmt.Println() // Print a newline at the end
}

// Delete a node from the linked list
func deleteNode(t *Node) {
	t.prev.next = t.next // Set the next pointer of the previous node to the next node of the node to be deleted
	t.next.prev = t.prev // Set the prev pointer of the next node to the previous node of the node to be deleted
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
	x := &Node{} // Allocate memory for the new node

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
	var n, i, key, np, nd int // Declare variables to store the number of commands, the current command, and a counter
	var com string              // Declare a variable to store the command as a string
	var size int                // Initialize a variable to store the current size of the list

	// Read the number of commands from standard input
	fmt.Scan(&n)

	// Initialize the linked list
	init()

	// Process each command in the input
	for i = 0; i < n; i++ {
		fmt.Scan(&com, &key) // Read the command and the key (if any) from standard input

		// If the command is an insert command, increment the np counter and insert the key into the list
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		}

		// If the command is a delete command, increment the nd counter and delete the node with the given key from the list
		else if com[0] == 'd' {
			if len(com) > 6 { // If the command is a delete first or delete last command, process it accordingly
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else { // If the command is a delete command with a key, delete the node with the given key from the list
				delete(key)
			}
			nd++ // Increment the nd counter
			size-- // Decrement the size of the list after the delete operation
		}
	}

	// Print the final size of the list and the number of insert and delete operations
	fmt.Printf("Size: %d, Number of insert operations: %d, Number of delete operations: %d\n", size, np, nd)
}

Translate the above Go code to Python and end with comment "