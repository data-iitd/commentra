package main

import (
	"fmt"
	"math"
)

func main() {
	// Define a constant for infinity
	const INF = int(1e9 + 5)

	// Create a scanner for input
	var n int
	fmt.Scan(&n)

	// Initialize slices to store the pairs
	a := make([]int, n)
	b := make([]int, n)

	// Initialize left to infinity and right to zero
	left := INF
	right := 0

	// Read the pairs and determine the minimum and maximum values
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the first element of the pair
		fmt.Scan(&b[i]) // Read the second element of the pair

		// Update left to the minimum value found in a
		left = int(math.Min(float64(left), float64(a[i])))
		// Update right to the maximum value found in b
		right = int(math.Max(float64(right), float64(b[i])))
	}

	// Check for a pair that matches the left and right bounds
	for i := 0; i < n; i++ {
		// If the current pair matches the min and max values
		if left == a[i] && right == b[i] {
			// Print the index (1-based) and exit
			fmt.Println(i + 1)
			return
		}
	}

	// If no matching pair is found, print -1
	fmt.Println(-1)
}

// <END-OF-CODE>
