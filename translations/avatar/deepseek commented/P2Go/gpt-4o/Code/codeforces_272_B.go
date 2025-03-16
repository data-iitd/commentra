package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take input from the user
	var input string
	fmt.Scanln(&input)
	// Process the input and call nPairsWithCommonFX with the processed input
	fmt.Println(nPairsWithCommonFX(parseInput(input)))
}

func parseInput(input string) []int {
	parts := strings.Fields(input)
	var sequence []int
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		sequence = append(sequence, num)
	}
	return sequence
}

func nPairsWithCommonFX(sequence []int) int {
	// Initialize a map to store values grouped by their computed property
	storage := make(map[int][]int)
	// List to store the computed property values
	var FXs []int

	for _, value := range sequence {
		// Compute the property for the current value
		y := f(value)
		// If the property is not already in storage, add it with the current value
		if _, exists := storage[y]; !exists {
			storage[y] = []int{value}
			FXs = append(FXs, y)
		} else {
			// Otherwise, append the current value to the list of values for this property
			storage[y] = append(storage[y], value)
		}
	}

	// Calculate the number of pairs with common factor greater than 1
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
	// Initialize y to 1, which will be the result for the property of n
	y := 1
	for n != 1 {
		if n%2 != 0 {
			y++
		}
		n /= 2
	}
	return y
}

// Entry point of the program
func init() {
	// This function is called before main
}

