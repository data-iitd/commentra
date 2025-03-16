package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of values to be processed
	var N int
	fmt.Scanf("%d", &N)

	// Initialize a slice to hold the float64 values
	values := make([]float64, N)

	// Read N float64 values from standard input
	for i := 0; i < N; i++ {
		fmt.Scanf("%f", &values[i])
	}

	// Sort the slice of float64 values in ascending order
	sort.Sort(sort.Float64Slice(values))

	// Variable to hold the generated average value
	var generated float64

	// Calculate the average of each pair of adjacent values
	for i := 0; i < N-1; i++ {
		generated = (values[i] + values[i+1]) / 2
		// Update the next value in the slice with the generated average
		values[i+1] = generated
	}

	// Print the last generated average value
	fmt.Println(generated)
}
