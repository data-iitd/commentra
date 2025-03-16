
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a node structure with key, previous and next pointers
type node struct {
	key  int32
	prev *node
	next *node
}

// Recursive function to print the linked list in reverse order
func (n *node) rPrint(buf *bytes.Buffer) {
	buf.WriteString(fmt.Sprint(n.key))
	if n.next != nil {
		// Recursively call rPrint function for next node
		buf.WriteString(" ")
		n.next.rPrint(buf)
	}
	// Return from the function
	return
}

// Function to delete a node from the linked list
func (n *node) Delete(first, last *node) (*node, *node) {
	// Base case: if node is the first and last node
	if n.prev == nil && n.next == nil {
		return nil, nil
	}

	// Base case: if node is the first node
	if n.prev == nil {
		first = n.next
		n.next.prev = nil
		return first, last
	}

	// Base case: if node is the last node
	if n.next == nil {
		last = n.prev
		n.prev.next = nil
		return first, last
	}

	// General case: swap the pointers of previous and next nodes
	n.prev.next = n.next
	n.next.prev = n.prev
	// Return the first and last nodes after deletion
	return first, last
}

// Initialize a new node with given key
func initNode(key int32) *node {
	return &node{
		key: key,
	}
}

// Main function to read commands from stdin and perform the corresponding actions
func main() {
	// Initialize standard input scanner
	stdin := bufio.NewScanner(os.Stdin)
	// Initialize first and last pointers to nil
	var first, last *node

	// Read the first command from stdin
	stdin.Scan()

	// Process each command until EOF is reached
	for stdin.Scan() {
		cmd := stdin.Text() // Read the command from stdin

		// Switch statement to perform the corresponding action based on the command
		switch cmd {
		case "deleteFirst":
			// Delete the first node from the linked list
			first, last = first.Delete(first, last)
		case "deleteLast":
			// Delete the last node from the linked list
			first, last = last.Delete(first, last)
		default:
			// Split the command into parts using space as delimiter
			xcmd := strings.Split(cmd, " ")
			// Parse the key from the second part of the command
			k, _ := strconv.Atoi(xcmd[1])
			// Convert the key to int32 type
			k32 := int32(k)
			// Switch statement to perform the corresponding action based on the command prefix
			switch xcmd[0] {
			case "delete":
				// Search for the node with the given key in the linked list
				for a := first; a != nil; a = a.next {
					// If the current node matches the given key, delete it
					if a.key == k32 {
						first, last = a.Delete(first, last)
						break
					}
				}
			case "insert":
				// Create a new node with the given key
				n := initNode(k32)
				// Insert the new node at the beginning of the linked list
				n.next = first
				if first != nil {
					first.prev = n
				}

				// Update the first and last pointers
				first = n
				if last == nil {
					last = n
				}
			}
		}
	}
	// Print the linked list in reverse order
	var buf bytes.Buffer
	first.rPrint(&buf)
	// Print the reversed linked list on the console
	fmt.Println(buf.String())
	// End of the code
	