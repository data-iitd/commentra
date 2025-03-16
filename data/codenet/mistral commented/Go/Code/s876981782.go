
package main

import (
	"fmt"
	"sort"
)

func main() {
	// Initialize variables
	var N int

	// Read input: number of values
	fmt.Scanf("%d", &N)

	// Allocate memory for N float64 values
	values := make([]float64, N)

	// Read input: N float64 values
	for i := 0; i < N; i++ {
		fmt.Scanf("%f", &values[i])
	}

	// Sort the slice in ascending order
	sort.Sort(sort.Float64Slice(values))

	// Calculate the median value
	var generated float64
	// Iterate through the slice, excluding the last value (which is the maximum)
	for i := 0; i < N-1; i++ {
		// Calculate the average of the current and next value
		generated = (values[i] + values[i+1]) / 2

		// Update the next value with the calculated average
		values[i+1] = generated
	}

	// Print the calculated median value
	fmt.Println(generated)
}

