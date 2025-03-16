package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line from standard input and return it as a string
func readString() string {
	var input string
	fmt.Scanln(&input)
	return input
}

// Function to read a single integer from standard input
func readInt() int {
	input := readString()
	value, _ := strconv.Atoi(input)
	return value
}

// Function to read a list of integers from standard input
func readIntSlice() []int {
	input := readString()
	parts := strings.Fields(input)
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func main() {
	// Read the number of test cases from standard input
	N := readInt()

	// Initialize the answer to 0
	ans := 0

	// Iterate through all numbers from 1 to N
	for i := 1; i <= N; i++ {
		// Calculate the contribution of i to the answer
		ans += i * (N / i) * (N/i + 1) / 2
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
