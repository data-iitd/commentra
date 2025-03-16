package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	var XY []float64

	// Step 1: Reading Input
	// The code reads the number of points N and the coordinates of the points XY from the standard input.
	fmt.Scan(&N)
	for i := 0; i < N; i++ {
		var x, y float64
		fmt.Scan(&x, &y)
		XY = append(XY, x, y)
	}

	// Step 2: Processing Coordinates
	// The coordinates are grouped into pairs and stored in the list XY.
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			x1, y1 := XY[2*i], XY[2*i+1]
			x2, y2 := XY[2*j], XY[2*j+1]

			// Step 3: Calculating Angles
			// For each point, the code calculates the angles to all other points using atan2.
			angle := math.Atan2(x2-x1, y2-y1)

			// Step 4: Handling Circular Angles
			// The angles are adjusted to handle the circular nature of angles (0 to 2π).
			angles := []float64{}
			for k := 0; k < N; k++ {
				if k != i && k != j {
					xk, yk := XY[2*k], XY[2*k+1]
					angleK := math.Atan2(xk-x1, yk-y1)
					angles = append(angles, angleK)
				}
			}
			angles = append(angles, angles[0]+2*math.Pi)

			// Step 5: Finding the Maximum Gap
			maxGap := 0.0
			for a, b := range angles {
				if b-a >= math.Pi {
					gap := (b - a) - math.Pi
					if gap > maxGap {
						maxGap = gap
					}
				}
			}

			// Step 6: Calculating the Fraction
			// The fraction of the circle covered by the maximum gap is calculated and printed.
			fraction := maxGap / (2 * math.Pi)
			fmt.Println(fraction)
		}
	}
}
