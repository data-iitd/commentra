package main

import (
	"fmt"
	"strconv"
)

// Initialize stack top to 0
var top int = 0
var S [10000]int

// Function to push an element onto the stack
func push(x int) {
	// Increment the top index and push the element
	top++
	S[top] = x
}

// Function to pop an element from the stack
func pop() int {
	// Return the top element and decrement the top index
	top--
	return S[top+1]
}

// Main function
func main() {
	// Initialize variables
	var a, b int
	var s string

	// Initialize stack top to 0
	top = 0

	// Read input until end of file
	for {
		fmt.Scan(&s)
		if s == "