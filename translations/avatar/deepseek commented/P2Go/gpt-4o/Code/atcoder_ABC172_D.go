package main

import (
	"fmt"
)

func main() {
	var N int
	// Read the integer value of N from standard input.
	fmt.Scan(&N)

	// Initialize the variable ans to 0.
	ans := 0

	// Start a loop that iterates from 1 to N + 1.
	for i := 1; i <= N; i++ {
		// Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
		ans += i * (N / i) * (N/i + 1) / 2
	}

	// Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
	fmt.Println(ans)
}

// <END-OF-CODE>
