package main

import (
	"fmt"
)

// Function to solve the problem
func solve() {
	// Initialize variables
	var a, b int

	// Read input values from the user
	fmt.Scan(&a, &b)

	// Initialize output string
	var ans string

	// Determine the answer based on the input values
	if a == 1 && b == 1 {
		// Both a and b are equal to 1, so the answer is a draw
		ans = "Draw"
	} else if a == 1 {
		// a is equal to 1, so the answer is Alice
		ans = "Alice"
	} else {
		// Neither a nor b is equal to 1, so the answer is Bob
		ans = "Bob"
	}

	// Print the answer to the console
	fmt.Println(ans)
}

func main() {
	// Call the solve function to solve the problem
	solve()
}

// <END-OF-CODE>
