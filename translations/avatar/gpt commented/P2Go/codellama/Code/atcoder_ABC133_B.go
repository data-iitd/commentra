
package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of points (n) and the dimension (d) from input
	var n, d int
	fmt.Scan(&n, &d)

	// Read the coordinates of the points into a list
	points := make([][]int, n)
	for i := range points {
		points[i] = make([]int, d)
		for j := range points[i] {
			fmt.Scan(&points[i][j])
		}
	}

	// Define a function to calculate the Euclidean distance between two points
	dist := func(x, y []int) float64 {
		tmp := 0.0
		// Calculate the squared differences for each dimension
		for i := range x {
			tmp += (x[i] - y[i]) * (x[i] - y[i])
		}
		// Return the square root of the sum of squared differences
		return math.Sqrt(tmp)
	}

	// Initialize a counter for pairs of points with integer distances
	count := 0

	// Iterate through each point and compare it with every other point
	for i, elm := range points {
		for j := i + 1; j < n; j++ {
			// Check if the distance between the two points is an integer
			if dist(elm, points[j]) == float64(int(dist(elm, points[j]))) {
				count++ // Increment the count if the distance is an integer
			}
		}
	}

	// Print the total count of pairs with integer distances
	fmt.Println(count)
}

