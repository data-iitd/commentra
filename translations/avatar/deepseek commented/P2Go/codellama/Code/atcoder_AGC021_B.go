package main

import (
	"fmt"
	"math"
)

func main() {
	// Step 1: Reading Input
	// The code reads the number of points N and the coordinates of the points XY from the standard input.
	var N int
	fmt.Scan(&N)
	XY := make([]int, N*2)
	for i := 0; i < N*2; i++ {
		fmt.Scan(&XY[i])
	}

	// Step 2: Processing Coordinates
	// The coordinates are grouped into pairs and stored in the list XY.
	XY = make([]int, N*2)
	for i := 0; i < N*2; i++ {
		XY[i] = XY[i]
	}

	// Step 3: Calculating Angles
	// For each point, the code calculates the angles to all other points using atan2.
	for i, (x, y) := range XY {
		// Calculate the angles for each point relative to others
		D := make([]float64, N)
		for j, (X, Y) := range XY {
			if j != i {
				D[j] = math.Atan2(float64(X-x), float64(Y-y))
			}
		}

		// Step 4: Handling Circular Angles
		// The angles are adjusted to handle the circular nature of angles (0 to 2π).
		D = append(D, D[0]+2*math.Pi)

		// Step 5: Finding the Maximum Gap
		ans := 0.0
		for a, b := range D {
			if b-a >= math.Pi {
				ans = b - a - math.Pi
			}
		}

		// Step 6: Calculating the Fraction
		// The fraction of the circle covered by the maximum gap is calculated and printed.
		fmt.Println(ans / (2 * math.Pi))
	}
}

