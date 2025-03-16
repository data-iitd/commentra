

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a node
type node struct {
	key  int
	next *node
	prev *node
}

// Typedef a NodePointer as a pointer to a node
type NodePointer *node
var N NodePointer // Initialize a pointer to the first node

// Initialize the linked list
func init() {
	N = new(node) // Allocate memory for the first node
	N.next = N // Initialize next pointer of the first node to itself
	N.prev = N // Initialize prev pointer of the first node to itself
}

// Print the contents of the linked list
func printList() {
	cur := N.next // Initialize a pointer to traverse the list
	snl := 1       // Set a flag to control the printing of spaces between numbers
	for cur!= N { // Traverse the list until the end is reached
		if snl == 0 { // If a space is not required before the number, print a space
			fmt.Print(" ")
		}
		fmt.Print(cur.key) // Print the key value of the current node
		cur = cur.next   // Move to the next node
		snl = 0             // Reset the flag for the next iteration
	}
	fmt.Println() // Print a newline at the end
}

// Delete the first node from the list
func deleteFirst() {
	t := N.next // Initialize a pointer to the second node
	N.next = t.next // Update the next pointer of the first node to point to the third node
	t.next.prev = N // Update the prev pointer of the third node to point to the first node
}

// Delete the last node from the list
func deleteLast() {
	delnode := N.prev // Initialize a pointer to the second last node
	N.prev = delnode.prev // Update the prev pointer of the second last node to point to the node before it
	delnode.prev.next = N // Update the next pointer of the second last node to point to the first node
	free(delnode) // Free the memory occupied by the last node
}

// Delete a node with the given key from the list
func delete(skey int) {
	judge := 0 // Initialize a flag to check if the node to be deleted exists
	n, t := N.next, N // Initialize two pointers to traverse the list
	for n!= N { // Traverse the list to find the node to be deleted
		if n.key == skey { // If the key matches, set the flag
			judge = 1
			break
		}
		t = n
		n = n.next
	}
	if judge == 1 { // If the node exists, delete it
		t.next = n.next // Update the next pointer of the previous node to point to the next node after the deleted node
		t.next.prev = t // Update the prev pointer of the next node to point to the previous node
		free(n) // Free the memory occupied by the deleted node
	}
}

// Insert a new node with the given key into the list
func insert(skey int) {
	new := new(node) // Initialize a pointer to the new node
	static count := 0 // Initialize a counter to keep track of the number of nodes in the list
	new.key = skey    // Set the key value of the new node
	if count == 0 { // If the list is empty, initialize the first node
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
		count++
	} else { // If the list is not empty, insert the new node at the end
		new.next = N.next
		N.next.prev = new
		N.next = new
		new.prev = N
		count++
	}
}

// Main function to read commands and perform the corresponding operations
func main() {
	var n, i int
	var com string
	var key int
	reader := bufio.NewReader(os.Stdin)
	fmt.Scan(&n) // Read the number of operations to be performed
	init() // Initialize the linked list
	for i = 0; i < n; i++ { // Perform each operation in the loop
		com, _ = reader.ReadString('\n') // Read the command string
		com = strings.TrimSpace(com)
		if com == "insert" { // If the command is to insert a node
			fmt.Scan(&key)
			insert(key)
		} else if com == "deleteFirst" {
			deleteFirst() // If the command is to delete the first node
		} else if com == "deleteLast" {
			deleteLast() // If the command is to delete the last node
		} else { // If the command is to delete a node with a given key
			fmt.Scan(&key)
			delete(key)
		}
	}
	printList() // Print the updated list after performing all the operations
}

