package main

import (
	"fmt"
	"sort"
)

func main() {
	var x, y, z, k int
	fmt.Scan(&x, &y, &z, &k)

	a := make([]int, x)
	b := make([]int, y)
	c := make([]int, z)

	for i := 0; i < x; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < y; i++ {
		fmt.Scan(&b[i])
	}
	for i := 0; i < z; i++ {
		fmt.Scan(&c[i])
	}

	// Initialize an empty slice ab to store the sum of each element from list a with each element from list b
	ab := make([]int, 0, x*y)

	// Iterate through each element in list a and b, appending their sum to list ab
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i]+b[j])
		}
	}

	// Sort list ab in descending order
	sort.Slice(ab, func(i, j int) bool {
		return ab[i] > ab[j]
	})

	// Initialize an empty slice abc to store the sum of each element from list ab with each element from list c
	abc := make([]int, 0, k*z)

	// Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z, append their sum to list abc
	for i := 0; i < min(k, x*y); i++ {
		for j := 0; j < z; j++ {
			abc = append(abc, ab[i]+c[j])
		}
	}

	// Sort list abc in descending order
	sort.Slice(abc, func(i, j int) bool {
		return abc[i] > abc[j]
	})

	// Iterate through the first k elements of list abc and print each element
	for i := 0; i < k; i++ {
		fmt.Println(abc[i])
	}
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
