package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input representing the length of the list `a`
	a := make([]int, n) // Initialize a slice `a` of length `n`
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Take space-separated integers and fill the slice `a`
	}
	b := make([]int, n) // Initialize a slice `b` of length `n`

	// Assign the index of each element in `a` to the corresponding position in `b`, adjusting for zero-based indexing
	for i := 0; i < n; i++ {
		b[a[i]-1] = i
	}

	res := 0 // Initialize the result variable `res` to 0

	// Calculate the sum of absolute differences between the positions of consecutive elements in `b`
	for i := 1; i < n; i++ {
		res += int(math.Abs(float64(b[i] - b[i-1])))
	}

	fmt.Println(res) // Print the result
}

// <END-OF-CODE>
