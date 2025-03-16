package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	// Read n integers into a slice
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Sort the slice
	sort.Ints(arr)

	// Calculate the sum of the first k elements
	sum := 0
	for i := 0; i < k; i++ {
		sum += arr[i]
	}

	// Print the result
	fmt.Println(sum)
}

// <END-OF-CODE>
