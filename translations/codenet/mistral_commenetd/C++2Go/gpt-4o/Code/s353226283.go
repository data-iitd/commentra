package main

import (
	"fmt"
	"sort"
)

func main() {
	// Define input variables
	var n, k int
	var t int
	var vec []int
	ans := 1000000001

	// Read input values for n and k
	fmt.Scan(&n, &k)

	// Initialize vector 'vec' with size 'n'
	for i := 0; i < n; i++ {
		// Read input value for 't' and add it to the vector
		fmt.Scan(&t)
		vec = append(vec, t)
	}

	// Sort the vector 'vec' in ascending order
	sort.Ints(vec)

	// Iterate through the vector with a sliding window of size 'k'
	for i := 0; i+k-1 < n; i++ {
		// Calculate the difference between the last and first element of the current window
		diff := vec[i+k-1] - vec[i]

		// Update the answer if the current difference is smaller than the previous one
		if diff < ans {
			ans = diff
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
