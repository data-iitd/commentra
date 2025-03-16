package main

import (
	"fmt"
)

func main() {
	const N = 368

	// Initialize slices to store changes for males and females
	m := make([]int, N)
	f := make([]int, N)

	var operations int
	fmt.Scan(&operations)

	// Read the number of operations
	for i := 0; i < operations; i++ {
		var gender string
		var a, b int
		fmt.Scan(&gender, &a, &b)
		b++ // Increment b to account for the end time

		// Update the changes in the slices based on gender
		if gender == "M" {
			m[a] += 2
			m[b] -= 2
		} else {
			f[a] += 2
			f[b] -= 2
		}
	}

	// Initialize variables to store the maximum number of people and the current number of people
	var maleCount, femaleCount, maxCount int

	// Calculate the cumulative sum of changes and find the maximum number of people at any time slot
	for i := 0; i < N; i++ {
		maleCount += m[i]
		femaleCount += f[i]
		if min(maleCount, femaleCount) > maxCount {
			maxCount = min(maleCount, femaleCount)
		}
	}

	// Print the maximum number of people at any time slot
	fmt.Println(maxCount)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
