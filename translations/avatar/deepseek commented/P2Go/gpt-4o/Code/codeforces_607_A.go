package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of pairs
	l := make([]int, 1000010) // Initialize slice `l` with zeros
	dp := make([]int, 1000010) // Initialize slice `dp` with zeros

	// Read `n` pairs of integers and store them in slice `l`
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		l[a] = b
	}

	// If the value at index 0 in `l` is greater than 0, set `dp[0]` to 1
	if l[0] > 0 {
		dp[0] = 1
	}

	mx := 0 // Initialize variable `mx` to 0

	// Iterate through the slice `l` from 1 to 1000010, updating the `dp` slice
	for i := 1; i < 1000010; i++ {
		if l[i] == 0 { // If `l[i]` is 0, copy the value from `dp[i-1]`
			dp[i] = dp[i-1]
		} else {
			if l[i] >= i { // If `l[i]` is greater than or equal to `i`, set `dp[i]` to 1
				dp[i] = 1
			} else { // Otherwise, update `dp[i]` based on the previous value
				dp[i] = dp[i-l[i]-1] + 1
			}
		}
		if dp[i] > mx { // Update `mx` if `dp[i]` is greater than the current `mx`
			mx = dp[i]
		}
	}

	// Print the result as `n - mx`
	fmt.Println(n - mx)
}

// <END-OF-CODE>
