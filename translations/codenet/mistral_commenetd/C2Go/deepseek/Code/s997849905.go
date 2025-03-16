package main

import (
	"fmt"
	"strings"
)

// Define a structure for a node
type Node struct {
	key  int
	next *Node
	prev *Node
}

// Typedef a NodePointer as a pointer to a node
type NodePointer *Node

var N NodePointer // Initialize a pointer to the first node

// Initialize the linked list
func init() {
	N = &Node{key: 0, next: N, prev: N} // Allocate memory for the first node
}

// Print the contents of the linked list
func printList() {
	cur := N.next
	snl := 1
	for cur != N {
		if snl == 0 {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		snl = 0
	}
	fmt.Println()
}

// Delete the first node from the list
func deleteFirst() {
	t := N.next
	N.next = t.next
	t.next.prev = N
}

// Delete the last node from the list
func deleteLast() {
	delnode := N.prev
	N.prev = delnode.prev
	delnode.prev.next = N
}

// Delete a node with the given key from the list
func delete(skey int) {
	judge := false
	var t, n *Node

	for n = N.next; n != N; n = n.next {
		if n.key == skey {
			judge = true
			break
		}
	}

	if judge {
		t = n.prev
		t.next = n.next
		t.next.prev = t
	}
}

// Insert a new node with the given key into the list
func insert(skey int) {
	new := &Node{key: skey}

	if N.next == N {
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
	} else {
		new.next = N.next
		N.next.prev = new
		N.next = new
		new.prev = N
	}
}

// Main function to read commands and perform the corresponding operations
func main() {
	var key, n, i int
	var com string

	fmt.Scan(&n)
	init()

	for i = 0; i < n; i++ {
		fmt.Scan(&com)
		if strings.EqualFold(com, "insert") {
			fmt.Scan(&key)
			insert(key)
		} else if strings.EqualFold(com, "deleteFirst") {
			deleteFirst()
		} else if strings.EqualFold(com, "deleteLast") {
			deleteLast()
		} else {
			fmt.Scan(&key)
			delete(key)
		}
	}
	printList()
}

