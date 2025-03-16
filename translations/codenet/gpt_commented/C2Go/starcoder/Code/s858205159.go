package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a doubly linked list node
type node struct {
	key  int
	next *node
	prev *node
}

var nil = &node{0, nil, nil}

// Function to search for a node with a specific key
func listSearch(key int) *node {
	cur := nil.next
	for cur!= nil {
		if cur.key == key {
			break
		}
		cur = cur.next
	}
	return cur
}

// Function to initialize the linked list
func init() {
	nil.next = nil
	nil.prev = nil
}

// Function to print all the keys in the linked list
func printList() {
	cur := nil.next
	isf := true
	for cur!= nil {
		if isf == false {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		isf = false
	}
	fmt.Println()
}

// Function to delete a specific node from the list
func deleteNode(t *node) {
	if t == nil {
		return
	}
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
func deleteKey(key int) {
	t := listSearch(key)
	if t!= nil {
		deleteNode(t)
	}
}

// Function to insert a new node with a specific key at the beginning of the list
func insert(key int) {
	x := new(node)
	x.key = key
	x.prev = nil
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
}

// Main function to execute the program
func main() {
	n, i := 0, 0
	key := 0
	com := make([]string, 20)
	np, nd := 0, 0
	size := 0
	fmt.Scanf("%d", &n)
	init()
	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &com, &key)
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

