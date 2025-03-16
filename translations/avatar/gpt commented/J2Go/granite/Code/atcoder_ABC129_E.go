
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a scanner to read input from the console
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Define a constant for the modulo operation
	M := 1000000007

	// Read a line of input and convert it to a character array
	s := []byte(sc.Text())

	// Get the length of the input character array
	n := len(s)

	// Initialize a 2D array for dynamic programming
	// dp[i][0] will store the count of valid sequences ending with '0'
	// dp[i][1] will store the count of valid sequences ending with '1'
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}

	// Base case: There is one way to have an empty sequence
	dp[0][0] = 1

	// Iterate through each character in the input string
	for i := 0; i < n; i++ {
		// If the current character is '0'
		if s[i] == '0' {
			// Carry forward the counts for sequences ending with '0' and '1'
			dp[i+1][0] = dp[i][0]
			dp[i+1][1] = dp[i][1]
		} else {
			// If the current character is '1', calculate new counts
			// The count of sequences ending with '1' can be formed by adding
			// the counts of sequences ending with '0' and '1' from the previous step
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % M
		}

		// If the current character is '0', update the counts for sequences ending with '1'
		if s[i] == '0' {
			// Count sequences ending with '1' that can be formed by doubling the previous count
			dp[i+1][1] += (dp[i][1] * 2) % M
			dp[i+1][1] %= M
		} else {
			// If the current character is '1', update counts for both endings
			// Count sequences ending with '0' that can be formed by doubling the previous count
			dp[i+1][0] += (dp[i][0] * 2) % M

			// Count sequences ending with '1' that can be formed by doubling the previous count
			dp[i+1][1] += (dp[i][1] * 2) % M

			// Ensure the counts remain within the modulo limit
			dp[i+1][0] %= M
			dp[i+1][1] %= M
		}
	}

	// Output the total number of valid sequences, which is the sum of counts
	// of sequences ending with '0' and '1' for the entire input
	fmt.Println((dp[n][0] + dp[n][1]) % M)
}

