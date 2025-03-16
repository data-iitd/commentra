package main

import (
	"fmt"
	"math"
)

const mod = 1000000007

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize a slice to store coefficients
	coef := make([]int, 0)

	// Calculate coefficients based on the divisors of n
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		coef = append(coef, (n/i)-(n/(i+1)))
	}

	// Fill the remaining coefficients with 1s to ensure the length matches n
	coef = append(coef, make([]int, n-sum(coef))...)

	// Reverse the coefficients slice for further processing
	for i, j := 0, len(coef)-1; i < j; i, j = i+1, j-1 {
		coef[i], coef[j] = coef[j], coef[i]
	}

	// Get the length of the coefficients slice
	nn := len(coef)

	// Initialize a 2D slice for dynamic programming
	dp := make([][]int, k+1)
	for i := range dp {
		dp[i] = make([]int, nn)
	}

	// Base case: there's one way to select 0 items (select nothing)
	dp[0][0] = 1

	// Fill the dp table for k selections
	for i := 1; i <= k; i++ {
		tmp := 0 // Temporary variable to accumulate values
		// Iterate through the coefficients in reverse order
		for j := nn - 1; j >= 0; j-- {
			// Accumulate the number of ways to select items
			tmp += dp[i-1][nn-1-j]
			tmp %= mod // Ensure the value stays within modulus
			// Calculate the number of ways to select i items using the j-th coefficient
			dp[i][j] = coef[j] * tmp % mod
		}
	}

	// Output the total number of ways to select k items, taking modulus
	result := 0
	for _, val := range dp[k] {
		result = (result + val) % mod
	}
	fmt.Println(result)
}

// <END-OF-CODE>
