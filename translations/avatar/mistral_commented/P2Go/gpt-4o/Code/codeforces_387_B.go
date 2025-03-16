package main

import (
	"fmt"
)

func main() {
	// Initialize variables n and m with the given input
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize slices roundComplexity and georgeComplexity with the given input
	roundComplexity := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&roundComplexity[i])
	}

	georgeComplexity := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&georgeComplexity[i])
	}

	// Initialize variables i and j to 0
	i, j := 0, 0

	// Start the while loop that compares the complexity of each
	// round with George's complexity and moves the pointers accordingly
	for i < n && j < m {
		// Increment i if the complexity of the current round is
		// less than or equal to George's complexity at the current j
		if roundComplexity[i] <= georgeComplexity[j] {
			i++
		}
		// Increment j
		j++
	}

	// Print the final answer
	fmt.Println(n - i)
}

// <END-OF-CODE>
