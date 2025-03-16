package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read two integers from input: n (total items) and m (number of groups)

	q := n / m // Calculate the quotient (q) when n is divided by m
	r := n % m // Calculate the remainder (r)

	a := make([]int, m) // Create a slice 'a' initialized with 'm' elements

	for i := 0; i < m; i++ {
		a[i] = q // Initialize each group with the quotient 'q'
	}

	// Distribute the remainder 'r' among the first 'r' groups
	for i := 0; i < r; i++ {
		a[i]++ // Increment the count for the first 'r' groups by 1
	}

	// Print the final distribution of items in each group
	for i := 0; i < m; i++ {
		fmt.Print(a[i], " ") // Print each group's item count on the same line
	}
}

// <END-OF-CODE>
