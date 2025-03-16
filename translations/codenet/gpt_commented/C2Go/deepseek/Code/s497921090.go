package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n, a, b uint64 = 0, 0, 0

	// Read an unsigned long long integer from user input
	fmt.Scan(&n)

	// Calculate the number of ways to choose 2 items from n items
	// This is done using the formula: b = n * (n - 1) / 2
	b = (n * (n - 1)) / 2

	// Print the result
	fmt.Println(b)
}

