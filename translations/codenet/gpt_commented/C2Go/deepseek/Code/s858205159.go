package main

import (
	"fmt"
	"strings"
)

// Define a structure for a doubly linked list node
type Node struct {
	Key  int
	Next *Node
	Prev *Node
}

// Define NodePointer as a pointer to a Node structure
type NodePointer *Node

var nil *Node // Sentinel node to represent the head and tail of the list

// Function to search for a node with a specific key
func listSearch(key int) NodePointer {
	cur := nil.Next // Start from the first node
	for cur != nil {
		if cur.Key == key {
			break
		}
		cur = cur.Next
	}
	return cur
}

// Function to initialize the linked list
func init() {
	nil = &Node{}
	nil.Next = nil
	nil.Prev = nil
}

// Function to print all the keys in the linked list
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

// Function to delete a specific node from the list
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

// Function to delete a node with a specific key
func deleteKey(key int) {
	t := listSearch(key)
	if t != nil {
		deleteNode(t)
	}
}

// Function to insert a new node with a specific key at the beginning of the list
func insert(key int) {
	x := &Node{Key: key}
	x.Prev = nil
	x.Next = nil.Next
	if nil.Next != nil {
		nil.Next.Prev = x
	}
	nil.Next = x
}

// Main function to execute the program
func main() {
	var key int
	var n, i int
	var com string
	var size int
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
				if com[6:] == "First" {
					deleteFirst()
				} else if com[6:] == "Last" {
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

