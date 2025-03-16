
package main

import (
	"fmt"
	"os"
	"strconv"
)

// Define the structure for a node in the doubly linked list
type node struct {
	key  int
	next *node
	prev *node
}

// Type alias for a pointer to a node
type NodePointer *node

// Sentinel node (dummy node) for the doubly linked list
var nil *node

// Function to search for a node with a given key
func listSearch(key int) NodePointer {
	cur := nil.next // Start from the first node
	for cur != nil { // Traverse the list until we reach the sentinel node
		if cur.key == key {
			break
		}
		cur = cur.next // Move to the next node
	}
	return cur // Return the node with the matching key, or nil if not found
}

// Function to initialize the doubly linked list with a sentinel node
func init() {
	nil = &node{} // Allocate memory for the sentinel node
	nil.next = nil
	nil.prev = nil
}

// Function to print the entire list starting from the first node
func printList() {
	cur := nil.next // Start from the first node
	isf := 1        // Flag to check if it's the first node to be printed
	for {
		if cur == nil {
			break
		} // If we reach the sentinel node, break the loop
		if isf == 0 {
			fmt.Print(" ")
		} // Print a space before each key except the first
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next      // Move to the next node
		isf = 0             // Update the flag to indicate that a node has been printed
	}
	fmt.Println() // Print a newline character at the end
}

// Function to delete a specified node from the list
func deleteNode(t NodePointer) {
	if t == nil {
		return
	} // If the node is the sentinel node, do nothing
	t.prev.next = t.next
	t.next.prev = t.prev
	t = nil
}

// Function to delete the first node in the list
func deleteFirst() {
	t := nil.next // Get the first node
	if t == nil {
		return
	} // If the list is empty, do nothing
	deleteNode(t) // Delete the first node
}

// Function to delete the last node in the list
func deleteLast() {
	t := nil.prev // Get the last node
	if t == nil {
		return
	} // If the list is empty, do nothing
	deleteNode(t) // Delete the last node
}

// Function to delete the node with a specified key
func deleteKey(key int) {
	t := listSearch(key) // Find the node with the specified key
	if t != nil {
		deleteNode(t) // If the node is found, delete it
	}
}

// Function to insert a new node with a specified key at the beginning of the list
func insert(key int) {
	x := &node{} // Allocate memory for the new node
	x.key = key  // Set the key of the new node
	x.prev = nil // The prev pointer of the new node points to the sentinel node
	x.next = nil.next
	x.next.prev = x
	nil.next = x // Update the next pointer of the sentinel node to the new node
}

// Main function to read commands and manipulate the doubly linked list
func main() {
	var key, n, i int
	var size int = 0 // Variable to keep track of the size of the list
	var com string
	var np, nd int // Counters for insertions and deletions
	fmt.Scan(&n) // Read the number of commands
	init()       // Initialize the list
	for i = 0; i < n; i++ {
		fmt.Scan(&com, &key) // Read the command and the key
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		} // Insert a new node if the command is 'i'
		else if com[0] == 'd' {
			if len(com) > 6 { // Check if the command is to delete the first or last node
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else {
				deleteKey(key)
				nd++
			} // Delete the node with the specified key
			size-- // Decrease the size of the list
		}
	}

	printList() // Print the final state of the list
	fmt.Println(np, nd) // Print the number of insertions and deletions
	os.Exit(0) // Return 0 to indicate successful execution
}

