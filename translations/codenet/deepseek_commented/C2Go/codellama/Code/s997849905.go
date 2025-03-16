
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the structure for a node in the circular doubly linked list
type node struct {
	key  int
	next *node
	prev *node
}

// Define a type for a pointer to a node
type nodePointer *node

// Declare a global variable N of type nodePointer
var N nodePointer

// Initialize the circular doubly linked list
func init() {
	N = new(node) // Allocate memory for the sentinel node
	N.next = N    // Set the next pointer of the sentinel node to itself
	N.prev = N    // Set the previous pointer of the sentinel node to itself
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
		snl = 0            // Set the flag to indicate a non-first element
	}
	fmt.Println() // Print a newline at the end
}

// Delete the first node in the circular doubly linked list
func deleteFirst() {
	t := N.next // Store the first node
	N.next = t.next
	t.next.prev = N
	t = nil
}

// Delete the last node in the circular doubly linked list
func deleteLast() {
	delnode := N.prev // Store the last node
	N.prev = delnode.prev
	delnode.prev.next = N
	delnode = nil
}

// Delete a node with a specific key from the circular doubly linked list
func delete(skey int) {
	judge := 0 // Flag to indicate if the key was found
	t := N.next
	n := N.next
	for n != N {
		if n.key == skey {
			judge = 1 // Set the flag if the key is found
		}
		n = n.next
	}

	// If the key is found, remove the node
	if judge == 1 {
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
		n = nil
	}
}

// Insert a new node with a specific key into the circular doubly linked list
func insert(skey int) {
	new := new(node) // Pointer to the new node
	count := 0       // Static variable to track the number of nodes
	new.key = skey   // Set the key of the new node

	// Special case: if the list is empty, set the new node as the only node
	if count == 0 {
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
		count++
	} else {
		new.next = N.next // Set the next pointer of the new node
		N.next.prev = new // Update the previous pointer of the current first node
		N.next = new      // Update the next pointer of the sentinel node
		new.prev = N      // Set the previous pointer of the new node
		count++
	}
}

// Main function to execute the operations on the circular doubly linked list
func main() {
	var key int
	var n int
	var i int
	var com string

	n, _ = strconv.Atoi(os.Args[1]) // Read the number of commands
	init()                          // Initialize the circular doubly linked list
	for i = 0; i < n; i++ {         // Loop through the number of commands
		com = os.Args[2+i] // Read the command
		if strings.Compare(com, "insert") == 0 { // If the command is to insert
			key, _ = strconv.Atoi(os.Args[3+i]) // Read the key to insert
			insert(key)                         // Insert the key into the list
		} else if strings.Compare(com, "deleteFirst") == 0 { // If the command is to delete the first node
			deleteFirst()
		} else if strings.Compare(com, "deleteLast") == 0 { // If the command is to delete the last node
			deleteLast()
		} else { // If the command is to delete a specific node
			key, _ = strconv.Atoi(os.Args[3+i]) // Read the key to delete
			delete(key)                         // Delete the node with the specified key
		}
	}
	printList() // Print the final state of the list
}

