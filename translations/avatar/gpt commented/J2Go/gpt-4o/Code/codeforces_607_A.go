package main

import (
	"fmt"
)

func main() {
	// Create a variable to keep track of the maximum number of beacons
	max := 0

	// Read the number of beacons
	var n int
	fmt.Scan(&n)

	// Create a slice to store the positions of the beacons
	beacon := make([]int, 1000001)

	// Create a dynamic programming slice to store the maximum beacons that can be placed
	dp := make([]int, 1000001)

	// Read the beacon positions and their corresponding values
	for i := 0; i < n; i++ {
		var a, value int
		fmt.Scan(&a, &value) // Read the position and value of the beacon
		beacon[a] = value
	}

	// Initialize the dp slice for the first position if there is a beacon
	if beacon[0] != 0 {
		dp[0] = 1
	}

	// Iterate through all possible positions to calculate the maximum beacons that can be placed
	for i := 1; i < 1000001; i++ {
		// If there is a beacon at position i and its value is less than i
		if beacon[i] != 0 && beacon[i] < i {
			// Update the dp slice based on the previous values
			dp[i] = dp[i-beacon[i]-1] + 1
		} else if beacon[i] != 0 { // If there is a beacon at position i but its value is greater than or equal to i
			dp[i] = 1 // Only this beacon can be placed
		} else { // If there is no beacon at position i
			dp[i] = dp[i-1] // Carry forward the previous maximum
		}
		// Update the maximum number of beacons found so far
		if dp[i] > max {
			max = dp[i]
		}
	}

	// Output the minimum number of beacons that need to be removed
	fmt.Print(n - max)
}

// <END-OF-CODE>
