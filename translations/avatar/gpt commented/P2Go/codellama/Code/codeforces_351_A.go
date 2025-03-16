package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input for the number of elements
	var n int
	fmt.Scan(&n)

	// Read a line of space-separated floats and convert them to a list of floats
	var arr []float64
	fmt.Scan(&arr)

	// Calculate the fractional parts of the elements, excluding whole numbers
	arr = arr[:0]
	for _, x := range arr {
		if x-math.Floor(x) != 0 {
			arr = append(arr, x-math.Floor(x))
		}
	}
	sort.Float64s(arr)

	// Calculate the number of whole numbers that can be added to the fractional parts
	o := 2*n - len(arr)

	// Calculate the sum of the fractional parts
	var arr_sum float64
	for _, x := range arr {
		arr_sum += x
	}

	// Initialize the result with a large number
	res := 2e9

	// Iterate through possible counts of fractional parts used
	for i := 0; i <= n; i++ {
		// Check if the current count of fractional parts plus whole numbers is sufficient
		if i+o >= n {
			// Update the result with the minimum difference found
			res = math.Min(res, math.Abs(float64(i)-arr_sum))
		}
	}

	// Print the result formatted to three decimal places
	fmt.Printf("%.3f", res)
}

// 