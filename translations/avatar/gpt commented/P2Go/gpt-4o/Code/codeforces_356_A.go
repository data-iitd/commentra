package main

import (
	"fmt"
)

func main() {
	// Read the values of n and m from input
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize an output slice with zeros
	out := make([]int, n)

	// Create a slice 'comp' that holds values from 2 to n+1 (inclusive)
	comp := make([]int, n)
	for i := 0; i < n; i++ {
		comp[i] = i + 2
	}

	// Process each of the m operations
	for i := 0; i < m; i++ {
		// Read the values of l, r, and x for the current operation
		var l, r, x int
		fmt.Scan(&l, &r, &x)

		// Start from the left index l
		t := l

		// Continue processing while t is within the range [l, r]
		for t <= r {
			// Get the next value from the 'comp' slice
			nextVal := comp[t-1]

			// If the current position in 'out' is still 0 and t is not equal to x
			if out[t-1] == 0 && t != x {
				// Set the output at position t-1 to x
				out[t-1] = x
			}

			// Update the 'comp' slice at position t-1 based on the current value of t and x
			if t >= x {
				comp[t-1] = r + 1
			} else {
				comp[t-1] = x
			}

			// Move to the next index as determined by nextVal
			t = nextVal
		}
	}

	// Print the final output slice, unpacking the values to display them in a single line
	for i, v := range out {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}

// <END-OF-CODE>
