package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read input for n and k
	x := 0           // Initialize x to 0

	// Check if k is within the feasible range for placing 'L' characters
	if k <= max(n*n/2, n*n-(n*n/2)) {
		fmt.Println("YES") // Print 'YES' if k is feasible
		for i := 0; i < n; i++ { // Loop through each row
			for j := 0; j < n; j++ { // Loop through each column
				if i%2 == j%2 && x < k { // Check if the cell should be 'L'
					fmt.Print("L") // Print 'L'
					x++            // Increment x
				} else {
					fmt.Print("S") // Print 'S' otherwise
				}
			}
			fmt.Println() // Move to the next line after each row
		}
	} else {
		fmt.Println("NO") // Print 'NO' if k is not feasible
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
