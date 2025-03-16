package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input numbers
	a := make([]int64, n)
	// Read the input numbers into the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Create a copy of the input slice to store absolute values
	absA := make([]int64, n)
	for i := 0; i < n; i++ {
		absA[i] = int64(math.Abs(float64(a[i])))
	}

	// Initialize variables to calculate the sum of absolute values and find the minimum absolute value
	ans := int64(0)
	min := absA[0]
	// Iterate through the absolute values to calculate the total sum and find the minimum
	for _, e := range absA {
		ans += e // Accumulate the sum of absolute values
		if min > e {
			min = e // Update the minimum absolute value found
		}
	}

	// Count the number of negative numbers in the original array
	numNegative := 0
	for _, e := range a {
		if e < 0 {
			numNegative++ // Increment count for each negative number
		}
	}

	// If the count of negative numbers is odd, adjust the total sum
	if numNegative%2 != 0 {
		ans -= min * 2 // Subtract twice the minimum absolute value from the total sum
	}

	// Output the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
