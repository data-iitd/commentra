
package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize Scanner to read input from the user
	scan := bufio.NewScanner(os.Stdin)

	// Read three double values: N, d, and x
	var N, d, x float64
	fmt.Fscanf(scan, "%f\n", &N)
	fmt.Fscanf(scan, "%f\n", &d)
	fmt.Fscanf(scan, "%f\n", &x)

	// Initialize big.Float to store the result with precision
	ans := big.NewFloat(0)

	// Continue the loop until N is greater than 0.5
	for N > 0.5 {
		// Calculate a value using big.Float for precision
		adnum := big.NewFloat(d + x*(N-0.5))
		ans.Add(ans, adnum)

		// Update the values of d and x based on the current value of N
		d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
		x = (1.0 + (2.0 / N)) * x

		// Decrement N by 1 in each iteration
		N--
	}

	// Initialize DecimalFormat to format the output
	format := new(big.Float).SetPrec(20)

	// Print the result formatted to a specific number of decimal places
	fmt.Printf("%s\n", format.Text(ans))
}

