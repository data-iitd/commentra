package main

import (
	"fmt"
)

func main() {
	// Read input values for n and k
	var n, k int64
	fmt.Scan(&n, &k)

	// Define MOD constant for modulo operations
	const MOD = 1e9 + 7

	// Calculate the maximum possible value based on n and k
	mx := n*(n+1)/2 - (n-k)*(n-k+1)/2

	// Calculate the minimum possible value based on k
	mn := k * (k - 1) / 2

	// Initialize result variable
	res := int64(0)

	// Loop through values from k to n+1 to compute the result
	for i := k; i <= n+1; i++ {
		// Update result based on current mx and mn values
		res += mx - mn + 1

		// Update mx and mn for the next iteration
		mx += n - i
		mn += i

		// Ensure result stays within the bounds of MOD
		res %= MOD
	}

	// Output the final result
	fmt.Println(res)
}

// <END-OF-CODE>
