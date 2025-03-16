package main

import (
	"fmt"
)

const m = 998244353

func main() {
	var A, B, C, D int
	fmt.Scan(&A, &B, &C, &D)

	// Initialize a 2D slice d with dimensions (C+1) x (D+1), filled with zeros
	d := make([][]int, C+1)
	for i := range d {
		d[i] = make([]int, D+1)
	}

	// Set the starting point for our calculations
	d[A][B] = 1

	// Iterate over the range from A to C for the rows and from B to D for the columns
	for i := A; i <= C; i++ {
		for j := B; j <= D; j++ {
			// Update the value of d[i][j] based on its neighboring cells and some arithmetic operations
			d[i][j] = (d[i][j] + (d[i][j-1]*i + d[i-1][j]*j - d[i-1][j-1]*(i-1)*(j-1))) % m
		}
	}

	// Print the value at the bottom-right corner of the array
	fmt.Println(d[C][D])
}

