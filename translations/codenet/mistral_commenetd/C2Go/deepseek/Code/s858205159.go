package main

import (
	"fmt"
	"unsafe"
)

// Define a structure for a node
type node struct {
	key  int
	next *node
	prev *node
}

// Typedef a NodePointer as a pointer to the node structure
type NodePointer *node

// Initialize nil node with nil pointers
var nil *node = nil

// Function to search a node with given key
func listSearch(key int) NodePointer {
	cur := nil.next
	for cur != nil {
		if cur.key == key {
			break
		}
		cur = cur.next
	}
	return cur
}

// Initialize the linked list with a nil node
func init() {
	nil = &node{}
	nil.next = nil
	nil.prev = nil
}

// Function to print the linked list
func printList() {
	cur := nil.next
	isf := true
	for {
		if cur == nil {
			break
		}
		if isf {
			fmt.Printf("[%d] ", cur.key)
		} else {
			fmt.Printf(" %d", cur.key)
		}
		cur = cur.next
		isf = false
	}
	fmt.Println()
}

// Function to delete a node from the linked list
func deleteNode(t *node) {
	if t == nil {
		return
	}
	t.prev.next = t.next
	t.next.prev = t.prev
	free(unsafe.Pointer(t))
}

// Function to delete the first node from the linked list
func deleteFirst() {
	t := nil.next
	if t == nil {
		return
	}
	deleteNode(t)
}

// Function to delete the last node from the linked list
func deleteLast() {
	t := nil.prev
	if t == nil {
		return
	}
	deleteNode(t)
}

// Function to delete a node with the given key from the linked list
func deleteKey(key int) {
	t := listSearch(key)
	if t != nil {
		deleteNode(t)
	}
}

// Function to insert a new node with the given key into the linked list
func insert(key int) {
	x := &node{key: key}
	x.prev = nil
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
}

// Main function to read commands and perform the corresponding actions
func main() {
	var key, n, i int
	var com string
	np := 0
	nd := 0
	size := 0
	fmt.Scan(&n)
	init()
	for i = 0; i < n; i++ {
		fmt.Scan(&com, &key)
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		} else if com[0] == 'd' {
			if len(com) > 6 {
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else {
				deleteKey(key)
				nd++
			}
			size--
		}
	}
	printList()
}

