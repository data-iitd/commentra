package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of points and the dimension from the input
	var n, d int
	fmt.Scan(&n, &d)

	// Read n points, each with d coordinates, and store them in a slice called points
	points := make([][]int, n)
	for i := 0; i < n; i++ {
		points[i] = make([]int, d)
		for j := 0; j < d; j++ {
			fmt.Scan(&points[i][j])
		}
	}

	// Define a function to calculate the Euclidean distance between two points
	dist := func(x, y []int) float64 {
		tmp := 0.0
		for i := 0; i < d; i++ {
			tmp += math.Pow(float64(x[i]-y[i]), 2)
		}
		return math.Sqrt(tmp)
	}

	// Initialize a counter to keep track of pairs with integer distances
	count := 0

	// Iterate over all pairs of points
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			// Check if the distance between the two points is an integer
			if dist(points[i], points[j]) == float64(int(dist(points[i], points[j]))) {
				count++
			}
		}
	}

	// Print the total count of pairs with integer distances
	fmt.Println(count)
}

// <END-OF-CODE>
