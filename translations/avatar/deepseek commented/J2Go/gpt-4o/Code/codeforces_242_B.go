package main

import (
	"fmt"
	"math"
)

const INF = int(1e9 + 5)

func main() {
	var n int
	fmt.Scan(&n) // Reading the integer value of n

	// Initializing slices to store the elements
	a := make([]int, n)
	b := make([]int, n)

	// Initializing variables to track the minimum and maximum values
	left := INF
	right := 0

	// Looping through n elements to read and update the slices and variables
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Reading element into slice a
		fmt.Scan(&b[i]) // Reading element into slice b
		left = min(left, a[i]) // Updating left with the minimum value
		right = max(right, b[i]) // Updating right with the maximum value
	}

	// Looping through the slices to find the target element
	for i := 0; i < n; i++ {
		if left == a[i] && right == b[i] {
			fmt.Println(i + 1) // Printing the 1-based index of the target element
			return // Returning from the method after finding the target
		}
	}

	// If no such element is found, print -1
	fmt.Println(-1)
}

// Helper function to find the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// Helper function to find the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
