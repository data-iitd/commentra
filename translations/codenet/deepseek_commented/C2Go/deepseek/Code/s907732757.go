package main

import (
	"fmt"
	"strings"
)

// Define the structure for a node in the doubly linked list
type node struct {
	key  int
	next *node
	prev *node
}

var head *node // Global pointer to the head of the doubly linked list

// Function prototypes
func makenode(a int) *node
func insert(a int)
func delete(a int)
func deleteFirst()
func deleteLast()

func main() {
	var i, n, a int
	var op string
	var x *node

	// Initialize the head node
	head = makenode(0)
	head.next = head
	head.prev = head

	// Read the number of operations
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
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
	x = head
	for x.next != head {
		fmt.Print(x.next.key)
		x = x.next
		if x.next != head {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

// Function to create a new node with the given key
func makenode(a int) *node {
	x := &node{key: a}
	x.next = nil
	x.prev = nil
	return x
}

// Function to insert a new node with the given key after the head node
func insert(a int) {
	x := makenode(a)
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

// Function to delete the node with the given key
func delete(a int) {
	x := head

	// Traverse the list to find the node with the given key
	for x.next != head {
		x = x.next
		if x.key == a {
			x.prev.next = x.next
			x.next.prev = x.prev
			break
		}
	}
}

// Function to delete the first node after the head node
func deleteFirst() {
	x := head.next
	head.next = x.next
	x.next.prev = head
}

// Function to delete the last node before the head node
func deleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
}

