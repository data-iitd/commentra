package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the user
	var scan = new(Scanner)

	// Read the number of points N
	var N int
	fmt.Scan(&N)

	// Initialize arrays to store the x and y coordinates of the points
	var x = make([]int, N)
	var y = make([]int, N)

	// Read the coordinates of the points from user input
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &y[i])
	}

	// Iterate over each point to calculate the angles with respect to other points
	for i := 0; i < N; i++ {
		// Create a list to store the angles (thetas) for the current point
		var thetas = make([]float64, 0)

		// Calculate the angle between the current point and all other points
		for j := 0; j < N; j++ {
			// Skip the current point itself
			if i == j {
				continue
			}

			// Calculate the angle using atan2 and add it to the list
			thetas = append(thetas, math.Atan2(float64(y[j]-y[i]), float64(x[j]-x[i])))
		}

		// Sort the angles in ascending order
		sort.Float64s(thetas)

		// Add the angle that wraps around (2 * PI) to handle circularity
		thetas = append(thetas, thetas[0]+2*math.Pi)

		// Initialize a variable to find the maximum angle difference
		var ans float64

		// Calculate the maximum angle difference between consecutive angles
		for k := 0; k < N-1; k++ {
			ans = math.Max(ans, thetas[k+1]-thetas[k]-math.Pi)
		}

		// Output the result as a fraction of the full circle (2 * PI)
		fmt.Println(ans / (math.Pi * 2))
	}
}

