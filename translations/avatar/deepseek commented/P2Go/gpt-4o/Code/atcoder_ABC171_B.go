package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	// Read the integers into a slice
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	// Sort the slice
	sort.Ints(nums)

	// Calculate the sum of the first k smallest numbers
	sum := 0
	for i := 0; i < k; i++ {
		sum += nums[i]
	}

	// Print the result
	fmt.Println(sum)
}

// <END-OF-CODE>
