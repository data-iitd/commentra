package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of vectors (N) and their dimensionality (D)
	var N, D int
	fmt.Scan(&N, &D)

	// Initialize a 2D slice to store the vectors
	vectors := make([][]int, N)
	for i := range vectors {
		vectors[i] = make([]int, D)
	}

	// Read each vector's components from the input
	for i := 0; i < N; i++ {
		for j := 0; j < D; j++ {
			fmt.Scan(&vectors[i][j])
		}
	}

	// Initialize a counter for the number of pairs with integer distances
	answer := 0

	// Calculate the pairwise distances between all vectors
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			dist := 0

			// Calculate the squared distance between vector i and vector j
			for d := 0; d < D; d++ {
				x := vectors[i][d] - vectors[j][d]
				dist += x * x
			}

			// Calculate the Euclidean distance
			sq := math.Sqrt(float64(dist))

			// Check if the distance is an integer (within a small epsilon)
			if math.Abs(sq-math.Floor(sq)) < 0.001 {
				answer++
			}
		}
	}

	// Output the total count of pairs with integer distances
	fmt.Println(answer)
}

// <END-OF-CODE>
