package main

import (
	"fmt"
	"strings"
)

// Define a structure for a node
type Node struct {
	key  int   // Key value of the node
	next *Node // Pointer to the next node
	prev *Node // Pointer to the previous node
}

// Define a structure for the linked list
type LinkedList struct {
	head *Node // Pointer to the first node
}

// Initialize the linked list
func (ll *LinkedList) init() {
	ll.head = &Node{} // Allocate memory for the first node
	ll.head.next = ll.head // Initialize next pointer of the first node to itself
	ll.head.prev = ll.head // Initialize prev pointer of the first node to itself
}

// Print the contents of the linked list
func (ll *LinkedList) printList() {
	cur := ll.head.next // Initialize a pointer to traverse the list
	snl := true         // Set a flag to control the printing of spaces between numbers
	for cur != ll.head { // Traverse the list until the end is reached
		if !snl { // If a space is not required before the number, print a space
			fmt.Print(" ")
		}
		fmt.Print(cur.key) // Print the key value of the current node
		cur = cur.next     // Move to the next node
		snl = false        // Reset the flag for the next iteration
	}
	fmt.Println() // Print a newline at the end
}

// Delete the first node from the list
func (ll *LinkedList) deleteFirst() {
	if ll.head.next == ll.head { // Check if the list is empty
		return
	}
	t := ll.head.next // Initialize a pointer to the second node
	ll.head.next = t.next // Update the next pointer of the first node to point to the third node
	t.next.prev = ll.head // Update the prev pointer of the third node to point to the first node
}

// Delete the last node from the list
func (ll *LinkedList) deleteLast() {
	if ll.head.prev == ll.head { // Check if the list is empty
		return
	}
	delNode := ll.head.prev // Initialize a pointer to the second last node
	ll.head.prev = delNode.prev // Update the prev pointer of the second last node to point to the node before it
	delNode.prev.next = ll.head // Update the next pointer of the second last node to point to the first node
}

// Delete a node with the given key from the list
func (ll *LinkedList) delete(skey int) {
	var judge bool // Initialize a flag to check if the node to be deleted exists
	var n *Node    // Initialize a pointer to traverse the list

	for n = ll.head.next; n != ll.head; n = n.next { // Traverse the list to find the node to be deleted
		if n.key == skey { // If the key matches, set the flag
			judge = true
			break
		}
	}

	if judge { // If the node exists, delete it
		t := n.prev // Initialize a pointer to the node before the node to be deleted
		t.next = n.next // Update the next pointer of the previous node to point to the next node after the deleted node
		n.next.prev = t // Update the prev pointer of the next node to point to the previous node
	}
}

// Insert a new node with the given key into the list
func (ll *LinkedList) insert(skey int) {
	newNode := &Node{key: skey} // Allocate memory for the new node

	if ll.head.next == ll.head { // If the list is empty, initialize the first node
		newNode.next = ll.head
		ll.head.next = newNode
		newNode.prev = ll.head
		ll.head.prev = newNode
	} else { // If the list is not empty, insert the new node at the end
		newNode.next = ll.head.next
		ll.head.next.prev = newNode
		ll.head.next = newNode
		newNode.prev = ll.head
	}
}

// Main function to read commands and perform the corresponding operations
func main() {
	var key, n int
	var command string
	ll := LinkedList{} // Initialize the linked list
	ll.init()          // Initialize the linked list

	fmt.Scan(&n) // Read the number of operations to be performed

	for i := 0; i < n; i++ { // Perform each operation in the loop
		fmt.Scan(&command) // Read the command string
		switch command {
		case "insert": // If the command is to insert a node
			fmt.Scan(&key)
			ll.insert(key)
		case "deleteFirst":
			ll.deleteFirst() // If the command is to delete the first node
		case "deleteLast":
			ll.deleteLast() // If the command is to delete the last node
		default: // If the command is to delete a node with a given key
			fmt.Scan(&key)
			ll.delete(key)
		}
	}
	ll.printList() // Print the updated list after performing all the operations
}

// <END-OF-CODE>
