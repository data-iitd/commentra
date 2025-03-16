package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	// Read an integer input for the number of elements
	var n int
	fmt.Scan(&n)

	// Read a line of space-separated floats and convert them to a slice of floats
	var arr []float64
	for i := 0; i < n; i++ {
		var x float64
		fmt.Scan(&x)
		arr = append(arr, x)
	}

	// Calculate the fractional parts of the elements, excluding whole numbers
	var fractions []float64
	for _, x := range arr {
		fraction := x - math.Floor(x)
		if fraction != 0 {
			fractions = append(fractions, fraction)
		}
	}

	// Sort the fractional parts
	sort.Float64s(fractions)

	// Calculate the number of whole numbers that can be added to the fractional parts
	o := 2*n - len(fractions)

	// Calculate the sum of the fractional parts
	arrSum := 0.0
	for _, fraction := range fractions {
		arrSum += fraction
	}

	// Initialize the result with a large number
	res := 2e9

	// Iterate through possible counts of fractional parts used
	for i := 0; i <= n; i++ {
		// Check if the current count of fractional parts plus whole numbers is sufficient
		if i+o >= n {
			// Update the result with the minimum difference found
			res = math.Min(res, math.Abs(float64(i)-arrSum))
		}
	}

	// Print the result formatted to three decimal places
	fmt.Printf("%.3f\n", res)
}

// <END-OF-CODE>
