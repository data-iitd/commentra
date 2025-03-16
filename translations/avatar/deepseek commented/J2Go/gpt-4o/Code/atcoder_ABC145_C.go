package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N) // Reading the number of points
	pos := make([][2]int, N) // Initializing a slice to store coordinates

	// Reading coordinates of points
	for i := 0; i < N; i++ {
		fmt.Scan(&pos[i][0]) // Reading x-coordinate
		fmt.Scan(&pos[i][1]) // Reading y-coordinate
	}

	sum := 0.0 // Initializing sum to store the total distance

	// Calculating the sum of distances between all pairs of points
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if i == j {
				continue // Skipping the diagonal elements
			}
			sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) // Adding distance to sum
		}
	}

	// Calculating and printing the average distance
	fmt.Println(sum / float64(N))
}

// Helper function to calculate the Euclidean distance between two points
func dist(x1, y1, x2, y2 int) float64 {
	return math.Sqrt(float64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))
}

// <END-OF-CODE>
