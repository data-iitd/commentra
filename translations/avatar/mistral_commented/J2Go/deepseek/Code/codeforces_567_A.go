package main

import (
	"fmt"
)

func main() {
	// Reading the size of the array from user input
	var a int
	fmt.Scan(&a)

	// Initializing the array with the given size
	ar := make([]int, a)

	// Reading array elements from user input
	for i := 0; i < a; i++ {
		fmt.Scan(&ar[i])
	}

	// Initializing variables for storing maximum and minimum differences
	var max, min int

	// Finding maximum and minimum differences between consecutive elements in the array
	for i := 0; i < len(ar); i++ {
		// Finding maximum difference between current element and first element
		max = maxInt(ar[i]-ar[0], ar[len(ar)-1]-ar[i])

		// Finding minimum difference between current element and previous element
		if i == 0 {
			min = ar[i+1] - ar[i] // For the first element, minimum difference is between current and next element
		} else if i == len(ar)-1 {
			min = ar[i] - ar[i-1] // For the last element, minimum difference is between current and previous element
		} else {
			min = minInt(ar[i]-ar[i-1], ar[i+1]-ar[i]) // For other elements, minimum difference is between current and previous or next element, whichever is smaller
		}

		// Printing minimum and maximum differences for each pair of consecutive elements
		fmt.Println(min, max)
	}
}

// Helper function to find the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to find the minimum of two integers
func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

