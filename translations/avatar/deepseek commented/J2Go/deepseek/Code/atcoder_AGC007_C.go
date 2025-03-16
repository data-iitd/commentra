package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	// Initialize Scanner to read input from the user
	var N, d, x float64
	fmt.Scan(&N, &d, &x)

	// Initialize *big.Rat to store the result with precision
	ans := new(big.Rat)
	ans.SetString("0")

	// Continue the loop until N is greater than 0.5
	for N > 0.5 {
		// Calculate a value using big.Rat for precision
		adnum := new(big.Rat)
		adnum.SetString(fmt.Sprintf("%f", d+x*(N-0.5)))
		ans.Add(ans, adnum)

		// Update the values of d and x based on the current value of N
		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		x = (1.0 + (2.0 / N)) * x

		// Decrement N by 1 in each iteration
		N--
	}

	// Format the result to a specific number of decimal places
	result := fmt.Sprintf("%.20f", ans.FloatString(20))
	fmt.Println(result)
}

