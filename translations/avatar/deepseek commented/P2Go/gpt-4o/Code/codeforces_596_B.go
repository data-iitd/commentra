package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements in the list `r`
	r := make([]int, n) // Create a slice of integers with length `n`
	for i := 0; i < n; i++ {
		fmt.Scan(&r[i]) // Read the space-separated integers into the slice `r`
	}

	ans := int(math.Abs(float64(r[0]))) // Initialize `ans` to the absolute value of the first element in the list `r`

	// The for loop iterates over the range from 1 to `n` (exclusive)
	// For each iteration, it adds the absolute difference between the current element and the previous element in the list `r` to `ans`
	for i := 1; i < n; i++ {
		ans += int(math.Abs(float64(r[i] - r[i-1])))
	}

	fmt.Println(ans) // Print the value of `ans`
}

// <END-OF-CODE>
