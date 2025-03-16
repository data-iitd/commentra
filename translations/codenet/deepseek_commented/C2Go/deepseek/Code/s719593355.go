package main

import (
	"fmt"
	"unsafe"
)

type node struct {
	key  int
	next *node
	prev *node
}

type NodePointer *node

var nil NodePointer

// Searches for a node with the specified key in the list
func listSearch(key int) NodePointer {
	cur := nil.next

	for cur != nil {
		if cur.key == key {
			return cur
		}
		cur = cur.next
	}

	return nil
}

// Initializes the list by creating a dummy node and setting its next and prev pointers
func init() {
	nil = new(node)
	nil.next = nil
	nil.prev = nil
}

// Prints the entire list from the first node to the last node
func printList() {
	cur := nil.next
	isf := true
	for {
		if cur == nil {
			break
		}
		if !isf {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		isf = false
	}
	fmt.Println()
}

// Deletes the specified node from the list
func deleteNode(t NodePointer) {
	t.prev.next = t.next
	t.next.prev = t.prev
	free(unsafe.Pointer(t))
}

// Deletes the first node in the list
func deleteFirst() {
	t := nil.next
	if t == nil {
		return
	}

	deleteNode(t)
}

// Deletes the last node in the list
func deleteLast() {
	t := nil.prev
	if t == nil {
		return
	}

	deleteNode(t)
}

// Deletes the node with the specified key from the list
func delete(key int) {
	t := listSearch(key)

	if t == nil {
		return
	}

	deleteNode(t)
}

// Inserts a new node with the given key at the beginning of the list
func insert(key int) {
	x := new(node)
	x.key = key

	x.next = nil.next
	nil.next.prev = x
	nil.next = x
	x.prev = nil
}

func main() {
	var key, n, i int
	var size int = 0 // Keeps track of the number of elements in the list
	var com [20]rune
	var np, nd int = 0, 0 // Counters for insertions and deletions

	fmt.Scan(&n)

	init() // Initialize the list

	for i = 0; i < n; i++ {
		fmt.Scan(&com, &key)

		if com[0] == 'i' { // Insert a new node with the specified key
			insert(key)
			np++
			size++
		} else if com[0] == 'd' { // Delete a node with the specified key or the first/last node
			if len(com) > 6 {
				if com[6] == 'F' { // Delete the first node
					deleteFirst()
				} else if com[6] == 'L' { // Delete the last node
					deleteLast()
				}
			} else {
				delete(key)
				nd++
			}

			size--
		}
	}

	printList() // Print the final list
}

