package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Input the number of elements (n)

	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i]) // Input the array elements
	}

	// Extract fractional parts
	fractionalParts := []float64{}
	for _, x := range arr {
		fraction := x - math.Floor(x)
		if fraction != 0 {
			fractionalParts = append(fractionalParts, fraction)
		}
	}

	// Sort the fractional parts
	sort.Float64s(fractionalParts)

	// Calculate the number of elements to be added to make the total number of elements equal to 2 * n
	o := 2*n - len(fractionalParts)

	// Sum of the sorted fractional parts
	arrSum := 0.0
	for _, val := range fractionalParts {
		arrSum += val
	}

	// Initialize the result variable to a very large number
	res := 2e9

	// Iterate to find the best position
	for i := 0; i <= n; i++ {
		if i+o >= n {
			res = math.Min(res, math.Abs(float64(i)-arrSum))
		}
	}

	// Print the result with three decimal places
	fmt.Printf("%.3f\n", res)
}

// <END-OF-CODE>
