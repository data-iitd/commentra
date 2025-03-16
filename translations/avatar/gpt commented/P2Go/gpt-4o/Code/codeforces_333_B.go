package main

import (
	"fmt"
)

func main() {
	var n, m int
	// Read the values of n and m from input
	fmt.Scan(&n, &m)

	// Initialize a slice b of size 2*n with all elements set to 1
	// This slice will represent the state of the cells (1 for unblocked, 0 for blocked)
	b := make([]int, n*2)
	for i := range b {
		b[i] = 1
	}

	// Set specific positions in the slice b to 0 to indicate they are blocked
	// The first and last elements of the first half and the last half are blocked
	b[0] = 0
	b[n-1] = 0
	b[n] = 0
	b[2*n-1] = 0

	// Process each blocked cell based on user input
	for i := 0; i < m; i++ {
		var r, c int
		// Read the row (r) and column (c) of the blocked cell
		fmt.Scan(&r, &c)
		// Mark the corresponding positions in the slice b as blocked (0)
		b[r-1] = 0
		b[n+c-1] = 0
	}

	// If n is odd and the middle cells are unblocked, block them
	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}

	// Output the total number of unblocked cells by summing the slice b
	totalUnblocked := 0
	for _, value := range b {
		totalUnblocked += value
	}
	fmt.Println(totalUnblocked)
}

// <END-OF-CODE>
