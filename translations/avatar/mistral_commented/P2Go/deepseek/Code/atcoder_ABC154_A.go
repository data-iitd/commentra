package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Define a function named 'solve' that takes five arguments: S, T, A, B, and U.
func solve(S string, T string, A int, B int, U string) {

	// Check if S is equal to U. If yes, decrement A.
	if S == U {
		A -= 1
	}

	// Check if T is equal to U. If yes, decrement B.
	if T == U {
		B -= 1
	}

	// Print the updated values of A and B.
	fmt.Println(A, B)
}

// Define a function named 'main' that doesn't take any arguments.
func main() {

	// Create a new scanner to read input from standard input.
	scanner := bufio.NewScanner(os.Stdin)

	// Read the next line of input and split it into words.
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")

	// Assign the parts to variables S, T, A, B, and U.
	S := parts[0]
	T := parts[1]
	A := toInt(parts[2])
	B := toInt(parts[3])
	U := parts[4]

	// Call the 'solve' function with the assigned variables.
	solve(S, T, A, B, U)
}

// Helper function to convert a string to an integer.
func toInt(s string) int {
	var i int
	fmt.Sscanf(s, "%d", &i)
	return i
}

