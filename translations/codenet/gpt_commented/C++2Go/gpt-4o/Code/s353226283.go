package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int // n: number of elements, k: size of the subset
	fmt.Scan(&n, &k)

	vec := make([]int, n) // Slice to store the input elements

	// Read n integers from input and store them in the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&vec[i]) // Read each integer
	}

	// Sort the slice in non-decreasing order
	sort.Ints(vec)

	ans := 1000000001 // Initialize ans to a large value to find the minimum difference

	// Iterate through the sorted slice to find the minimum difference
	for i := 0; i+k-1 < n; i++ {
		// Calculate the difference between the maximum and minimum of the current subset of size k
		diff := vec[i+k-1] - vec[i]

		// Update the minimum difference found so far
		if diff < ans {
			ans = diff // Update ans if a smaller difference is found
		}
	}

	// Output the minimum difference found
	fmt.Println(ans)
}

// <END-OF-CODE>
