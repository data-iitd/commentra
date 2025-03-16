package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n, b uint64

	// Read an unsigned long long integer from user input
	fmt.Scanf("%d", &n)

	// Calculate the number of ways to choose 2 items from n items
	// This is done using the formula: b = n * (n - 1) / 2
	b = (n * (n - 1)) / 2

	// Print the result
	fmt.Println(b)
}

// <END-OF-CODE>
