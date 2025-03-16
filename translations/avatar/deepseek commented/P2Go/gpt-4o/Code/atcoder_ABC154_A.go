package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(S string, T string, A int, B int, U string) {
	// Check if the string S is equal to the string U
	if S == U {
		// Decrement the count of A by 1
		A--
	}
	// Check if the string T is equal to the string U
	if T == U {
		// Decrement the count of B by 1
		B--
	}
	// Print the updated counts of A and B
	fmt.Println(A, B)
}

func main() {
	var S, T, U string
	var A, B int

	// Read input from standard input
	input := make([]byte, 1024)
	n, _ := os.Stdin.Read(input)
	tokens := strings.Fields(string(input[:n]))

	// Read the string S
	S = tokens[0]
	// Read the string T
	T = tokens[1]
	// Read the integer A
	A, _ = strconv.Atoi(tokens[2])
	// Read the integer B
	B, _ = strconv.Atoi(tokens[3])
	// Read the string U
	U = tokens[4]

	// Call the solve function with the read inputs
	solve(S, T, A, B, U)
}

// <END-OF-CODE>
