package main

import (
	"fmt"
	"strings"
)

// Define the structure for a node in the doubly linked list
type Node struct {
	Key  int
	Next *Node
	Prev *Node
}

// Type alias for a pointer to a node
type NodePointer *Node

// Sentinel node (dummy node) for the doubly linked list
var nil *Node

// Function to search for a node with a given key
func listSearch(key int) NodePointer {
	cur := nil.Next
	for cur != nil {
		if cur.Key == key {
			break
		}
		cur = cur.Next
	}
	return cur
}

// Function to initialize the doubly linked list with a sentinel node
func init() {
	nil = &Node{}
	nil.Next = nil
	nil.Prev = nil
}

// Function to print the entire list starting from the first node
func printList() {
	cur := nil.Next
	isf := true
	for {
		if cur == nil {
			break
		}
		if !isf {
			fmt.Print(" ")
		}
		fmt.Print(cur.Key)
		cur = cur.Next
		isf = false
	}
	fmt.Println()
}

// Function to delete a specified node from the list
func deleteNode(t NodePointer) {
	if t == nil {
		return
	}
	t.Prev.Next = t.Next
	t.Next.Prev = t.Prev
}

// Function to delete the first node in the list
func deleteFirst() {
	t := nil.Next
	if t == nil {
		return
	}
	deleteNode(t)
}

// Function to delete the last node in the list
func deleteLast() {
	t := nil.Prev
	if t == nil {
		return
	}
	deleteNode(t)
}

// Function to delete the node with a specified key
func deleteKey(key int) {
	t := listSearch(key)
	if t != nil {
		deleteNode(t)
	}
}

// Function to insert a new node with a specified key at the beginning of the list
func insert(key int) {
	x := &Node{Key: key}
	x.Prev = nil
	x.Next = nil.Next
	if nil.Next != nil {
		nil.Next.Prev = x
	}
	nil.Next = x
}

// Main function to read commands and manipulate the doubly linked list
func main() {
	var key, n, i int
	var size int
	var com string
	var np, nd int

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
				if com[6:8] == "F" {
					deleteFirst()
				} else if com[6:8] == "L" {
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

