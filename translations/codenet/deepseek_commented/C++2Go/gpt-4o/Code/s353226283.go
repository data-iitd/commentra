package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read the number of elements and the subarray size

	vec := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&vec[i]) // Read each element and add it to the slice
	}

	sort.Ints(vec) // Sort the slice in ascending order

	ans := 1000000001 // Initialize the answer with a large number
	for i := 0; i+k-1 < n; i++ { // Iterate through the sorted slice
		diff := vec[i+k-1] - vec[i] // Calculate the difference between the max and min in the subarray
		if diff < ans { // Update the answer if the current difference is smaller
			ans = diff
		}
	}

	fmt.Println(ans) // Output the minimum difference
}

// <END-OF-CODE>
