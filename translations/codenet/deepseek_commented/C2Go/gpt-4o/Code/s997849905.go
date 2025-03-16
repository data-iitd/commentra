package main

import (
	"fmt"
	"os"
)

// Define the structure for a node in the circular doubly linked list
type Node struct {
	key  int   // Integer key stored in the node
	next *Node // Pointer to the next node in the list
	prev *Node // Pointer to the previous node in the list
}

// Declare a global variable N of type *Node
var N *Node

// Initialize the circular doubly linked list
func initList() {
	N = &Node{} // Create the sentinel node
	N.next = N  // Set the next pointer of the sentinel node to itself
	N.prev = N  // Set the previous pointer of the sentinel node to itself
}

// Print the elements of the circular doubly linked list
func printList() {
	cur := N.next // Start from the first node
	snl := 1      // Flag to determine if it's the first element
	for cur != N { // Iterate until the sentinel node is reached
		if snl == 0 {
			fmt.Print(" ") // Print a space before non-first elements
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next     // Move to the next node
		snl = 0           // Set the flag to indicate a non-first element
	}
	fmt.Println() // Print a newline at the end
}

// Delete the first node in the circular doubly linked list
func deleteFirst() {
	t := N.next // Store the first node
	N.next = t.next // Update the next pointer of the sentinel node
	t.next.prev = N // Update the previous pointer of the new first node
	free(t) // Free the memory of the deleted node
}

// Delete the last node in the circular doubly linked list
func deleteLast() {
	delnode := N.prev // Store the last node
	N.prev = delnode.prev // Update the previous pointer of the sentinel node
	delnode.prev.next = N // Update the next pointer of the new last node
	free(delnode) // Free the memory of the deleted node
}

// Delete a node with a specific key from the circular doubly linked list
func delete(skey int) {
	judge := 0 // Flag to indicate if the key was found
	var t, n *Node // Temporary pointers for node traversal and search

	// Iterate through the list to find the node with the specified key
	for n = N.next; n != N; n = n.next {
		if n.key == skey {
			judge = 1 // Set the flag if the key is found
			break
		}
	}

	// If the key is found, remove the node
	if judge == 1 {
		t = n.prev
		t.next = n.next
		t.next.prev = t
		free(n)
	}
}

// Insert a new node with a specific key into the circular doubly linked list
func insert(skey int) {
	newNode := &Node{key: skey} // Create the new node
	staticCount := 0 // Variable to track the number of nodes

	// Special case: if the list is empty, set the new node as the only node
	if staticCount == 0 {
		newNode.next = N
		N.next = newNode
		newNode.prev = N
		N.prev = newNode
		staticCount++
	} else {
		newNode.next = N.next // Set the next pointer of the new node
		N.next.prev = newNode // Update the previous pointer of the current first node
		N.next = newNode      // Update the next pointer of the sentinel node
		newNode.prev = N      // Set the previous pointer of the new node
		staticCount++
	}
}

// Free the memory of the node (simulated, as Go has garbage collection)
func free(node *Node) {
	// In Go, we don't need to explicitly free memory, but we can set the node to nil
	node = nil
}

// Main function to execute the operations on the circular doubly linked list
func main() {
	var key, n int
	var com string // Variable to store the command

	fmt.Scan(&n) // Read the number of commands
	initList()   // Initialize the circular doubly linked list
	for i := 0; i < n; i++ { // Loop through the number of commands
		fmt.Scan(&com) // Read the command
		switch com {
		case "insert": // If the command is to insert
			fmt.Scan(&key) // Read the key to insert
			insert(key)    // Insert the key into the list
		case "deleteFirst": // If the command is to delete the first node
			deleteFirst()
		case "deleteLast": // If the command is to delete the last node
			deleteLast()
		default: // If the command is to delete a specific node
			fmt.Scan(&key) // Read the key to delete
			delete(key)    // Delete the node with the specified key
		}
	}
	printList() // Print the final state of the list
}

// <END-OF-CODE>
