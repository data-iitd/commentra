package main

import (
	"fmt"
	"math"
)

func main() {
	var n, d int

	// Read the number of points (n) and the number of dimensions (d)
	fmt.Scan(&n, &d)

	// Declare a 2D slice to store the coordinates of the points
	point := make([][]int, n+1)
	for i := range point {
		point[i] = make([]int, d+1)
	}

	// Input the coordinates for each point
	for i := 1; i <= n; i++ {
		for j := 1; j <= d; j++ {
			fmt.Scan(&point[i][j])
		}
	}

	// Initialize a counter for the number of pairs with integer distance
	count := 0

	// Iterate through all unique pairs of points
	for i := 1; i <= n-1; i++ {
		for j := i + 1; j <= n; j++ {
			// Calculate the squared distance between point i and point j
			sum := 0
			for k := 1; k <= d; k++ {
				diff := point[i][k] - point[j][k]
				sum += diff * diff
			}

			// Compute the Euclidean distance
			kyori := math.Sqrt(float64(sum))

			// Check if the distance is an integer
			if math.Ceil(kyori) == math.Floor(kyori) {
				count++ // Increment the count if the distance is an integer
			}
		}
	}

	// Output the total count of pairs with integer distance
	fmt.Println(count)
}

// <END-OF-CODE>
