package main

import (
	"fmt"
	"unsafe"
)

// Define a structure for a node in the linked list
type Node struct {
	Key  int
	Next *Node
	Prev *Node
}

// Define a typedef for a pointer to a node
type NodePointer *Node

// Initialize the linked list with a nil node
var nil *Node

// Function to search for a node with a given key in the list
func listSearch(key int) NodePointer {
	cur := nil.Next // Initialize a pointer to the first node in the list

	// Search for the node with the given key
	for cur != nil && cur.Key != key {
		cur = cur.Next
	}

	// Return the found node or nil if not found
	return cur
}

// Initialize the linked list with a nil node
func init() {
	nil = &Node{} // Allocate memory for the nil node
	nil.Next = nil
	nil.Prev = nil
}

// Print the contents of the linked list
func printList() {
	cur := nil.Next // Initialize a pointer to the first node in the list
	isf := true     // Flag to indicate if this is the first node to be printed

	// Traverse the list and print each node
	for {
		if cur == nil {
			break // If we have reached the end of the list, exit the loop
		}
		if !isf {
			fmt.Print(" ") // If this is not the first node, print a space before the key
		}
		fmt.Print(cur.Key) // Print the key of the current node
		cur = cur.Next     // Move to the next node
		isf = false        // Reset the flag for the next iteration
	}
	fmt.Println() // Print a newline at the end
}

// Delete a node from the linked list
func deleteNode(t NodePointer) {
	t.Prev.Next = t.Next // Set the next pointer of the previous node to the next node of the node to be deleted
	t.Next.Prev = t.Prev // Set the prev pointer of the next node to the previous node of the node to be deleted
}

// Delete and free the first node in the list
func deleteFirst() {
	t := nil.Next // Initialize a pointer to the first node in the list

	// If the list is empty, return
	if t == nil {
		return
	}

	// Delete and free the first node
	deleteNode(t)
}

// Delete and free the last node in the list
func deleteLast() {
	t := nil.Prev // Initialize a pointer to the last node in the list

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
	x := &Node{Key: key} // Allocate memory for the new node

	// Insert the new node at the end of the list
	x.Next = nil.Next
	nil.Next.Prev = x
	nil.Next = x
	x.Prev = nil
}

// Main function to read commands from standard input and perform the corresponding actions
func main() {
	var n, i int
	var key int
	var com string
	var size int
	var np, nd int

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
		if com[0] == 'd' {
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
	for nil.Next != nil {
		t := nil.Next
		nil.Next = nil.Next.Next
		free(unsafe.Pointer(t))
	}
}

