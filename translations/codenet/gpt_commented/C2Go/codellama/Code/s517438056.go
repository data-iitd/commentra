package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Declare variables for number of vectors (N), dimensions (D), and loop counters
	var N, D, i, j, k int = 0, 0, 0, 0, 0
	var l float64 = 0.0
	var matrix [][]int = make([][]int, 0)

	// Read the number of vectors (N) and their dimensions (D) from user input
	fmt.Scan(&N, &D)

	// Allocate memory for a 2D array (matrix) to hold N vectors of D dimensions
	for i = 0; i < N; i++ {
		matrix = append(matrix, make([]int, D))
	}

	// Read the vectors from user input and store them in the matrix
	for i = 0; i < N; i++ {
		for j = 0; j < D; j++ {
			fmt.Scan(&matrix[i][j])
		}
	}

	// Calculate the pairwise distances between all vectors
	for i = 0; i < N-1; i++ {
		for j = i + 1; j < N; j++ {
			var m int = 0 // Variable to accumulate the squared differences
			// Calculate the squared distance between vector i and vector j
			for n = 0; n < D; n++ {
				m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m
			}
			// Calculate the Euclidean distance
			l = math.Sqrt(float64(m))
			// Check if the distance is an integer (i.e., if its ceiling equals its floor)
			if math.Ceil(l) == math.Floor(l) {
				k++
			}
		}
	}

	// Output the count of pairs of vectors with integer distances
	fmt.Println(k)
}

