package main

import (
	"fmt"
)

// Function to solve the problem
func solve() {
	var n int // Declare variable for input
	fmt.Scan(&n) // Read input value for n
	fmt.Println(n == 0) // Output the negation of n (true if n is zero, false if n is non-zero)
}

// Main function
func main() {
	n := 1 // Initialize n to 1 (can be modified to read input)
	for n > 0 {
		solve() // Call the solve function n times
		n--
	}
}

// <END-OF-CODE>
