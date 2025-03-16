package main

import (
	"fmt"
	"math"
)

func main() {
	var N, D int
	fmt.Scan(&N, &D)

	// Initialize the slice to store the vectors
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

	// Initialize the answer variable
	answer := 0

	// Calculate the Euclidean distance between each pair of vectors
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			dist := 0
			for d := 0; d < D; d++ {
				x := vectors[i][d] - vectors[j][d]
				dist += x * x
			}
			sq := math.Sqrt(float64(dist))
			// Check if the distance is an integer and increment the answer if it is
			if math.Abs(sq-math.Floor(sq)) < 0.001 {
				answer++
			}
		}
	}

	// Print the answer
	fmt.Println(answer)
}

// <END-OF-CODE>
