
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the structure for a node in the circular doubly linked list
type Node struct {
	key  int
	next *Node
	prev *Node
}

// Define a type for a pointer to a node
type NodePointer *Node

// Global variable N of type NodePointer
var N NodePointer

// Initialize the circular doubly linked list
func init() {
	N = new(Node) // Allocate memory for the sentinel node
	N.next = N // Set the next pointer of the sentinel node to itself
	N.prev = N // Set the previous pointer of the sentinel node to itself
}

// Print the elements of the circular doubly linked list
func printList() {
	cur := N.next // Start from the first node
	snl := 1        // Flag to determine if it's the first element
	for cur!= N { // Iterate until the sentinel node is reached
		if snl == 0 {
			fmt.Print(" ") // Print a space before non-first elements
		}
		fmt.Print(cur.key) // Print the key of the current node
		cur = cur.next   // Move to the next node
		snl = 0            // Set the flag to indicate a non-first element
	}
	fmt.Println() // Print a newline at the end
}

// Delete the first node in the circular doubly linked list
func deleteFirst() {
	t := N.next // Store the first node
	N.next = t.next
	t.next.prev = N // Update the previous pointer of the new first node
	free(t)         // Free the memory of the deleted node
}

// Delete the last node in the circular doubly linked list
func deleteLast() {
	delnode := N.prev // Store the last node
	N.prev = delnode.prev
	delnode.prev.next = N // Update the next pointer of the new last node
	free(delnode)         // Free the memory of the deleted node
}

// Delete a node with a specific key from the circular doubly linked list
func delete(skey int) {
	judge := 0 // Flag to indicate if the key was found
	n := N.next
	for n!= N {
		if n.key == skey {
			judge = 1 // Set the flag if the key is found
		}
		n = n.next
	}
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
}

// Insert a new node with a specific key into the circular doubly linked list
func insert(skey int) {
	new := new(Node) // Pointer to the new node
	new.key = skey   // Set the key of the new node
	count++           // Increment the count of nodes
	if count == 1 {   // Special case: if the list is empty
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
	} else {
		new.next = N.next // Set the next pointer of the new node
		N.next.prev = new // Update the previous pointer of the current first node
		N.next = new       // Update the next pointer of the sentinel node
		new.prev = N       // Set the previous pointer of the new node
	}
}

// Main function to execute the operations on the circular doubly linked list
func main() {
	var key, n, i int
	var com string
	reader := bufio.NewReader(os.Stdin)
	fmt.Scan(&n) // Read the number of commands
	init()       // Initialize the circular doubly linked list
	for i = 0; i < n; i++ {
		fmt.Scan(&com) // Read the command
		if com == "insert" { // If the command is to insert
			fmt.Scan(&key) // Read the key to insert
			insert(key)    // Insert the key into the list
		} else if com == "deleteFirst" { // If the command is to delete the first node
			deleteFirst() // Delete the first node
		} else if com == "deleteLast" { // If the command is to delete the last node
			deleteLast() // Delete the last node
		} else { // If the command is to delete a specific node
			fmt.Scan(&key) // Read the key to delete
			delete(key)    // Delete the node with the specified key
		}
	}
	printList() // Print the final state of the list
}

// Free the memory of a node
func free(n *Node) {
	// Implement memory deallocation here
}

// Convert a string to an integer
func atoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

// Convert a string to a slice of strings
func split(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to an integer slice
func atoiSlice(s []string) []int {
	var result []int
	for _, v := range s {
		result = append(result, atoi(v))
	}
	return result
}

// Convert a slice of strings to a string slice
func strSlice(s []string) []string {
	return s
}

// Convert a slice of strings to an integer slice
func strToIntSlice(s []string) []int {
	var result []int
	for _, v := range s {
		result = append(result, atoi(v))
	}
	return result
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	return s
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	return s
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	return s
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	return s
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	return s
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	return s
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	return s
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	return s
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	return s
}

// Convert a slice of strings to a string slice
func intSliceToStrSlice(s []int) []string {
	var result []string
	for _, v := range s {
		result = append(result, strconv.Itoa(v))
	}
	return result
}

// Convert a slice of strings to an integer slice
func strToStrSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string slice
func intToStrSlice(s int) []string {
	return []string{strconv.Itoa(s)}
}

// Convert a slice of strings to an integer slice
func strSliceToStrSlice(s []string) []string {
	ret