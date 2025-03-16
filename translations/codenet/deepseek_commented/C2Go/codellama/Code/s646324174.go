package main

import (
	"fmt"
	"strconv"
)

// Define the stack array and top variable
var top int
var S [10000]int

// Function to push an element onto the stack
func push(x int) {
	S[top] = x
	top++
}

// Function to pop an element from the stack
func pop() int {
	top--
	return S[top]
}

// Main function to read input, perform operations, and print the result
func main() {
	var a, b int
	var s string
	top = 0 // Initialize the top of the stack

	// Read input until end of file
	for {
		fmt.Scan(&s)
		if s == "