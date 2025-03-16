package main

import (
	"fmt"
)

func main() {
	var n, m int // Declare variables n and m of type int

	fmt.Scan(&n, &m) // Read input values of n and m from standard input

	ans := 0 // Initialize answer variable ans to 0

	// Calculate the sum of combinations for n
	ans += n * (n - 1) / 2 // Calculate the sum of numbers from 1 to n-1 and add it to the answer

	// Calculate the sum of combinations for m
	ans += m * (m - 1) / 2 // Calculate the sum of numbers from 1 to m-1 and add it to the answer

	fmt.Println(ans) // Print the answer to the standard output
}

// <END-OF-CODE>
