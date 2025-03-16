package main

import (
	"fmt"
)

func solve(n int) int {
	// Calculate the sum of the first n natural numbers
	s := (1 + n) * n / 2
	// Initialize t to 1
	t := 1
	// Subtract twice the sum of powers of 2 up to n from s
	for t <= n {
		s -= 2 * t
		t *= 2
	}
	return s
}

func main() {
	var t int
	fmt.Scan(&t) // Read the number of test cases

	for i := 0; i < t; i++ {
		var n int
		fmt.Scan(&n) // Read each n for the test case
		fmt.Println(solve(n)) // Print the result of the solve function for the current n
	}
}

