package main

import (
	"fmt"
)

func main() {
	// Initialize variables for number of requests and preemptions
	var n, m int
	fmt.Scan(&n, &m)

	// Create slices to store request and preemption indices
	req := make([]int, n)
	pre := make([]int, m)

	// Read request indices and store them in the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&req[i])
		// Comment: Read and store request index i
	}

	// Read preemption indices and store them in the slice
	for i := 0; i < m; i++ {
		fmt.Scan(&pre[i])
		// Comment: Read and store preemption index i
	}

	// Initialize index variables for requests and preemptions
	i := n - 1
	j := m - 1

	// Initialize answer variable
	ans := 0

	// While there are still requests and preemptions to compare
	for i >= 0 && j >= 0 {
		// If the current request can preempt the current preemption
		if req[i] > pre[j] {
			// Increment answer variable
			ans++
		} else {
			// Decrement preemption index
			j--
		}
		// Decrement request index
		i--
	}

	// Print the answer and the number of remaining requests
	fmt.Print(ans + i + 1)
}

// <END-OF-CODE>
