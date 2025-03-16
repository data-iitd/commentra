package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n int
	// Read the number of elements
	fmt.Scan(&n)

	// Read the list of integers
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize the previous value to infinity
	pre := math.Inf(1)

	// Initialize the answer variable to accumulate the result
	ans := 0

	// Sort the list in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(a)))

	// Iterate through the sorted list
	for j := 0; j < n; j++ {
		// Calculate the current contribution to the answer
		// It takes the minimum of (pre - 1) and the current element a[j], ensuring it's non-negative
		current := int(math.Max(0, math.Min(pre-1, float64(a[j]))))
		ans += current

		// Update the previous value for the next iteration
		pre = math.Max(0, math.Min(pre-1, float64(a[j])))
	}

	// Print the final accumulated answer
	fmt.Println(ans)
}

// <END-OF-CODE>
