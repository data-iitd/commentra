package main

import (
	"fmt"
	"math"
)

func main() {
	var n, d int // Declare integer variables n and d to store the number of points and dimensions
	fmt.Scan(&n, &d) // Read the values of n and d from the standard input

	point := make([][]int, n+1) // Create a slice of slices to store the points
	for i := range point {
		point[i] = make([]int, d+1) // Initialize each slice for dimensions
	}

	// Nested loop to read the coordinates of each point from the standard input
	for i := 1; i <= n; i++ {
		for j := 1; j <= d; j++ {
			fmt.Scan(&point[i][j])
		}
	}

	count := 0 // Initialize a counter to zero to count the number of integer distances

	// Nested loop to calculate the Euclidean distance between each pair of points
	for i := 1; i <= n-1; i++ {
		for j := i + 1; j <= n; j++ {
			sum := 0 // Initialize a variable to store the sum of squared differences
			for k := 1; k <= d; k++ {
				diff := point[i][k] - point[j][k]
				sum += diff * diff // Calculate the squared difference
			}
			kyori := math.Sqrt(float64(sum)) // Compute the square root of the sum to get the distance

			// Check if the distance is an integer by comparing ceil and floor of the distance
			if math.Ceil(kyori) == math.Floor(kyori) {
				count++ // Increment the counter if the distance is an integer
			}
		}
	}

	fmt.Println(count) // Print the final count of integer distances
}

// <END-OF-CODE>
