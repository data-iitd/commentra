package main

import (
	"fmt"
)

func main() {
	// Read input: two integers n and k
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize variable x to 0
	x := 0

	// Check if k is valid based on the condition
	if k <= max(n*n/2, n*n-(n*n/2)) {
		// If k is valid, print 'YES'
		fmt.Println("YES")

		// Iterate through rows and columns of the grid
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				// Check if current position (i, j) is valid based on the condition
				if i%2 == j%2 && x < k {
					// If valid, print 'L' and increment x
					fmt.Print("L")
					x++
				} else {
					// If not valid, print 'S'
					fmt.Print("S")
				}
			}
			// Move to the next line after completing a row
			fmt.Println()
		}
	} else {
		// If k is not valid, print 'NO'
		fmt.Println("NO")
	}
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
