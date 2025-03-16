package main

import (
	"fmt"
)

func main() {
	var n, d int
	fmt.Scan(&n) // Read the number of elements
	fmt.Scan(&d) // Read the difference threshold
	nums := make([]int, n) // Initialize a slice to store the numbers

	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i]) // Read the numbers and store them in the slice
	}

	result := 0 // Initialize the result variable to 0
	var a int   // Initialize another variable to store the difference

	for i := 1; i < n; i++ {
		a = nums[i-1] - nums[i] // Calculate the difference between consecutive elements
		if a >= 0 {
			result += a/d + 1 // Update the result based on the difference
			nums[i] += (a/d + 1) * d // Adjust the current element to meet the condition
		}
	}

	fmt.Println(result) // Print the final result
}

// <END-OF-CODE>
