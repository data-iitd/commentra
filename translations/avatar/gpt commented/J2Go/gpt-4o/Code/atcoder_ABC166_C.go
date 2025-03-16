package main

import (
	"fmt"
)

func main() {
	// Read the number of elements (N) and the number of comparisons (M)
	var N int
	var M int64
	fmt.Scan(&N, &M)

	// Initialize a slice to hold the heights and a boolean slice to track valid heights
	H := make([]int64, N)
	ans := make([]bool, N)

	// Read the heights and initialize the ans slice to true
	for i := 0; i < N; i++ {
		fmt.Scan(&H[i]) // Read the height for each element
		ans[i] = true   // Assume all heights are valid initially
	}

	// Process M comparisons between pairs of heights
	for i := int64(0); i < M; i++ {
		var temp1, temp2 int
		fmt.Scan(&temp1, &temp2) // Read the first and second index for comparison

		// Compare the heights and update the ans slice based on the comparison results
		if H[temp1-1] < H[temp2-1] {
			ans[temp1-1] = false // temp1 is shorter, mark it as invalid
		} else if H[temp1-1] > H[temp2-1] {
			ans[temp2-1] = false // temp2 is shorter, mark it as invalid
		} else {
			// If heights are equal, mark both as invalid
			ans[temp1-1] = false
			ans[temp2-1] = false
		}
	}

	// Count the number of valid heights
	ans2 := 0
	for i := 0; i < N; i++ {
		if ans[i] {
			ans2++ // Increment count for each valid height
		}
	}

	// Output the count of valid heights
	fmt.Println(ans2)
}

// <END-OF-CODE>
