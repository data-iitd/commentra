package main

import (
	"fmt"
)

func main() {
	// Read two integers n and k from input
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize a counter to keep track of the number of 'L' printed
	x := 0

	// Check if k is less than or equal to the maximum number of 'L' that can be printed
	if k <= max(n*n/2, n*n-(n*n/2)) {
		// If the condition is satisfied, print 'YES'
		fmt.Println("YES")

		// Iterate over each row of the n x n grid
		for i := 0; i < n; i++ {
			// Iterate over each column of the n x n grid
			for j := 0; j < n; j++ {
				// Check if the current position (i, j) is in the same parity group and if we can still print 'L'
				if i%2 == j%2 && x < k {
					// Print 'L' and increment the counter
					fmt.Print("L")
					x++
				} else {
					// Print 'S' if the conditions for 'L' are not met
					fmt.Print("S")
				}
			}
			// Move to the next line after finishing a row
			fmt.Println()
		}
	} else {
		// If k is greater than the maximum possible 'L', print 'NO'
		fmt.Println("NO")
	}
}

// Helper function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
