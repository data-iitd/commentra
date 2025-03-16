package main

import (
	"fmt"
)

func main() {
	// Reading the number of elements (n) and the divisor (d) from user input
	var n, d int
	fmt.Scan(&n, &d)

	// Initializing a slice to hold the numbers
	nums := make([]int, n)

	// Reading n integers from user input and storing them in the nums slice
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	// Initializing result variable to count the total adjustments made
	result := 0

	// Looping through the nums slice starting from the second element
	for i := 1; i < n; i++ {
		// Calculating the difference between the previous and current element
		a := nums[i-1] - nums[i]

		// If the difference is non-negative, adjustments are needed
		if a >= 0 {
			// Calculating how many times we can adjust the current element
			result += a/d + 1

			// Adjusting the current element to maintain the required condition
			nums[i] += (a/d + 1) * d
		}
	}

	// Printing the total number of adjustments made
	fmt.Println(result)
}

// <END-OF-CODE>
