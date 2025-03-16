package main

import (
	"fmt"
	"os"
)

func main() {
	// Read input from the user (not stored, just consumed)
	var input string
	fmt.Scanln(&input)

	// Process the input sequence and return the number of pairs with common factors
	var sequence []int
	for _, s := range strings.Fields(input) {
		value, _ := strconv.Atoi(s)
		sequence = append(sequence, value)
	}
	
	result := nPairsWithCommonFX(sequence)
	fmt.Println(result)
}

func nPairsWithCommonFX(sequence []int) int {
	// Initialize a map to store values based on their computed factor
	storage := make(map[int][]int)
	// Slice to keep track of unique factors
	var FXs []int

	// Iterate through each value in the input sequence
	for _, value := range sequence {
		// Compute the factor for the current value
		y := f(value)
		// If the factor is not already in storage, add it
		if _, exists := storage[y]; !exists {
			storage[y] = []int{value} // Store the value under its factor
			FXs = append(FXs, y)      // Keep track of the unique factor
		} else {
			// If the factor already exists, append the value to the existing list
			storage[y] = append(storage[y], value)
		}
	}

	// Calculate the total number of pairs with common factors
	// The formula counts pairs and subtracts the number of single occurrences
	totalPairs := 0
	for _, y := range FXs {
		count := len(storage[y])
		totalPairs += count * count
	}
	for _, y := range FXs {
		totalPairs -= len(storage[y])
	}
	return totalPairs / 2
}

func f(n int) int {
	// Initialize the factor count
	y := 1
	// Loop until n is reduced to 1
	for n != 1 {
		// If n is odd, increment the factor count
		if n%2 != 0 {
			y++
		}
		// Divide n by 2 to reduce it
		n /= 2
	}
	// Return the total count of factors
	return y
}

