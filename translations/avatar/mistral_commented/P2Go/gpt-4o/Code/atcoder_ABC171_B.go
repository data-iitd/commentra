package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	// Read two integers `n` and `k` from the standard input
	fmt.Scan(&n, &k)

	// Create a slice to hold the integers
	numbers := make([]int, n)

	// Read `n` integers from the standard input
	for i := 0; i < n; i++ {
		fmt.Scan(&numbers[i])
	}

	// Sort the slice in ascending order
	sort.Ints(numbers)

	// Calculate the sum of the first `k` elements of the sorted slice
	result := 0
	for i := 0; i < k; i++ {
		result += numbers[i]
	}

	// Print the result
	fmt.Println(result)
}

// <END-OF-CODE>
