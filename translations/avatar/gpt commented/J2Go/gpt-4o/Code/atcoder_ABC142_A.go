package main

import (
	"fmt"
	"math/big"
	"os"
)

func main() {
	var input float64

	// Read a line of input and parse it as a float64
	_, err := fmt.Scanf("%f", &input)
	if err != nil {
		// Handle input errors
		fmt.Println(err)
		os.Exit(1)
	}

	// Calculate the count of odd numbers based on the input
	countOdd := input / 2

	// Create a big.Float to hold the result of the division
	result := new(big.Float).SetFloat64(countOdd / input)

	// Set the precision to 10 decimal places
	result = result.SetPrec(10 * 4) // 10 decimal places, 4 bits per decimal

	// Print the result to the console
	fmt.Println(result.Text('f', 10))
}
