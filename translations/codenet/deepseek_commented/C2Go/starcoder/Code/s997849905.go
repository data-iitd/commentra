<<<<<<< HEAD

// Define the structure for a node in the circular doubly linked list
type node struct {
  key int
  next *node
  prev *node
}

// Define a type for a pointer to a node
type NodePointer *node
=======
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the structure for a node in the circular doubly linked list
type Node struct {
	Key  int
	Next *Node
	Prev *Node
}

// Define a type for a pointer to a node
type NodePointer *Node
>>>>>>> 98c87cb78a (data updated)

// Declare a global variable N of type NodePointer
var N NodePointer

// Initialize the circular doubly linked list
func init() {
<<<<<<< HEAD
  N = new(node) // Allocate memory for the sentinel node
  N.next = N // Set the next pointer of the sentinel node to itself
  N.prev = N // Set the previous pointer of the sentinel node to itself
=======
	N = new(Node)
	N.Next = N
	N.Prev = N
>>>>>>> 98c87cb78a (data updated)
}

// Print the elements of the circular doubly linked list
func printList() {
<<<<<<< HEAD
  cur := N.next // Start from the first node
  snl := 1 // Flag to determine if it's the first element
  for cur!= N { // Iterate until the sentinel node is reached
    if snl == 0 { // Print a space before non-first elements
      fmt.Printf(" ")
    }
    fmt.Printf("%d", cur.key) // Print the key of the current node
    cur = cur.next // Move to the next node
    snl = 0 // Set the flag to indicate a non-first element
  }
  fmt.Printf("\n") // Print a newline at the end
=======
	cur := N.Next
	snl := 1
	for cur!= N {
		if snl == 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", cur.Key)
		cur = cur.Next
		snl = 0
	}
	fmt.Printf("\n")
>>>>>>> 98c87cb78a (data updated)
}

// Delete the first node in the circular doubly linked list
func deleteFirst() {
<<<<<<< HEAD
  t := N.next // Store the first node
  N.next = t.next // Update the next pointer of the sentinel node
  t.next.prev = N // Update the previous pointer of the new first node
  free(t) // Free the memory of the deleted node
=======
	t := N.Next
	N.Next = t.Next
	t.Next.Prev = N
	t.Next = nil
	t.Prev = nil
	t = nil
>>>>>>> 98c87cb78a (data updated)
}

// Delete the last node in the circular doubly linked list
func deleteLast() {
<<<<<<< HEAD
  delnode := N.prev // Store the last node
  N.prev = delnode.prev // Update the previous pointer of the sentinel node
  delnode.prev.next = N // Update the next pointer of the new last node
  free(delnode) // Free the memory of the deleted node
=======
	delnode := N.Prev
	N.Prev = delnode.Prev
	delnode.Prev.Next = N
	delnode.Next = nil
	delnode.Prev = nil
	delnode = nil
>>>>>>> 98c87cb78a (data updated)
}

// Delete a node with a specific key from the circular doubly linked list
func delete(skey int) {
<<<<<<< HEAD
  judge := 0 // Flag to indicate if the key was found
  n := N.next // Temporary pointer for node traversal
  for n!= N { // Iterate through the list to find the node with the specified key
    if n.key == skey {
      judge = 1 // Set the flag if the key is found
    }
    n = n.next
  }

  // If the key is found, remove the node
  if judge == 1 {
    n = N.next
    for n!= N {
      if n.key == skey {
	break
      }
      n = n.next
    }
    t := n.prev
    t.next = n.next
    t.next.prev = t
    free(n)
  }
=======
	judge := 0
	var t, n NodePointer

	// Iterate through the list to find the node with the specified key
	for n = N.Next; n!= N; n = n.Next {
		if n.Key == skey {
			judge = 1
		}
	}

	// If the key is found, remove the node
	if judge == 1 {
		n = N.Next
		for n!= N {
			if n.Key == skey {
				break
			}
			n = n.Next
		}
		t = n.Prev
		t.Next = n.Next
		t.Next.Prev = t
		n.Next = nil
		n.Prev = nil
		t = nil
		n = nil
	}
>>>>>>> 98c87cb78a (data updated)
}

// Insert a new node with a specific key into the circular doubly linked list
func insert(skey int) {
<<<<<<< HEAD
  new := new(node) // Pointer to the new node
  new.key = skey // Set the key of the new node
  static count int = 0 // Static variable to track the number of nodes

  // Special case: if the list is empty, set the new node as the only node
  if count == 0 {
    new.next = N
    N.next = new
    new.prev = N
    N.prev = new
    count++
  } else {
    new.next = N.next // Set the next pointer of the new node
    N.next.prev = new // Update the previous pointer of the current first node
    N.next = new // Update the next pointer of the sentinel node
    new.prev = N // Set the previous pointer of the new node
    count++
  }
=======
	var new NodePointer
	new = new(Node)
	new.Key = skey

	// Special case: if the list is empty, set the new node as the only node
	if N.Next == N {
		new.Next = N
		N.Next = new
		new.Prev = N
		N.Prev = new
	} else {
		new.Next = N.Next
		N.Next.Prev = new
		N.Next = new
		new.Prev = N
	}
>>>>>>> 98c87cb78a (data updated)
}

// Main function to execute the operations on the circular doubly linked list
func main() {
<<<<<<< HEAD
  var key, n, i int
  var com [12]byte // Array to store the command

  fmt.Scanf("%d", &n) // Read the number of commands
  init() // Initialize the circular doubly linked list
  for i = 0; i < n; i++ { // Loop through the number of commands
    fmt.Scanf("%s", &com) // Read the command
    if string(com) == "insert" { // If the command is to insert
      fmt.Scanf("%d", &key) // Read the key to insert
      insert(key) // Insert the key into the list
    } else if string(com) == "deleteFirst" { // If the command is to delete the first node
      deleteFirst()
    } else if string(com) == "deleteLast" { // If the command is to delete the last node
      deleteLast()
    } else { // If the command is to delete a specific node
      fmt.Scanf("%d", &key) // Read the key to delete
      delete(key) // Delete the node with the specified key
    }
  }
  printList() // Print the final state of the list
=======
	var key, n, i int
	var com string

	n, _ = strconv.Atoi(os.Args[1])
	init()
	for i = 0; i < n; i++ {
		com = strings.TrimSpace(os.Args[2+i])
		if com == "insert" {
			key, _ = strconv.Atoi(os.Args[3+i])
			insert(key)
		} else if com == "deleteFirst" {
			deleteFirst()
		} else if com == "deleteLast" {
			deleteLast()
		} else {
			key, _ = strconv.Atoi(os.Args[3+i])
			delete(key)
		}
	}
	printList()
>>>>>>> 98c87cb78a (data updated)
}

