
package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	// Reading input values from the user
	N, _ := strconv.ParseFloat(os.Args[1], 64)
	d, _ := strconv.ParseFloat(os.Args[2], 64)
	x, _ := strconv.ParseFloat(os.Args[3], 64)

	ans := big.NewFloat(0.0) // Initializing an answer variable of BigFloat type with zero value

	// Calculating the answer using the given formula
	for N > 0.5 {
		adnum := big.NewFloat(d + x*(N-0.5)) // Calculating the next term of the sum
		ans.Add(ans, adnum)                  // Adding the next term to the answer

		// Updating the values of d and x for the next iteration
		d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
		x = (1.0 + (2.0 / N)) * x

		N -= 1.0 // Decreasing the value of N by 1 for the next iteration
	}

	// Formatting the output with 20 decimal places
	format := "%.20f"

	// Printing the final answer with 20 decimal places
	fmt.Printf(format, ans)
}

