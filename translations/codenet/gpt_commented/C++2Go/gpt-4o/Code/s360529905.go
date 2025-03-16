package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	// Read the number of elements
	fmt.Scan(&N)

	// Dynamically allocate memory for two slices of size N
	a := make([]int, N)
	b := make([]int, N)

	// Read elements into slice 'a' and copy them to slice 'b'
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i]) // Read element into slice 'a'
		b[i] = a[i]     // Copy element from 'a' to 'b'
	}

	// Sort the slice 'b' to find the median values
	sort.Ints(b)

	// Determine the two middle values (for even-sized arrays)
	frontHalf := b[N/2-1] // Value just before the median
	backHalf := b[N/2]    // Median value

	// Output the appropriate value based on the original slice 'a'
	for i := 0; i < N; i++ {
		// If the current element is less than the backHalf (median), print backHalf
		if a[i] < backHalf {
			fmt.Println(backHalf)
		} else {
			// Otherwise, print frontHalf
			fmt.Println(frontHalf)
		}
	}
}

// <END-OF-CODE>
