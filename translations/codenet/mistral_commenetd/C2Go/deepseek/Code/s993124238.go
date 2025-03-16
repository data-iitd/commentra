package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables for number of points and their dimensions
	var n, d int

	// Read number of points and their dimensions from the user
	fmt.Scan(&n, &d)

	// Declare a 2D slice 'point' to store the coordinates of each point
	point := make([][]int, n+1)
	for i := range point {
		point[i] = make([]int, d+1)
	}

	// Read the coordinates of each point and store them in the 'point' slice
	for i := 1; i <= n; i++ {
		for j := 1; j <= d; j++ {
			fmt.Scan(&point[i][j])
			// Read the j-th coordinate of the i-th point
		}
		// Read the i-th row of the 'point' slice (i.e., the i-th point's coordinates)
	}

	// Initialize a counter variable 'count' to 0
	count := 0

	// Iterate through all pairs of points (i, j) where i < j
	for i := 1; i <= n-1; i++ {
		for j := i + 1; j <= n; j++ {
			// Initialize a variable 'sum' to store the sum of the squared differences between the corresponding coordinates of points i and j
			sum := 0

			// Calculate the sum of the squared differences between the corresponding coordinates of points i and j
			for k := 1; k <= d; k++ {
				sum += (point[i][k] - point[j][k]) * (point[i][k] - point[j][k])
				// Calculate the difference between the k-th coordinate of point i and the k-th coordinate of point j, square it, and add it to the 'sum' variable
			}

			// Calculate the Euclidean distance between points i and j using the 'sum' variable
			kyori := math.Sqrt(float64(sum))

			// Check if the Euclidean distance is equal to an integer value (i.e., the points are on the same circle)
			if math.Ceil(kyori) == math.Floor(kyori) {
				// If so, increment the 'count' variable
				count++
			}
		}
	}

	// Print the final count of pairs of points on the same circle
	fmt.Println(count)
}

