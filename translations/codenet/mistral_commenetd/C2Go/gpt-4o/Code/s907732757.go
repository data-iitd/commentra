package main

import (
	"fmt"
	"strings"
)

type Node struct {
	key  int
	next *Node
	prev *Node
}

var head *Node // Initialize head pointer to nil

func makeNode(a int) *Node {
	x := &Node{key: a} // Create a new node
	return x          // Return the new node
}

// Initialize the head node with a dummy node
func initList() {
	head = makeNode(0)
	head.next = head
	head.prev = head
}

func insert(a int) {
	x := makeNode(a) // Allocate memory for new node

	// Insert new node at the end of the list
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

func delete(a int) {
	x := head

	// Search for the node to be deleted
	for x.next != head {
		x = x.next
		if x.key == a { // Found the node to be deleted
			prev := x.prev // Save the previous node
			prev.next = x.next // Update the previous node's next pointer
			x.next.prev = prev // Update the next node's prev pointer
			break
		}
	}
}

func deleteFirst() {
	x := head.next // Save the second node in a temporary variable

	// Update the head pointer and the previous node's next pointer
	head.next = x.next
	x.next.prev = head

	// Free the memory occupied by the first node (handled by Go's garbage collector)
}

func deleteLast() {
	x := head

	// Search for the second last node
	for x.next != head {
		x = x.next
	}

	prev := x.prev // Save the previous node

	// Update the previous node's next pointer
	prev.next = head
	head.prev = prev

	// Free the memory occupied by the last node (handled by Go's garbage collector)
}

func main() {
	var n, a int
	var op string

	initList() // Initialize the head node

	fmt.Scan(&n) // Read the number of operations

	for i := 0; i < n; i++ {
		fmt.Scan(&op) // Read the operation

		if op == "insert" { // If the operation is to insert a node
			fmt.Scan(&a) // Read the key value of the node to be inserted
			insert(a) // Call the insert function
		} else if op == "delete" { // If the operation is to delete a node
			fmt.Scan(&a) // Read the key value of the node to be deleted
			delete(a) // Call the delete function
		} else if op == "deleteFirst" { // If the operation is to delete the first node
			deleteFirst() // Call the deleteFirst function
		} else if op == "deleteLast" { // If the operation is to delete the last node
			deleteLast() // Call the deleteLast function
		}
	}

	x := head // Initialize a pointer to traverse the list

	for x.next != head { // Traverse the list and print the keys of the nodes
		fmt.Printf("%d ", x.next.key)
		x = x.next
	}

	fmt.Println() // Print a newline character at the end
}

// <END-OF-CODE>
