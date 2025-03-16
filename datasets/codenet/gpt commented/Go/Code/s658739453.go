package main

import (
	"fmt"
)

// Define a constant for the modulo operation
const d = 1000000007

func main() {
	// Declare variables for the number of elements (n) and the number of blocked positions (p)
	var n, p int
	
	// Read the total number of elements (n) and the number of blocked positions (p) from input
	fmt.Scan(&n)
	fmt.Scan(&p)

	// Create a map to store the blocked positions
	mdans := map[int64]int64{}
	
	// Read the blocked positions and store them in the map
	for index := 0; index < p; index++ {
		var n1 int64
		fmt.Scan(&n1)
		mdans[n1] = n1
	}

	// Initialize a slice to store the number of ways to reach each position
	dp := make([]int64, n+1, n+1)
	
	// Base cases: There is 1 way to reach the 0th and 1st positions
	dp[0] = 1
	dp[1] = 1

	// If the first position is blocked, set the number of ways to reach it to 0
	if _, ok := mdans[1]; ok {
		dp[1] = 0
	}

	// Iterate through positions from 2 to n to calculate the number of ways to reach each position
	for i := 2; i <= n; i++ {
		// If the current position is blocked, skip the calculation
		if _, ok := mdans[int64(i)]; ok {
			continue
		}
		// Calculate the number of ways to reach the current position using the previous two positions
		dp[i] = (dp[i-1] + dp[i-2]) % d
	}

	// Print the number of ways to reach the nth position
	fmt.Printf("%#v\n", dp[n])
}
