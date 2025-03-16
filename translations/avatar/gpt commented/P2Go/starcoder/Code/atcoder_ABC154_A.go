package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the first string S from input
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')
	// Read the second string T from input
	T, _ := reader.ReadString('\n')
	// Read the integer A from input and convert it to an integer
	A, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	// Read the integer B from input and convert it to an integer
	B, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	// Read the string U from input
	U, _ := reader.ReadString('\n')

	// Call the solve function with the read values
	solve(S, T, A, B, U)
}

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

