package main

import (
	"fmt"
	"strings"
)

// Define the structure for a node in the circular doubly linked list
type Node struct {
	key  int
	next *Node
	prev *Node
}

// Define a type for a pointer to a node
type NodePointer *Node

// Declare a global variable N of type NodePointer
var N NodePointer

// Initialize the circular doubly linked list
func init() {
	N = &Node{key: 0} // Allocate memory for the sentinel node
	N.next = N       // Set the next pointer of the sentinel node to itself
	N.prev = N       // Set the previous pointer of the sentinel node to itself
}

// Print the elements of the circular doubly linked list
func printList() {
	cur := N.next // Start from the first node
	snl := true   // Flag to determine if it's the first element
	for cur != N { // Iterate until the sentinel node is reached
		if !snl {
			fmt.Print(" ") // Print a space before non-first elements
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next     // Move to the next node
		snl = false        // Set the flag to indicate a non-first element
	}
	fmt.Println() // Print a newline at the end
}

// Delete the first node in the circular doubly linked list
func deleteFirst() {
	t := N.next // Store the first node
	N.next = t.next // Update the next pointer of the sentinel node
	t.next.prev = N // Update the previous pointer of the new first node
}

// Delete the last node in the circular doubly linked list
func deleteLast() {
	delnode := N.prev // Store the last node
	N.prev = delnode.prev // Update the previous pointer of the sentinel node
	delnode.prev.next = N // Update the next pointer of the new last node
}

// Delete a node with a specific key from the circular doubly linked list
func delete(skey int) {
	judge := false // Flag to indicate if the key was found
	var t *Node
	var n *Node

	// Iterate through the list to find the node with the specified key
	for n = N.next; n != N; n = n.next {
		if n.key == skey {
			judge = true // Set the flag if the key is found
		}
	}

	// If the key is found, remove the node
	if judge {
		n = N.next
		for n != N {
			if n.key == skey {
				break
			}
			n = n.next
		}
		t = n.prev
		t.next = n.next
		t.next.prev = t
		n = nil // Set the node to nil to be garbage collected
	}
}

// Insert a new node with a specific key into the circular doubly linked list
func insert(skey int) {
	new := &Node{key: skey} // Pointer to the new node
	staticCount := 0 // Static variable to track the number of nodes

	// Special case: if the list is empty, set the new node as the only node
	if staticCount == 0 {
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
		staticCount++
	} else {
		new.next = N.next // Set the next pointer of the new node
		N.next.prev = new // Update the previous pointer of the current first node
		N.next = new       // Update the next pointer of the sentinel node
		new.prev = N       // Set the previous pointer of the new node
		staticCount++
	}
}

// Main function to execute the operations on the circular doubly linked list
func main() {
	var key int
	var n, i int
	var com string // String to store the command

	fmt.Scan(&n) // Read the number of commands
	init() // Initialize the circular doubly linked list
	for i = 0; i < n; i++ { // Loop through the number of commands
		fmt.Scan(&com) // Read the command
		if strings.Compare(com, "insert") == 0 { // If the command is to insert
			fmt.Scan(&key) // Read the key to insert
			insert(key) // Insert the key into the list
		} else if strings.Compare(com, "deleteFirst") == 0 { // If the command is to delete the first node
			deleteFirst()
		} else if strings.Compare(com, "deleteLast") == 0 { // If the command is to delete the last node
			deleteLast()
		} else { // If the command is to delete a specific node
			fmt.Scan(&key) // Read the key to delete
			delete(key) // Delete the node with the specified key
		}
	}
	printList() // Print the final state of the list
}

