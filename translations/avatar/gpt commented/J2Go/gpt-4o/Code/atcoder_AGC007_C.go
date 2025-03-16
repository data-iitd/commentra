package main

import (
	"fmt"
	"math/big"
)

func main() {
	// Create a variable to read input from the user
	var N, d, x float64

	// Read three float64 values from the user: N, d, and x
	fmt.Scan(&N, &d, &x)

	// Initialize a big.Float variable to store the accumulated answer
	ans := big.NewFloat(0.0)

	// Loop until N is greater than 0.5
	for N > 0.5 {
		// Calculate the current term to be added to the answer
		adnum := big.NewFloat(d + x*(N-0.5))
		// Add the current term to the accumulated answer
		ans.Add(ans, adnum)

		// Update d using the formula provided
		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		// Update x using the formula provided
		x = (1.0 + (2.0 / N)) * x

		// Decrement N for the next iteration
		N--
	}

	// Print the formatted result with 20 decimal places
	fmt.Printf("%.20f\n", ans)
}

// <END-OF-CODE>
