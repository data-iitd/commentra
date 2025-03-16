
package main

import (
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

// Typedef a NodePointer as a pointer to a node
type NodePointer *node

// Initialize a pointer to the first node
var N NodePointer

// Initialize the linked list
func init() {
	N = new(node)
	N.next = N
	N.prev = N
}

// Print the contents of the linked list
func printList() {
	cur := N.next // Initialize a pointer to traverse the list
	snl := 1      // Set a flag to control the printing of spaces between numbers
	for cur != N { // Traverse the list until the end is reached
		if snl == 0 { // If a space is not required before the number, print a space
			fmt.Print(" ")
		}
		fmt.Print(cur.key) // Print the key value of the current node
		cur = cur.next      // Move to the next node
		snl = 0             // Reset the flag for the next iteration
	}
	fmt.Println() // Print a newline at the end
}

// Delete the first node from the list
func deleteFirst() {
	t := N.next // Initialize a pointer to the second node
	N.next = t.next
	t.next.prev = N
}

// Delete the last node from the list
func deleteLast() {
	delnode := N.prev // Initialize a pointer to the second last node
	N.prev = delnode.prev
	delnode.prev.next = N
	delnode = nil
}

// Delete a node with the given key from the list
func delete(skey int) {
	judge := 0 // Initialize a flag to check if the node to be deleted exists
	t, n := N.next, N.next
	for n != N { // Traverse the list to find the node to be deleted
		if n.key == skey { // If the key matches, set the flag
			judge = 1
			break
		}
		t = n
		n = n.next
	}

	if judge == 1 { // If the node exists, delete it
		n = t.next
		t.next = n.next
		t.next.prev = t
		n = nil
	}
}

// Insert a new node with the given key into the list
func insert(skey int) {
	new := new(node) // Allocate memory for the new node
	new.key = skey   // Set the key value of the new node

	if N.next == N { // If the list is empty, initialize the first node
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
	} else { // If the list is not empty, insert the new node at the end
		new.next = N.next
		N.next.prev = new
		N.next = new
		new.prev = N
	}
}

// Main function to read commands and perform the corresponding operations
func main() {
	var n, i int
	var key int
	var com string

	n, _ = strconv.Atoi(os.Args[1]) // Read the number of operations to be performed
	init()                          // Initialize the linked list

	for i = 0; i < n; i++ { // Perform each operation in the loop
		com = os.Args[2+i] // Read the command string
		if com == "insert" {
			key, _ = strconv.Atoi(os.Args[2+n+i])
			insert(key)
		} else if com == "deleteFirst" {
			deleteFirst() // If the command is to delete the first node
		} else if com == "deleteLast" {
			deleteLast() // If the command is to delete the last node
		} else { // If the command is to delete a node with a given key
			key, _ = strconv.Atoi(os.Args[2+n+i])
			delete(key)
		}
	}
	printList() // Print the updated list after performing all the operations
}

