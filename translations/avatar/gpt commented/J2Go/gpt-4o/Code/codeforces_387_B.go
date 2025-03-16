package main

import (
	"fmt"
)

func main() {
	// Create a scanner to read input from the console
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize slices to store the required items and the available items
	req := make([]int, n)
	pre := make([]int, m)

	// Read the required items from the input and store them in the req slice
	for i := 0; i < n; i++ {
		fmt.Scan(&req[i])
	}

	// Read the available items from the input and store them in the pre slice
	for i := 0; i < m; i++ {
		fmt.Scan(&pre[i])
	}

	// Initialize pointers for the required items (i) and available items (j)
	i, j := n-1, m-1

	// Variable to count how many required items can be satisfied
	ans := 0

	// Compare the required items with the available items from the end of both slices
	for i >= 0 && j >= 0 {
		// If the current required item is greater than the current available item
		if req[i] > pre[j] {
			// Increment the count of satisfied items
			ans++
		} else {
			// Move to the next available item if the current one cannot satisfy the requirement
			j--
		}
		// Move to the next required item
		i--
	}

	// Print the total number of satisfied items plus the remaining unsatisfied required items
	fmt.Print(ans + i + 1)
}

// <END-OF-CODE>
