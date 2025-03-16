package main

import (
	"fmt"
)

func main() {
	const mod = 1e9 + 7 // Define the modulo constant
	var n, k int
	fmt.Scan(&n, &k) // Read the integers n and k from input

	len := []int{} // Create a slice to store segment lengths
	l := 1         // Initialize the starting point of the segment
	for l <= n {
		r := n / (n / l) // Calculate the ending point of the segment
		len = append(len, r-l+1) // Add the length of the segment to the slice
		l = r + 1 // Move to the next segment
	}

	q := len(len) // Store the size of the len slice in q
	dp := make([]int64, k*(q+1)) // Initialize the dp slice with sufficient size

	// Calculate the prefix sums of the lengths and store them in the dp slice
	for j := 1; j <= q; j++ {
		dp[j] = int64(len[j-1]) + dp[j-1]
	}

	// Main loop to calculate the dynamic programming values for k iterations
	for i := 1; i < k; i++ {
		for j := 1; j <= q; j++ {
			dp[i*(q+1)+j] = (dp[i*(q+1)+j-1] + dp[(i-1)*(q+1)+q-j+1]*int64(len[j-1])) % mod)
		}
	}

	// Print the result stored in the dp slice
	fmt.Println(dp[k*(q+1)-1])
}

// <END-OF-CODE>
