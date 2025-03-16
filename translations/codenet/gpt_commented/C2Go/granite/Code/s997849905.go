
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a doubly linked list node
type Node struct {
	key  int
	next *Node
	prev *Node
}

// Define a pointer type for the node structure
type NodePointer *Node

var N NodePointer // Head of the doubly linked list

// Function to initialize the doubly linked list
func init() {
	N = new(Node) // Allocate memory for the head node
	N.next = N     // Point next of head to itself (circular)
	N.prev = N     // Point prev of head to itself (circular)
}

// Function to print the elements of the list
func printList() {
	cur := N.next // Start from the first node
	snl := 1       // Flag to manage spacing
	for cur!= N { // Traverse until we reach the head again
		if snl == 0 {
			fmt.Print(" ") // Print space before the next number
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next    // Move to the next node
		snl = 0              // Set flag to indicate that we have printed at least one element
	}
	fmt.Println() // Print a newline after the list
}

// Function to delete the first node in the list
func deleteFirst() {
	t := N.next // Node to be deleted (first node)
	N.next = t.next
	t.next.prev = N // Update the new first node's prev to head
}

// Function to delete the last node in the list
func deleteLast() {
	delnode := N.prev // Node to be deleted (last node)
	N.prev = delnode.prev
	delnode.prev.next = N // Update the new last node's next to head
	os.Free(delnode)       // Free the memory of the deleted node
}

// Function to delete a node with a specific key
func delete(skey int) {
	judge := 0 // Flag to check if the key exists
	n := N.next
	for n!= N { // Traverse the list to check if the key exists
		if n.key == skey {
			judge = 1 // Key found
		}
		n = n.next
	}
	if judge == 1 { // If the key exists, proceed to delete the node
		n = N.next
		for n!= N { // Traverse until we find the key
			if n.key == skey {
				break // Break if key is found
			}
			n = n.next
		}
		t := n.prev // Get the previous node
		t.next = n.next
		t.next.prev = t // Update the next node's prev pointer
		os.Free(n)       // Free the memory of the deleted node
	}
}

// Function to insert a new node with a specific key
func insert(skey int) {
	new := new(Node) // Pointer for the new node
	static count := 0 // Static variable to track the number of nodes
	new.key = skey    // Set the key of the new node
	if count == 0 {   // If this is the first node being inserted
		new.next = N // Point new node's next to head
		N.next = new // Update head's next to new node
		new.prev = N // Point new node's prev to head
		N.prev = new // Update head's prev to new node
		count++       // Increment the count of nodes
	} else {          // If there are already nodes in the list
		new.next = N.next // Point new node's next to the first node
		N.next.prev = new // Update the first node's prev to new node
		N.next = new       // Update head's next to new node
		new.prev = N        // Point new node's prev to head
		count++              // Increment the count of nodes
	}
}

// Main function to execute the program
func main() {
	var n, i int // Variables for number of operations and loop index
	var key int
	var com string
	reader := bufio.NewReader(os.Stdin)
	fmt.Scan(&n) // Read the number of operations
	init()       // Initialize the doubly linked list
	for i = 0; i < n; i++ { // Loop through each operation
		com, _ = reader.ReadString('\n') // Read the command
		com = strings.TrimSpace(com)
		if com == "insert" { // Check if command is 'insert'
			fmt.Scan(&key) // Read the key to insert
			insert(key)    // Call insert function
		} else if com == "deleteFirst" { // Check if command is 'deleteFirst'
			deleteFirst() // Call deleteFirst function
		} else if com == "deleteLast" { // Check if command is 'deleteLast'
			deleteLast()  // Call deleteLast function
		} else { // If command is 'delete'
			fmt.Scan(&key) // Read the key to delete
			delete(key)    // Call delete function
		}
	}
	printList() // Print the final state of the list
}

