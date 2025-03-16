
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

var nil *node // Sentinel node to represent the head and tail of the list

// Function to search for a node with a specific key
func listSearch(key int) *node {
	cur := nil.next // Start from the first node
	for cur != nil { // Traverse until the sentinel node
		if cur.key == key {
			break
		}
		cur = cur.next // Move to the next node
	}
	return cur // Return the found node or sentinel if not found
}

// Function to initialize the linked list
func init() {
	nil = &node{} // Allocate memory for the sentinel node
	nil.next = nil
	nil.prev = nil
}

// Function to print all the keys in the linked list
func printList() {
	cur := nil.next // Start from the first node
	isf := 1        // Flag to manage spacing between numbers
	for {
		if cur == nil {
			break
		} // Stop if we reach the sentinel node
		if isf == 0 {
			fmt.Print(" ") // Print space before the next number if not the first
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next      // Move to the next node
		isf = 0             // Set flag to indicate that we have printed at least one number
	}
	fmt.Println() // Print a new line after printing all keys
}

// Function to delete a specific node from the list
func deleteNode(t *node) {
	if t == nil {
		return
	} // Do nothing if the node is the sentinel
	t.prev.next = t.next
	t.next.prev = t.prev
	t = nil
}

// Function to delete the first node in the list
func deleteFirst() {
	t := nil.next // Get the first node
	if t == nil {
		return
	} // Do nothing if the list is empty
	deleteNode(t) // Delete the first node
}

// Function to delete the last node in the list
func deleteLast() {
	t := nil.prev // Get the last node
	if t == nil {
		return
	} // Do nothing if the list is empty
	deleteNode(t) // Delete the last node
}

// Function to delete a node with a specific key
func deleteKey(key int) {
	t := listSearch(key) // Search for the node with the key
	if t != nil {
		deleteNode(t) // If found, delete the node
	}
}

// Function to insert a new node with a specific key at the beginning of the list
func insert(key int) {
	x := &node{} // Pointer for the new node
	x.key = key  // Set the key of the new node
	x.prev = nil // Set the previous pointer to the sentinel
	x.next = nil.next
	x.next.prev = x
	nil.next = x
}

// Main function to execute the program
func main() {
	var key, n, i int // Variables for key, number of operations, and loop index
	var size int      // Variable to keep track of the size of the list
	var com string    // Array to store command strings
	var np, nd int    // Counters for number of insertions and deletions
	fmt.Scan(&n)      // Read the number of operations
	init()            // Initialize the linked list
	for i = 0; i < n; i++ { // Loop through each operation
		fmt.Scan(&com, &key) // Read the command and key
		if com[0] == 'i' { // If the command is 'insert'
			insert(key)
			np++
			size++
		} else if com[0] == 'd' { // If the command is 'delete'
			if len(com) > 6 { // Check if the command specifies 'First' or 'Last'
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else {
				deleteKey(key)
				nd++
			}
			size--
		}
	}

	printList() // Print the final state of the list
	fmt.Println(np, nd)
}

