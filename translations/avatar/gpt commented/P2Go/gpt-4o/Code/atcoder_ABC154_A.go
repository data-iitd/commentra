package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(S string, T string, A int, B int, U string) {
	// Check if the first string S matches the string U
	if S == U {
		A-- // Decrement A if S matches U
	}
	// Check if the second string T matches the string U
	if T == U {
		B-- // Decrement B if T matches U
	}
	// Print the final values of A and B
	fmt.Println(A, B)
}

func main() {
	// Read all input from standard input
	input, err := os.ReadFile("/dev/stdin")
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	// Split the input into tokens
	tokens := strings.Fields(string(input))

	// Read the first string S from input
	S := tokens[0]
	// Read the second string T from input
	T := tokens[1]
	// Read the integer A from input and convert it to an integer
	A, _ := strconv.Atoi(tokens[2])
	// Read the integer B from input and convert it to an integer
	B, _ := strconv.Atoi(tokens[3])
	// Read the string U from input
	U := tokens[4]

	// Call the solve function with the read values
	solve(S, T, A, B, U)
}

// <END-OF-CODE>
