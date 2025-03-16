package main

import (
	"fmt"
	"math/big"
	"math/rand"
)

func main() {
	// Reading input values from the user
	var N float64
	var d float64
	var x float64
	fmt.Scan(&N, &d, &x)

	// Initializing an answer variable of big.Rat type with zero value
	ans := new(big.Rat).SetInt64(0)

	// Calculating the answer using the given formula
	for N > 0.5 {
		adnum := new(big.Rat).SetFloat64(d + x*(N-0.5)) // Calculating the next term of the sum
		ans.Add(ans, adnum)                            // Adding the next term to the answer

		// Updating the values of d and x for the next iteration
		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		x = (1.0 + (2.0/N)) * x

		N-- // Decreasing the value of N by 1 for the next iteration
	}

	// Formatting the output with 20 decimal places
	format := new(big.Rat)
	format.SetString("0.00000000000000000000")
	format.Add(format, ans)

	// Printing the final answer with 20 decimal places
	fmt.Println(format.FloatString(20))
}
