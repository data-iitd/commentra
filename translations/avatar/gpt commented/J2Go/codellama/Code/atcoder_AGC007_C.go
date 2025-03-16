package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the user
	scan := bufio.NewScanner(os.Stdin)

	// Read three double values from the user: N, d, and x
	var N, d, x float64
	fmt.Scan(&N, &d, &x)

	// Initialize a BigDecimal variable to store the accumulated answer
	var ans big.Float
	ans.SetFloat64(0.0)

	// Loop until N is greater than 0.5
	for N > 0.5 {
		// Calculate the current term to be added to the answer
		adnum := big.NewFloat(d + x*(N-0.5))
		// Add the current term to the accumulated answer
		ans.Add(&ans, adnum)

		// Update d using the formula provided
		d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
		// Update x using the formula provided
		x = (1.0 + (2.0 / N)) * x

		// Decrement N for the next iteration
		N--
	}

	// Create a DecimalFormat object to format the output
	format := new(big.Float).SetFloat64(0.0)
	// Set the minimum number of fraction digits to 20
	format.SetMinimumFractionDigits(20)

	// Print the formatted result
	fmt.Println(format.Format(ans))
}

