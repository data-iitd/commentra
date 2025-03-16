package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a function named 'solve' that takes five arguments: S, T, A, B, and U.
func solve(S string, T string, A int, B int, U string) {
	// Check if S is equal to U. If yes, decrement A.
	if S == U {
		A--
	}

	// Check if T is equal to U. If yes, decrement B.
	if T == U {
		B--
	}

	// Print the updated values of A and B.
	fmt.Println(A, B)
}

// Define a function named 'main' that doesn't take any arguments.
func main() {
	// Read input from standard input.
	var input string
	_, err := fmt.Scan(&input)
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	// Split the input into tokens.
	tokens := strings.Fields(input)

	// Assign the tokens to variables S, T, A, B, and U.
	S := tokens[0]
	T := tokens[1]
	A, _ := strconv.Atoi(tokens[2])
	B, _ := strconv.Atoi(tokens[3])
	U := tokens[4]

	// Call the 'solve' function with the assigned variables.
	solve(S, T, A, B, U)
}

// <END-OF-CODE>
