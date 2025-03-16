
package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 100000007

func main() {
	// Read input values for n and k
	var n, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &k)

	// Initialize a list to store coefficients
	coef := make([]int, n)

	// Calculate coefficients based on the divisors of n
	for i := 1; i < int(n*1.0); i++ {
		// Append the count of divisors in the range
		coef[i] = (n / i) - (n / (i + 1))
	}

	// Fill the remaining coefficients with 1s to ensure the length matches n
	for i := int(n * 1.0); i < n; i++ {
		coef[i] = 1
	}

	// Reverse the coefficients list for further processing
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		coef[i], coef[j] = coef[j], coef[i]
	}

	// Get the length of the coefficients list
	nn := len(coef)

	// Initialize a 2D list for dynamic programming
	// dp[i][j] will store the result for i selections and j coefficients
	dp := make([][]int, k+1)
	for i := 0; i <= k; i++ {
		dp[i] = make([]int, nn)
	}

	// Base case: there's one way to select 0 items (select nothing)
	dp[0][0] = 1

	// Fill the dp table for k selections
	for i := 1; i <= k; i++ {
		tmp := 0  // Temporary variable to accumulate values
		// Iterate through the coefficients in reverse order
		for j := nn - 1; j >= 0; j-- {
			// Accumulate the number of ways to select items
			tmp += dp[i-1][(nn-1)-j]
			tmp %= mod  // Ensure the value stays within modulus
			// Calculate the number of ways to select i items using the j-th coefficient
			dp[i][j] = coef[j] * tmp
			dp[i][j] %= mod  // Again, ensure the value stays within modulus
		}
	}

	// Output the total number of ways to select k items, taking modulus
	fmt.Println(sum(dp[k]) % mod)
}

func sum(a []int) int {
	s := 0
	for _, v := range a {
		s += v
	}
	return s
}

