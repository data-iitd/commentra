package main

import (
	"fmt"
)

func main() {
	// Read the number of elements in the array
	var n int
	fmt.Scan(&n)

	// Read the array elements from input
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Initialize an answer array with zeros, which will store the results
	ans := make([]int, n)

	// Set the maximum value to the last element of the array
	mx := arr[n-1]

	// Iterate through the array from the second last element to the first
	for i := n - 2; i >= 0; i-- {
		// Calculate the required value for ans[i] based on the difference from the maximum
		ans[i] = max(0, mx-arr[i]+1)

		// Update the maximum value if the current element is greater than the current maximum
		if arr[i] > mx {
			mx = arr[i]
		}
	}

	// Print the result array as space-separated values
	for i, v := range ans {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}

// Helper function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
