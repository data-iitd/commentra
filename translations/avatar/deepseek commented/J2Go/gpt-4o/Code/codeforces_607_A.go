package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Step 6: Read the number of beacons

	beacon := make([]int, 1000001) // Step 5: Initialize the beacon array
	dp := make([]int, 1000001)      // Step 5: Initialize the dp array
	max := 0                         // Step 5: Initialize the maximum value in dp array

	// Step 6: Read the positions and strengths of the beacons
	for i := 0; i < n; i++ {
		var a, strength int
		fmt.Scan(&a, &strength)
		beacon[a] = strength
	}

	// Step 7: Check if the first beacon's strength is not zero and initialize dp[0] to 1
	if beacon[0] != 0 {
		dp[0] = 1
	}

	// Step 8: Iterate through the range of 1 to 1000000, updating the dp array based on the beacon strengths
	for i := 1; i < 1000001; i++ {
		if beacon[i] != 0 && beacon[i] < i {
			dp[i] = dp[i-beacon[i]-1] + 1
		} else if beacon[i] != 0 {
			dp[i] = 1
		} else {
			dp[i] = dp[i-1]
		}
		max = maxInt(max, dp[i]) // Step 9: Update the maximum value in dp array
	}

	// Step 9: Print the result
	fmt.Print(n - max)
}

// Helper function to find the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}
