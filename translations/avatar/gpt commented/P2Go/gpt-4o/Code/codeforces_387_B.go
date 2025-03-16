package main

import (
	"fmt"
)

func main() {
	// Read the number of rounds (n) and the number of George's complexities (m)
	var n, m int
	fmt.Scan(&n, &m)

	// Read the complexities for each round into a slice
	roundComplexity := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&roundComplexity[i])
	}

	// Read George's complexities into another slice
	georgeComplexity := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&georgeComplexity[i])
	}

	// Initialize indices for both slices
	i, j := 0, 0

	// Iterate through both slices to compare complexities
	for i < n && j < m {
		// If the current round's complexity is less than or equal to George's complexity,
		// move to the next round
		if roundComplexity[i] <= georgeComplexity[j] {
			i++
		}
		// Always move to the next complexity of George
		j++
	}

	// Output the number of rounds that George cannot handle
	fmt.Println(n - i)
}

// <END-OF-CODE>
