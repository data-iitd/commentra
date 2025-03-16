
package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Read the list of integers and convert them to a list of integers
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize the previous value to infinity
	pre := int(^uint(0) >> 1)

	// Initialize the answer variable to accumulate the result
	ans := 0

	// Sort the list in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(a)))

	// Iterate through the sorted list
	for j := 0; j < n; j++ {
		// Calculate the current contribution to the answer
		// It takes the minimum of (pre - 1) and the current element a[j], ensuring it's non-negative
		ans += max(0, min(pre-1, a[j]))

		// Update the previous value for the next iteration
		pre = max(0, min(pre-1, a[j]))
	}

	// Print the final accumulated answer
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

