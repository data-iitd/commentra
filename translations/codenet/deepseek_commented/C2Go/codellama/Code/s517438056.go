package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	// Step 1: Reading Input
	var N, D, i, j, k int
	var l float64
	var matrix [][]int
	fmt.Scan(&N, &D)

	// Allocate memory for the matrix
	matrix = make([][]int, N)
	for i = 0; i < N; i++ {
		matrix[i] = make([]int, D)
	}

	// Step 2: Inputting Points
	for i = 0; i < N; i++ {
		for j = 0; j < D; j++ {
			fmt.Scan(&matrix[i][j])
		}
	}

	// Step 3: Calculating Distances
	for i = 0; i < N-1; i++ {
		for j = i + 1; j < N; j++ {
			m := 0
			for n = 0; n < D; n++ {
				m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m
			}
			l = math.Sqrt(float64(m))
			if math.Ceil(l) == math.Floor(l) {
				k++
			}
		}
	}

	// Step 4: Outputting the Result
	fmt.Println(k)
}

