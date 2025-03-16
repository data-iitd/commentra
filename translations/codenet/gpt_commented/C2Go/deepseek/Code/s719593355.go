package main

import (
	"fmt"
	"strconv"
)

// Define a doubly linked list node structure
type Node struct {
	key  int
	next *Node
	prev *Node
}

// Define a pointer type for node
type NodePointer *Node

var nil *Node // Sentinel node to represent the head and tail of the list

// Function prototypes
func listSearch(key int) *Node
func init()
func printList()
func deleteNode(t *Node)
func deleteFirst()
func deleteLast()
func delete(key int)
func insert(key int)

func main() {
	var key, n, i int
	var size int = 0
	var com string
	var np, nd int = 0, 0

	// Read the number of operations to perform
	fmt.Scan(&n)

	// Initialize the doubly linked list
	init()

	// Loop to process each operation
	for i = 0; i < n; i++ {
		// Read command and key value
		fmt.Scan(&com, &key)

		// If the command is to insert a node
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		}
		// If the command is to delete a node
		else if com[0] == 'd' {
			// Check for specific delete commands (delete first or last)
			if len(com) > 6 {
				if com[6:] == "F" {
					deleteFirst()
				} else if com[6:] == "L" {
					deleteLast()
				}
			} else {
				delete(key)
				nd++
			}
			size--
		}
	}

	// Print the final state of the list
	printList()
}

// Function to search for a node with a specific key
func listSearch(key int) *Node {
	cur := nil.next

	// Traverse the list until the end or until the key is found
	for cur != nil && cur.key != key {
		cur = cur.next
	}

	return cur
}

// Function to initialize the doubly linked list
func init() {
	nil = &Node{}
	nil.next = nil
	nil.prev = nil
}

// Function to print the contents of the list
func printList() {
	cur := nil.next
	isf := 1

	// Loop to print each node's key
	for {
		if cur == nil {
			break
		}
		if isf == 0 {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		isf = 0
	}
	fmt.Println()
}

// Function to delete a specific node from the list
func deleteNode(t *Node) {
	t.prev.next = t.next
	t.next.prev = t.prev
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
	x := &Node{key: key}

	// Insert the new node at the beginning of the list
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
	x.prev = nil
}

