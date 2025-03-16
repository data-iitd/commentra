package main

import (
	"fmt"
)

func main() {
	var n, d int
	// Read the number of elements in the array and the difference d from the input
	fmt.Scan(&n, &d)

	// Create a slice to store the numbers
	nums := make([]int, n)

	// Read the numbers in the array from the input
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i]) // Read the next number and store it in the slice
	}

	// Initialize variables for calculating the result and the difference between two consecutive numbers
	result := 0
	var a int

	// Iterate through the slice starting from the second element
	for i := 1; i < n; i++ {
		// Calculate the difference between the current and previous numbers
		a = nums[i-1] - nums[i]

		// If the difference is positive, add the number of jumps to the result and update the current number in the slice
		if a >= 0 {
			result += a/d + 1
			nums[i] += (a/d + 1) * d
		}
	}

	// Print the result to the console
	fmt.Println(result)
}

// <END-OF-CODE>
