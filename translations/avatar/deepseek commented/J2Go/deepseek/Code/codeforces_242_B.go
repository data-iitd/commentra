package main

import (
	"fmt"
	"math"
)

func main() {
	// Defining a constant INF for a very large number
	const INF = int(1e9 + 5)

	// Creating a Scanner object to read input
	var n int
	fmt.Scan(&n)

	// Initializing two slices to store the elements
	a := make([]int, n)
	b := make([]int, n)

	// Initializing variables to track the minimum and maximum values
	left := INF
	right := 0

	// Looping through n elements to read and update the slices and variables
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i], &b[i])
		if a[i] < left {
			left = a[i]
		}
		if b[i] > right {
			right = b[i]
		}
	}

	// Looping through the slices to find the target element
	for i := 0; i < n; i++ {
		if a[i] == left && b[i] == right {
			fmt.Println(i + 1)
			return
		}
	}

	// If no such element is found, print -1
	fmt.Println(-1)
}
