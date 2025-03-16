package main

import (
	"fmt"
	"strings"
)

// Define the structure for a node in the doubly linked list
type Node struct {
	key  uint
	next *Node
	prev *Node
}

// Sentinel node (dummy node) for the doubly linked list
var nilNode *Node

// Function to search for a node with a given key
func listSearch(key int) *Node {
	cur := nilNode.next // Start from the first node
	for cur != nilNode { // Traverse the list until we reach the sentinel node
		if cur.key == uint(key) {
			return cur // Return the node with the matching key
		}
		cur = cur.next // Move to the next node
	}
	return nilNode // Return nil if not found
}

// Function to initialize the doubly linked list with a sentinel node
func initList() {
	nilNode = &Node{} // Create the sentinel node
	nilNode.next = nilNode // The next pointer of the sentinel node points to itself
	nilNode.prev = nilNode // The prev pointer of the sentinel node points to itself
}

// Function to print the entire list starting from the first node
func printList() {
	cur := nilNode.next // Start from the first node
	isFirst := true // Flag to check if it's the first node to be printed
	for {
		if cur == nilNode {
			break // If we reach the sentinel node, break the loop
		}
		if !isFirst {
			fmt.Print(" ") // Print a space before each key except the first
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next // Move to the next node
		isFirst = false // Update the flag to indicate that a node has been printed
	}
	fmt.Println() // Print a newline character at the end
}

// Function to delete a specified node from the list
func deleteNode(t *Node) {
	if t == nilNode {
		return // If the node is the sentinel node, do nothing
	}
	t.prev.next = t.next // Update the next pointer of the previous node
	t.next.prev = t.prev // Update the prev pointer of the next node
}

// Function to delete the first node in the list
func deleteFirst() {
	t := nilNode.next // Get the first node
	if t == nilNode {
		return // If the list is empty, do nothing
	}
	deleteNode(t) // Delete the first node
}

// Function to delete the last node in the list
func deleteLast() {
	t := nilNode.prev // Get the last node
	if t == nilNode {
		return // If the list is empty, do nothing
	}
	deleteNode(t) // Delete the last node
}

// Function to delete the node with a specified key
func deleteKey(key int) {
	t := listSearch(key) // Find the node with the specified key
	if t != nilNode {
		deleteNode(t) // If the node is found, delete it
	}
}

// Function to insert a new node with a specified key at the beginning of the list
func insert(key int) {
	x := &Node{key: uint(key)} // Allocate memory for the new node
	x.prev = nilNode // The prev pointer of the new node points to the sentinel node
	x.next = nilNode.next // The next pointer of the new node points to the current first node
	x.next.prev = x // Update the prev pointer of the current first node
	nilNode.next = x // Update the next pointer of the sentinel node to the new node
}

// Main function to read commands and manipulate the doubly linked list
func main() {
	var key, n int
	var command string
	size := 0 // Variable to keep track of the size of the list
	np, nd := 0, 0 // Counters for insertions and deletions
	fmt.Scan(&n) // Read the number of commands
	initList() // Initialize the list
	for i := 0; i < n; i++ {
		fmt.Scan(&command, &key) // Read the command and the key
		if command[0] == 'i' {
			insert(key)
			np++
			size++
		} else if command[0] == 'd' {
			if len(command) > 6 { // Check if the command is to delete the first or last node
				if command[6] == 'F' {
					deleteFirst()
				} else if command[6] == 'L' {
					deleteLast()
				}
			} else {
				deleteKey(key) // Delete the node with the specified key
				nd++
			}
			size-- // Decrease the size of the list
		}
	}

	printList() // Print the final state of the list
}

// <END-OF-CODE>
