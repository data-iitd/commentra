package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a doubly linked list node structure
type node struct {
	key  int32   // The value of the node
	prev *node   // Pointer to the previous node
	next *node   // Pointer to the next node
}

// Method to recursively print the keys of the linked list starting from the current node
func (n *node) rPrint(buf *bytes.Buffer) {
	buf.WriteString(fmt.Sprint(n.key)) // Append the current node's key to the buffer
	if n.next != nil {
		buf.WriteString(" ") // Add a space if there is a next node
		n.next.rPrint(buf)   // Recursively print the next node
	}
	return
}

// Method to delete the current node from the linked list
func (n *node) Delete(first, last *node) (*node, *node) {
	if n.prev != nil && n.next != nil {
		// Node is in the middle; update pointers of adjacent nodes
		n.prev.next = n.next
		n.next.prev = n.prev
		return first, last // Return unchanged first and last pointers
	}

	if n.next == nil && n.prev == nil {
		// Node is the only node in the list
		return nil, nil // Return nil for both first and last
	}

	if n.prev == nil {
		// Node is the first node
		first = n.next // Update first to the next node
		n.next.prev = nil // Set the previous pointer of the new first node to nil
	}

	if n.next == nil {
		// Node is the last node
		last = n.prev // Update last to the previous node
		n.prev.next = nil // Set the next pointer of the new last node to nil
	}

	return first, last // Return updated first and last pointers
}

// Function to initialize a new node with a given key
func initNode(key int32) *node {
	return &node{
		key: key, // Set the key of the new node
	}
}

// Main function to execute the program
func main() {
	stdin := bufio.NewScanner(os.Stdin) // Create a scanner to read input from standard input
	var first, last *node                 // Initialize pointers for the first and last nodes of the list
	stdin.Scan()                          // Read the first line of input (not used)

	// Loop to process each command from the input
	for stdin.Scan() {
		cmd := stdin.Text() // Get the current command
		switch cmd {
		case "deleteFirst":
			// Command to delete the first node
			first, last = first.Delete(first, last)
		case "deleteLast":
			// Command to delete the last node
			first, last = last.Delete(first, last)
		default:
			// Handle commands that involve inserting or deleting specific keys
			xcmd := strings.Split(cmd, " ") // Split the command into parts
			k, _ := strconv.Atoi(xcmd[1])    // Convert the second part to an integer
			k32 := int32(k)                   // Convert the integer to int32
			switch xcmd[0] {
			case "delete":
				// Command to delete a node with a specific key
				for a := first; a != nil; a = a.next {
					if a.key == k32 {
						first, last = a.Delete(first, last) // Delete the node and update first and last
						break
					}
				}
			case "insert":
				// Command to insert a new node at the beginning of the list
				n := initNode(k32) // Initialize a new node
				n.next = first      // Set the new node's next pointer to the current first node
				if first != nil {
					first.prev = n // Update the previous pointer of the current first node
				}

				first = n // Update first to the new node
				if last == nil {
					last = n // If the list was empty, set last to the new node
				}
			}
		}
	}
	var buf bytes.Buffer
	first.rPrint(&buf) // Print the keys of the linked list starting from the first node
	fmt.Println(buf.String()) // Output the result
}
