package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables for number of vectors (N), dimensions (D), and loop counters
	var N, D int
	var k int // Variable to count pairs with integer distances

	// Read the number of vectors (N) and their dimensions (D) from user input
	fmt.Scan(&N, &D)

	// Allocate a 2D slice to hold N vectors of D dimensions
	matrix := make([][]int, N)
	for i := range matrix {
		matrix[i] = make([]int, D)
	}

	// Read the vectors from user input and store them in the matrix
	for i := 0; i < N; i++ {
		for j := 0; j < D; j++ {
			fmt.Scan(&matrix[i][j])
		}
	}

	// Calculate the pairwise distances between all vectors
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			m := 0 // Variable to accumulate the squared differences
			// Calculate the squared distance between vector i and vector j
			for n := 0; n < D; n++ {
				diff := matrix[i][n] - matrix[j][n]
				m += diff * diff
			}
			// Calculate the Euclidean distance
			l := math.Sqrt(float64(m))
			// Check if the distance is an integer (i.e., if its ceiling equals its floor)
			if math.Ceil(l) == math.Floor(l) {
				k++
			}
		}
	}

	// Output the count of pairs of vectors with integer distances
	fmt.Println(k)
}

// <END-OF-CODE>
