package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	// Create a scanner to read input from the user
	var N int
	fmt.Scan(&N)

	// Initialize slices to store the x and y coordinates of the points
	x := make([]int, N)
	y := make([]int, N)

	// Read the coordinates of the points from user input
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &y[i])
	}

	// Iterate over each point to calculate the angles with respect to other points
	for i := 0; i < N; i++ {
		// Create a slice to store the angles (thetas) for the current point
		thetas := make([]float64, 0)

		// Calculate the angle between the current point and all other points
		for j := 0; j < N; j++ {
			// Skip the current point itself
			if i == j {
				continue
			}

			// Calculate the angle using atan2 and add it to the slice
			theta := math.Atan2(float64(y[j]-y[i]), float64(x[j]-x[i]))
			thetas = append(thetas, theta)
		}

		// Sort the angles in ascending order
		sort.Float64s(thetas)

		// Add the angle that wraps around (2 * PI) to handle circularity
		thetas = append(thetas, thetas[0]+2*math.Pi)

		// Initialize a variable to find the maximum angle difference
		ans := 0.0

		// Calculate the maximum angle difference between consecutive angles
		for k := 0; k < len(thetas)-1; k++ {
			ans = math.Max(ans, thetas[k+1]-thetas[k]-math.Pi)
		}

		// Output the result as a fraction of the full circle (2 * PI)
		fmt.Println(ans / (2 * math.Pi))
	}
}

// <END-OF-CODE>
