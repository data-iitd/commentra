package main

import (
	"bufio"
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	// Read the string S
	S := parts[0]
	// Read the string T
	T := parts[1]
	// Read the integer A
	A, _ := strconv.Atoi(parts[2])
	// Read the integer B
	B, _ := strconv.Atoi(parts[3])
	// Read the string U
	U := parts[4]
	// Call the solve function with the read inputs
	solve(S, T, A, B, U)
}
