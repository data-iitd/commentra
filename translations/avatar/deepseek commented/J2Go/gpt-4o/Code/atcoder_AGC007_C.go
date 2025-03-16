package main

import (
	"fmt"
	"math/big"
)

func main() {
	// Initialize variables to read input from the user
	var N, d, x float64
	fmt.Scan(&N, &d, &x)

	// Initialize a big.Float to store the result with precision
	ans := big.NewFloat(0.0)

	// Continue the loop until N is greater than 0.5
	for N > 0.5 {
		// Calculate a value using big.Float for precision
		adnum := new(big.Float).SetFloat64(d + x*(N-0.5))
		ans.Add(ans, adnum)

		// Update the values of d and x based on the current value of N
		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		x = (1.0 + (2.0 / N)) * x

		// Decrement N by 1 in each iteration
		N--
	}

	// Print the result formatted to a specific number of decimal places
	fmt.Printf("%.20f\n", ans)
}

// <END-OF-CODE>
