package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a doubly linked list node structure
type node struct {
	key  int
	next *node
	prev *node
}

var nil = &node{0, nil, nil}

// Function prototypes
func listSearch(key int) *node
func init()
func printList()
func deleteNode(t *node)
func deleteFirst()
func deleteLast()
func delete(key int)
func insert(key int)

func main() {
	var key, n, i int
	var com string
	var np, nd int
	var size int

	// Read the number of operations to perform
	n, _ = strconv.Atoi(os.Args[1])

	// Initialize the doubly linked list
	init()

	// Loop to process each operation
	for i = 0; i < n; i++ {
		// Read command and key value
		com = strings.Split(os.Args[2+i], " ")[0]
		key, _ = strconv.Atoi(strings.Split(os.Args[2+i], " ")[1])

		// If the command is to insert a node
		if com[0] == 'i' {
			insert(key) // Insert the key into the list
			np++        // Increment the insertion counter
			size++      // Increment the size of the list
		}
		// If the command is to delete a node
		else if com[0] == 'd' {
			// Check for specific delete commands (delete first or last)
			if len(com) > 6 {
				if com[6] == 'F' {
					deleteFirst() // Delete the first node
				} else if com[6] == 'L' {
					deleteLast() // Delete the last node
				}
			} else {
				delete(key) // Delete the node with the specified key
				nd++        // Increment the deletion counter
			}
			size-- // Decrement the size of the list
		}
	}

	// Print the final state of the list
	printList()
}

// Function to search for a node with a specific key
func listSearch(key int) *node {
	cur := nil.next // Start searching from the first node

	// Traverse the list until the end or until the key is found
	for cur!= nil && cur.key!= key {
		cur = cur.next
	}

	return cur // Return the found node or nil if not found
}

// Function to initialize the doubly linked list
func init() {
	nil.next = nil
	nil.prev = nil
}

// Function to print the contents of the list
func printList() {
	cur := nil.next
	isf := 1

	// Loop to print each node's key
	for cur!= nil {
		if isf == 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", cur.key)
		cur = cur.next
		isf = 0
	}
	fmt.Printf("\n")
}

// Function to delete a specific node from the list
func deleteNode(t *node) {
	t.prev.next = t.next
	t.next.prev = t.prev
	free(t)
}

// Function to delete the first node in the list
func deleteFirst() {
	t := nil.next
	if t == nil {
		return
	}

	deleteNode(t)
}

// Function to delete the last node in the list
func deleteLast() {
	t := nil.prev
	if t == nil {
		return
	}

	deleteNode(t)
}

// Function to delete a node with a specific key
func delete(key int) {
	t := listSearch(key)
	if t == nil {
		return
	}

	deleteNode(t)
}

// Function to insert a new node with a specific key at the beginning of the list
func insert(key int) {
	x := new(node)
	x.key = key

	// Insert the new node at the beginning of the list
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
	x.prev = nil
}

