package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	// Take an integer input 'n' from the user
	var n int
	fmt.Scan(&n)

	// Take 'n' floating point numbers as input and store them in a slice 'arr'
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Filter out the integers from the slice 'arr' and sort the remaining floating point numbers
	var filtered []float64
	for _, x := range arr {
		if x-int(x) != 0 {
			filtered = append(filtered, x-int(x))
		}
	}
	sort.Float64s(filtered)

	// Calculate the length of the filtered slice 'arr' and assign it to the variable 'o'
	o := 2*n - len(filtered)

	// Calculate the sum of all the floating point numbers in the slice 'arr' and assign it to the variable 'arr_sum'
	arr_sum := 0.0
	for _, x := range filtered {
		arr_sum += x
	}

	// Initialize the variable 'res' with a large integer value
	res := 2e9

	// Iterate through the range from 0 to n+1
	for i := 0; i <= n; i++ {
		// Check if the index 'i' plus the offset 'o' is greater than or equal to 'n'
		if i+o >= n {
			// Update the minimum value of 'res' with the absolute difference between 'i' and 'arr_sum'
			res = int(math.Min(float64(res), math.Abs(float64(i)-arr_sum)))
		}
	}

	// Print the result with three decimal places
	fmt.Printf("%.3f\n", float64(res))
}

// <END-OF-CODE>
