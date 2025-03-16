package main

import (
	"fmt"
	"sort"
)

func main() {
	var x, y, z, k int
	fmt.Scan(&x, &y, &z, &k)

	a := make([]int, x)
	for i := 0; i < x; i++ {
		fmt.Scan(&a[i])
	}

	b := make([]int, y)
	for i := 0; i < y; i++ {
		fmt.Scan(&b[i])
	}

	c := make([]int, z)
	for i := 0; i < z; i++ {
		fmt.Scan(&c[i])
	}

	// Initialize a slice to store the sums of elements from lists a and b
	ab := make([]int, 0, x*y)

	// Calculate all possible sums of elements from list a and list b
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i]+b[j])
		}
	}

	// Sort the list of sums in descending order
	sort.Slice(ab, func(i, j int) bool {
		return ab[i] > ab[j]
	})

	// Initialize a slice to store the sums of the top k elements from ab and elements from list c
	abc := make([]int, 0)

	// Calculate sums of the top k elements from ab with each element in c
	for i := 0; i < min(k, len(ab)); i++ {
		for j := 0; j < z; j++ {
			abc = append(abc, ab[i]+c[j])
		}
	}

	// Sort the resulting sums in descending order
	sort.Slice(abc, func(i, j int) bool {
		return abc[i] > abc[j]
	})

	// Print the top k sums from the final list abc
	for i := 0; i < k; i++ {
		fmt.Println(abc[i])
	}
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
