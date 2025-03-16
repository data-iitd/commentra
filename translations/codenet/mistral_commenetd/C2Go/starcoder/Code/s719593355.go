
<<<<<<< HEAD

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a node in the linked list
type node struct {
	key  int
	next *node
	prev *node
=======
package main

// Define a structure for a node in the linked list
type node struct {
  key int
  next *node
  prev *node
>>>>>>> 98c87cb78a (data updated)
}

// Define a typedef for a pointer to a node
type NodePointer *node

// Initialize the linked list with a nil node
<<<<<<< HEAD
var nil NodePointer

// Function to search for a node with a given key in the list
func listSearch(key int) NodePointer {
	cur := nil.next // Initialize a pointer to the first node in the list

	// Search for the node with the given key
	for cur!= nil && cur.key!= key {
		cur = cur.next
	}

	// Return the found node or nil if not found
	return cur
=======
var nil *node

// Function to search for a node with a given key in the list
func listSearch(key int) NodePointer {
  cur := nil.next // Initialize a pointer to the first node in the list

  // Search for the node with the given key
  for cur!= nil && cur.key!= key {
    cur = cur.next
  }

  // Return the found node or nil if not found
  return cur
>>>>>>> 98c87cb78a (data updated)
}

// Initialize the linked list with a nil node
func init() {
<<<<<<< HEAD
	nil = new(node) // Allocate memory for the nil node
	nil.next = nil  // Set the next pointer of the nil node to itself
	nil.prev = nil  // Set the prev pointer of the nil node to itself
=======
  nil = new(node) // Allocate memory for the nil node
  nil.next = nil // Set the next pointer of the nil node to itself
  nil.prev = nil // Set the prev pointer of the nil node to itself
>>>>>>> 98c87cb78a (data updated)
}

// Print the contents of the linked list
func printList() {
<<<<<<< HEAD
	cur := nil.next // Initialize a pointer to the first node in the list
	isf := 1        // Flag to indicate if this is the first node to be printed

	// Traverse the list and print each node
	for {
		if cur == nil {
			break
		}
		if isf == 0 {
			fmt.Printf(" ") // If this is not the first node, print a space before the key
		}
		fmt.Printf("%d", cur.key) // Print the key of the current node
		cur = cur.next              // Move to the next node
		isf = 0                     // Reset the flag for the next iteration
	}
	fmt.Printf("\n") // Print a newline at the end
}

// Delete a node from the linked list
func deleteNode(t NodePointer) {
	t.prev.next = t.next // Set the next pointer of the previous node to the next node of the node to be deleted
	t.next.prev = t.prev // Set the prev pointer of the next node to the previous node of the node to be deleted
	free(t)              // Free the memory occupied by the node to be deleted
=======
  cur := nil.next // Initialize a pointer to the first node in the list
  isf := 1 // Flag to indicate if this is the first node to be printed

  // Traverse the list and print each node
  for {
    if cur == nil {
      break
    }
    if isf == 0 {
      fmt.Printf(" ") // If this is not the first node, print a space before the key
    }
    fmt.Printf("%d", cur.key) // Print the key of the current node
    cur = cur.next // Move to the next node
    isf = 0 // Reset the flag for the next iteration
  }
  fmt.Printf("\n") // Print a newline at the end
}

// Delete a node from the linked list
func deleteNode(t *node) {
  t.prev.next = t.next // Set the next pointer of the previous node to the next node of the node to be deleted
  t.next.prev = t.prev // Set the prev pointer of the next node to the previous node of the node to be deleted
  free(t) // Free the memory occupied by the node to be deleted
>>>>>>> 98c87cb78a (data updated)
}

// Delete and free the first node in the list
func deleteFirst() {
<<<<<<< HEAD
	t := nil.next // Initialize a pointer to the first node in the list

	// If the list is empty, return
	if t == nil {
		return
	}

	// Delete and free the first node
	deleteNode(t)
=======
  t := nil.next // Initialize a pointer to the first node in the list

  // If the list is empty, return
  if t == nil {
    return
  }

  // Delete and free the first node
  deleteNode(t)
>>>>>>> 98c87cb78a (data updated)
}

// Delete and free the last node in the list
func deleteLast() {
<<<<<<< HEAD
	t := nil.prev // Initialize a pointer to the last node in the list

	// If the list is empty, return
	if t == nil {
		return
	}

	// Delete and free the last node
	deleteNode(t)
=======
  t := nil.prev // Initialize a pointer to the last node in the list

  // If the list is empty, return
  if t == nil {
    return
  }

  // Delete and free the last node
  deleteNode(t)
>>>>>>> 98c87cb78a (data updated)
}

// Delete a node with the given key from the list
func delete(key int) {
<<<<<<< HEAD
	t := listSearch(key) // Search for the node with the given key

	// If the node is not found, return
	if t == nil {
		return
	}

	// Delete and free the node
	deleteNode(t)
=======
  t := listSearch(key) // Search for the node with the given key

  // If the node is not found, return
  if t == nil {
    return
  }

  // Delete and free the node
  deleteNode(t)
>>>>>>> 98c87cb78a (data updated)
}

// Allocate memory for a new node and insert it into the list
func insert(key int) {
<<<<<<< HEAD
	x := new(node) // Allocate memory for the new node

	// Initialize the new node with the given key
	x.key = key

	// Insert the new node at the end of the list
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
	x.prev = nil
=======
  x := new(node) // Allocate memory for the new node

  // Initialize the new node with the given key
  x.key = key

  // Insert the new node at the end of the list
  x.next = nil.next
  nil.next.prev = x
  nil.next = x
  x.prev = nil
>>>>>>> 98c87cb78a (data updated)
}

// Main function to read commands from standard input and perform the corresponding actions
func main() {
<<<<<<< HEAD
	var key, n, i int // Declare variables to store the number of commands, the current command, and a counter
	var size, np, nd int // Initialize variables to store the current size of the list, the number of insert and delete operations
	var com string       // Declare a variable to store the command as a string

	// Read the number of commands from standard input
	fmt.Scanf("%d", &n)

	// Initialize the linked list
	init()

	// Process each command in the input
	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &com, &key) // Read the command and the key (if any) from standard input

		// If the command is an insert command, increment the np counter and insert the key into the list
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		}

		// If the command is a delete command, increment the nd counter and delete the node with the given key from the list
		else if com[0] == 'd' {
			if len(com) > 6 { // If the command is a delete first or delete last command, process it accordingly
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else { // If the command is a delete command with a key, delete the node with the given key from the list
				delete(key)
				nd++
			}

			size-- // Decrement the size of the list after the delete operation
		}
	}

	// Print the final size of the list and the number of insert and delete operations
	fmt.Printf("Size: %d, Number of insert operations: %d, Number of delete operations: %d\n", size, np, nd)

	// Free the memory occupied by the linked list
	for nil.next!= nil {
		t := nil.next
		nil.next = nil.next.next
		free(t)
	}
=======
  var key, n, i int // Declare variables to store the number of commands, the current command, and a counter
  var size, np, nd int // Initialize variables to store the current size of the list, the number of insert and delete operations
  var com [20]byte // Declare an array to store the command as a string

  // Read the number of commands from standard input
  fmt.Scanf("%d", &n)

  // Initialize the linked list
  init()

  // Process each command in the input
  for i = 0; i < n; i++ {
    fmt.Scanf("%s%d", &com, &key) // Read the command and the key (if any) from standard input

    // If the command is an insert command, increment the np counter and insert the key into the list
    if com[0] == 'i' {
      insert(key)
      np++
      size++
    }

    // If the command is a delete command, increment the nd counter and delete the node with the given key from the list
    else if com[0] == 'd' {
      if com[6] == 'F' {
        deleteFirst()
      } else if com[6] == 'L' {
        deleteLast()
      } else {
        delete(key)
      }
      nd++
      size--
    }
  }

  // Print the final size of the list and the number of insert and delete operations
  fmt.Printf("Size: %d, Number of insert operations: %d, Number of delete operations: %d\n", size, np, nd)
>>>>>>> 98c87cb78a (data updated)
}

