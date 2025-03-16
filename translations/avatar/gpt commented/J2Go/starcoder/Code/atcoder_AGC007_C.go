package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

	// Read the first line of input from stdin
	str, _, err := reader.ReadLine()
	checkError(err)

	// Convert the string to a float64
	N, err := strconv.ParseFloat(string(str), 64)
	checkError(err)

	// Read the second line of input from stdin
	str, _, err = reader.ReadLine()
	checkError(err)

	// Convert the string to a float64
	d, err := strconv.ParseFloat(string(str), 64)
	checkError(err)

	// Read the third line of input from stdin
	str, _, err = reader.ReadLine()
	checkError(err)

	// Convert the string to a float64
	x, err := strconv.ParseFloat(string(str), 64)
	checkError(err)

	// Initialize a big.Float variable to store the accumulated answer
	ans := big.NewFloat(0.0)

	// Loop until N is greater than 0.5
	for N > 0.5 {
		// Calculate the current term to be added to the answer
		adnum := big.NewFloat(d + x * (N-0.5))
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
	fmt.Printf("%.20f\n", ans)
}

// Utility function to check for errors
func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

