package main

import (
	"fmt"
	"strings"
)

// Define a structure for a node in the linked list
type Node struct {
	key  uint
	next *Node
	prev *Node
}

// Initialize the linked list with a nil node
var nilNode *Node

// Function to search for a node with a given key in the list
func listSearch(key int) *Node {
	cur := nilNode.next // Initialize a pointer to the first node in the list

	// Search for the node with the given key
	for cur != nilNode && cur.key != uint(key) {
		cur = cur.next
	}

	// Return the found node or nil if not found
	return cur
}

// Initialize the linked list with a nil node
func initList() {
	nilNode = &Node{} // Create the nil node
	nilNode.next = nilNode // Set the next pointer of the nil node to itself
	nilNode.prev = nilNode // Set the prev pointer of the nil node to itself
}

// Print the contents of the linked list
func printList() {
	cur := nilNode.next // Initialize a pointer to the first node in the list
	isFirst := true     // Flag to indicate if this is the first node to be printed

	// Traverse the list and print each node
	for {
		if cur == nilNode {
			break // If we have reached the end of the list, exit the loop
		}
		if !isFirst {
			fmt.Print(" ") // If this is not the first node, print a space before the key
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next     // Move to the next node
		isFirst = false    // Reset the flag for the next iteration
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
	t := nilNode.next // Initialize a pointer to the first node in the list

	// If the list is empty, return
	if t == nilNode {
		return
	}

	// Delete the first node
	deleteNode(t)
}

// Delete and free the last node in the list
func deleteLast() {
	t := nilNode.prev // Initialize a pointer to the last node in the list

	// If the list is empty, return
	if t == nilNode {
		return
	}

	// Delete the last node
	deleteNode(t)
}

// Delete a node with the given key from the list
func delete(key int) {
	t := listSearch(key) // Search for the node with the given key

	// If the node is not found, return
	if t == nilNode {
		return
	}

	// Delete the node
	deleteNode(t)
}

// Allocate memory for a new node and insert it into the list
func insert(key int) {
	x := &Node{key: uint(key)} // Allocate memory for the new node

	// Insert the new node at the end of the list
	x.next = nilNode.next
	nilNode.next.prev = x
	nilNode.next = x
	x.prev = nilNode
}

// Main function to read commands from standard input and perform the corresponding actions
func main() {
	var key, n, np, nd int // Declare variables to store the number of commands, the current command, and counters
	size := 0              // Initialize a variable to store the current size of the list

	// Read the number of commands from standard input
	fmt.Scan(&n)

	// Initialize the linked list
	initList()

	// Process each command in the input
	for i := 0; i < n; i++ {
		var com string
		fmt.Scan(&com, &key) // Read the command and the key (if any) from standard input

		// If the command is an insert command, increment the np counter and insert the key into the list
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		} else if com[0] == 'd' { // If the command is a delete command
			if len(com) > 6 { // If the command is a delete first or delete last command, process it accordingly
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
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
	for nilNode.next != nilNode {
		t := nilNode.next
		nilNode.next = nilNode.next.next
	}

	// Note: In Go, memory management is handled by the garbage collector, so explicit freeing is not necessary.
}

// <END-OF-CODE>
