package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the user
	var n int
	fmt.Scan(&n)
	
	// Initialize a slice to hold the Long integers
	ans := make([]int64, n)
	
	// Read n Long integers from the user and store them in the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&ans[i])
	}
	
	// Sort the slice in ascending order
	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})
	
	// Initialize count with the largest element in the sorted slice
	count := ans[n - 1]
	
	// Iterate through the slice from the second largest element to the first
	for i := n - 2; i >= 0; i-- {
		// If the current element is less than the next element, add it to count
		if ans[i] < ans[i + 1] {
			count += ans[i]
		} else {
			// If the current element is not less, decrement it until it is less than the next element
			for ans[i] >= ans[i + 1] {
				ans[i]--
			}
			// If the decremented value is still positive, add it to count
			if ans[i] > 0 {
				count += ans[i]
			}
		}
	}
	
	// Print the final count
	fmt.Println(count)
}
