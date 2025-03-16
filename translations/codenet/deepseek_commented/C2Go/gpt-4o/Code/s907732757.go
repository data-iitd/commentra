package main

import (
	"fmt"
	"strings"
)

// Define the structure for a node in the doubly linked list
type Node struct {
	key  int   // The value stored in the node
	next *Node // Pointer to the next node
	prev *Node // Pointer to the previous node
}

var head *Node // Global pointer to the head of the doubly linked list

// Function to create a new node with the given key
func makeNode(a int) *Node {
	return &Node{key: a}
}

// Function to insert a new node with the given key after the head node
func insert(a int) {
	x := makeNode(a) // Create a new node
	x.next = head.next // Set the next pointer of the new node to the current head->next
	head.next.prev = x // Set the prev pointer of the current head->next to the new node
	head.next = x // Set the next pointer of the head to the new node
	x.prev = head // Set the prev pointer of the new node to the head
}

// Function to delete the node with the given key
func delete(a int) {
	x := head

	// Traverse the list to find the node with the given key
	for x.next != head {
		x = x.next
		if x.key == a {
			x.prev.next = x.next // Update the next pointer of the previous node
			x.next.prev = x.prev // Update the prev pointer of the next node
			break // Exit the loop after deleting the node
		}
	}
}

// Function to delete the first node after the head node
func deleteFirst() {
	x := head.next // Get the first node
	head.next = x.next // Update the next pointer of the head to the node after the first node
	x.next.prev = head // Update the prev pointer of the node after the first node to the head
}

// Function to delete the last node before the head node
func deleteLast() {
	x := head.prev // Get the last node
	head.prev = x.prev // Update the prev pointer of the head to the node before the last node
	x.prev.next = head // Update the next pointer of the node before the last node to the head
}

// Main function
func main() {
	var n, a int
	var op string

	// Initialize the head node
	head = makeNode(0)
	head.next = head
	head.prev = head

	// Read the number of operations
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		// Read the operation type
		fmt.Scan(&op)
		if op == "insert" {
			// Read the value to insert
			fmt.Scan(&a)
			insert(a)
		} else if op == "delete" {
			// Read the value to delete
			fmt.Scan(&a)
			delete(a)
		} else if op == "deleteFirst" {
			deleteFirst()
		} else if op == "deleteLast" {
			deleteLast()
		}
	}

	// Print the list
	x := head
	var output []string
	for x.next != head {
		x = x.next
		output = append(output, fmt.Sprintf("%d", x.key))
	}
	fmt.Println(strings.Join(output, " "))
}

// <END-OF-CODE>
