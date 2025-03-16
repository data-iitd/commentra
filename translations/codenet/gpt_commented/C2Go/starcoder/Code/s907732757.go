package main

import (
	"bufio"
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

var head *node

// Function prototypes for node operations
func makenode(a int) *node
func insert(a int)
func delete(a int)
func deleteFirst()
func deleteLast()

func main() {
	var i, n, a int
	var op string
	var x *node

	// Initialize the head node of the doubly linked list
	head = makenode(0)
	head.next = head
	head.prev = head

	// Read the number of operations to perform
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		// Read the operation command
		fmt.Scanf("%s", &op)
		if op == "insert" {
			fmt.Scanf("%d", &a)
			insert(a)
		} else if op == "delete" {
			fmt.Scanf("%d", &a)
			delete(a)
		} else if op == "deleteFirst" {
			deleteFirst()
		} else if op == "deleteLast" {
			deleteLast()
		}
	}

	// Print the remaining elements in the list
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

// Function to create a new node with a given key
func makenode(a int) *node {
	x := new(node)
	x.key = a
	return x
}

// Function to insert a new node with a given key at the beginning of the list
func insert(a int) {
	x := makenode(a)
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

// Function to delete a node with a given key from the list
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

// Function to delete the first node in the list
func deleteFirst() {
	x := head.next
	head.next = x.next
	x.next.prev = head
	free(x)
}

// Function to delete the last node in the list
func deleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
	free(x)
}

