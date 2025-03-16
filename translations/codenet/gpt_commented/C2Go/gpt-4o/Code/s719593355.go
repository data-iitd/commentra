package main

import (
	"fmt"
	"strings"
)

// Define a doubly linked list node structure
type Node struct {
	key  uint
	next *Node
	prev *Node
}

var nilNode *Node // Sentinel node to represent the head and tail of the list

// Function prototypes
func listSearch(key int) *Node
func initList()
func printList()
func deleteNode(t *Node)
func deleteFirst()
func deleteLast()
func delete(key int)
func insert(key int)

func main() {
	var key, n int // Variables for key and number of operations
	var size int   // Variable to keep track of the size of the list
	var command string // Variable to hold command strings
	np, nd := 0, 0 // Counters for number of insertions and deletions

	// Read the number of operations to perform
	fmt.Scan(&n)

	// Initialize the doubly linked list
	initList()

	// Loop to process each operation
	for i := 0; i < n; i++ {
		fmt.Scan(&command, &key)

		// If the command is to insert a node
		if command[0] == 'i' {
			insert(key) // Insert the key into the list
			np++        // Increment the insertion counter
			size++      // Increment the size of the list
		} else if command[0] == 'd' { // If the command is to delete a node
			// Check for specific delete commands (delete first or last)
			if len(command) > 6 {
				if command[6] == 'F' {
					deleteFirst() // Delete the first node
				} else if command[6] == 'L' {
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

// Function to search for a node with a specific key
func listSearch(key int) *Node {
	cur := nilNode.next // Start searching from the first node

	// Traverse the list until the end or until the key is found
	for cur != nilNode && cur.key != uint(key) {
		cur = cur.next
	}

	return cur // Return the found node or nilNode if not found
}

// Function to initialize the doubly linked list
func initList() {
	nilNode = &Node{} // Create the sentinel node
	nilNode.next = nilNode // Point next of nilNode to itself
	nilNode.prev = nilNode // Point prev of nilNode to itself
}

// Function to print the contents of the list
func printList() {
	cur := nilNode.next // Start from the first node
	isFirst := true     // Flag to manage spacing between numbers

	// Loop to print each node's key
	for {
		if cur == nilNode {
			break // Stop if we reach the sentinel node
		}
		if !isFirst {
			fmt.Print(" ") // Print space before subsequent numbers
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next     // Move to the next node
		isFirst = false    // Set flag to indicate that the first number has been printed
	}
	fmt.Println() // Print a newline at the end
}

// Function to delete a specific node from the list
func deleteNode(t *Node) {
	t.prev.next = t.next // Bypass the node to be deleted
	t.next.prev = t.prev // Bypass the node to be deleted
}

// Function to delete the first node in the list
func deleteFirst() {
	t := nilNode.next // Get the first node
	if t == nilNode { // Check if the list is empty
		return
	}

	deleteNode(t) // Delete the first node
}

// Function to delete the last node in the list
func deleteLast() {
	t := nilNode.prev // Get the last node
	if t == nilNode { // Check if the list is empty
		return
	}

	deleteNode(t) // Delete the last node
}

// Function to delete a node with a specific key
func delete(key int) {
	t := listSearch(key) // Search for the node with the given key

	if t == nilNode { // If the node is not found, return
		return
	}

	deleteNode(t) // Delete the found node
}

// Function to insert a new node with a specific key at the beginning of the list
func insert(key int) {
	x := &Node{key: uint(key)} // Create a new node

	// Insert the new node at the beginning of the list
	x.next = nilNode.next // Point the new node's next to the current first node
	nilNode.next.prev = x // Update the current first node's previous to point to the new node
	nilNode.next = x      // Update the sentinel's next to point to the new node
	x.prev = nilNode      // Set the new node's previous to the sentinel
}

// <END-OF-CODE>
