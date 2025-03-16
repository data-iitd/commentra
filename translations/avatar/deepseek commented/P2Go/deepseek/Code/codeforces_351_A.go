package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Input the number of elements (n)

	var arr []float64
	for i := 0; i < n; i++ {
		var x float64
		fmt.Scan(&x)
		arr = append(arr, x)
	}

	// Extract fractional parts and sort them
	var fractionalParts []float64
	for _, x := range arr {
		if x != float64(int(x)) {
			fractionalParts = append(fractionalParts, x-float64(int(x)))
		}
	}
	sort.Float64s(fractionalParts)

	// Calculate the number of elements to be added to make the total number of elements equal to 2 * n
	o := 2*n - len(fractionalParts)

	// Sum of the sorted fractional parts
	var arrSum float64
	for _, x := range fractionalParts {
		arrSum += x
	}

	// Initialize the result variable to a very large number
	res := int(2e9)

	// Iterate to find the best position
	for i := 0; i <= n; i++ {
		if i+o >= n {
			res = min(res, int(abs(float64(i)-arrSum)))
		}
	}

	// Print the result with three decimal places
	fmt.Printf("%.3f\n", float64(res))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(x float64) float64 {
	if x < 0 {
		return -x
	}
	return x
}
