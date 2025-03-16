<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the structure for a node in the doubly linked list
type node struct {
	key  int
	next *node
	prev *node
}

var head *node

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
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		// Read the operation type
		fmt.Scanf("%s", &op)
		if op == "insert" {
			// Read the value to insert
			fmt.Scanf("%d", &a)
			insert(a)
		} else if op == "delete" {
			// Read the value to delete
			fmt.Scanf("%d", &a)
			delete(a)
		} else if op == "deleteFirst" {
			deleteFirst()
		} else if op == "deleteLast" {
			deleteLast()
		}
	}

	// Print the list
	x = head
	for x.next!= head {
		fmt.Printf("%d", x.next.key)
		x = x.next
		if x.next!= head {
			fmt.Printf(" ")
		}
	}
	fmt.Printf("\n")
}

// Function to create a new node with the given key
func makenode(a int) *node {
	x := new(node) // Allocate memory for the new node
	x.key = a      // Set the key of the new node
	x.next = nil   // Initialize next pointer to NULL
	x.prev = nil   // Initialize prev pointer to NULL
	return x       // Return the pointer to the new node
}

// Function to insert a new node with the given key after the head node
func insert(a int) {
	x := makenode(a) // Create a new node
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

// Function to delete the node with the given key
func delete(a int) {
	x := head
	for x.next!= head {
		x = x.next
		if x.key == a {
			x.prev.next = x.next
			x.next.prev = x.prev
			free(x)
			break
		}
	}
}

// Function to delete the first node after the head node
func deleteFirst() {
	x := head.next
	head.next = x.next
	x.next.prev = head
	free(x)
}

// Function to delete the last node before the head node
func deleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
	free(x)
}

