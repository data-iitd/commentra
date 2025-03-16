package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare global variables
	var n, k, t int // n: number of elements, k: size of the subset, t: temporary variable for input
	vec := make([]int, 0) // Vector to store the input elements
	ans := 1000000001 // Initialize ans to a large value to find the minimum difference

	// Read the number of elements (n) and the size of the subset (k)
	fmt.Scan(&n, &k)

	// Read n integers from input and store them in the vector
	for i := 0; i < n; i++ {
		fmt.Scan(&t) // Read each integer
		vec = append(vec, t) // Add the integer to the vector
	}

	// Sort the vector in non-decreasing order
	sort.Ints(vec)

	// Iterate through the sorted vector to find the minimum difference
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

