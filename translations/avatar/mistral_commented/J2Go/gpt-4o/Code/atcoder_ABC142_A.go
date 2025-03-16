package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Create a buffered reader for standard input
	inputStr, err := reader.ReadString('\n') // Read input from standard input
	if err != nil { // Check for I/O errors
		fmt.Println(err) // Print the error
		return
	}

	var input float64
	_, err = fmt.Sscanf(inputStr, "%f", &input) // Parse input as a float64
	if err != nil { // Check for number format errors
		fmt.Println(err) // Print the error
		return
	}

	// Calculate the number of odd numbers in the input
	countOdd := float64(int(input) / 2)

	// Create a big.Float object for the result
	result := new(big.Float).SetFloat64(countOdd / input)

	// Set the precision and rounding mode for the result
	result.SetPrec(100).SetMode(big.ToNearestEven)

	// Print the result with 10 decimal places
	fmt.Printf("%.10f\n", result)
}
