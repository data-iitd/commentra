

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a node
type node struct {
	key  int
	next *node
	prev *node
}

// Typedef a NodePointer as a pointer to the node structure
type NodePointer *node

// Initialize nil node with NULL pointers
var nil = (*node)(nil)

// Function to search a node with given key
func listSearch(key int) NodePointer {
	cur := nil.next // Initialize current node as the first node after nil
	for cur!= nil { // Traverse the list until nil is reached
		if cur.key == key {
			break // If the current node's key matches the given key, break the loop
		}
		cur = cur.next // Move to the next node
	}
	return cur // Return the found node or nil if not found
}

// Initialize the linked list with a nil node
func init() {
	nil = new(node) // Allocate memory for the nil node
	nil.next = nil // Initialize next pointer of nil to itself
	nil.prev = nil // Initialize prev pointer of nil to itself
}

// Function to print the linked list
func printList() {
	cur := nil.next // Initialize current node as the first node after nil
	isf := true       // Initialize isFirst flag to true
	for { // Traverse the list until nil is reached
		if cur == nil {
			break // If the current node is nil, break the loop
		}
		if isf {
			fmt.Printf("[%d] ", cur.key) // If it's the first node, print its key with an index
		} else {
			fmt.Printf(" %d", cur.key) // Otherwise, print only the key
		}
		cur = cur.next // Move to the next node
		isf = false      // Set isFirst flag to false
	}
	fmt.Println() // Print a newline after the list is printed
}

// Function to delete a node from the linked list
func deleteNode(t NodePointer) {
	if t == nil {
		return // Return if the node to be deleted is nil
	}
	t.prev.next = t.next // Update the next pointer of the previous node to point to the next node
	t.next.prev = t.prev // Update the prev pointer of the next node to point to the previous node
	t = nil               // Set the deleted node to nil
}

// Function to delete the first node from the linked list
func deleteFirst() {
	t := nil.next // Initialize the node to be deleted as the first node
	if t == nil {
		return // Return if the list is empty
	}
	deleteNode(t) // Delete the first node
}

// Function to delete the last node from the linked list
func deleteLast() {
	t := nil.prev // Initialize the node to be deleted as the last node
	if t == nil {
		return // Return if the list is empty
	}
	deleteNode(t) // Delete the last node
}

// Function to delete a node with the given key from the linked list
func deleteKey(key int) {
	t := listSearch(key) // Search for the node with the given key
	if t!= nil {
		deleteNode(t) // Delete the node if it's found
	}
}

// Function to insert a new node with the given key into the linked list
func insert(key int) {
	x := new(node) // Allocate memory for the new node
	x.key = key     // Set the key value of the new node
	x.prev = nil   // Set the prev pointer of the new node to nil
	x.next = nil.next
	nil.next.prev = x // Update the prev pointer of the first node after nil to point to the new node
	nil.next = x      // Update the next pointer of nil to point to the new node
}

// Main function to read commands and perform the corresponding actions
func main() {
	var key, n, i int // Initialize variables for reading commands and list size
	var size, np, nd int // Initialize the current size of the list and counters for number of insertions and deletions
	var com string // Initialize a string to store the command
	fmt.Scan(&n) // Read the number of commands
	init() // Initialize the linked list
	for i = 0; i < n; i++ { // Traverse the commands
		fmt.Scanf("%s%d", &com, &key) // Read the command and the key value
		if com[0] == 'i' { // If the command is 'i', insert a new node
			insert(key)
			np++
			size++
		} else if com[0] == 'd' { // If the command is 'd', delete a node
			if len(com) > 6 { // If the command is 'd F' or 'd L', delete the first or last node
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else { // Otherwise, delete a node with the given key
				deleteKey(key)
				nd++
			}
			size--
		}
	}
	printList() // Print the updated linked list
}

Translate the above Go code to Python and end with comment "