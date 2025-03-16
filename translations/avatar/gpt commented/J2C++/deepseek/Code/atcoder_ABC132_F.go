package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Define the modulo constant for calculations to prevent overflow
	const mod int64 = 1e9 + 7

	// Initialize scanner to read input values
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the values of n and k from input
	sc.Scan()
	n := parseInt(sc.Text())
	sc.Scan()
	k := parseInt(sc.Text())

	// Close the scanner as we no longer need input
	sc.Scan()

	// Create a slice to store the lengths of segments
	len := []int{}

	// Initialize the starting point for segment calculation
	l := 1

	// Calculate the lengths of segments based on the value of n
	for l <= n {
		// Calculate the right endpoint of the current segment
		r := n / (n / l)
		// Add the length of the current segment to the slice
		len = append(len, r-l+1)
		// Move to the next segment
		l = r + 1
	}

	// Get the total number of segments calculated
	q := len(len)

	// Initialize a dynamic programming slice to store results
	dp := make([]int64, k*(q+1))

	// Fill the dp slice for the first segment
	for j := 1; j <= q; j++ {
		dp[j] = int64(len[j-1]) + dp[j-1]
	}

	// Fill the dp slice for subsequent segments
	for i := 1; i < k; i++ {
		for j := 1; j <= q; j++ {
			// Calculate the number of ways to form segments
			dp[i*(q+1)+j] = dp[i*(q+1)+j-1] + dp[(i-1)*(q+1)+q-j+1]*int64(len[j-1])
			// Apply modulo to keep the value within limits
			dp[i*(q+1)+j] %= mod
		}
	}

	// Output the final result, which is the number of ways to form k segments
	fmt.Println(dp[k*(q+1)-1])
}

// Helper function to parse string to int
func parseInt(s string) int {
	var result int
	for _, c := range s {
		result = result*10 + int(c-'0')
	}
	return result
}

