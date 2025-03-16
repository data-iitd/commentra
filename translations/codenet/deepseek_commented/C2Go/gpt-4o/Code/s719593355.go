package main

import (
	"fmt"
	"strings"
)

type Node struct {
	key  uint
	next *Node
	prev *Node
}

var nilNode *Node // A dummy node used for easier list manipulation

// Searches for a node with the specified key in the list
func listSearch(key int) *Node {
	cur := nilNode.next
	for cur != nilNode && cur.key != uint(key) {
		cur = cur.next
	}
	return cur
}

// Initializes the list by creating a dummy node and setting its next and prev pointers
func initList() {
	nilNode = &Node{}
	nilNode.next = nilNode
	nilNode.prev = nilNode
}

// Prints the entire list from the first node to the last node
func printList() {
	cur := nilNode.next
	isFirst := true
	for {
		if cur == nilNode {
			break
		}
		if !isFirst {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		isFirst = false
	}
	fmt.Println()
}

// Deletes the specified node from the list
func deleteNode(t *Node) {
	t.prev.next = t.next
	t.next.prev = t.prev
}

// Deletes the first node in the list
func deleteFirst() {
	t := nilNode.next
	if t == nilNode {
		return
	}
	deleteNode(t)
}

// Deletes the last node in the list
func deleteLast() {
	t := nilNode.prev
	if t == nilNode {
		return
	}
	deleteNode(t)
}

// Deletes the node with the specified key from the list
func delete(key int) {
	t := listSearch(key)
	if t == nilNode {
		return
	}
	deleteNode(t)
}

// Inserts a new node with the given key at the beginning of the list
func insert(key int) {
	x := &Node{key: uint(key)}
	x.next = nilNode.next
	nilNode.next.prev = x
	nilNode.next = x
	x.prev = nilNode
}

func main() {
	var key, n int
	var command string
	var size int // Keeps track of the number of elements in the list
	var np, nd int // Counters for insertions and deletions

	fmt.Scan(&n)

	initList() // Initialize the list

	for i := 0; i < n; i++ {
		fmt.Scan(&command, &key)

		if command[0] == 'i' { // Insert a new node with the specified key
			insert(key)
			np++
			size++
		} else if command[0] == 'd' { // Delete a node with the specified key or the first/last node
			if len(command) > 6 {
				if command[6] == 'F' { // Delete the first node
					deleteFirst()
				} else if command[6] == 'L' { // Delete the last node
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

// <END-OF-CODE>
