package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	// Create a Scanner object to read input from the user
	var N, d, x float64
	fmt.Scan(&N, &d, &x)
	
	// Initialize a big.Rat variable to store the accumulated answer
	ans := new(big.Rat)
	
	// Loop until N is greater than 0.5
	for N > 0.5 {
		// Calculate the current term to be added to the answer
		adnum := new(big.Rat)
		adnum.SetFloat64(d + x * (N - 0.5))
		
		// Add the current term to the accumulated answer
		ans.Add(ans, adnum)
		
		// Update d using the formula provided
		d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
		// Update x using the formula provided
		x = (1.0 + (2.0 / N)) * x
		
		// Decrement N for the next iteration
		N--
	}
	
	// Print the formatted result
	fmt.Println(ans.FloatString(20))
}
