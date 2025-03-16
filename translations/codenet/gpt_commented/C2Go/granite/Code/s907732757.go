
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	key  int
	next *Node
	prev *Node
}

var head *Node

func main() {
	// Initialize the head node of the doubly linked list
	head = &Node{key: 0}
	head.next = head
	head.prev = head

	// Read the number of operations to perform
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[0])
	for i := 0; i < n; i++ {
		// Read the operation command
		op := strings.Split(reader.ReadLine()[0], " ")[0]
		if op == "insert" { // Check if the operation is "insert"
			// Read the value to insert
			a, _ := strconv.Atoi(reader.ReadLine()[0])
			insert(a) // Call insert function
		} else if op == "delete" { // Check if the operation is "delete"
			// Read the value to delete
			a, _ := strconv.Atoi(reader.ReadLine()[0])
			deleteNode(a) // Call delete function
		} else if op == "deleteFirst" { // Check if the operation is "deleteFirst"
			deleteFirst() // Call function to delete the first node
		} else if op == "deleteLast" { // Check if the operation is "deleteLast"
			deleteLast() // Call function to delete the last node
		}
	}

	// Print the remaining elements in the list
	x := head
	for x.next!= head { // Traverse the list until we reach the head again
		fmt.Printf("%d ", x.next.key) // Print the key of the next node
		x = x.next // Move to the next node
	}
	fmt.Println() // Print newline after all elements
}

// Function to create a new node with a given key
func newNode(a int) *Node {
	x := new(Node) // Allocate memory for a new node
	x.key = a // Set the key of the new node
	return x // Return the new node
}

// Function to insert a new node with a given key at the beginning of the list
func insert(a int) {
	x := newNode(a) // Create a new node
	x.next = head.next // Set the new node's next to the current first node
	head.next.prev = x // Update the current first node's previous to the new node
	head.next = x // Update head's next to the new node
	x.prev = head // Set the new node's previous to head
}

// Function to delete a node with a given key from the list
func deleteNode(a int) {
	x := head // Start from the head
	for x.next!= head { // Traverse the list to find the node with the given key
		x = x.next // Move to the next node
		if x.key == a { // Check if the current node's key matches the key to delete
			// Update the pointers to remove the node from the list
			x.prev.next = x.next // Bypass the node to delete it
			x.next.prev = x.prev // Update the previous node's next pointer
			break // Exit the loop after deletion
		}
	}
}

// Function to delete the first node in the list
func deleteFirst() {
	x := head.next // Get the first node
	head.next = x.next // Update head's next to the second node
	x.next.prev = head // Update the new first node's previous to head
}

// Function to delete the last node in the list
func deleteLast() {
	x := head.prev // Get the last node
	head.prev = x.prev // Update head's previous to the second last node
	x.prev.next = head // Update the new last node's next to head
}

// END-OF-CODE