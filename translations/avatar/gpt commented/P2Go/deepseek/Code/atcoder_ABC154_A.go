package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func solve(S string, T string, A int, B int, U string) {
	// Check if the first string S matches the string U
	if S == U {
		A -= 1 // Decrement A if S matches U
	}
	// Check if the second string T matches the string U
	if T == U {
		B -= 1 // Decrement B if T matches U
	}
	// Print the final values of A and B
	fmt.Println(A, B)
}

func main() {
	// Create a new scanner for reading input
	scanner := bufio.NewScanner(os.Stdin)
	// Read the first line of input and split it into words
	scanner.Scan()
	words := strings.Split(scanner.Text(), " ")
	S := words[0]
	T := words[1]
	// Read the second line of input and convert it to an integer
	scanner.Scan()
	A := 0
	fmt.Sscanf(scanner.Text(), "%d", &A)
	// Read the third line of input and convert it to an integer
	scanner.Scan()
	B := 0
	fmt.Sscanf(scanner.Text(), "%d", &B)
	// Read the fourth line of input
	scanner.Scan()
	U := scanner.Text()
	
	// Call the solve function with the read values
	solve(S, T, A, B, U)
}
