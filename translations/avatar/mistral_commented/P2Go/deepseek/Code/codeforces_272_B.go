package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// This function takes an integer as input and returns its FX value
func f(n int) int {
	// Initialize a variable to store the FX value
	fx := 1

	// Perform bitwise operations until the number is reduced to 1
	for n != 1 {
		// If the number is odd, increment the FX value
		if n%2 != 0 {
			fx += 1
		}

		// Divide the number by 2 to reduce it further
		n /= 2
	}

	// Return the final FX value
	return fx
}

// This function takes a sequence as input and returns the number of pairs with common FX
func nPairsWithCommonFX(sequence []int) int {
	// Initialize an empty map to store FX values and their corresponding values
	storage := make(map[int][]int)

	// Initialize an empty slice to store unique FX values
	var FXs []int

	// Iterate through each value in the sequence
	for _, value := range sequence {
		// Compute the FX value for the current value
		fx := f(value)

		// If the FX value is not already in the map, add it along with the value
		if _, exists := storage[fx]; !exists {
			storage[fx] = []int{value}
			FXs = append(FXs, fx)
		} else {
			// If the FX value is already in the map, add the current value to the list of values for that FX
			storage[fx] = append(storage[fx], value)
		}
	}

	// Calculate the result using the formula given in the problem statement
	result := 0
	for _, fx := range FXs {
		count := len(storage[fx])
		result += count * (count - 1) / 2
	}

	// Return the result
	return result
}

// The main function that reads input and calls the helper function nPairsWithCommonFX
func main() {
	// Create a new scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input (which is not used)
	scanner.Scan()

	// Read the second line of input and split it into a sequence of integers
	scanner.Scan()
	sequence := []int{}
	for _, value := range strings.Split(scanner.Text(), " ") {
		intValue, _ := strconv.Atoi(value)
		sequence = append(sequence, intValue)
	}

	// Call the helper function with the sequence obtained from input
	result := nPairsWithCommonFX(sequence)

	// Print the result
	fmt.Println(result)
}

