package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements from standard input
	var n int
	fmt.Scan(&n)

	// Initialize a slice to hold the input integers
	a := make([]int, n)
	// Read n integers from standard input into the slice a
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize a slice b to hold the longest increasing subsequence
	b := make([]int, 0, n)
	// Iterate over each value in the input slice a
	for _, v := range a {
		// Use binary search to find the index where v can be placed in b
		x := sort.Search(len(b), func(i int) bool {
			return b[i] < v
		})
		// If v is greater than all elements in b, append it to b
		if x == len(b) {
			b = append(b, v)
		} else {
			// Otherwise, replace the existing value at index x with v
			b[x] = v
		}
	}

	// Output the length of the longest increasing subsequence
	fmt.Println(len(b))
}
