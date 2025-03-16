package main

import (
	"fmt"
	"math/big" // Importing big package for arithmetic operations with large numbers
)

func main() {
	var N, d, x float64

	// Reading input values from the user
	fmt.Scan(&N, &d, &x)

	ans := new(big.Float).SetFloat64(0.0) // Initializing an answer variable of big.Float type with zero value

	// Calculating the answer using the given formula
	for N > 0.5 {
		adnum := new(big.Float).SetFloat64(d + x*(N-0.5)) // Calculating the next term of the sum
		ans = new(big.Float).Add(ans, adnum) // Adding the next term to the answer

		// Updating the values of d and x for the next iteration
		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		x = (1.0 + (2.0 / N)) * x

		N-- // Decreasing the value of N by 1 for the next iteration
	}

	// Printing the final answer with 20 decimal places
	fmt.Printf("%.20f\n", ans) // Using Printf to format the output with 20 decimal places
}

// <END-OF-CODE>
