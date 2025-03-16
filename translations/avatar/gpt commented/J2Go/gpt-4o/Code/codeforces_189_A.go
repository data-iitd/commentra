package main

import (
	"fmt"
)

func main() {
	// Read the total number of items (n) to be processed
	var n int
	fmt.Scan(&n)

	// Define the maximum size for the dp array
	const maxn = 4010

	// Read three integer values (a, b, c) which represent the sizes of items
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	// Store the sizes of items in a slice for easier access
	arr := []int{a, b, c}

	// Initialize a dp slice to store the maximum number of items that can be formed
	dp := make([]int, maxn)

	// Set all dp values to a very small number to indicate uncomputed states
	for i := 0; i < n; i++ {
		dp[i] = -1 << 31 // Equivalent to Integer.MIN_VALUE in Java
	}

	// Base case: zero items can be formed with zero size
	dp[0] = 0

	// Iterate through each item size (a, b, c)
	for i := 0; i < 3; i++ {
		// Update the dp slice for each possible size from the current item size
		for j := arr[i]; j < len(dp); j++ {
			// Calculate the maximum number of items that can be formed
			dp[j] = max(dp[j], dp[j-arr[i]]+1)
		}
	}

	// Output the maximum number of items that can be formed with size n
	fmt.Println(dp[n])
}

// max function to return the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// <END-OF-CODE>
