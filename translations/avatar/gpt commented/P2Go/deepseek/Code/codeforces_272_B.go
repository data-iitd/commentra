package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input from the user (not stored, just consumed)
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')
	// Process the input sequence and return the number of pairs with common factors
	fmt.Println(nPairsWithCommonFX(readInts(reader)))
}

func nPairsWithCommonFX(sequence []int) int {
	// Initialize a dictionary to store values based on their computed factor
	storage := make(map[int][]int)
	// List to keep track of unique factors
	var FXs []int
	
	// Iterate through each value in the input sequence
	for _, value := range sequence {
		// Compute the factor for the current value
		y := f(value)
		// If the factor is not already in storage, add it
		if _, exists := storage[y]; !exists {
			storage[y] = []int{value}  // Store the value under its factor
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
		totalPairs += len(storage[y]) * len(storage[y])
	}
	singleOccurrences := 0
	for _, y := range FXs {
		singleOccurrences += len(storage[y])
	}
	return (totalPairs - singleOccurrences) / 2
}

func f(n int) int {
	// Initialize the factor count
	y := 1
	// Loop until n is reduced to 1
	for n != 1 {
		// If n is odd, increment the factor count
		if n % 2 == 1 {
			y += 1
		}
		// Divide n by 2 to reduce it
		n /= 2
	}
	// Return the total count of factors
	return y
}

func readInts(reader *bufio.Reader) []int {
	line, _ := reader.ReadString('\n')
	ints := []int{}
	for _, s := range strings.Split(strings.TrimSpace(line), " ") {
		num, _ := strconv.Atoi(s)
		ints = append(ints, num)
	}
	return ints
}
