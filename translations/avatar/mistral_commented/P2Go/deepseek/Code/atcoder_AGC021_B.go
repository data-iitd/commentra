package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	var XY [][]float64

	// Read the input from standard input and parse it into two variables: N (number of points) and XY (a list of slices representing the coordinates of N points)
	fmt.Scan(&N)
	XY = make([][]float64, N)
	for i := 0; i < N; i++ {
		XY[i] = make([]float64, 2)
		fmt.Scan(&XY[i][0], &XY[i][1])
	}

	// Iterate through each point in XY and calculate the angles between it and all other points
	for i := 0; i < N; i++ {
		var D []float64

		// Calculate the differences between the x and y coordinates of the current point and all other points
		for j := 0; j < N; j++ {
			if i != j {
				dx := XY[j][0] - XY[i][0]
				dy := XY[j][1] - XY[i][1]
				D = append(D, math.Atan2(dx, dy))
			}
		}

		// Sort the angles
		math.Sort(D)

		// Append the angle between the current point and the first point (wrapped around if it's greater than pi)
		D = append(D, D[0]+2*math.Pi)

		// Initialize a variable to store the answer
		ans := 0.0

		// Iterate through each pair of consecutive angles and calculate the area of the corresponding sector
		for k := 0; k < len(D)-1; k++ {
			a := D[k]
			b := D[k+1]

			// If the angle between two consecutive points is greater than pi, subtract pi from it and add it to the answer
			if b-a >= math.Pi {
				ans += (b - a) - math.Pi
			}
		}

		// Print the answer, which is the total area of the sectors divided by the total possible area (2π)
		fmt.Println(ans / (2 * math.Pi))
	}
}
