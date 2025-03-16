package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of points (N) from the user
	var N int
	fmt.Scan(&N)

	// Initialize a slice to store the coordinates of the points
	pos := make([][2]int, N)

	// Loop to read the coordinates of each point
	for i := 0; i < N; i++ {
		// Read the x and y coordinates for the i-th point
		fmt.Scan(&pos[i][0], &pos[i][1])
	}

	// Initialize a variable to accumulate the sum of distances
	var sum float64

	// Loop through each pair of points to calculate distances
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			// Skip the distance calculation if both points are the same
			if i == j {
				continue
			}

			// Calculate the distance between point i and point j and add it to the sum
			sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])
		}
	}

	// Print the average distance by dividing the total sum by N
	fmt.Println(sum / float64(N))
}

// Function to calculate the Euclidean distance between two points (x1, y1) and (x2, y2)
func dist(x1, y1, x2, y2 int) float64 {
	return math.Sqrt(float64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))
}

// <END-OF-CODE>
