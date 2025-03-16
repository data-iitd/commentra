package main

import (
	"fmt"
	"math"
)

func main() {
	// Step 1: Reading Input
	var N, D int
	fmt.Scan(&N, &D)

	// Allocate memory for the matrix
	matrix := make([][]int, N)
	for i := range matrix {
		matrix[i] = make([]int, D)
	}

	// Step 2: Inputting Points
	for i := 0; i < N; i++ {
		for j := 0; j < D; j++ {
			fmt.Scan(&matrix[i][j])
		}
	}

	// Step 3: Calculating Distances
	k := 0
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			m := 0
			for n := 0; n < D; n++ {
				diff := matrix[i][n] - matrix[j][n]
				m += diff * diff
			}
			l := math.Sqrt(float64(m))
			if l == math.Floor(l) { // Check if l is an integer
				k++
			}
		}
	}

	// Step 4: Outputting the Result
	fmt.Println(k)
}
