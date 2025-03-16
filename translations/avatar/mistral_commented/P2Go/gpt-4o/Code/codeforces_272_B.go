package main

import (
	"fmt"
	"os"
)

// This is the main function that takes input and calls the helper function nPairsWithCommonFX
func main() {
	// Read input from standard input
	var n int
	fmt.Scan(&n)

	sequence := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&sequence[i])
	}

	// Call the helper function with the sequence obtained from input
	result := nPairsWithCommonFX(sequence)

	// Print the result
	fmt.Println(result)
}

// This function takes a sequence as input and returns the number of pairs with common FX
func nPairsWithCommonFX(sequence []int) int {
	// Initialize a map to store FX values and their corresponding values
	storage := make(map[int][]int)

	// Iterate through each value in the sequence
	for _, value := range sequence {
		// Compute the FX value for the current value
		fx := f(value)

		// Add the current value to the list of values for that FX
		storage[fx] = append(storage[fx], value)
	}

	// Calculate the result using the formula given in the problem statement
	result := 0
	for _, values := range storage {
		count := len(values)
		result += count * count
	}
	for _, values := range storage {
		result -= len(values)
	}
	result /= 2

	// Return the result
	return result
}

// This function takes an integer as input and returns its FX value
func f(n int) int {
	// Initialize a variable to store the FX value
	fx := 1

	// Perform bitwise operations until the number is reduced to 1
	for n != 1 {
		// If the number is odd, increment the FX value
		if n%2 != 0 {
			fx++
		}

		// Divide the number by 2 to reduce it further
		n /= 2
	}

	// Return the final FX value
	return fx
}
