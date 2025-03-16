package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables for minimum index and minimum difference
	var i_min, min int

	// Read the values of X and N from user input
	X, _ := strconv.Atoi(strings.TrimSpace(os.Args[1]))
	N, _ := strconv.Atoi(strings.TrimSpace(os.Args[2]))

	// If N is 0, print X and exit the program
	if N == 0 {
		fmt.Println(X)
		os.Exit(0)
	}

	// Initialize arrays to hold positive and negative values
	plus := make([]int, 256)
	minus := make([]int, 256)

	// Fill the plus array with indices and minus array with negative indices
	for i := 0; i < 256; i++ {
		plus[i] = i
		minus[i] = -1 * i
	}

	// Read N values and set corresponding indices in the plus array to 0
	for i := 0; i < N; i++ {
		j, _ := strconv.Atoi(strings.TrimSpace(os.Args[i+3]))
		plus[j] = 0 // Mark the value as unavailable
	}

	// Initialize minimum index and minimum difference
	i_min = 0
	min = 1000

	// Iterate through the plus array in reverse order to find the closest value to X
	for i := 255; i >= 0; i-- {
		// Skip indices that are marked as unavailable (0) and are greater than 0
		if plus[i] == 0 && i > 0 {
			continue
		}

		// Calculate the difference between X and the current value in the plus array
		k := X - plus[i]
		if k < 0 {
			k *= -1 // Take the absolute value of the difference
		}

		// Update minimum difference and index if a closer value is found
		if k <= min {
			min = k
			i_min = i // Store the index of the closest value
		}
	}

	// Print the index of the closest value found
	fmt.Println(i_min)
}

