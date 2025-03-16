package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewReader(os.Stdin) // Initialize buffered reader for fast input
	var n int
	fmt.Fscan(in, &n) // Read the value of n
	left := make([]int, n) // Initialize a slice to keep track of indices
	for i := 0; i < n; i++ {
		left[i] = i // Add indices from 0 to n-1 to the slice
	}
	answer := make([]int, n) // Initialize a slice to store the results

	var q int
	fmt.Fscan(in, &q) // Read the number of queries
	for i := 0; i < q; i++ { // Process each query
		var l, r, win int
		fmt.Fscan(in, &l, &r, &win) // Read the left index, right index, and winning index
		l-- // Adjust for 0-based indexing
		r-- // Adjust for 0-based indexing
		win-- // Adjust for 0-based indexing

		// Create a temporary slice to hold the valid indices
		validIndices := []int{}
		for _, idx := range left {
			if idx >= l && idx <= r {
				validIndices = append(validIndices, idx)
			}
		}

		// Assign the winning index to the current elements in the range
		for _, curr := range validIndices {
			answer[curr] = win + 1 // Store the winning index (adjusted back to 1-based)
		}

		answer[win] = 0 // Set the winning index to 0
		left = append(left[:win], left[win+1:]...) // Remove the winning index from the slice
	}

	// Build the result string
	result := ""
	for _, ans := range answer {
		result += fmt.Sprintf("%d", ans) // Append each element of the answer slice to the result
	}
	fmt.Println(result) // Print the final result
}

// <END-OF-CODE>
