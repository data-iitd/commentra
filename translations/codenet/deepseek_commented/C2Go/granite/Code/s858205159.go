
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the structure for a node in the doubly linked list
type Node struct {
	key  int
	next *Node
	prev *Node
}

// Function to search for a node with a given key
func listSearch(root *Node, key int) *Node {
	cur := root.next  // Start from the first node
	for cur!= root {  // Traverse the list until we reach the sentinel node
		if cur.key == key {
			break  // If the key matches, break the loop
		}
		cur = cur.next  // Move to the next node
	}
	return cur  // Return the node with the matching key, or root if not found
}

// Function to initialize the doubly linked list with a sentinel node
func initList() *Node {
	root := &Node{}  // Allocate memory for the sentinel node
	root.next = root  // The next pointer of the sentinel node points to itself
	root.prev = root  // The prev pointer of the sentinel node points to itself
	return root  // Return the root node of the list
}

// Function to print the entire list starting from the first node
func printList(root *Node) {
	cur := root.next  // Start from the first node
	isf := true  // Flag to check if it's the first node to be printed
	for cur!= root {  // Traverse the list until we reach the sentinel node
		if isf {
			fmt.Print(cur.key)  // Print the key of the current node
			isf = false  // Update the flag to indicate that a node has been printed
		} else {
			fmt.Print(" ", cur.key)  // Print a space before each key except the first
		}
		cur = cur.next  // Move to the next node
	}
	fmt.Println()  // Print a newline character at the end
}

// Function to delete a specified node from the list
func deleteNode(root *Node, t *Node) {
	if t == root {
		return  // If the node is the sentinel node, do nothing
	}
	t.prev.next = t.next  // Update the next pointer of the previous node
	t.next.prev = t.prev  // Update the prev pointer of the next node
	t = nil  // Set the node to nil to free the memory
}

// Function to delete the first node in the list
func deleteFirst(root *Node) {
	t := root.next  // Get the first node
	if t == root {
		return  // If the list is empty, do nothing
	}
	deleteNode(root, t)  // Delete the first node
}

// Function to delete the last node in the list
func deleteLast(root *Node) {
	t := root.prev  // Get the last node
	if t == root {
		return  // If the list is empty, do nothing
	}
	deleteNode(root, t)  // Delete the last node
}

// Function to delete the node with a specified key
func deleteKey(root *Node, key int) {
	t := listSearch(root, key)  // Find the node with the specified key
	if t!= root {
		deleteNode(root, t)  // If the node is found, delete it
	}
}

// Function to insert a new node with a specified key at the beginning of the list
func insert(root *Node, key int) {
	x := &Node{key: key}  // Allocate memory for the new node
	x.prev = root  // The prev pointer of the new node points to the sentinel node
	x.next = root.next  // The next pointer of the new node points to the current first node
	x.next.prev = x  // Update the prev pointer of the current first node
	root.next = x  // Update the next pointer of the sentinel node to the new node
}

// Main function to read commands and manipulate the doubly linked list
func main() {
	var key, n, i int
	var size int = 0  // Variable to keep track of the size of the list
	var com string
	var np, nd int = 0, 0  // Counters for insertions and deletions
	root := initList()  // Initialize the list
	scanner := bufio.NewScanner(os.Stdin)  // Create a scanner to read input from the user
	fmt.Println("Enter the number of commands:")
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())  // Read the number of commands
	for i = 0; i < n; i++ {
		fmt.Println("Enter the command and the key:")
		scanner.Scan()
		com = scanner.Text()  // Read the command and the key
		if strings.HasPrefix(com, "i") {
			key, _ = strconv.Atoi(strings.TrimSpace(com[1:]))  // Extract the key from the command
			insert(root, key)  // Insert a new node if the command is 'i'
			np++
			size++
		} else if strings.HasPrefix(com, "d") {
			if len(com) > 6 {  // Check if the command is to delete the first or last node
				if com[6] == 'F' {
					deleteFirst(root)
				} else if com[6] == 'L' {
					deleteLast(root)
				}
			} else {
				key, _ = strconv.Atoi(strings.TrimSpace(com[1:]))  // Extract the key from the command
				deleteKey(root, key)  // Delete the node with the specified key
				nd++
				size--
			}
		}
	}
	printList(root)  // Print the final state of the list
	fmt.Println("