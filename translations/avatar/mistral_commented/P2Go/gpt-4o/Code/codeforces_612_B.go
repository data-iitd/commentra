package main

import (
	"fmt"
	"math"
)

func main() {
	// Take an integer 'n' as input
	var n int
	fmt.Scan(&n)

	// Initialize a slice 'a' of 'n' integers by taking input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize a slice 'b' of length 'n'
	b := make([]int, n)

	// Assign indices to 'b' based on the values in 'a'
	for i := 0; i < n; i++ {
		// Assign index 'i' to the position 'a[i] - 1' in slice 'b'
		b[a[i]-1] = i
	}

	// Initialize a variable 'res' to 0
	res := 0

	// Calculate the absolute difference between consecutive indices in 'b' and sum them up
	for i := 1; i < n; i++ {
		// Add the absolute difference between indices 'i' and 'i-1' to 'res'
		res += int(math.Abs(float64(b[i] - b[i-1])))
	}

	// Print the final result 'res'
	fmt.Println(res)
}

// <END-OF-CODE>
