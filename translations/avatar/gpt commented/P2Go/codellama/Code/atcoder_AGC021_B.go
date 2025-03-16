package main

import (
	"fmt"
	"math"
)

func main() {
	// Read input values: the first value is N (number of points), followed by the coordinates
	var N int
	fmt.Scan(&N)
	XY := make([]int, N*2)
	for i := 0; i < N*2; i++ {
		fmt.Scan(&XY[i])
	}

	// Pair the coordinates into a list of tuples (x, y)
	XY = XY[:N*2]

	// Iterate over each point in the list with its index
	for i, xy := range XY {
		// Calculate angles from the current point (x, y) to all other points
		D := make([]float64, N)
		for j, xy := range XY {
			if i != j {
				D[j] = math.Atan2(float64(xy[0]-XY[i][0]), float64(xy[1]-XY[i][1]))
			}
		}

		// Append the angle that wraps around (2*pi) to handle circularity
		D = append(D, D[0]+2*math.Pi)

		// Initialize the answer for the current point
		ans := 0.0

		// Calculate the gaps between consecutive angles
		for a, b := range D {
			// Check if the gap is greater than or equal to pi
			if b-a >= math.Pi {
				// Update the answer with the size of the gap minus pi
				ans = b - a - math.Pi
			}
		}

		// Print the normalized answer (as a fraction of 2*pi)
		fmt.Println(ans / (2 * math.Pi))
	}
}

