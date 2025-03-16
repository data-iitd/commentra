package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements
	ans := make([]int64, n) // Initialize slice to store int64 integers

	// Populate the slice with input values
	for i := 0; i < n; i++ {
		fmt.Scan(&ans[i])
	}

	// Sort the slice in ascending order
	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	// Initialize count with the largest element in the slice
	count := ans[n-1]

	// Iterate through the slice from the second-to-last element to the first
	for i := n - 2; i >= 0; i-- {
		if ans[i] < ans[i+1] {
			count += ans[i] // Add the current element to count if it's less than the next element
		} else {
			for ans[i] >= ans[i+1] {
				ans[i]-- // Decrease the current element until it's less than the next element
			}
			if ans[i] > 0 {
				count += ans[i] // Add the adjusted current element to count
			}
		}
	}

	// Print the final count
	fmt.Println(count)
}

// <END-OF-CODE>
