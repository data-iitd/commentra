package main

import (
	"fmt"
)

func main() {
	// Read input values A, B, C, D and convert them to integers
	var A, B, C, D int
	fmt.Scan(&A, &B, &C, &D)

	// Define a large prime number for modulo operations
	const m = 998244353

	// Initialize a 2D slice (matrix) d with dimensions (C+1) x (D+1) filled with zeros
	d := make([][]int, C+1)
	for i := range d {
		d[i] = make([]int, D+1)
	}

	// Set the starting point in the matrix d at position (A, B) to 1
	d[A][B] = 1

	// Iterate over the range from A to C (inclusive) for the first dimension
	for i := A; i <= C; i++ {
		// Iterate over the range from B to D (inclusive) for the second dimension
		for j := B; j <= D; j++ {
			// Update the current cell d[i][j] using the values from the previous cells
			d[i][j] = (d[i][j] + (d[i][j-1]*i + d[i-1][j]*j - d[i-1][j-1]*(i-1)*(j-1))%m + m) % m) % m
		}
	}

	// Output the final result from the bottom-right corner of the matrix d
	fmt.Println(d[C][D])
}

// <END-OF-CODE>
