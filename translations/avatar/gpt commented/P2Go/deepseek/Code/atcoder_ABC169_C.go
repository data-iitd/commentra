package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set the recursion limit to a higher value to prevent recursion depth errors
	// This is not necessary in Go, as it uses a stack-based recursion by default

	// Define a debug print function that only prints if running in a terminal environment
	// This is not necessary in Go, as it always prints to the terminal

	// Redefine input to read a line from standard input and strip trailing whitespace
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.TrimSpace(scanner.Text())

	// Define a function to read a list of integers from input
	LMIIS := func() []int {
		parts := strings.Split(input, " ")
		ints := make([]int, len(parts))
		for i, part := range parts {
			ints[i], _ = strconv.Atoi(part)
		}
		return ints
	}

	// Define a function to read a single integer from input
	II := func() int {
		ints := LMIIS()
		return ints[0]
	}

	// Constants for calculations
	const P = 1000000007 // A large prime number for modulo operations
	const INF = 10000000010 // A large number representing infinity

	// Read two values from input: one as an integer and the other as a float in string format
	parts := strings.Split(input, " ")
	sa := parts[0]
	sb := parts[1]

	// Convert the first value to an integer
	a, _ := strconv.Atoi(sa)

	// Convert the second value to an integer representing cents (by multiplying by 100)
	b, _ := strconv.Atoi(strings.ReplaceAll(sb, ".", ""))

	// Calculate and print the product of a and b, divided by 100 to get the final result
	result := a * b / 100
	fmt.Println(result)
}

