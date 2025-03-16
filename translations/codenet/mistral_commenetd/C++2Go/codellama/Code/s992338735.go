package main

import (
	"fmt"
)

func main() {
	// Define two integer variables N and S for input and output respectively
	var N, S int

	// Start the while loop that runs as long as the user inputs a positive integer N
	for {
		// Initialize variables M, m, and addup with default values
		M := -1 // Initialize M as an invalid value to represent the minimum sum of subarrays
		m := 1001 // Initialize m as a large value to represent the maximum sum of subarrays
		addup := 0 // Initialize addup as a variable to store the sum of all subarrays
		i := 0 // Initialize i as a loop counter

		// Read the next integer N from the user input
		fmt.Scan(&N)

		// Run the loop N times
		for i = 0; i < N; i++ {
			// Read the next integer S from the user input
			fmt.Scan(&S)
			// Add the current subarray sum S to the total sum addup
			addup += S
			// Update M if the current subarray sum is larger than the current minimum sum
			if S > M {
				M = S
			}
			// Update m if the current subarray sum is smaller than the current maximum sum
			if S < m {
				m = S
			}
		}

		// Calculate and print the average of the differences between the maximum and minimum sums of all subarrays
		fmt.Println((addup - M - m) / (N - 2))
	}
}

