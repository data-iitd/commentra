package main

import (
	"fmt"
)

func main() {
	// Read the input from the user
	var n, m int
	fmt.Scan(&n, &m)

	// Calculate the quotient and remainder of n divided by m
	q := n / m
	r := n % m

	// Initialize a slice with q repeated m times
	a := make([]int, m)
	for i := range a {
		a[i] = q
	}

	// Increment the corresponding elements in the a slice for the remaining elements
	for i := 0; i < r; i++ {
		a[i]++
	}

	// Print each element of the a slice separated by a space
	for i := 0; i < m; i++ {
		fmt.Print(a[i], " ")
	}
}

// <END-OF-CODE>
