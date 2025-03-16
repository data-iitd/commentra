package main

import (
	"fmt"
)

func main() {
	// Read two integers n and d from input
	var n, d int
	fmt.Scan(&n, &d)

	// Initialize a slice to store the elements
	x := make([]int, n)
	// Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
	m := 0

	// Read the elements of the list from input
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}

	// Iterate through the list to compare adjacent elements
	for a := 0; a < n-1; a++ {
		// Check if the current element is greater than or equal to the next element
		if x[a] >= x[a+1] {
			// Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
			q := (x[a] - x[a+1]) / d + 1
			// Update the total adjustments made
			m += q
			// Adjust the next element by adding the necessary increments of d
			x[a+1] += q * d
		}
	}

	// Print the total number of adjustments made
	fmt.Println(m)
}

// <END-OF-CODE>
