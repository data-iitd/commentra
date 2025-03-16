package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	// Step 1: Reading Input
	var N int
	fmt.Scan(&N)
	XY := make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&XY[i][0], &XY[i][1])
	}

	// Step 2: Processing Coordinates
	// Coordinates are already stored in XY as pairs.

	// Step 3: Calculating Angles
	for i, point := range XY {
		x, y := point[0], point[1]
		var D []float64

		// Calculate the angles for each point relative to others
		for j, otherPoint := range XY {
			if j != i {
				X, Y := otherPoint[0], otherPoint[1]
				angle := math.Atan2(float64(X-x), float64(Y-y))
				D = append(D, angle)
			}
		}

		// Step 4: Handling Circular Angles
		sort.Float64s(D)
		D = append(D, D[0]+2*math.Pi)

		// Step 5: Finding the Maximum Gap
		ans := 0.0
		for k := 0; k < len(D)-1; k++ {
			if D[k+1]-D[k] >= math.Pi {
				ans = math.Max(ans, D[k+1]-D[k]-math.Pi)
			}
		}

		// Step 6: Calculating the Fraction
		fmt.Println(ans / (2 * math.Pi))
	}
}

// <END-OF-CODE>
