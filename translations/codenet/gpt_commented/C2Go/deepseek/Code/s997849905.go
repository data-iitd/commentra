package main

import (
	"fmt"
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
	N = &Node{key: 0, next: N, prev: N} // Allocate memory for the head node
}

// Function to print the elements of the list
func printList() {
	cur := N.next // Start from the first node
	snl := 1      // Flag to manage spacing
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

// Function to delete the first node in the list
func deleteFirst() {
	t := N.next // Node to be deleted (first node)
	N.next = t.next
	t.next.prev = N
}

// Function to delete the last node in the list
func deleteLast() {
	delnode := N.prev // Node to be deleted (last node)
	N.prev = delnode.prev
	delnode.prev.next = N
}

// Function to delete a node with a specific key
func delete(skey int) {
	judge := false
	var t, n *Node
	for n = N.next; n != N; n = n.next {
		if n.key == skey {
			judge = true
		}
	}
	if judge {
		n = N.next
		for n != N {
			if n.key == skey {
				break
			}
			n = n.next
		}
		t = n.prev
		t.next = n.next
		t.next.prev = t
	}
}

// Function to insert a new node with a specific key
func insert(skey int) {
	newNode := &Node{key: skey}
	if N.next == N {
		newNode.next = N
		N.next = newNode
		newNode.prev = N
		N.prev = newNode
	} else {
		newNode.next = N.next
		N.next.prev = newNode
		N.next = newNode
		newNode.prev = N
	}
}

// Main function to execute the program
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

