package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the user
	var N, D int
	fmt.Scan(&N, &D)
	
	// Initialize a 2D slice to store the vectors
	vectors := make([][]int, N)
	for i := range vectors {
		vectors[i] = make([]int, D)
		for j := range vectors[i] {
			fmt.Scan(&vectors[i][j])
		}
	}
	
	// Initialize a counter for the number of pairs with integer distances
	answer := 0
	
	// Calculate the pairwise distances between all vectors
	for i := 0; i < N - 1; i++ {
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
			if math.Abs(sq - math.Floor(sq)) < 1e-3 {
				answer++
			}
		}
	}
	
	// Output the total count of pairs with integer distances
	fmt.Println(answer)
}

